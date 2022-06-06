from collections import defaultdict
from sys import stdin

class Graph:
    def __init__(self, order) -> None:
        self.order: int = order
        self.neighbours_list: list[list[int]] = defaultdict(list)

    def connect_vertices(self, vertices) -> None:
        assert(len(vertices) == 2)
        self.neighbours_list[vertices[0]].append(vertices[1])
        self.neighbours_list[vertices[1]].append(vertices[0])
    
    def distance_list(self, base_node) -> list[int]:
        max_neighbours: int = max(self.neighbours_list)
        visited: list[bool] = [False] * max_neighbours
        distances_table: list[int] = [-1] * max_neighbours
        
        visiting_queue: list[int] = [base_node]
        distances_table[base_node - 1] = 0

        while visiting_queue:
            current_node: int = visiting_queue.pop(0)
            visited[current_node - 1] = True
            for i in self.neighbours_list[current_node]:
                if not visited[i - 1]:
                    distances_table[i - 1] = distances_table[current_node - 1] + 1
                    visiting_queue.append(i)
        return distances_table

def main() -> None:
    order: int = int(input().split()[-1])
    graph: Graph = Graph(order)
    
    input() # Discard "*Edges" line

    for line in stdin: graph.connect_vertices([int(node) for node in line.split()])
    for node in range(order): print(*graph.distance_list(node + 1))

if __name__ == "__main__": main()
