from DataStructures.Node.LinkedNode.LinkedNode import LinkedNode


class Stack:
    def __init__(self):
        self._top = None
        self.size = 0

    def push(self, value):
        node = LinkedNode(value)
        node.setNext(self._top)
        self._top = node
        self.size += 1

    def pop(self):
        if self._top is None:
            return None
        value = self._top.getValue()
        self._top = self._top.getNext()
        self.size -= 1
        return value

    def peek(self):
        return self._top

    def isEmpty(self):
        return self._top is None

    def size(self):
        return self.size

    def __str__(self):
        if self._top is None:
            return "[]"
        else:
            current = self._top
            result = "["
            while current.hasNext():
                result += str(current.getValue()) + ", "
                current = current.getNext()
            result += str(current.getValue()) + "]"