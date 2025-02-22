#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas

int main() {
    char codCidade[100];
    float pib;
    float area;
    char nomeCidade[100];
    int populacao;
    int pontosTuristicos;

    // Cadastro da Cidade
    printf("Digite o nome da cidade: ");
    getchar(); // Limpa o buffer do teclado
    fgets(nomeCidade, sizeof(nomeCidade), stdin);

    // Cadastro dos Pontos Turísticos
    printf("Digite o número de pontos turísticos da cidade: ");
    scanf("%d", &pontosTuristicos);

    // Cadastro da População
    printf("Digite a população da cidade: ");
    scanf("%d", &populacao);

    // Cadastro da Área
    printf("Digite a área da cidade: ");
    scanf("%f", &area);

    // Cadastro do Código
    printf("Digite o código da cidade: ");
    scanf("%s", codCidade);

    // Cadastro do PIB
    printf("Digite o PIB da cidade: ");
    scanf("%f", &pib);

    // Exibição dos Dados
    printf("\n--- Dados da Cidade ---\n");
    printf("Nome: %s", nomeCidade);
    printf("Código: %s\n", codCidade);
    printf("População: %d habitantes\n", populacao);
    printf("Área: %.2f km²\n", area);
    printf("PIB: %.2f bilhões\n", pib);
    printf("Pontos Turísticos: %d\n", pontosTuristicos);

    return 0;
}