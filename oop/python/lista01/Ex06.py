from math import ceil
from typing import Union

from KeyboardInput import KeyboardInput

class Ex06:
    def isPrime(self, n) -> bool:
        divisor = 2
        while n % divisor != 0 and divisor < ceil(n**(1/2)): divisor += 1
        return n % divisor != 0

    def getPrimePredecessor(self, n) -> Union[int, None]:
        while (n > 1):
            n -= 1
            if (self.isPrime(n)): return n
        return None

if __name__ == "__main__":
    predecessorPrimeCalculator = Ex06()
    keyboardInput = KeyboardInput()

    input = keyboardInput.readPositiveInt("Provide the base number: ")

    divisor = predecessorPrimeCalculator.getPrimePredecessor(input)
    print("{0} is the first prime number lower than the input.".format(divisor))