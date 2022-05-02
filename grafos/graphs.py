from ast import arg
from random import random

class Graphs:
    def __init__(self, *args) -> None:
        self.__adj_table = self.generate_adj_table(args[0], args[1]) if len(args) > 1 else args[0]

    def are_linked(self, origin, destiny): return self.__adj_table[origin][destiny] == 1

    def get_node_order(self, node_number):
        order = 0
        for node in self.__adj_table[node_number]:
            if node == 1: order += 1
        return order

    def list_node_neighbours(self, node_number):
        print("Node {0} is linked to nodes:".format(node_number), end="")
        for node_index in range(self.__adj_table[node_number]): print(" {0}".format(node_index + 1), end="")
        print("\n")

    def is_eulerian_path(self, path):
        for step in path.steps:
            self.__adj_table[step.origin][step.destiny] = self.__adj_table[step.origin][step.destiny] = 0
        for row in self.__adj_table:
            if 1 in row: return False
        return True

    def generate_adj_table(order, linkProbability):
        matrix = [[0 for col in range(order)] for row in range(order)]
        iterator = 1
        for i in range(order - 1):
            for j in range(iterator, order):
                if (random() <= linkProbability):
                    matrix[i][j] = matrix[j][i] = 1
            iterator += 1
        return matrix

    def print_adj_table(mx):
        print("")
        for i in range(len(mx)):
            print("| ", end="")
            for j in range(len(mx)):
                print(mx[i][j], end=" ")
            print("|")