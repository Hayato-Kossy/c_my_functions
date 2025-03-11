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
  int num;
  char name[100];

  my_printf("整数を入力してください: ");
  my_scanf("%d", &num);
  my_printf("入力された数値: %d\n", num);

  my_printf("名前を入力してください: ");
  my_scanf("%s", name);
  my_printf("入力された名前: %s\n", name);

  return 0;
}
