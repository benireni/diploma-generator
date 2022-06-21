class KeyboardInput:
    def readPositiveInt(self, message = ""):
        value = input(message)
        isValidInput = False

        while not isValidInput:
            try:
                value = int(value)
                if value <= 0: raise Exception()
                isValidInput = True
            except:
                value = input("Your input must be a positive integer. Try again: ")
        return value

    def readFloat(self, message = ""):
        value = input(message)
        isValidInput = False

        while not isValidInput:
            try:
                value = float(value)
                isValidInput = True
            except:
                value = input("Your input must be a float number. Try again: ")
        return value