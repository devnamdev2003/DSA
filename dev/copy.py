class Player:
    def __init__(self, name):
        self.name = name
        self.cards = []

    def add_card(self, card_str):
        self.cards.append(Card(card_str[0], card_str[1:]))


class Card:
    all_values = "23456789|0jqka"

    def __init__(self, suit, value):
        self.suit = suit
        self.value = value

    def __lt__(self, other):
        return Card.all_values.index(self.value) < Card.all_values.index(other.value)


class Game:
    def __init__(self, player_names, trump):
        self.players = {name: Player(name) for name in player_names}
        self.played_cards = []
        self.trump = trump
        self.player_names = player_names

    def add_card_to_player(self, player_name, card_str):
        card = Card(card_str[0], card_str[1:])
        self.players[player_name].add_card(card_str)
        self.played_cards.append(card)

    def get_optimal_card(self, player):
        teammate = self.player_names[(self.player_names.index(player.name) + 2) % len(self.player_names)]

        highest_card = max(self.played_cards)
        for card in self.played_cards:
            if (highest_card.suit == card.suit and card > highest_card) or (card.suit == self.trump and highest_card.suit != self.trump):
                highest_card = card

        if highest_card in self.players[teammate].cards:
            return self.get_smallest_card(player.cards, '0')

        if highest_card.suit != self.trump:
            smallest_bigger_card = self.get_smallest_card_bigger_than(player.cards, highest_card, highest_card.suit)
            if smallest_bigger_card:
                return smallest_bigger_card
            return self.get_smallest_card(player.cards, '0')

        highest_teammate_trump_card = max(self.players[teammate].cards, default=None)
        highest_enemy_trump_card = None

        for player_name in self.player_names:
            if player_name in [teammate, player.name]:
                continue
            temp_card = max(self.players[player_name].cards, default=None)
            if temp_card and (not highest_enemy_trump_card or temp_card > highest_enemy_trump_card):
                highest_enemy_trump_card = temp_card

        if not highest_teammate_trump_card or (highest_enemy_trump_card and highest_teammate_trump_card > highest_enemy_trump_card):
            smallest_trump_higher_than_enemy = self.get_smallest_card_bigger_than(player.cards, highest_enemy_trump_card, self.trump)
            if smallest_trump_higher_than_enemy:
                return smallest_trump_higher_than_enemy

        return self.get_smallest_card(player.cards, self.trump)

    def get_highest_card(self, cards, suit):
        cards.sort(reverse=True)
        for card in cards:
            if card.suit == suit:
                return card
        return None

    def get_smallest_card(self, cards, suit):
        cards.sort()
        for card in cards:
            if suit == '0' or card.suit == suit:
                return card
        return None

    def get_smallest_card_bigger_than(self, cards, target_card, target_suit):
        smallest_bigger_card = None
        for card in cards:
            if card.suit == target_suit and card > target_card:
                if smallest_bigger_card is None or card < smallest_bigger_card:
                    smallest_bigger_card = card
        return smallest_bigger_card

def main():
    input_str = input().strip()

    input_map = {}
    parts = input_str.split(";")
    for part in parts:
        key_value = part.split(":")
        if len(key_value) == 2:
            input_map[key_value[0]] = key_value[1]

    player_names = input_map.get("players", "").split(",")
    trump = input_map.get("trump", ' ')

    game = Game(player_names, trump)

    for player_name in player_names:
        if player_name in input_map:
            game.add_card_to_player(player_name, input_map[player_name])

    self_player = game.players.get(input_map.get("self", ""))
    if self_player:
        for card_str in input_map.get("cards", "").split(","):
            self_player.add_card(card_str)

        optimal_card = game.get_optimal_card(self_player)
        print(optimal_card.suit + optimal_card.value)


if __name__ == "__main__":
    main()
