"""

"""

class LinkedNode:
    def __init__(self, value=None, next=None):
        """
        Klasa reprezentująca węzeł jednokierunkowy.
        :param value: wartość węzła
        :param next: następny węzeł
        """
        self._value = value
        self._next = next

    def __repr__(self) -> str:
        return str(self._value)

    def __str__(self) -> str:
        return str(self._value)

    def getValue(self):
        return self._value

    def setValue(self, value) -> None:
        self._value = value

    def getNext(self):
        return self._next

    def setNext(self, next) -> None:
        self._next = next

    def hasNext(self) -> bool:
        return self._next is not None