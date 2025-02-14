class ClientInterface:
    def __init__(self, table_id):
        self.table_id = table_id
        self.order = []

    def add_item(self, item):
        self.order.append(item)

    def get_order(self):
        return self.order

    def get_table_id(self):
        return self.table_id