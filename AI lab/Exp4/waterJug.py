

def waterJugBfs(x, y, target):
    visited = set()
    queue = []

    queue.append((0, 0, []))

    while queue:
        a, b, path = queue.pop(0)

        if (a, b) in visited:
            continue
        visited.add((a, b))


        path = path + [(a, b)]


        if a == target or b == target:
            return path


        next_states = [
            (x, b),
            (a, y),
            (0, b),
            (a, 0),
            (a - min(a, y - b), b + min(a, y - b)),
            (a + min(b, x - a), b - min(b, x - a))
        ]

        for state in next_states:
            if state not in visited:
                queue.append((state[0], state[1], path))

    return None



jug1 = int(input("Enter capacity of Jug 1: "))
jug2 = int(input("Enter capacity of Jug 2: "))
target = int(input("Enter target amount: "))

result = waterJugBfs(jug1, jug2, target)

if result:
    print("Steps to achieve target:")
    for step in result:
        print(step)
else:
    print("No solution possible")
