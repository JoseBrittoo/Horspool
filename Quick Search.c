#include <stdio.h>
#include <string.h>

// Função que implementa o algoritmo de busca rápida
int quick_search(char str[], char pattern[]) {
    int n = strlen(str);
    int m = strlen(pattern);
    int i, j;

    // Cria a tabela de saltos
    int jump_table[256];
    for (i = 0; i < 256; i++) {
        jump_table[i] = m + 1;
    }
    for (i = 0; i < m; i++) {
        jump_table[pattern[i]] = m - i - 1;
    }

    // Busca o padrão no texto
    i = m - 1;
    while (i < n) {
        j = m - 1;
        while (j >= 0 && str[i] == pattern[j]) {
            i--;
            j--;
        }
        if (j < 0) {
            return i + 1; // Retorna a posição em que o padrão começa
        }
        i += jump_table[str[i]];
    }

    return -1; // Retorna -1 caso o padrão não seja encontrado
}

int main() {
    char str[100];
    char pattern[20];

    printf("Digite o texto: ");
    fgets(str, 100, stdin);

    printf("Digite o padrão: ");
    fgets(pattern, 20, stdin);

    // Remove o caractere de quebra de linha do final das strings
    str[strcspn(str, "\n")] = '\0';
    pattern[strcspn(pattern, "\n")] = '\0';

    // Busca o padrão no texto
    int pos = quick_search(str, pattern);

    // Imprime o resultado
    if (pos >= 0) {
        printf("Padrão encontrado na posição %d\n", pos);
    } else {
        printf("Padrão não encontrado\n");
    }

    return 0;
}
