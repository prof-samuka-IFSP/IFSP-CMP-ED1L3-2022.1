#include <stdio.h>


// 5! = 5 * 4 * 3 * 2 * 1 = 120

int fatorial(int n) {
    int fat = 1;

    for (int i = n; i > 1; i--) {
        fat *= i;
        // ALTERNATIVA
        // fat = fat * i;
    }

    return fat;
}


int main() {
    int a, b;

    scanf("%d %d", &a, &b);

    // ALTERNATIVA QUE FUNCIONA TAMBÉM
    // scanf("%d", &a);
    // scanf("%d", &b);

    int fat_a = fatorial(a);
    int fat_b = fatorial(b);
    int soma_fatoriais = fat_a + fat_b;

    printf("%d\n", fat_a);
    printf("%d\n", fat_b);
    printf("%d\n", soma_fatoriais);

    return 0;
}
