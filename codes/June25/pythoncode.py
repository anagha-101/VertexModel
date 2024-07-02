class Vertices:
    def __init__(self, x1, y1):
        self.x = x1
        self.y = y1

class Cell:
    def __init__(self):
        self.apical_nodes = []
        self.basal_nodes = []

    def get_area(self, xa, ya, xb, yb):
        area = 0
        n = len(xa)
        for i in range(n):
            area += (xa[(i + 1) % n] * ya[i] + xb[(i + 1) % n] * ya[(i + 1) % n] + 
                     xb[i] * yb[(i + 1) % n] + xa[i] * yb[i] - xa[i] * ya[(i + 1) % n] - 
                     xa[(i + 1) % n] * yb[(i + 1) % n] - xb[(i + 1) % n] * yb[i] - 
                     xb[i] * ya[i])
        area /= 2
        return area

class System:
    def __init__(self, xa, ya, xb, yb):
        self.apical_nodes = [Vertices(x, y) for x, y in zip(xa, ya)]
        self.basal_nodes = [Vertices(x, y) for x, y in zip(xb, yb)]
        self.cell = [Cell() for _ in range(len(xa))]

if __name__ == "__main__":
    xa = [1, 2, 3, 4, 5, 6]
    ya = [2, 2, 2, 2, 2, 2]
    xb = [1, 2, 3, 4, 5, 6]
    yb = [1, 1, 1, 1, 1, 1]

    S = System(xa, ya, xb, yb)
    print("Area of a Cell:", S.cell[2].get_area(xa, ya, xb, yb))

    xa[2] = 10
    S_new = System(xa, ya, xb, yb)
    print("Area of second Cell:", S_new.cell[2].get_area(xa, ya, xb, yb))
    print("Area of third Cell:", S_new.cell[3].get_area(xa, ya, xb, yb))
    print("Area of fourth Cell:", S_new.cell[4].get_area(xa, ya, xb, yb))
