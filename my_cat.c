#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define N 1024

// INICIALITZACIÓ VARIABLES
int desc1, desc2;
char arxiu[N], contingut[N];

// MAIN
int main(){
  //printf("Nom de l'arxiu: ");
  scanf("%s", arxiu); //scanf perquè l'usuari introdueixi el nom de l'arxiu
  desc1=open(arxiu, O_RDONLY); //obrim l'arxiu
  
  if (desc1==-1){ //si la funció ens retorna el valor -1
    printf("\nError: L'arxiu no existeix\n"); //l'arxiu no existeix
  }
  else{ //sinó
    read(desc1, contingut, N); //realitzem la lectura
    //printf("\nEl contingut de l'arxiu %s es\n", arxiu);
    for (int i=0; i<N; i++){ //i fem un for per recórrer l'array
      printf("%c", contingut[i]); //mostrem per pantalla el contingut
      
    }
    desc2=close(desc1); //tanquem l'arxiu
    if (desc2==-1){printf("\nError: L'arxiu no s'ha pogut tancar\n");} //si l'arxiu no s'ha pogut tancar correctament, avisa a l'usuari
    //else{printf("\nL'arxiu s'ha tancat correctament\n");} //sinó, avisa a l'usuari de que s'ha tancat l'arxiu
  }
}