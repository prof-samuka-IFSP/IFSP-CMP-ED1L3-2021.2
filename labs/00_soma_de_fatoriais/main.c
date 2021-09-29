#include <stdio.h>

int fatorial(int n) {
    int fat = 1;

    for (int i = n; i >= 1; i--) {
        fat *= i;
    }

    return fat;
}


int main() {
    int a;
    int b;

    scanf("%d %d", &a, &b);

    int fat_a = fatorial(a);
    int fat_b = fatorial(b);
    int soma_fats = fat_a + fat_b;

    printf("%d\n", fat_a);
    printf("%d\n", fat_b);
    printf("%d\n", soma_fats);


    return 0;
}
