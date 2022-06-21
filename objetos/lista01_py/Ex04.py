from KeyboardInput import KeyboardInput

class Ex04:
    def printTree(self, height) -> None:
        currentHeight = height
        while currentHeight > 0:
            print(" " * (height - currentHeight) + "*" * currentHeight)
            currentHeight -= 1

if __name__ == "__main__":
    inverseTreePrinter = Ex04()
    keyboardInput = KeyboardInput()

    treeHeight = keyboardInput.readPositiveInt("Provide the inverse tree height: ")
    inverseTreePrinter.printTree(treeHeight)