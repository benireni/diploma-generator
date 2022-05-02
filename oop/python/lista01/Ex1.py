from random import randrange

from KeyboardInput import KeyboardInput

class Ex1:
    def sqrt(self, n) -> float:
        previousAttempt = randrange(1, n)
        currentAttempt = (previousAttempt + n/previousAttempt) / 2

        while previousAttempt - currentAttempt > 0.00000001:
            previousAttempt = currentAttempt
            currentAttempt = (previousAttempt + n/previousAttempt) / 2
        return currentAttempt

if __name__ == "__main__":
    squareRooter = Ex1()
    keyboardInput = KeyboardInput()

    n = keyboardInput.readPositiveInt("Provide a number: ")
    print("Square root: {}".format(squareRooter.sqrt(n)))