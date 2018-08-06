""" Linked List implementation in Python 3
"""


class Node:
    
    def __init__(self, data):
        self.data = data
        self.next_node = None
    
    def get_data(self):
        return self.data
    
    def get_next(self):
        return self.next_node


class LinkedList():
    
    def __init__(self, head=None):
        self.head = head
    
    def insert_front(self, data):
        new_node = Node(data)
        new_node.next_node = self.head
        self.head = new_node
    
    def insert_rear(self, data):
        new_node = Node(data)
        if self.head is not None:
            node = self.head
            while node.next_node != None:
                node = node.next_node
            node.next_node = new_node
        else:
            self.head = new_node
    
    def delete(self, data):
        if self.head.data == data:
            self.head = self.head.next_node
        else:
            current_node = self.head.next_node
            previous_node = self.head
            while current_node != None:
                if current_node.data == data:
                    previous_node.next_node = current_node.next_node
                    break
                current_node = current_node.next_node
            if current_node is None:
                print('Data is not in list')
    
    def traverse(self):
        node = self.head
        while node != None:
            print(node.data, '-->')
            node = node.next_node

