from sys import float_info
from typing import Dict, List
from KeyboardInput import KeyboardInput

class Ex07:

    def __init__(self) -> None:
        self.keyboardInput = KeyboardInput()

    def readDoubleStream(self) -> List:
        inputStream = []
        currentInput = self.keyboardInput.readFloat()
        while currentInput != 0.0:
            inputStream.append(currentInput)
            currentInput = self.keyboardInput.readFloat() 
        return inputStream

    def getStreamExtremes(self, doubleStream) -> Dict:
        max = -10e10
        min = 10e10
        for record in doubleStream:
            if (record > max): max = record
            if (record < min): min = record
        return { "min": min, "max": max }

if __name__ == "__main__":
    doubleStreamAnalyst = Ex07()

    print("Provide your doubles separated by line breaks (enter 0 to halt): ")
    input = doubleStreamAnalyst.readDoubleStream()

    inputExtremes = doubleStreamAnalyst.getStreamExtremes(input)
    print("Stream min: {0}, max: {1}".format(inputExtremes["min"], inputExtremes["max"]))