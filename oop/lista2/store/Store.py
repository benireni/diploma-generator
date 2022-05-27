from copy import deepcopy
from uuid import UUID
from Product import Product

class Store:
    def __init__(self) -> None:
        self.stock: list[Product] = []
        self.gross_profit: int

    def sell(self, id: str) -> None:
        product: Product = self.search_product(id)
        if product: self.stock.remove(product)

    def buy(self, product: Product, quantity: int) -> list[UUID]:
        generated_ids: list[UUID] = []
        for i in range(quantity):
            new_product: Product = deepcopy(product)
            generated_ids.append(new_product.generateId())
            self.stock.append(new_product)
        return generated_ids

    def search_product(self, id: str) -> Product:
        for product in self.stock: 
            if product.id == id: return product

    def list_stock(self) -> dict[Product, int]:
        stock_products: list[str] = [ type(product).__name__ for product in self.stock ]
        return {product_type: stock_products.count(product_type) for product_type in set(stock_products)}

    def list_all_stock_items(self) -> list[Product]:
        return ', '.join([str(product) for product in self.stock])
