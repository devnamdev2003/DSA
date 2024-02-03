function createPlayer(name) {
    return {
        name: name,
        cards: [],
        addCard: function (cardStr) {
            this.cards.push(createCard(cardStr.charAt(0), cardStr.substring(1)));
        }
    };
}

function createCard(suit, value) {
    return {
        suit: suit,
        value: value,
        allValues: "23456789|0jqka",
        compareTo: function (other) {
            return this.allValues.indexOf(this.value) - this.allValues.indexOf(other.value);
        }
    };
}

function createGame(playerNames, trump) {
    const players = {};
    const playedCards = [];

    for (let name of playerNames) {
        players[name] = createPlayer(name);
    }

    function addCardToPlayer(playerName, cardStr) {
        const card = createCard(cardStr.charAt(0), cardStr.substring(1));
        players[playerName].addCard(cardStr);
        playedCards.push(card);
    }

    function getOptimalCard(self) {
        const teammate = (playerNames.indexOf(self.name) % 2 === 0)
            ? playerNames[playerNames.indexOf(self.name) + 2]
            : playerNames[playerNames.indexOf(self.name) - 2];

        let highestCard = playedCards[0];
        for (let card of playedCards) {
            if ((highestCard.suit === card.suit && card.compareTo(highestCard) > 0)
                || (card.suit === trump && highestCard.suit !== trump)) {
                highestCard = card;
            }
        }

        if (players[teammate].cards.some(c => c.suit === highestCard.suit && c.value === highestCard.value)) {
            return getSmallestCard(self.cards, '0');
        }

        if (highestCard.suit !== trump) {
            const smallestBiggerCard = getSmallestCardBiggerThan(self.cards, highestCard, highestCard.suit);
            if (smallestBiggerCard !== null) {
                return smallestBiggerCard;
            }
            return getSmallestCard(self.cards, '0');
        }

        const highestTeammateTrumpCard = getHighestCard(players[teammate].cards, trump);
        let highestEnemyTrumpCard = null;

        for (let playerName of playerNames) {
            if (playerName === teammate || playerName === self.name)
                continue;
            const tempCard = getHighestCard(players[playerName].cards, trump);
            if (tempCard !== null && (highestEnemyTrumpCard === null || tempCard.compareTo(highestEnemyTrumpCard) > 0)) {
                highestEnemyTrumpCard = tempCard;
            }
        }

        if (highestTeammateTrumpCard === null || (highestEnemyTrumpCard !== null
            && highestTeammateTrumpCard.compareTo(highestEnemyTrumpCard) > 0)) {
            const smallestTrumpHigherThanEnemy = getSmallestCardBiggerThan(self.cards, highestEnemyTrumpCard, trump);
            if (smallestTrumpHigherThanEnemy !== null) {
                return smallestTrumpHigherThanEnemy;
            }
        }

        return getSmallestCard(self.cards, trump);
    }

    function getHighestCard(cards, suit) {
        cards.sort((a, b) => b.compareTo(a));
        for (let card of cards) {
            if (card.suit === suit) {
                return card;
            }
        }
        return null;
    }

    function getSmallestCard(cards, suit) {
        cards.sort((a, b) => a.compareTo(b));
        for (let card of cards) {
            if (suit === '0' || card.suit === suit) {
                return card;
            }
        }
        return null;
    }

    function getSmallestCardBiggerThan(cards, targetCard, targetSuit) {
        let smallestBiggerCard = null;
        for (let card of cards) {
            if (card.suit === targetSuit && card.compareTo(targetCard) > 0) {
                if (smallestBiggerCard === null || card.compareTo(smallestBiggerCard) < 0) {
                    smallestBiggerCard = card;
                }
            }
        }
        return smallestBiggerCard;
    }

    return {
        players: players,
        playedCards: playedCards,
        addCardToPlayer: addCardToPlayer,
        getOptimalCard: getOptimalCard
    };
}

process.stdin.resume();
process.stdin.setEncoding("utf-8");
var stdin_input = "";

process.stdin.on("data", function (input) {
    stdin_input += input;
});
process.stdin.on("end", function () {
    main(stdin_input);
});
function main(input) {
    inputString = input
    const components = inputString.split(';');
    const inputMap = {};
    for (const component of components) {
        const [key, value] = component.split(':');
        inputMap[key.trim()] = value.trim();
    }
    const playerNames = inputMap["players"].split(",").map(name => name.trim());

    const trump = inputMap["trump"].charAt(0);
    const game = createGame(playerNames, trump);

    for (let playerName of playerNames) {
        if (inputMap[playerName]) {
            game.addCardToPlayer(playerName, inputMap[playerName]);
        }
    }

    const self = game.players[inputMap["self"]];
    for (let cardStr of inputMap["cards"].split(",")) {
        self.addCard(cardStr.trim());
    }

    const optimalCard = game.getOptimalCard(self);
    console.log(optimalCard.suit + optimalCard.value);

}

