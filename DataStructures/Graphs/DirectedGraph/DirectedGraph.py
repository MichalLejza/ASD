from Node import *

class DirectedGraph:
    def __init__(self, connections: list[tuple[str, str]]):
        self.connections = connections
        self.nodes: set[Node] = set()
        self._createGraph()

    def _createGraph(self) -> None:
        for connection in self.connections:
            firstNode = Node(connection[0])
            secondNode = Node(connection[1])
            if firstNode not in self.nodes:
                self.nodes.add(firstNode)
            else:
                for node in self.nodes:
                    if node == firstNode:
                        firstNode = node
            if secondNode not in self.nodes:
                self.nodes.add(secondNode)
            else:
                for node in self.nodes:
                    if node == secondNode:
                        secondNode = node
            firstNode.addNeighbour(secondNode)

    def print(self) -> None:
        for node in self.nodes:
            node.print()

    def addConnection(self, connection: tuple[str, str]) -> None:
        firstNode = Node(connection[0])
        secondNode = Node(connection[1])
        if firstNode not in self.nodes:
            self.nodes.add(firstNode)
        else:
            for node in self.nodes:
                if node == firstNode:
                    firstNode = node
        if secondNode not in self.nodes:
            self.nodes.add(secondNode)
        else:
            for node in self.nodes:
                if node == secondNode:
                    secondNode = node
        firstNode.addNeighbour(secondNode)

    def removeConnection(self, connection: tuple[str, str]) -> None:
        firstNode = Node(connection[0])
        secondNode = Node(connection[1])
        if firstNode not in self.nodes:
            return
        else:
            for node in self.nodes:
                if node == firstNode:
                    firstNode = node
        if secondNode not in self.nodes:
            return
        else:
            for node in self.nodes:
                if node == secondNode:
                    secondNode = node
        firstNode.removeNeighbour(secondNode)

    def getGivenNode(self, name: str) -> Node:
        dummy = Node(name)
        for node in self.nodes:
            if node == dummy:
                dummy = node
        return dummy


if __name__ == '__main__':
    graph = DirectedGraph([('a', 'b'), ('a', 'c'), ('b', 'c'), ('b', 'd'), ('c', 'd')])
    graph.print()
