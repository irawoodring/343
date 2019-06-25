class Bucket:
    def __init__(self, size):
        self.items = [ None ] * size
    def __str__(self):
        st = "This bucket contains:\n\n"
        for i in self.items:
            st = st + str(i) + '\n'
        return st
    def __getitem__(self, index):
        return self.items[index]
    def __setitem__(self, key, item):
        self.items[key] = item
    def __add__(self, other_list):
        self.items = self.items + other_list.items
    def __len__(self):
        return len(self.items)
