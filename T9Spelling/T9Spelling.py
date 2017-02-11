import sys


def main():
    keys = {
        0: ' ',
        2: 'abc',
        3: 'def',
        4: 'ghi',
        5: 'jkl',
        6: 'mno',
        7: 'pqrs',
        8: 'tuv',
        9: 'wxyz'
    }

    my_dict = {w: str(k)*(i+1) for k, v in keys.items() for i, w in enumerate(v)}

    n = int(sys.stdin.readline())

    for i in range(1, n+1):
        print('Case #%d: ' % i, end = '')
        line = sys.stdin.readline().replace('\n', '')

        lc = ''
        for char in line:
            item = my_dict.get(char)

            if lc == item[-1]:
                print(' ', end = '')

            print(item, end = '')
            lc = item[-1]

        print()


if __name__ == '__main__':
    main()
