#include <stdio.h>
#include <string.h>

#define MAX 128

int horspool(char src[], char p[]) {
    int i, j, k, m, n;
    int t[MAX]; // tabela de deslocamento
    n = strlen(src);
    m = strlen(p);
    printf("\nComprimento do texto=%d", n);
    printf("\nComprimento do padrão=%d", m);
    
    // preencher a tabela de deslocamento
    for (i = 0; i < MAX; i++) {
        t[i] = m;
    }
    for (i = 0; i < m - 1; i++) {
        t[p[i]] = m - 1 - i;
    }
    // busca do padrão na string de texto
    i = m - 1; // Representa o índice na string de texto a partir do qual a 
                // comparação do padrão com a substring será ativada
    
    while (i < n) { // Percorre o texto a partir do índice 'i', o loop só execulta
                  // enquanto o 'i' é menor que o comprimento do texto 'n'.
        k = 0;    // Contagem de caracteres a partir do inicio do padrão.

        while ((k < m) && (p[m - 1 - k] == src[i - k])) { // Compara o padrão com uma substring atual da string de texto,
                                                         // só é executado se 'k' se for menor que padrão 'm' e os caracteres
                                                        // correspondentes na substring da string de texto e no padrão são iguais.
            k++;
        }
        if (k == m) {  // Se forem inguais, uma correspondencia foi encontrada.
            return i - m + 1;  // Retorna a posição inicial da substring no texto.
        } else {
            i += t[src[i]];
        //  Se a comparação não resultar em uma correspondência, a posição atual na string
       // de texto é atualizada adicionando um valor a i. Esse valor é obtido a partir de 
       // uma tabela de deslocamento de caracteres.
        }
    }
    return -1; // Retorna -1 seo padrão não foi encontrado no texto.
}

int main() {
    char src[] = "o rato roeu a roupa do rei de roma";
    char p[] = "rou";
    int pos = horspool(src, p);
    if (pos == -1) {
        printf("\nPadrão não encontrado\n");
    } else {
        printf("\nPadrão encontrado na posição %d\n", pos);
    }
    return 0;
}
