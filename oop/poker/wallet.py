class Wallet():
    def __init__(self, budget=0) -> None:
        self.budget = budget

    def pay(self, value) -> None:
        self.budget -= value

    def receive(self, value) -> None:
        self.budget += value

    def isBroke(self): return self.budget <= 0