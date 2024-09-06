class Node:
    def __init__(self, name: str):
        self.name: str = name
        self.neighbours: set['Node'] = set()
        self.visited: bool = False

    def __hash__(self):
        return hash(self.name)

    def __eq__(self, other):
        return isinstance(other, Node) and self.name == other.name

    def __repr__(self):
        return f'{self.name}'

    def print(self) -> None:
        print(self.name, end=" -> ")
        for neighbour in self.neighbours:
            print(neighbour, end=", ")
        print()

    def setVisited(self, value: bool) -> None:
        self.visited = value

    def addNeighbour(self, node: 'Node') -> None:
        newNode = Node(name=node.name)
        if newNode not in self.neighbours:
            self.neighbours.add(newNode)

    def removeNeighbour(self, node) -> None:
        n = Node(name=node.name)
        if n in self.neighbours:
            self.neighbours.remove(n)

    def clearNeighbours(self) -> None:
        self.neighbours = set()

    def neighboursCount(self) -> int:
        return len(self.neighbours)

    def getNeighbours(self) -> set['Node']:
        return self.neighbours
