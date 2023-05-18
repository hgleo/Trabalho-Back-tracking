// Todas as combinações de {a,e,i}, de tamanho n, quue o número de a´s é menor que a soma dos totais de e`s e de i´s

#include <stdio.h>

void printCombinations(char set[], int n, int index, char current[], int count_a, int count_ei) {
    if (index == n) {
        current[index] = '\0';  // Adiciona o caractere nulo para finalizar a string
        printf("%s\n", current);
        return;
    }

    for (int i = 0; i < 3; i++) {
        if (i == 0 && count_a >= count_ei) {
            continue;  // Ignora a letra 'a' se o número de 'a's for maior ou igual à soma total de 'e's e 'i's
        }

        current[index] = set[i];

        if (i == 0) {
            printCombinations(set, n, index + 1, current, count_a + 1, count_ei);
        } else {
            printCombinations(set, n, index + 1, current, count_a, count_ei + 1);
        }
    }
}

int main() {
    int n;
    printf("Digite o tamanho das combinacoes: ");
    scanf("%d", &n);

    char set[] = {'a', 'e', 'i'};
    char current[100];  // Um array grande o suficiente para armazenar a combinação atual
    printCombinations(set, n, 0, current, 0, 0);

    return 0;
}
