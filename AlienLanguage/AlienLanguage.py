import functools


def main():
    l = list(map(lambda x: int(x), input().split(' ')))
    L, D, N = l[0], l[1], l[2]

    word_dict = []
    for i in range(0, D):
        word_dict.append(input())

    for i in range(1, N+1):
        pattern = input()
        pattern_list = make_check_list(pattern)
        # print(pattern_list)
        assert(len(pattern_list) == L)

        count = 0
        for word in word_dict:
            z = list(zip(word, pattern_list))
            test = list(map(lambda x: x[0] in x[1], z))
            all_true = functools.reduce(lambda x, y: x and y, test)

            if all_true:
                count += 1

        print('Case #%d: %d' % (i, count))


def make_check_list(word):
    ret = []

    is_open_parenthesis = False
    chunk = ''

    for ch in word:
        if ch == '(':
            is_open_parenthesis = True
            chunk = ''
        elif ch == ')':
            is_open_parenthesis = False
            ret.append(chunk)
        else:
            if is_open_parenthesis:
                chunk = chunk + ch
            else:
                ret.append(ch)

    return ret


if __name__ == '__main__':
    main()
