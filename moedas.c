//  Dado um valor em centavos, imprimir todas as maneiras de representá-lo itulizando moedas de 1,5,10,25 e 50 centavos.

#include "stdio.h"

void printCoins(int cents, int coins[], int coinIndex, int currentCoin[], int currentIndex) {
    if (cents == 0) {
        // Imprime a combinação atual de moedas
        for (int i = 0; i < currentIndex; i++) {
            printf("%d ", currentCoin[i]);
        }
        printf("\n");
        return;
    }

    if (coinIndex >= 5 || cents < 0) {
        // Verifica se todas as moedas foram consideradas ou se o valor restante é negativo
        return;
    }

    // Recursivamente tenta usar a próxima moeda disponível
    currentCoin[currentIndex] = coins[coinIndex];
    printCoins(cents - coins[coinIndex], coins, coinIndex, currentCoin, currentIndex + 1);

    // Recursivamente avança para a próxima moeda
    printCoins(cents, coins, coinIndex + 1, currentCoin, currentIndex);
}

int main() {
    int cents;
    printf("Digite o valor em centavos: ");
    scanf("%d", &cents);

    int coins[] = {1, 5, 10, 25, 50};
    int currentCoin[100000];  // Um array grande o suficiente para armazenar a combinação de moedas
    printCoins(cents, coins, 0, currentCoin, 0);

    return 0;
}
