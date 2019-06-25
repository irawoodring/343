class Square(object):
    def __init__(self, l, w):
        self.l = l
        self.w = w
    
    def area(self):
        return self.l * self.w

    def __lt__(self, other):
        if isinstance('Triangle', other):
        	return self.area() < other.area()

class Triangle(object):
    def __init__(self, b, h):
        self.b = b
        self.h = h
    def area(self):
        return .5 * self.b * self.h
    def __lt__(self, other):
        return self.area() < other.area
