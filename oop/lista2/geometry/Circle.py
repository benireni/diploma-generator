from Polygon import Polygon
from math import pi as PI

class Square(Polygon):
    def __init__(self, color: str, isFilled: bool, radius: int) -> None:
        super().__init__(color, isFilled)
        self.radius: int = radius

    def getArea(self) -> int: return PI * self.radius ** 2
    def getPerimeter(self) -> int: return 2 * PI * self.radius