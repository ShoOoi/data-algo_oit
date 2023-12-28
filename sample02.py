import random

#グロ－バル変数を定義する
MAX_ELEMENT = 10000  #最大のデータ数
OFFSET = 100         #データ数の増分値

#配列の初期化
_list = [0 for x in range(0, MAX_ELEMENT, 1)]
roop_list = [x for x in range(OFFSET, MAX_ELEMENT+OFFSET, OFFSET)]

swap = 0 #交換回数
comp = 0 #比較回数

#リストの初期化
def init_list(key):
    pass

#ヘッダを表示
def print_header(s):
    print(s)
    print("n\tcomp_count\tswap_count\tSorted");

#ソートしているかチェック（初期は、昇順チェック）
def sorted(n):
    global _list

    for i in range(0, n-1, 1):
        if _list[i] > _list[i+1]:
            return 0
    return 1

# 変数の初期化
def init():
    global comp, swap
    comp = 0
    swap = 0

# サンプル関数（線形探索）
def serach(n, key):
    global comp, swap
    for i in range(0, n, 1):
        comp += 1 
        if _list[i] == key:
            return key
    return -1

# ヘッダ情報を出力
def print_counter(n):
    print(f'{comp:13g}\t{swap:10g}\t', end='')


# 必要に応じてここにソートの関数を追加する
#def ShellSort():
#def QuickSort():
#def MergeSort():
#def HeapSort():





# main関数
def main():
    global _list
    #昇順にソートされた入力の場合
    print_header('ascending order')
    for n in roop_list:
        init()
        print(f'{n:5g}', end='')

        #リストを昇順にする
        _list = [x for x in range(0, n, 1)]

        #ここのsearchを課題で当たったソート関数に変更する
        # 線形探索を実行
        serach(n, n//3)

        #実行回数のカウント
        print_counter(n)

        #ソートされているかチェック
        if sorted(n) == 0:
            print('not sorted')
        print('sorted')
    
    #降順にソートされた入力の場合
    print_header('descending order')
    for n in roop_list:
        init()
        print(f'{n:5g}', end='')

        #リストを降順にする
        _list = [x for x in range(n, 0, -1)]

        #ここのsearchを課題で当たったソート関数に変更する
        # 線形探索を実行
        serach(n, n//3)

        #実行回数のカウント
        print_counter(n)

        #ソートされているかチェック
        if sorted(n) == 0:
            print('not sorted')
            exit(1)
        print('sorted')

    #降順にソートされた入力の場合
    print_header('random order')
    for n in roop_list:
        init()
        print(f'{n:5g}', end='')

        #リストを降順にする
        _list = [random.randint(50, 100) for x in range(0, n, 1)]
        print(_list)

        #ここのsearchを課題で当たったソート関数に変更する
        # 線形探索を実行
        serach(n, n//3)

        #実行回数のカウント
        print_counter(n)

        #ソートされているかチェック
        if sorted(n) == 0:
            print('not sorted')
            exit(1)
        print('sorted')

#main関数
if __name__ == "__main__":
    main()