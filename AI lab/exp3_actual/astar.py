import heapq

def a_star(graph, heuristic, start, goal):

    open_list = []
    heapq.heappush(open_list, (heuristic[start], start))


    g_cost = {start: 0}


    parent = {start: None}

    while open_list:
        _, current = heapq.heappop(open_list)


        if current == goal:
            path = []
            while current is not None:
                path.append(current)
                current = parent[current]
            return path[::-1], g_cost[goal]


        for neighbor, weight in graph[current]:
            tentative_g = g_cost[current] + weight

            if neighbor not in g_cost or tentative_g < g_cost[neighbor]:
                g_cost[neighbor] = tentative_g
                f_cost = tentative_g + heuristic[neighbor]
                heapq.heappush(open_list, (f_cost, neighbor))
                parent[neighbor] = current

    return None, float("inf")


graph = {
    'A': [('B', 2), ('C', 3)],
    'B': [('D', 4), ('E', 1)],
    'C': [('E', 5)],
    'D': [('G', 3)],
    'E': [('G', 2)],
    'G': []
}
heuristic = {
    'A': 7,
    'B': 5,
    'C': 6,
    'D': 3,
    'E': 2,
    'G': 0
}


print(a_star(graph, heuristic, 'A', 'G'))
