"""

"""
from LinkedNode import LinkedNode

class DoubleLinkedNode(LinkedNode):
    def __init__(self, value=None, prev=None, next=None):
        """
        Klasa reprezentująca węzeł dwukierunkowy.
        :param value: wartość węzła
        :param prev: poprzedni węzeł
        :param next: następny węzeł
        """
        super().__init__(value, next)
        self._prev = prev

    def getPrev(self):
        return self._prev

    def setPrev(self, prev):
        self._prev = prev
