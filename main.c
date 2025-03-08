#include "my_stdio.h"
// オブジェクトファイルの作成 → テストコードのコンパイル → 実行
// gcc -c my_stdio.c -o my_stdio.o
// gcc main.c my_stdio.o -o main

int main()
{
  my_puts("Hello, world!\n");
  my_puts("こんにちは!\n");
  my_printf("Hello, %s!\n", "Alice");
  my_printf("%d", 12);
  return 0;
}
