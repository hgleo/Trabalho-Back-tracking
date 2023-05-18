// Todas as combinações de {15,31,55,44}, de tamanho n, cuja soma dos elementos  da combinação é par.

#include <stdio.h>

void printCombinations(int set[], int n, int index, int current[], int currentSum) {
    if (index == n) {
        if (currentSum % 2 == 0) {
            printf("Combinação: ");
            for (int i = 0; i < n; i++) {
                printf("%d ", current[i]);
            }
            printf("\n");
        }
        return;
    }

    for (int i = 0; i < 4; i++) {
        current[index] = set[i];
        printCombinations(set, n, index + 1, current, currentSum + set[i]);
    }
}

int main() {
    int n;
    printf("Digite o tamanho das combinações: ");
    scanf("%d", &n);

    int set[] = {15, 31, 55, 44};
    int current[100];  // Um array grande o suficiente para armazenar a combinação atual
    printCombinations(set, n, 0, current, 0);

    return 0;
}
