import random
from re import sub
from card import Card

class Deck():
    def __init__(self) -> None:
        self.cards = []
        for suit in range(4):
            for value in range(2, 15): self.cards.append(Card(suit, value))
    
    def shuffle(self) -> None:
        random.shuffle(self.cards)

    def deal(self, hand_size = 1) -> list:
        if hand_size == 1: return self.cards.pop()

        hand = self.cards[-hand_size:]
        del self.cards[-hand_size:]
        return hand

    def replace_cards(self, current_hand, requests) -> None:
        substitutions = sub("\D", " ", requests).split()
        substitutions = set(map(int, substitutions))

        out_of_bounds_requests = set([index for index in substitutions if index > 5 or index < 1])
        if len(out_of_bounds_requests) > 0:
            print("At least one of your requests is out of bounds. Executing the valid ones (if any).")
            substitutions = list(substitutions - out_of_bounds_requests)

        for target in substitutions: current_hand[target - 1] = self.deal()