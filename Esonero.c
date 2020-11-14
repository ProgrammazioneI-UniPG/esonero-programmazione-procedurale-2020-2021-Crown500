#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void){
  int n = 0;
  char M[128];
  time_t t;
  printf("Scrivere una stringa di massimo 128 caratteri.\n");
  fgets(M, 128, stdin);

  printf("Lunghezza della stringa immessa: %ld caratteri.\n\n", (strlen(M)-1));
  fflush(stdin);

  printf("Per cifrare la stringa scegli tra 1 e 2:\n1)");
  printf("Scrivere un'ulteriore stringa di lunghezza ");
  printf("maggiore o uguale\n2)Generare una stringa ");
  printf("casuale\n");

  scanf("%d", &n);
while (n!=1 && n!=2) {
  printf(" - Puoi scegliere solo tra 1 e 2!\n");
  scanf("%d", &n);
}
  char C[strlen(M)];
  char F[strlen(M)];
  if(n==1){
    char k[128];
    printf(" - Digita la stringa:\n");
    fgets(k, 128, stdin);
    while(strlen(k)<strlen(M)){
        fgets(k, 128, stdin);
        if(strlen(k)<strlen(M)){
        printf(" - Stringa troppo corta!\n");
        }
    }
      for(int i = 0; i<strlen(M); i++){
        C[i] = k[i] ^ M[i];
        F[i] = C[i] ^ k[i];
      }
      printf("\n - Stringa codificata: %s", C);
      printf("\n\n");
      printf(" - Stringa iniziale: %s", F);
      fflush(stdout);
    }
    if(n==2){
      srand((unsigned) time(&t));
      char k2[strlen(M)];
      for (int i = 0; i < strlen(M); i++) {
      k2[i] = (rand()%96)+32;
      C[i] = k2[i] ^ M[i];
      F[i] = C[i] ^ k2[i];
      }
      printf(" - Stringa casuale generata: %s\n\n", k2);
      printf(" - Stringa codificata: %s\n\n", C);
      printf(" - Stringa iniziale: %s\n", F);
      fflush(stdout);
    }
  return 0;
}
