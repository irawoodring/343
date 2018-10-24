class DataStructure:
    def __init__(self):
        self.stuff = []
    def __iter__(self):
        self.position = 0
        return self
    def __next__(self):
        if self.position < len(self.stuff) and len(self.stuff) != 0:
            self.position = self.position + 1
            return self.stuff[self.position]
        else:
            raise StopIteration        

