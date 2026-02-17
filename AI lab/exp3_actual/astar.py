import heapq

def aStar(graph, heuristic, start, goal):

    openQueue = []
    closedList = []

    gCost = {}
    parent = {}

    gCost[start] = 0
    parent[start] = None

    fStart = gCost[start] + heuristic[start]
    heapq.heappush(openQueue, (fStart, start))

    while len(openQueue) > 0:

        print("\n open List:")
        for item in openQueue:
            print("node:", item[1], " f:", item[0])

        currentF, currentNode = heapq.heappop(openQueue)
        print("\n selected node:", currentNode)

        if currentNode == goal:
            print("\n reached ")

            path = []
            node = goal

            while node is not None:
                path.append(node)
                node = parent[node]

            path.reverse()

            print("\nsoln path:")
            for i in range(len(path)):
                print(path[i], end="")
                if i != len(path) - 1:
                    print(" - >  ", end="")

            print("\nTotal Cost:", gCost[goal])
            return

        closedList.append(currentNode)
        print("CLOSED List:", closedList)

        neighbors = graph[currentNode]

        for neighbor, cost in neighbors:

            if neighbor in closedList:
                continue

            tentativeG = gCost[currentNode] + cost

            if neighbor not in gCost:
                gCost[neighbor] = tentativeG
                parent[neighbor] = currentNode

                fValue = tentativeG + heuristic[neighbor]
                heapq.heappush(openQueue, (fValue, neighbor))

            else:
                if tentativeG < gCost[neighbor]:
                    gCost[neighbor] = tentativeG
                    parent[neighbor] = currentNode

                    fValue = tentativeG + heuristic[neighbor]
                    heapq.heappush(openQueue, (fValue, neighbor))

    print("No solution found")


graph = {
    0: [(1, 1), (2, 4)],
    1: [(0, 1), (3, 5), (4, 2)],
    2: [(0, 4), (4, 3)],
    3: [(1, 5), (4, 1)],
    4: [(1, 2), (2, 3), (3, 1)]
}

heuristic = {
    0: 7,
    1: 6,
    2: 4,
    3: 1,
    4: 0
}

aStar(graph, heuristic, 0, 4)
