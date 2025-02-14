class Menu:
    def __init__(self):
        self.items = {
            "Pizza": 10.99,
            "Burger": 8.99,
            "Pasta": 12.99,
            "Salad": 6.99,
            "Cola": 2.99,
            "Water": 1.99
        }

    def display_menu(self):
        print("Menu:")
        for item, price in self.items.items():
            print(f"{item}: ${price:.2f}")

    def get_item_price(self, item):
        return self.items.get(item, 0.0)