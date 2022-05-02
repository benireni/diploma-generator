
from KeyboardInput import KeyboardInput


class Ex08:
    def __init__(self) -> None:
        self.ERROR = 10e-7
        self.__iterator = 0

    def calculateBaseEquation(self, x) -> float: return x**3 - x**2 - 13*x + 8

    def getLastOperationTotalIterations(self) -> int: return self.__iterator

    def solveByBisection(self, a, b) -> float:
        if self.calculateBaseEquation(a) * self.calculateBaseEquation(b) >= 0: return a

        c = a
        self.__iterator = 0
        while b - a >= self.ERROR:
            c = (a + b) / 2
            if (self.calculateBaseEquation(c) == 0.0): break
            elif self.calculateBaseEquation(c) * self.calculateBaseEquation(a) < 0: b = c
            else: a = c

            self.__iterator += 1
        return c

if __name__ == "__main__":
    bisectionCalculator = Ex08()
    keyboardInput = KeyboardInput()

    print("Provide the desired interval: ")
    a = keyboardInput.readFloat()
    b = keyboardInput.readFloat()

    print("Solution by Bisection: {}".format(bisectionCalculator.solveByBisection(a, b)))
    print("{} total iterations".format(bisectionCalculator.getLastOperationTotalIterations()))