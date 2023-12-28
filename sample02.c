#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* MAX_ELEMENTやOFSETは適宜必要に応じて変更すること */
#define MAX_ELEMENTS    10000 /* 最大のデータ数 */
#define OFFSET          100   /* データ数の増分値 */

int  a[MAX_ELEMENTS] ; /* 探索するデータ領域 */

int search(int, int); /* サンプル関数・線形探索をする */
void print_count(int); /* ステップ数を表示する */
void print_header(char *); /* ヘッダを表示する*/
int sorted(int); /* ソートされているか確認する関数 */

/* 必要に応じて、仮引数の設定を行うこと */
void ShellSort();
void QuickSort();
void MergeSort();
void HeapSort();

int swap; /* 交換回数をカウント */
int comp; /* 比較回数をカウント */

int main(void){
  int i;
  int n; /* データ数 */

  srand(time(0));               /* 乱数の種を初期設定する */

/* 昇順にソートされた入力の場合 */
  print_header("ascending order");
  for (n = OFFSET; n <= MAX_ELEMENTS; n += OFFSET) {
    printf("%5d\t", n);
    //init_step();                  /* 配列sの初期化 */
    for (i = 0; i < n ; i++) {
      a[i] = i ;                  /* 配列要素に昇順のデータ値を設定する */
    }

    /* ここのsearchを課題で当たったソート関数に変更する */
    search(n, n/3);               /* 線形探索を実行 */

    print_count(n);                /* 各行の実行回数表示 */

    if (!sorted(n)) {             /* 配列が昇順に整列されているかチェック */
      fprintf(stderr, "not sorted\n");
      exit(1);
    }
    fprintf(stderr, "sorted\n");
  }

/* 降順にソートされた入力の場合 */
  print_header("descending order");
  for (n = OFFSET; n <= MAX_ELEMENTS; n += OFFSET) {
    printf("%5d\t", n);
    //init_step();                  /* 配列sの初期化 */
    for (i = 0; i < n ; i++) {
      a[i] = n - i ;              /* 配列要素に降順のデータ値を設定する */
    }

    /* ここのsearchを課題で当たったソート関数に変更する */
    search(n, n/3);               /* 線形探索を実行 */

    print_count(n);                /* 各行の実行回数表示 */
    
    if (!sorted(n)) {             /* 配列が昇順に整列されているかチェック */
      fprintf(stderr, "not sorted\n");
      exit(1);
    }
    fprintf(stderr, "sorted\n");
  }

  /* ランダム入力の場合 */
  print_header("random");
  for (n = OFFSET; n <= MAX_ELEMENTS; n += OFFSET) {
    printf("%5d\t", n);
    //init_step();                  /* 配列sの初期化 */
    for (i = 0; i < n ; i++) {
      a[i] = rand() % n ;       /* 配列要素に乱数値を設定する */
    }
    
    /* ここのsearchを課題で当たったソート関数に変更する */
    search(n, n/3);               /* 線形探索を実行 */

    print_count(n);                /* 各行の実行回数表示 */
    
    if (!sorted(n)) {             /* 配列が昇順に整列されているかチェック */
      fprintf(stderr, "not sorted\n");
      exit(1);
    }
    fprintf(stderr, "sorted\n");
  }

  return 0;
}

void print_count(int n){
  printf("%10d\t%10d\t", comp, swap);
}

void print_header(char *s) {
  int i;

  printf("%s\n    n", s);
  printf("\tcomp_count\tswap_count\tSorted");
  printf("\n");
}

int sorted(int n) {
  int i;

  for (i = 0; i < n - 1; i++) {
    if (a[i] > a[i+1]) return 0;
  }
  return 1;
}

/* 線形探索 */
int search(int n, int key){
  int i;

  i = 0;
  while (i < n) {
    if (comp++ && a[i] == key) { /* 比較回数をカウントする */
      return (key);
    }
    i++;
  }
  return -1;
}

/* ここより下に課題で当たったソートのプログラムを記述する */
/*
void ShellSort();
void QuickSort();
void MergeSort();
void HeapSort();
*/