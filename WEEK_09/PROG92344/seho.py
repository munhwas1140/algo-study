def solution(board, skill):
    answer = 0
    n = len(board)
    m = len(board[0])
    tmp = [[0 for _ in range(m)] for _ in range(n)]
    for arr in skill:
        t = arr[0]
        r1 = arr[1]
        c1 = arr[2]
        r2 = arr[3]
        c2 = arr[4]
        d = arr[5]

        if t == 2:
            tmp[r1][c1] += d
            if r2 + 1 < n:
                tmp[r2 + 1][c1] -= d
            if c2 + 1 < m:
                tmp[r1][c2 + 1] -= d
            if r2 + 1 < n and c2 + 1 < m:
                tmp[r2 + 1][c2 + 1] += d
        else:
            tmp[r1][c1] -= d
            if r2 + 1 < n:
                tmp[r2 + 1][c1] += d
            if c2 + 1 < m:
                tmp[r1][c2 + 1] += d
            if r2 + 1 < n and c2 + 1 < m:
                tmp[r2 + 1][c2 + 1] -= d

    for i in range(n):
        for j in range(1, m):
            tmp[i][j] += tmp[i][j - 1]
    for i in range(1, n):
        for j in range(m):
            tmp[i][j] += tmp[i - 1][j]

    for i in range(n):
        for j in range(m):
            if (board[i][j] + tmp[i][j] > 0):
                answer += 1
        # print(*board[i])

    return answer