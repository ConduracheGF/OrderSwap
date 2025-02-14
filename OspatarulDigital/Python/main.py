from ClientInterface import ClientInterface
from Menu import Menu

def save_order_to_file(table_id, items):
    with open("shared/order.txt", "w") as file:
        file.write(f"Table ID: {table_id}\n")
        for item in items:
            file.write(f"{item}\n")

def main():
    table_id = int(input("Enter your table ID: "))
    client = ClientInterface(table_id)
    menu = Menu()

    menu.display_menu()

    while True:
        item = input("Enter the item you want to order (or 'done' to finish): ")
        if item.lower() == 'done':
            break
        if item in menu.items:
            client.add_item(item)
            print(f"{item} added to your order.")
        else:
            print("Item not found in the menu.")

    save_order_to_file(client.get_table_id(), client.get_order())
    print(f"Your order for table {client.get_table_id()} has been saved.")

if __name__ == "__main__":
    main()