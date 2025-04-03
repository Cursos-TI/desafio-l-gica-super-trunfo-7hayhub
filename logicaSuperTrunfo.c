#include <stdio.h>
#include <string.h>  // Adicionando a biblioteca correta

// Estrutura para armazenar os dados da carta
typedef struct {
    char estado[3];
    char codigo[10];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
} Carta;

// Função para calcular a densidade populacional e o PIB per capita
void calcularMetricas(Carta *carta) {
    carta->densidade_populacional = carta->populacao / carta->area;
    carta->pib_per_capita = carta->pib / carta->populacao;
}

// Função para comparar as cartas com base no atributo escolhido
void compararCartas(Carta c1, Carta c2, char atributo[]) {
    float valor1, valor2;
    int menor_vence = 0; // Indica se o menor valor vence (aplicado à densidade populacional)

    if (strcmp(atributo, "Populacao") == 0) {
        valor1 = c1.populacao;
        valor2 = c2.populacao;
    } else if (strcmp(atributo, "Area") == 0) {
        valor1 = c1.area;
        valor2 = c2.area;
    } else if (strcmp(atributo, "PIB") == 0) {
        valor1 = c1.pib;
        valor2 = c2.pib;
    } else if (strcmp(atributo, "Densidade Populacional") == 0) {
        valor1 = c1.densidade_populacional;
        valor2 = c2.densidade_populacional;
        menor_vence = 1;
    } else if (strcmp(atributo, "PIB per capita") == 0) {
        valor1 = c1.pib_per_capita;
        valor2 = c2.pib_per_capita;
    } else {
        printf("Atributo inválido!\n");
        return;
    }

    printf("Comparação de cartas (Atributo: %s):\n\n", atributo);
    printf("Carta 1 - %s (%s): %.2f\n", c1.nome, c1.estado, valor1);
    printf("Carta 2 - %s (%s): %.2f\n\n", c2.nome, c2.estado, valor2);
    
    if ((valor1 > valor2 && !menor_vence) || (valor1 < valor2 && menor_vence)) {
        printf("Resultado: Carta 1 (%s) venceu!\n", c1.nome);
    } else if ((valor2 > valor1 && !menor_vence) || (valor2 < valor1 && menor_vence)) {
        printf("Resultado: Carta 2 (%s) venceu!\n", c2.nome);
    } else {
        printf("Resultado: Empate!\n");
    }
}

int main() {
    // Definição das cartas
    Carta carta1 = {"SP", "C01", "São Paulo", 12300000, 1521.11, 699.28, 15};
    Carta carta2 = {"RJ", "C02", "Rio de Janeiro", 6710000, 1200.27, 362.15, 10};

    // Cálculo das métricas
    calcularMetricas(&carta1);
    calcularMetricas(&carta2);

    // Escolha do atributo para comparação (definido no código)
    char atributo[] = "Populacao";

    // Comparação das cartas
    compararCartas(carta1, carta2, atributo);

    return 0;
}
