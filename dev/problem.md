# Optimal Card Selection

This problem is about playing the optimal card in a game similar to bridge.

## Problem Details
There are 52 cards. Each card has a suit (Spades, Clubs, Diamonds and Hearts) and a value (2,3,4,5,6,7,8,9,10,J,Q,K,A). The 52 cards are each a unique combination of the two (4 suits x 13 values = 52). Within cards of the same suit, a 'bigger' card is determined by the value as listed in ascending order. Thus, 5 is bigger than 2, K is bigger than 10, A is bigger than J and so on.

## Rules of the game

Before playing the game one suit is designated as the trump suit. The game is played by 4 people using a standard deck of playing cards. Alternate people are in the same team. The game is played in rounds. Each round is started by the winner of the previous round. In a round, each person plays exactly one card. The suit of the round is the suit of the card played by the first person. A person may only play a card of the suit of the round. Only if the person does NOT have any card of the suit, the person may play a card of some other suit

## Scoring

Once all the cards have been played, scoring is as follows. If trumps have been played, biggest card of the trump suit is considered the highest. If not, the biggest card of the suit of the round (ie the suit of the card played by the person who started the round) is considered the highest. The round is won by the team whose member played the biggest card

## Optimal strategy

Once three cards have been played, the fourth person plays the cards as per the following optimal strategy.

If the current biggest card is of the fourth person's teammate, the person aims to play the smallest card overall. Else, if the person can win the suit, he alms to play the smallest card that will enable him to win the suit. Else, the person aims to play the smallest card overall.

## Choosing smallest card to win

If nobody has played the trump card, and the player has cards of the suit of the round, it will be the smallest card of the suit that is larger than the largest card played.

If nobody has played the trump card, and the player does not have cards of the suit of the round, it is the smallest trump card.

If someone has already played the trump card, it is the smallest trump card greater than the greatest trump card already played

## Choosing smallest card overall

1 If the person has cards of the suit of the round, it is the card with the smallest value within cards of that suit.

If the person does not have any card of the suit of the round, and the person does not have any cards other than trump cards, it will be the smallest trump card

If the person does not have any card of the suit of the round, and the person has cards other than the trump card, it will be card with the smallest number with a suit preference of clubs, diamonds, hearts and spades in that order (only suits that are neither the suit of the round nor trump are considered) Thus, 3 of diamonds is considered smaller than 3 of spades but considered larger than 2 of spades.

## Input format

The input will be a single line of text with various components. Each component has a key, followed by colon (:) followed by the value. Different components are separated by.. Each component comes exactly once.

### The various components are

Players: The value is a list of 4 player names separated by comma (.). The player names are provided in order, so player 1 and player 3 are in a team and player 2 and player 4 are in another team.

Self: The name of the player who is playing last in this round (ie. the person who will select the optimal strategy.
Cards played by each of the other players. There will be 3 such components and the key for each component will be the name of the player.

Cards: This is a comma separated list of cards of the last player (Le. 'Self)

Trump: This is the suit of the trump

When cards are mentioned, they will have the suit (s.h.d.c) followed by the value (2,3,4,5,6,7,8,9,10,j.q.k.a). Thus sa is Ace of Spades and so on.

Please note that the components can be in any order. In particular, the player who played first does not necessarily come before all other players. The first player as will as the other team member wit need to be determined from the order of the playersthe "Players" component

## Output format

The optimum card to be played

## Sample input
```

```
Trump:h;self:Tom;Players:Alice,Bob,Charlie,Tom;Alice:dk;Bob:h8;Charlie:ha;cards:ck,h10,ca


## Sample output
```
s3
```








input: 
players:Tom,dick,Harry,john;self:john;trump:s;dick:S10;Tom:s2;Harry:ca;cards:s3,sk,ha

output:
s3

input:
players:Bob,Charlie,Dave,Alice;self:Alice;trump:c;Bob:ca;Charlie:ck;Dave:h5;cards:dk,c8,s9

output:
c8

input:
trump:h;self:Tom;players:Alice,Bob,Charlie,Tom;Alice:dk;Bob:ha;Charlie:hk;cards:ck,h10,ca

output:
h10