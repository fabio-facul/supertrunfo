#include <stdio.h>
#include <string.h>

#define MAXI_CIDADES 2
#define CODIGO_TAMANHO 5
#define NOME_CIDADE_TAMANHO 50

typedef struct {
    char estado;
    char codigo[CODIGO_TAMANHO];
    char nomeCidade[NOME_CIDADE_TAMANHO];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
} Carta;

void lerDados(Carta *carta) {
    printf("Digite o Estado (A-H): ");
    scanf(" %c", &carta->estado);
    
    printf("Digite o Código da Carta (ex: A01): ");
    scanf("%s", carta->codigo);
    
    printf("Digite o Nome da Cidade: ");
    getchar(); // Limpa o buffer
    fgets(carta->nomeCidade, NOME_CIDADE_TAMANHO, stdin);
    carta->nomeCidade[strcspn(carta->nomeCidade, "\n")] = 0; // Remove nova linha
    
    printf("Digite a População: ");
    scanf("%d", &carta->populacao);
    
    printf("Digite a Área (em km²): ");
    scanf("%f", &carta->area);
    
    printf("Digite o PIB: ");
    scanf("%f", &carta->pib);
    
    printf("Digite o Número de Pontos Turísticos: ");
    scanf("%d", &carta->pontosTuristicos);
}

void exibirDados(const Carta *carta) {
    printf("\nInformações da Carta:\n");
    printf("Estado: %c\n", carta->estado);
    printf("Código da Carta: %s\n", carta->codigo);
    printf("Nome da Cidade: %s\n", carta->nomeCidade);
    printf("População: %d\n", carta->populacao);
    printf("Área: %.2f km²\n", carta->area);
    printf("PIB: %.2f\n", carta->pib);
    printf("Pontos Turísticos: %d\n", carta->pontosTuristicos);
}

int main() {
    Carta cartas[MAXI_CIDADES];

    for (int i = 0; i < MAXI_CIDADES; i++) {
        printf("\n--- Dados da Carta %d ---\n", i + 1);
        lerDados(&cartas[i]);
    }

    for (int i = 0; i < MAXI_CIDADES; i++) {
        printf("\n--- Exibindo Dados da Carta %d ---\n", i + 1);
        exibirDados(&cartas[i]);
    }

    return 0;
}