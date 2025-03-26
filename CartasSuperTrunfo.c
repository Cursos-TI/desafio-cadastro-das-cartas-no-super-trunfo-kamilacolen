#include <stdio.h>
#include <string.h>

typedef struct {
    char nomeCidade[100];
    float pib;
    float area;
    int populacao;
    int pontosTuristicos;
    float densidadeDemografica;
} CartaCidade;

// Função para comparar dois valores, com exceção para a densidade demográfica
int compararValores(float valor1, float valor2, int isDensidade) {
    if (isDensidade) {
        return valor1 < valor2;  // Menor valor vence na densidade demográfica
    } else {
        return valor1 > valor2;  // Maior valor vence para outros atributos
    }
}

// Função principal do jogo
int main() {
    CartaCidade cartas[5] = {
        {"São Paulo", 500.3, 1521.11, 12300000, 100, 8197.5},
        {"Rio de Janeiro", 300.4, 1182.3, 6748000, 120, 5705.1},
        {"Brasília", 150.5, 5802.9, 3055149, 50, 526.3},
        {"Salvador", 120.2, 713.5, 2930000, 40, 4115.0},
        {"Belo Horizonte", 180.8, 331.9, 2500000, 70, 7542.5}
    };

    int cartaEscolhida1, cartaEscolhida2, escolha1, escolha2;
    float somaCarta1, somaCarta2;

    // Apresentação das cartas
    printf("Escolha a primeira cidade (1-5):\n");
    printf("1. São Paulo\n2. Rio de Janeiro\n3. Brasília\n4. Salvador\n5. Belo Horizonte\n");
    scanf("%d", &cartaEscolhida1);

    printf("Escolha a segunda cidade (1-5):\n");
    printf("1. São Paulo\n2. Rio de Janeiro\n3. Brasília\n4. Salvador\n5. Belo Horizonte\n");
    scanf("%d", &cartaEscolhida2);

    // Garantir que o jogador não escolha a mesma cidade
    if (cartaEscolhida1 == cartaEscolhida2) {
        printf("Você não pode escolher a mesma cidade duas vezes!\n");
        return 0;
    }

    CartaCidade carta1 = cartas[cartaEscolhida1 - 1];
    CartaCidade carta2 = cartas[cartaEscolhida2 - 1];

    // Menus interativos para escolha dos atributos
    printf("\nEscolha o primeiro atributo para a comparação:\n");
    printf("1. PIB\n2. Área\n3. População\n4. Pontos Turísticos\n5. Densidade Demográfica\n");
    printf("Escolha: ");
    scanf("%d", &escolha1);

    // Garantir que o jogador não escolha o mesmo atributo para a segunda escolha
    printf("Escolha o segundo atributo para a comparação (não pode ser o mesmo que o primeiro):\n");
    printf("1. PIB\n2. Área\n3. População\n4. Pontos Turísticos\n5. Densidade Demográfica\n");
    printf("Escolha: ");
    scanf("%d", &escolha2);
    
    // Comparar os valores
    float valor1A, valor1B, valor2A, valor2B;
    int isDensidade1, isDensidade2;
    
    // Atribuindo valores para o primeiro atributo
    switch (escolha1) {
        case 1: valor1A = carta1.pib; valor1B = carta2.pib; isDensidade1 = 0; break;
        case 2: valor1A = carta1.area; valor1B = carta2.area; isDensidade1 = 0; break;
        case 3: valor1A = carta1.populacao; valor1B = carta2.populacao; isDensidade1 = 0; break;
        case 4: valor1A = carta1.pontosTuristicos; valor1B = carta2.pontosTuristicos; isDensidade1 = 0; break;
        case 5: valor1A = carta1.densidadeDemografica; valor1B = carta2.densidadeDemografica; isDensidade1 = 1; break;
        default: printf("Opção inválida!\n"); return 0;
    }

    // Atribuindo valores para o segundo atributo
    switch (escolha2) {
        case 1: valor2A = carta1.pib; valor2B = carta2.pib; isDensidade2 = 0; break;
        case 2: valor2A = carta1.area; valor2B = carta2.area; isDensidade2 = 0; break;
        case 3: valor2A = carta1.populacao; valor2B = carta2.populacao; isDensidade2 = 0; break;
        case 4: valor2A = carta1.pontosTuristicos; valor2B = carta2.pontosTuristicos; isDensidade2 = 0; break;
        case 5: valor2A = carta1.densidadeDemografica; valor2B = carta2.densidadeDemografica; isDensidade2 = 1; break;
        default: printf("Opção inválida!\n"); return 0;
    }
    
    // Comparação de cada atributo individualmente
    int v1 = compararValores(valor1A, valor1B, isDensidade1);
    int v2 = compararValores(valor2A, valor2B, isDensidade2);
    
    // Soma dos atributos
    somaCarta1 = valor1A + valor2A;
    somaCarta2 = valor1B + valor2B;

    // Exibição dos resultados
    printf("\n--- Resultados da Comparação ---\n");
    printf("Cidade 1: %s\n", carta1.nomeCidade);
    printf("Cidade 2: %s\n", carta2.nomeCidade);
    
    // Exibição de detalhes sobre os atributos escolhidos
    printf("Atributo 1 escolhido: ");
    switch (escolha1) {
        case 1: printf("PIB\n"); break;
        case 2: printf("Área\n"); break;
        case 3: printf("População\n"); break;
        case 4: printf("Pontos Turísticos\n"); break;
        case 5: printf("Densidade Demográfica\n"); break;
    }
    
    printf("Atributo 2 escolhido: ");
    switch (escolha2) {
        case 1: printf("PIB\n"); break;
        case 2: printf("Área\n"); break;
        case 3: printf("População\n"); break;
        case 4: printf("Pontos Turísticos\n"); break;
        case 5: printf("Densidade Demográfica\n"); break;
    }

    // Exibição dos resultados dos atributos
    printf("\nCidade 1: %.2f, %.2f\n", valor1A, valor2A);
    printf("Cidade 2: %.2f, %.2f\n", valor1B, valor2B);

    // Verificação de quem venceu
    if (v1 && v2) {
        printf("\nA Carta 1 venceu em ambos os atributos!\n");
    } else if (!v1 && !v2) {
        printf("\nA Carta 2 venceu em ambos os atributos!\n");
    } else {
        printf("\nEmpate!\n");
    }

    // Verificando quem tem a maior soma
    if (somaCarta1 > somaCarta2) {
        printf("\nA Carta 1 venceu a rodada com uma soma de %.2f!\n", somaCarta1);
    } else if (somaCarta1 < somaCarta2) {
        printf("\nA Carta 2 venceu a rodada com uma soma de %.2f!\n", somaCarta2);
    } else {
        printf("\nEmpate na soma dos atributos!\n");
    }

    return 0;
}
