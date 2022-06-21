from Product import Product

class Book(Product):
    def __init__(self, name: str, author: str, genre: str, pages: int) -> None:
        super().__init__()
        self.name: str = name
        self.author: str = author
        self.genre: str = genre
        self.pages: int = pages

    def __str__(self) -> str:
        return super().__str__()[:-1] + ", type:book, name:{0}, author:{1}, genre:{2}, director:{3}}}".format(
            self.name, self.author, self.genre, self.pages)