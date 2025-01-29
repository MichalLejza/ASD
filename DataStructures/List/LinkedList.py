from DataStructures.Node.LinkedNode.LinkedNode import LinkedNode


class LinkedList:
    def __init__(self, value=None):
        self._head = LinkedNode(value) if value is not None else None
        self._size = 0 if value is None else 1

    def get_head(self):
        return self._head

    def get_size(self):
        return self._size

    def is_empty(self):
        return self._head is None

    def clear(self):
        self._head = None
        self._size = 0

    def extend(self, values: list):
        for value in values:
            self.add_back(value)

    def add_back(self, value):
        if self._head is None:
            self._head = LinkedNode(value)
        else:
            current = self._head
            while current.hasNext():
                current = current.getNext()
            current.setNext(LinkedNode(value))
        self._size += 1

    def add_front(self, value):
        if self._head is None:
            self._head = LinkedNode(value)
        else:
            self._head = LinkedNode(value, self._head)
        self._size += 1

    def remove_back(self):
        if self._head is not None:
            current = self._head
            prev = None
            while current.hasNext():
                prev = current
                current = current.getNext()
            prev.setNext(None)
            self._size -= 1

    def remove_front(self):
        if self._head is not None:
            self._head = self._head.getNext()
            self._size -= 1

    def __str__(self):
        if self._head is None:
            return "[]"
        else:
            current = self._head
            result = "["
            while current.hasNext():
                result += str(current.getValue()) + ", "
                current = current.getNext()
            result += str(current.getValue()) + "]"
