from DataStructures.Node.LinkedNode.LinkedNode import LinkedNode


class Queue:
    def __init__(self):
        self._head = None
        self._tail = None
        self.size = 0

    def enqueue(self, value):
        node = LinkedNode(value)
        if self._head is None:
            self._head = node
            self._tail = node
        else:
            self._tail.setNext(node)
            self._tail = node
        self.size += 1

    def dequeue(self):
        if self._head is None:
            return None
        value = self._head.getValue()
        self._head = self._head.getNext()
        if self._head is None:
            self._tail = None
        self.size -= 1
        return value

    def isEmpty(self):
        return self._head is None

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
            return result

