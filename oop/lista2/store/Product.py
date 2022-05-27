from uuid import UUID, uuid4

class Product:
    def __init__(self) -> None: self.id = None

    def generateId(self) -> UUID:
        self.id = str(uuid4())
        return self.id

    def __str__(self) -> str: return "{{id={0}}}".format(self.id)