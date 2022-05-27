from Contact import Contact

class Individual(Contact):
    def __init__(self, name: str, address: str, email: str, CPF: int, birthdate: str, marital_status: str) -> None:
        super().__init__(name, address, email)
        self.CPF: int = CPF
        self.birthdate: str = birthdate
        self.marital_status: str = marital_status

    def __gt__(self, other: Contact) -> bool:
        if isinstance(other, Individual): return self.CPF > other.CPF
        else: return True

    def __str__(self) -> str:
        return super().__str__()[:-1] + ", CPF:{0}, birthdate:{1}, marital_status:{2}}}".format(
            self.CPF,
            self.birthdate,
            self.marital_status
        )