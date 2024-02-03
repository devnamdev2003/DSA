class Player:
    def __init__(self, name):
        self.name = name
        self.cards = []

    def add_card(self, card_str):
        self.cards.append(Card(card_str[0], card_str[1:]))


class Card:
    def __init__(self, suit, value):
        self.suit = suit
        self.value = value
        self.all_values = "23456789|0jqka"

    def compare_to(self, other):
        return self.all_values.index(self.value) - self.all_values.index(other.value)


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

    def get_optimal_card(self):
        teammate_index = (self.player_names.index(self.name) + 2) if self.player_names.index(self.name) % 2 == 0 else (self.player_names.index(self.name) - 2)
        teammate = self.player_names[teammate_index]

        highest_card = self.played_cards[0]
        for card in self.played_cards:
            if (highest_card.suit == card.suit and card.compare_to(highest_card) > 0) or (card.suit == self.trump and highest_card.suit != self.trump):
                highest_card = card

        if any(c.suit == highest_card.suit and c.value == highest_card.value for c in self.players[teammate].cards):
            return self.get_smallest_card(self.cards, '0')

        if highest_card.suit != self.trump:
            smallest_bigger_card = self.get_smallest_card_bigger_than(self.cards, highest_card, highest_card.suit)
            if smallest_bigger_card is not None:
                return smallest_bigger_card
            return self.get_smallest_card(self.cards, '0')

        highest_teammate_trump_card = self.get_highest_card(self.players[teammate].cards, self.trump)
        highest_enemy_trump_card = None

        for player_name in self.player_names:
            if player_name == teammate or player_name == self.name:
                continue
            temp_card = self.get_highest_card(self.players[player_name].cards, self.trump)
            if temp_card is not None and (highest_enemy_trump_card is None or temp_card.compare_to(highest_enemy_trump_card) > 0):
                highest_enemy_trump_card = temp_card

        if highest_teammate_trump_card is None or (highest_enemy_trump_card is not None and highest_teammate_trump_card.compare_to(highest_enemy_trump_card) > 0):
            smallest_trump_higher_than_enemy = self.get_smallest_card_bigger_than(self.cards, highest_enemy_trump_card, self.trump)
            if smallest_trump_higher_than_enemy is not None:
                return smallest_trump_higher_than_enemy

        return self.get_smallest_card(self.cards, self.trump)

    def get_highest_card(cards, suit):
        cards.sort(key=lambda card: card.compare_to(card), reverse=True)
        for card in cards:
            if card.suit == suit:
                return card
        return None

    def get_smallest_card(cards, suit):
        cards.sort(key=lambda card: card.compare_to(card))
        for card in cards:
            if suit == '0' or card.suit == suit:
                return card
        return None

    def get_smallest_card_bigger_than(cards, target_card, target_suit):
        smallest_bigger_card = None
        for card in cards:
            if card.suit == target_suit and card.compare_to(target_card) > 0:
                if smallest_bigger_card is None or card.compare_to(smallest_bigger_card) < 0:
                    smallest_bigger_card = card
        return smallest_bigger_card


def main():
    input_string = "players:Tom,dick,Harry,john;self:john;trump:s;dick:S10;Tom:s2;Harry:ca;cards:s3,sk,ha"
    input_map = {}
    components = input_string.split(';')
    for component in components:
        key, value = map(str.strip, component.split(':'))
        input_map[key] = value

    player_names = list(map(str.strip, input_map["players"].split(",")))
    trump = input_map["trump"][0]
    game = Game(player_names, trump)

    for player_name in player_names:
        if player_name in input_map:
            game.add_card_to_player(player_name, input_map[player_name])

    self_player = game.players[input_map["self"]]
    for card_str in input_map["cards"].split(","):
        self_player.add_card(card_str.strip())
    
    print(self_player.player_names)
    optimal_card = game.get_optimal_card(self_player)
    print(optimal_card.suit + optimal_card.value)


main()
# Example usage:
# input_str = "players:Tom,dick,Harry,john;self:john;trump:s;dick:S10;Tom:s2;Harry:ca;cards:s3,sk,ha"
# main(input_str)
