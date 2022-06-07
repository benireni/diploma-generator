def main() -> None:
    graph: list[list[int]] = read_pajek(input())
    print('S' if is_ciclic_graph(graph) else 'N')

def is_ciclic_graph(graph) -> bool:
    parents: dict[int, int] = {}
    colors: dict[int, str] = {}

    for node in range(len(graph)):
        colors[node] = 'RED'
        parents[node] = None

    return is_ciclic_graph_util(graph, 0, colors, parents)

def is_ciclic_graph_util(graph: list[list[int]], vertex: int, colors: dict[int, str], parents: list[int]) -> bool:
    colors[vertex] = 'BLUE'

    for neighbour in graph[vertex]:
        if colors[neighbour] == 'RED':
            parents[neighbour] = vertex
            if is_ciclic_graph_util(graph, neighbour, colors, parents): return True
        elif colors[neighbour] == 'BLUE' and parents[vertex] != neighbour: return True

    colors[vertex] = 'BLACK'
    return False

def read_pajek(filename) -> list[list[int]]:
    pajek = open(filename, 'r')

    order: int = int(pajek.readline().split()[1])
    graph: list[list[int]] = [[] for node in range(order)]
    pajek.readline()

    for line in pajek:
        vertexes: list[int] = [int(vertex) for vertex in line.split()]
        if len(vertexes) == 0: continue
        graph[vertexes[0] - 1].append(vertexes[1] - 1)
    else: pajek.close()

    return graph

if __name__ == '__main__':
    main()