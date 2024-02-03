def create_player(name):
    return {
        'name': name,
        'cards': [],
    }

def add_card_to_player(player, card_str):
    card = create_card(card_str[0], card_str[1:])
    player['cards'].append(card)

def create_card(suit, value):
    return {
        'suit': suit,
        'value': value,
        'all_values': "23456789|0jqka",
    }

def compare_to(card, other):
    return card['all_values'].index(card['value']) - card['all_values'].index(other['value'])

def get_highest_card(cards, suit):
    cards.sort(key=lambda x: x['all_values'].index(x['value']), reverse=True)
    for card in cards:
        if card['suit'] == suit:
            return card
    return None

def get_smallest_card(cards, suit):
    cards.sort(key=lambda x: x['all_values'].index(x['value']))
    for card in cards:
        if suit == '0' or card['suit'] == suit:
            return card
    return None

def get_smallest_card_bigger_than(cards, target_card, target_suit):
    smallest_bigger_card = None
    for card in cards:
        if card['suit'] == target_suit and compare_to(card, target_card) > 0:
            if smallest_bigger_card is None or compare_to(card, smallest_bigger_card) < 0:
                smallest_bigger_card = card
    return smallest_bigger_card

def create_game(player_names, trump):
    players = {name: create_player(name) for name in player_names}
    played_cards = []

    def add_card_to_player(player_name, card_str):
        nonlocal played_cards
        card = create_card(card_str[0], card_str[1:])
        players[player_name]['cards'].append(card)
        played_cards.append(card)

    def get_optimal_card(self_name):
        nonlocal played_cards
        teammate = (player_names.index(self_name) + 2) % len(player_names)

        highest_card = played_cards[0]
        for card in played_cards:
            if (highest_card['suit'] == card['suit'] and compare_to(card, highest_card) > 0) or \
                    (card['suit'] == trump and highest_card['suit'] != trump):
                highest_card = card

        teammate_cards = players[player_names[teammate]]['cards']
        if any(c['suit'] == highest_card['suit'] and c['value'] == highest_card['value'] for c in teammate_cards):
            return get_smallest_card(players[self_name]['cards'], '0')

        if highest_card['suit'] != trump:
            smallest_bigger_card = get_smallest_card_bigger_than(players[self_name]['cards'], highest_card, highest_card['suit'])
            if smallest_bigger_card is not None:
                return smallest_bigger_card
            return get_smallest_card(players[self_name]['cards'], '0')

        highest_teammate_trump_card = get_highest_card(teammate_cards, trump)
        highest_enemy_trump_card = None

        for player_name in player_names:
            if player_name == player_names[teammate] or player_name == self_name:
                continue
            temp_card = get_highest_card(players[player_name]['cards'], trump)
            if temp_card is not None and (highest_enemy_trump_card is None or compare_to(temp_card, highest_enemy_trump_card) > 0):
                highest_enemy_trump_card = temp_card

        if highest_teammate_trump_card is None or (highest_enemy_trump_card is not None
                and compare_to(highest_teammate_trump_card, highest_enemy_trump_card) > 0):
            smallest_trump_higher_than_enemy = get_smallest_card_bigger_than(players[self_name]['cards'], highest_enemy_trump_card, trump)
            if smallest_trump_higher_than_enemy is not None:
                return smallest_trump_higher_than_enemy

        return get_smallest_card(players[self_name]['cards'], trump)

    return {
        'players': players,
        'played_cards': played_cards,
        'add_card_to_player': add_card_to_player,
        'get_optimal_card': get_optimal_card
    }

# Example usage
input_string = "trump: c; self: Alice; players: Bob, Charlie, Dave, Alice; Bob: ca; Charlie: ck; Dave: h5; cards: dk, c8, s9"
components = input_string.split(';')
input_map = {key.strip(): value.strip() for key, value in (component.split(':') for component in components)}
player_names = input_map["players"].split(",")
trump = input_map["trump"][0]
game = create_game(player_names, trump)

for player_name in player_names:
    if player_name in input_map:
        game['add_card_to_player'](player_name, input_map[player_name])

self_name = input_map["self"]
for card_str in input_map["cards"].split(","):
    game['players'][self_name]['cards'].append(create_card(card_str[0], card_str[1:]))

optimal_card = game['get_optimal_card'](self_name)
print(optimal_card['suit'] + optimal_card['value'])
