class Renderer():

    def __init__(self) -> None:
        self.__face_cards = ["J", "Q", "K"]
        self.__suits_symbol = ["♣", "♤", "♥", "♦"]

    def print_hand(self, source) -> None:

        for i in range(1, len(source) + 1):
            print(f"{i}      ", end=" ")

        print("\n", end="")
        print("+-----+ "*len(source))
        print("|     | "*len(source))

        for i in source: 
            print(f"| {self.__suits_symbol[i.suit]}", end="")
            if i.value != 10: print(" ", end="")
            print(f"{self.__face_cards[i.value - 11] if 10 < i.value < 14 else i.value} |", end=" ")

        print("\n", end="")
        print("|     | "*len(source))
        print("+-----+ "*len(source))
