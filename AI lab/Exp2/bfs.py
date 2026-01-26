def bfs(graph, start, goal):
    fringe = [start]          
    visited = []              
    parent = {start: None}    

    iteration = 1

    while len(fringe) > 0:
        print("\nIteration", iteration)
        print("Fringe:", fringe)
        print("Visited:", visited)

        current = fringe.pop(0)   

        if current == goal:
            break

        if current not in visited:
            visited.append(current)

            for neighbor in graph[current]:
                if neighbor not in visited and neighbor not in fringe:
                    fringe.append(neighbor)
                    parent[neighbor] = current

        iteration += 1

    
    path = []
    node = goal
    while node is not None:
        path.append(node)
        node = parent.get(node)

    path.reverse()

    print("\nFinal Traversed Path:", path)



graph = {
    'A': ['B', 'C'],
    'B': ['A', 'D', 'E'],
    'C': ['A', 'F', 'G'],
    'D': ['B'],
    'E': ['B'],
    'F': ['C'],
    'G': ['C']
}


bfs(graph, 'A', 'F')
