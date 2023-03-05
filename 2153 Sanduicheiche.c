#include <stdio.h>
#include <string.h>

#define MAX_LEN 31

// Função que preenche a tabela de saltos
void preencheTabelaSaltos(int tabelaSaltos[], char padrao[]) {
  int m = strlen(padrao);
  
  for (int i = 0; i < MAX_LEN; i++) {
    tabelaSaltos[i] = m;
  }
  for (int j = 0; j < m - 1; j++) {
    tabelaSaltos[padrao[j]] = m - 1 - j;
  }
}

// Função de busca em string Horspool
int buscaHorspool(char texto[], char padrao[], int tabelaSaltos[]) {
  int n = strlen(texto);
  int m = strlen(padrao);
  printf("\nComprimento do texto: %d", n);
  printf("\nComprimento do padrão: %d ", m);
  
  int i = m - 1; // Representa o índice na string de texto a partir do qual a 
                // comparação do padrão com a substring será ativada
  while (i < n) {  // Percorre o texto a partir do índice 'i', o loop só execulta
                  // enquanto o 'i' é menor que o comprimento do texto 'n'.
    int k = 0;   // Contagem de caracteres a partir do inicio do padrão.
    
    while (k < m && padrao[m - 1 - k] == texto[i - k]) { 
            // Compara o padrão com uma substring atual da string de texto,
            // só é executado se 'k' se for menor que padrão 'm' e os caracteres
            // correspondentes na substring da string de texto e no padrão são iguais.
      k++; // Se os caracteres comparados não forem iguais, a contagem ké interrompida.
    }
    if (k == m) {  // Se forem inguais, uma correspondencia foi encontrada.
      return i - m + 1; // Retorna a posição inicial da substring no texto.
    } else {
      i += tabelaSaltos[texto[i]];
       //  Se a comparação não resultar em uma correspondência, a posição atual na string
       // de texto é atualizada adicionando um valor a i. Esse valor é obtido a partir de 
       // uma tabela de deslocamento de caracteres.
    }
  }
  return -1; // Retorna a -1 se o padrão não foi encontrado no texto
}


int main() {
  char texto[MAX_LEN];
  char padrao[MAX_LEN];
  
  printf("Digite um texto (max %d caracteres):\n", MAX_LEN - 1);
  fgets(texto, MAX_LEN, stdin);
  texto[strcspn(texto, "\n")] = '\0'; // remove o caractere de quebra de linha
  
  printf("Digite um padrao de busca (max %d caracteres):\n", MAX_LEN - 1);
  fgets(padrao, MAX_LEN, stdin);
  padrao[strcspn(padrao, "\n")] = '\0'; // remove o caractere de quebra de linha
  
  int tabelaSaltos[MAX_LEN];
  preencheTabelaSaltos(tabelaSaltos, padrao);
  
  int posicao = buscaHorspool(texto, padrao, tabelaSaltos);
  
  if (posicao == -1) {
    printf("\nPadrao nao encontrado no texto.\n");
  } else {
    printf("\nO padrao foi encontrado na posicao %d do texto.\n", posicao);
  }
  return 0;
}