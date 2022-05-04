from KeyboardInput import KeyboardInput

class Ex09:
    def __init__(self) -> None:
        self.ERROR = 10e-7
        self.__iterator = 0

    def calculateBaseEquation(self, x): return x**3 - x**2 - 13*x + 8
    def deriveBaseEquation(self, x): return 3 * x**2 - 2 * x - 13

    def getLastOperationTotalIterations(self): return self.__iterator

    def solveByNewtonRaphson(self, attempt):
        previousAttempt = attempt
        attempt -= self.calculateBaseEquation(attempt) / self.deriveBaseEquation(attempt)
        self.__iterator = 1

        while previousAttempt - attempt >= self.ERROR:
            previousAttempt = attempt
            attempt -= self.calculateBaseEquation(attempt) / self.deriveBaseEquation(attempt)
            self.__iterator += 1
        return attempt

if __name__ == "__main__":
    newtonRaphsonCalculator = Ex09()
    keyboardInput = KeyboardInput()

    print("Provide the desired attempt: ")
    input = keyboardInput.readFloat()

    print("Solution by Newton-Raphson: {0}\n".format(newtonRaphsonCalculator.solveByNewtonRaphson(input)))
    print("{0} total iterations".format(newtonRaphsonCalculator.getLastOperationTotalIterations()))