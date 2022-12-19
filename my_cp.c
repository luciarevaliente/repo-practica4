#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define N 1024


int file, desc1, desc2, dif;
char arxiu[N], contingut[N];

int main(){
  scanf("%s",arxiu); //scanf--> escaneja el nom de l'arxiu que li posem (%c char) &-->pq es una varible
  desc1=open(arxiu, O_RDONLY); // nomes volem llegir l'arxiu, ja que hi farem una còpia, comanda per obrir el fitxer
  if (desc1==-1){ // si al executar l'open dona -1 significa que hi ha un error a l'obrir-lo
    printf("Error: L'arxiu no existeix \n");
  }

  else{
     read(desc1, contingut, N); //llegeix l'arxiu
     desc2=open( "copia.fi", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU );  //creant el fitxer on copiarem l'arxiu 
     write(desc2, contingut, N); // se suposa que escriu el contingut de l'arxiu al nou fitxer
//     desc3=diff 'arxiu' 'copiafi';//per veure les diferències, serveix de comprovació
//     if (desc3==-1){
//       printf("Els arxius no són iguals.");
     }
//     else{
//       printf("Els arxius són iguals.");
//     }
  close(desc1);
  close(desc2);
//  close(desc3);
//  }
}
