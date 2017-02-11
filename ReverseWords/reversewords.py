import sys


def main():
    N = int(sys.stdin.readline())

    for i in range(1, N+1):
        line = sys.stdin.readline().replace('\n', '')
        words = line.split(' ')
        words.reverse()

        print('Case #%d: ' % i, end = '')
        for word in words:
            print(word, end= ' ')
        print()


if __name__ == '__main__':
    main()