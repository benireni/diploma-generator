from Product import Product

class DVD(Product):
    def __init__(self, movie: str, genre: str, director: str) -> None:
        super().__init__()
        self.movie: str = movie
        self.genre: str = genre
        self.director: str = director

    def __str__(self) -> str:
        return super().__str__()[:-1] + ", type:DVD, movie:{0}, genre:{1}, director:{2}}}".format(
            self.movie, self.genre, self.director)