#include <stdio.h>
#include <string.h>

#define MAX_LEN 300000

// Função de busca em string Quick Search
int quick_search(char *text, char *pattern) {
    int i, j, k, m, n;

    n = strlen(text);
    m = strlen(pattern);

    if (m > n) {
        return 0;
    }

    for (k = 0; k < m - 1 && pattern[k] == pattern[k + 1]; k++);
    if (k == m - 1) {
        for (i = 0; i <= n - m; i++) {
            if (text[i] == pattern[0]) {
                return 1;
            }
        }
        return 0;
    }
    // Função que preenche a tabela de saltos
    int pular[256];
    for (i = 0; i < 256; i++) {
        pular[i] = m;
    }
    for (i = 0; i < m - 1; i++) {
        pular[pattern[i]] = m - 1 - i;
    }

    i = m - 1;
    j = m - 1;
    while (i < n) {
        if (text[i] == pattern[j]) {
            if (j == 0) {
                return 1;
            }
            i--;
            j--;
        } else {
            i += pular[text[i]];
            j = m - 1;
        }
    }

    return 0;
}

int main() {
    int a, instancia = 1;
    char painel[MAX_LEN];
    char assinatura[MAX_LEN];

    while (1) {
        scanf("%d", &a);
        if (a == 0) {
            break;
        }
        scanf("%s", painel);

        sprintf(assinatura, "%d", a);

        printf("Instancia %d\n", instancia);
        if (quick_search(painel, assinatura)) {
            printf("verdadeira\n\n");
        } else {
            printf("falsa\n\n");
        }

        instancia++;
    }

    return 0;
}
