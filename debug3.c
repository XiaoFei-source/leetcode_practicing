#include <stdio.h>

int main(void) {
    int input;
    printf("我好想撞牆");
    if (scanf("%d", &input) != 1) {
         printf("輸入\n");
         return 1;
     }

     printf("無效\n", input);

    return 0;
}