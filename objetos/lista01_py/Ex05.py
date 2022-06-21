
from math import ceil

from KeyboardInput import KeyboardInput

class Ex05:
    def getLesserDivisor(self, n) -> int:
        divisor = 2
        while n % divisor != 0 and divisor < ceil(n**(1/2)): divisor += 1
        return divisor if n % divisor == 0 else None

if __name__ == "__main__":
    lesserDivisorCalculator = Ex05()
    keyboardInput = KeyboardInput()

    print("Provide the base number: ")
    input = keyboardInput.readPositiveInt()

    divisor = lesserDivisorCalculator.getLesserDivisor(input)
    if (divisor == None): print("{0} is a prime number.".format(input))
    else: print("{0} is not a prime and it's lesser divisor is {1}.".format(input, divisor))