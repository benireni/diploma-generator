from Polygon import Polygon

class Rectangle(Polygon):
    def __init__(self, color: str, isFilled: bool, lenght: int, height: int) -> None:
        super().__init__(color, isFilled)
        self.lenght: int = lenght
        self.height: int = height

    def getArea(self) -> int: return self.lenght * self.height
    def getPerimeter(self) -> int: return 2 * self.lenght + 2 * self.height