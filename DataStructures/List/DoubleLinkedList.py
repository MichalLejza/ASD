from DataStructures.Node.LinkedNode.DoubleLinkedNode import DoubleLinkedNode


class DoubleLinkedList:
    def __init__(self, value=None):
        """
        Klasa reprezentująca listę dwukierunkową.
        :param value: wartość węzła
        """
        self._head = DoubleLinkedNode(value, None, None) if value is not None else None
        self._tail = self._head
        self._size = 0 if value is None else 1

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

    def get_head(self):
        return self._head

    def get_tail(self):
        return self._tail

    def get_size(self):
        return self._size

    def clear(self):
        self._head = None
        self._size = 0

    def extend(self, values: list):
        for value in values:
            self.add_back(value)

    def is_empty(self):
        return self._head is None

    def add_back(self, value):
        if self._head is None:
            self._head = DoubleLinkedNode(value, None, None)
            self._tail = self._head
        else:
            self._tail.setNext(DoubleLinkedNode(value, self._tail, None))
            self._tail = self._tail.getNext()
        self._size += 1

    def add_front(self, value):
        if self._head is None:
            self._head = DoubleLinkedNode(value, None, None)
            self._tail = self._head
        else:
            self._head.setPrev(DoubleLinkedNode(value, None, self._head))
            self._head = self._head.getPrev()
        self._size += 1

    def remove_back(self):
        if self._head is None:
            return
        if self._head == self._tail:
            self._head = None
            self._tail = None
        else:
            self._tail = self._tail.getPrev()
            self._tail.setNext(None)
        self._size -= 1

    def remove_front(self):
        if self._head is None:
            return
        if self._head == self._tail:
            self._head = None
            self._tail = None
        else:
            self._head = self._head.getNext()
            self._head.setPrev(None)
        self._size -= 1
