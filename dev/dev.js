class Player {
    constructor(name) {
        this.name = name;
        this.cards = [];
    }

    addCard(cardStr) {
        this.cards.push(new Card(cardStr.charAt(0), cardStr.substring(1)));
    }
}

class Card {
    constructor(suit, value) {
        this.suit = suit;
        this.value = value;
        this.allValues = "23456789|0jqka";
    }

    compareTo(other) {
        return this.allValues.indexOf(this.value) - this.allValues.indexOf(other.value);
    }
}

class Game {
    constructor(playerNames, trump) {
        this.players = {};
        this.playedCards = [];
        this.trump = trump;
        this.playerNames = playerNames;

        for (let name of playerNames) {
            this.players[name] = new Player(name);
        }
    }

    addCardToPlayer(playerName, cardStr) {
        const card = new Card(cardStr.charAt(0), cardStr.substring(1));
        this.players[playerName].addCard(cardStr);
        this.playedCards.push(card);
    }

    getOptimalCard(self) {
        const teammate = (this.playerNames.indexOf(self.name) % 2 === 0)
            ? this.playerNames[this.playerNames.indexOf(self.name) + 2]
            : this.playerNames[this.playerNames.indexOf(self.name) - 2];

        let highestCard = this.playedCards[0];
        for (let card of this.playedCards) {
            if ((highestCard.suit === card.suit && card.compareTo(highestCard) > 0)
                || (card.suit === this.trump && highestCard.suit !== this.trump)) {
                highestCard = card;
            }
        }

        if (this.players[teammate].cards.some(c => c.suit === highestCard.suit && c.value === highestCard.value)) {
            return this.getSmallestCard(self.cards, '0');
        }

        if (highestCard.suit !== this.trump) {
            const smallestBiggerCard = this.getSmallestCardBiggerThan(self.cards, highestCard, highestCard.suit);
            if (smallestBiggerCard !== null) {
                return smallestBiggerCard;
            }
            return this.getSmallestCard(self.cards, '0');
        }

        const highestTeammateTrumpCard = this.getHighestCard(this.players[teammate].cards, this.trump);
        let highestEnemyTrumpCard = null;

        for (let playerName of this.playerNames) {
            if (playerName === teammate || playerName === self.name)
                continue;
            const tempCard = this.getHighestCard(this.players[playerName].cards, this.trump);
            if (tempCard !== null
                && (highestEnemyTrumpCard === null || tempCard.compareTo(highestEnemyTrumpCard) > 0)) {
                highestEnemyTrumpCard = tempCard;
            }
        }

        if (highestTeammateTrumpCard === null || (highestEnemyTrumpCard !== null
            && highestTeammateTrumpCard.compareTo(highestEnemyTrumpCard) > 0)) {
            const smallestTrumpHigherThanEnemy = this.getSmallestCardBiggerThan(self.cards, highestEnemyTrumpCard, this.trump);
            if (smallestTrumpHigherThanEnemy !== null) {
                return smallestTrumpHigherThanEnemy;
            }
        }

        return this.getSmallestCard(self.cards, this.trump);
    }

    getHighestCard(cards, suit) {
        cards.sort((a, b) => b.compareTo(a));
        for (let card of cards) {
            if (card.suit === suit) {
                return card;
            }
        }
        return null;
    }

    getSmallestCard(cards, suit) {
        cards.sort((a, b) => a.compareTo(b));
        for (let card of cards) {
            if (suit === '0' || card.suit === suit) {
                return card;
            }
        }
        return null;
    }

    getSmallestCardBiggerThan(cards, targetCard, targetSuit) {
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
}

inputString = "trump:c;self:Alice;players:Bob,Charlie,Dave,Alice;Bob:ca;Charlie:ck;Dave:h5;cards:dk,c8,s9"
// inputString = input
const components = inputString.split(';');
const inputMap = {};
for (const component of components) {
    const [key, value] = component.split(':');
    inputMap[key.trim()] = value.trim();
}
const playerNames = inputMap["players"].split(",").map(name => name.trim());

const trump = inputMap["trump"].charAt(0);
const game = new Game(playerNames, trump);

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
process.stdout.write(optimalCard.suit + optimalCard.value);
