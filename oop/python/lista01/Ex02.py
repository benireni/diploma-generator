from typing import Dict, List

from KeyboardInput import KeyboardInput

class Ex02:

    def __init__(self) -> None:
        self.keyboardInput = KeyboardInput()

    def readEquation(self) -> Dict:
        print("Provide coefficients 'a', 'b' and 'c' separated by line breaks:")
        return {
            'a': self.keyboardInput.readFloat(),
            'b': self.keyboardInput.readFloat(),
            'c': self.keyboardInput.readFloat()
        }

    def solveQuadraticEquation(self, equation) -> List:
        det = equation.get('b')**2 - 4 * equation.get('a') * equation.get('c')
        detSqrt = det ** (1/2)

        if det > 0: return [
            (-equation.get('b') + detSqrt)/(2*equation.get('a')),
            (-equation.get('b') - detSqrt)/(2*equation.get('a'))
        ]
        elif det == 0: return [
            (-equation.get('b') + detSqrt)/(2*equation.get('a'))
        ]
        else: return []


if __name__ == "__main__":
    quadraticSolver = Ex02()

    equation = quadraticSolver.readEquation()
    solution = quadraticSolver.solveQuadraticEquation(equation)

    print("\nSolution: {0}".format(solution))