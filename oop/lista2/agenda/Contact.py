class Contact():
    def __init__(self, name: str, address: str, email: str) -> None:
        self.name: str = name
        self.address: str = address
        self.email: str = email

    def __str__(self) -> str:
        return "{{name:{0}, address:{1}, email:{2}}}".format(
            self.name,
            self.address,
            self.email
        )