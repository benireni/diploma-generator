from Product import Product

class CD(Product):
    def __init__(self, album: str, artist: str, genre: str, year: int) -> None:
        super().__init__()
        self.album: str = album
        self.artist: str = artist
        self.genre: str = genre
        self.year: int = year

    def __str__(self) -> str:
        return super().__str__()[:-1] + ", type:CD, album:{0}, artist:{1}, genre:{2}, year:{3}}}".format(
            self.album, self.artist, self.genre, self.year)