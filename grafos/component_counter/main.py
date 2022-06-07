def main() -> None:
    filename: str = input()
    graph: list[list[int]] = read_pajek(filename)

    components, component_sizes = get_components_sizes(graph)
    print(components)
    for size in sorted(component_sizes, reverse=True): print(size)

def get_components_sizes(graph):
    visited: list[bool] = [False] * len(graph)
    count: list[int] = []
    components: int = 0

    for vertex in range(len(graph)):
        if not visited[vertex]:
            count.append(1)
            get_component_size(graph, vertex, visited, count)
            components += 1
    return (components, count)

def get_component_size(graph: list[list[int]], vertex: int, visited: list[bool], count: list[int]) -> None:
    visited[vertex] = True
    for neighbour in graph[vertex]:
        if not visited[neighbour]:
            count[-1] += 1
            get_component_size(graph, neighbour, visited, count)

def read_pajek(filename) -> list[list[int]]:
    pajek = open(filename, 'r')

    order: int = int(pajek.readline().split()[1])
    graph: list[list[int]] = [[] for node in range(order)]
    pajek.readline()

    for line in pajek:
        vertexes: list[int] = [int(vertex) for vertex in line.split()]
        graph[vertexes[0] - 1].append(vertexes[1] - 1)
        graph[vertexes[1] - 1].append(vertexes[0] - 1)
    else: pajek.close()

    return graph

if __name__ == '__main__':
    main()