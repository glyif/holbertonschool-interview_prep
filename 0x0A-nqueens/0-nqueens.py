#!/usr/bin/python3

from sys import argv, exit


def nQueens(n):
    """
    nQueens - solves n queens
    :param n: n by n grid
    :return: an array of arrays of arrays of possible solutions
    """
    res = []

    def depth_search(i, l, r, m, arr):
        """
        dps search
        :param i: i
        :param l: l
        :param r: r
        :param m: m
        :param arr: array
        """
        if i == n:
            res.append(arr)
        else:
            l = l[1:] + [0]
            r = [0] + r[:-1]
            for j in range(n):
                if m[j] == l[j] == r[j] == 0:
                    l[j] = r[j] = m[j] = 1
                    lst = [] + arr
                    lst.append([i, j])
                    depth_search(i + 1, l, r, m, lst)
                    l[j] = r[j] = m[j] = 0

    depth_search(0, [0] * n, [0] * n, [0] * n, [])

    return res


def main():
    """
    main
    :return:
    """
    if len(argv) is not 2:
        print("Usage: nqueens N")
        exit(1)
    elif argv[1].isdigit() is not True:
        print("N must be a number")
        exit(1)
    elif int(argv[1]) < 4:
        print("N must be at least 4")
        exit(1)

    boards = nQueens(int(argv[1]))

    for board in boards:
        print(board)


if __name__ == "__main__":
    main()
