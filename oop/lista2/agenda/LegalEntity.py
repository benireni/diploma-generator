from Contact import Contact

class LegalEntity(Contact):
    def __init__(self, name: str, address: str, email: str, CNPJ: int, state_subscription: str, company_name: str) -> None:
        super().__init__(name, address, email)
        self.CNPJ: int = CNPJ
        self.state_subscription: str = state_subscription
        self.company_name: str = company_name

    def __gt__(self, other: Contact) -> bool:
        if isinstance(other, LegalEntity): return self.CNPJ > other.CNPJ
        else: return False

    def __str__(self) -> str:
        return super().__str__()[:-2] + ", CNPJ:{0}, state_subscription:{1}, company_name:{2}}}".format(
            self.CNPJ, self.state_subscription, self.company_name)