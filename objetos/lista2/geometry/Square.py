from Polygon import Polygon

class Square(Polygon):
    def __init__(self, color: str, isFilled: bool, side: int) -> None:
        super().__init__(color, isFilled)
        self.side: int = side

    def getArea(self) -> int: return self.side ** 2
    def getPerimeter(self) -> int: return 4 * self.side