class PotHandler():
    def __init__(self, currentPot = 0) -> None:
        self.currentPot = currentPot
        self.COMBINATION_MULTIPLIERS = {
            self.__check_royal_straight_flush: 200,
            self.__check_straight_flush: 100,
            self.__check_quadruplet: 50,
            self.__check_full_hand: 20,
            self.__check_flush: 10,
            self.__check_straight: 5,
            self.__check_triplet: 2,
            self.__check_double_pair: 1
        }

    def read_gamble(self, budget) -> int:
        self.currentPot = budget
        while True:
            pot = input("How much do you wish to gamble?\n")
            try:
                pot = int(pot.strip())

                if (pot <= 0): print("It must be a positive number\n")
                elif (pot > budget): print("Not enought budget in your wallet. Try a smaller value.\n")
                else: return pot
            except: print("It must be a natural number.\n")

    def reward_hand(self, hand) -> int:
        for check, multiplier in self.COMBINATION_MULTIPLIERS.items():
            if check(hand): return self.currentPot * multiplier
        return 0

    def __check_double_pair(self, hand) -> bool:
        hand_values = [card.value for card in hand]
        hand_unique_values = set(hand_values)

        has_pair = False
        for unique_value in hand_unique_values:
            if hand_values.count(unique_value) == 2:
                if has_pair: return True
                else: has_pair = True

    def __check_triplet(self, hand) -> bool:
        hand_values = [card.value for card in hand]
        hand_unique_values = set(hand_values)

        for unique_value in hand_unique_values:
            if hand_values.count(unique_value) == 3:
                return True

    def __check_straight(self, hand) -> bool:
        hand_values = [card.value for card in hand]
        return sorted(hand_values) == list(range(min(hand_values), max(hand_values) + 1))

    def __check_flush(self, hand) -> bool:
        return all(card.suit == hand[0].suit for card in hand)

    def __check_full_hand(self, hand) -> bool:
        hand_values = [card.value for card in hand]
        hand_unique_values = set(hand_values)

        return len(hand_unique_values) == 2 and hand_values.count(hand_values[0]) in [2, 3]

    def __check_quadruplet(self, hand) -> bool:
        hand_values = [card.value for card in hand]
        hand_unique_values = set(hand_values)

        if len(hand_unique_values) > 2: return False
        elif len(hand_unique_values) == 1: return True

        for unique_value in hand_unique_values:
            if hand_values.count(unique_value) >= 4 or hand_values.count(unique_value) == 1:
                return True
        return False

    def __check_straight_flush(self, hand) -> bool:
        hand_values = [card.value for card in hand]
        straight = sorted(hand_values) == list(range(min(hand_values), max(hand_values) + 1))
        flush = all(card.suit == hand[0].suit for card in hand)

        return straight and flush
        

    def __check_royal_straight_flush(self, hand) -> bool:
        hand_values = [card.value for card in hand]
        royal_straight = sorted(hand_values) == list(range(10, 15))
        flush = all(card.suit == hand[0].suit for card in hand)

        return royal_straight and flush