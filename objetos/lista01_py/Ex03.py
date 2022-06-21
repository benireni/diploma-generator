from KeyboardInput import KeyboardInput

class Ex03:
    def printTree(self, height) -> None:
        while height > 0:
            print("*" * height)
            height -= 1

if __name__ == "__main__":
    treePrinter = Ex03()
    keyboardInput = KeyboardInput()

    treeHeight = keyboardInput.readPositiveInt("Provide the tree high: ")
    treePrinter.printTree(treeHeight)