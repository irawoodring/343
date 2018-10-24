class Mammal(object):
    def __init__(self):
        self.type = "Mammal"

class Dolphin(Mammal):
    def __init__(self):
        super(Dolphin, self).__init__()


