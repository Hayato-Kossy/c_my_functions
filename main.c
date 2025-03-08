#include "my_stdio.h"
// https://chatgpt.com/g/g-p-67c9b635d74c8191aef14e2562dbd92d-cyan-yu-zi-zuo-guan-shu/c/67c9b680-2eec-8008-abea-b24a0933c721
// オブジェクトファイルの作成 → テストコードのコンパイル → 実行
// gcc -c my_stdio.c -o my_stdio.o
// gcc main.c my_stdio.o -o main

int main()
{
  my_puts("Hello, world!\n");
  my_puts("こんにちは!\n");
  my_printf("Hello, %s!\n", "Alice");
  my_printf("アホ%dドジ", 12);
  return 0;
}
