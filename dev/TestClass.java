import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

class Player {
    String name;
    List<Card> cards;

    public Player(String name) {
        this.name = name;
        this.cards = new ArrayList<>();
    }

    public void addCard(String cardStr) {
        this.cards.add(new Card(cardStr.charAt(0), cardStr.substring(1)));
    }
}

class Card {
    char suit;
    String value;
    String allValues = "23456789|0jqka";

    public Card(char suit, String value) {
        this.suit = suit;
        this.value = value;
    }

    public int compareTo(Card other) {
        return this.allValues.indexOf(this.value) - this.allValues.indexOf(other.value);
    }
}

class Game {
    Map<String, Player> players;
    List<Card> playedCards;
    char trump;
    List<String> playerNames;

    public Game(List<String> playerNames, char trump) {
        this.players = new HashMap<>();
        this.playedCards = new ArrayList<>();
        this.trump = trump;
        this.playerNames = playerNames;

        for (String name : playerNames) {
            this.players.put(name, new Player(name));
        }
    }

    public void addCardToPlayer(String playerName, String cardStr) {
        Card card = new Card(cardStr.charAt(0), cardStr.substring(1));
        this.players.get(playerName).addCard(cardStr);
        this.playedCards.add(card);
    }

    public Card getOptimalCard(Player self) {
        String teammate = (this.playerNames.indexOf(self.name) % 2 == 0)
                ? this.playerNames.get(this.playerNames.indexOf(self.name) + 2)
                : this.playerNames.get(this.playerNames.indexOf(self.name) - 2);

        Card[] highestCard = { this.playedCards.get(0) }; 

        this.playedCards.forEach(card -> {
            if ((highestCard[0].suit == card.suit && card.compareTo(highestCard[0]) > 0)
                    || (card.suit == this.trump && highestCard[0].suit != this.trump)) {
                highestCard[0] = card;
            }
        });

        if (this.players.get(teammate).cards.stream()
                .anyMatch(c -> c.suit == highestCard[0].suit && c.value.equals(highestCard[0].value))) {
            return this.getSmallestCard(self.cards, "0");
        }

        if (highestCard[0].suit != this.trump) {
            Card smallestBiggerCard = this.getSmallestCardBiggerThan(self.cards, highestCard[0], highestCard[0].suit);
            if (smallestBiggerCard != null) {
                return smallestBiggerCard;
            }
            return this.getSmallestCard(self.cards, "0");
        }

        Card highestTeammateTrumpCard = this.getHighestCard(this.players.get(teammate).cards, this.trump);
        Card highestEnemyTrumpCard = null;

        for (String playerName : this.playerNames) {
            if (playerName.equals(teammate) || playerName.equals(self.name))
                continue;
            Card tempCard = this.getHighestCard(this.players.get(playerName).cards, this.trump);
            if (tempCard != null
                    && (highestEnemyTrumpCard == null || tempCard.compareTo(highestEnemyTrumpCard) > 0)) {
                highestEnemyTrumpCard = tempCard;
            }
        }

        if (highestTeammateTrumpCard == null || (highestEnemyTrumpCard != null
                && highestTeammateTrumpCard.compareTo(highestEnemyTrumpCard) > 0)) {
            Card smallestTrumpHigherThanEnemy = this.getSmallestCardBiggerThan(self.cards, highestEnemyTrumpCard,
                    this.trump);
            if (smallestTrumpHigherThanEnemy != null) {
                return smallestTrumpHigherThanEnemy;
            }
        }

        return this.getSmallestCard(self.cards, String.valueOf(this.trump));
    }

    public Card getHighestCard(List<Card> cards, char suit) {
        cards.sort((a, b) -> b.compareTo(a));
        for (Card card : cards) {
            if (card.suit == suit) {
                return card;
            }
        }
        return null;
    }

    public Card getSmallestCard(List<Card> cards, String suit) {
        cards.sort((a, b) -> a.compareTo(b));
        for (Card card : cards) {
            if (suit.equals("0") || card.suit == suit.charAt(0)) {
                return card;
            }
        }
        return null;
    }

    public Card getSmallestCardBiggerThan(List<Card> cards, Card targetCard, char targetSuit) {
        Card smallestBiggerCard = null;
        for (Card card : cards) {
            if (card.suit == targetSuit && card.compareTo(targetCard) > 0) {
                if (smallestBiggerCard == null || card.compareTo(smallestBiggerCard) < 0) {
                    smallestBiggerCard = card;
                }
            }
        }
        return smallestBiggerCard;
    }
}

public class TestClass {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            String inputString = scanner.nextLine();
            String[] components = inputString.split(";");
            Map<String, String> inputMap = new HashMap<>();
            for (String component : components) {
                String[] keyValue = component.split(":");
                inputMap.put(keyValue[0].trim(), keyValue[1].trim());
            }

            List<String> playerNames = Arrays.asList(inputMap.get("players").split(","));
            char trump = inputMap.get("trump").charAt(0);
            Game game = new Game(playerNames, trump);

            for (String playerName : playerNames) {
                if (inputMap.containsKey(playerName)) {
                    game.addCardToPlayer(playerName, inputMap.get(playerName));
                }
            }

            Player self = game.players.get(inputMap.get("self"));
            for (String cardStr : inputMap.get("cards").split(",")) {
                self.addCard(cardStr.trim());
            }

            Card optimalCard = game.getOptimalCard(self);
            System.out.println(optimalCard.suit + optimalCard.value);
        }
    }
}
