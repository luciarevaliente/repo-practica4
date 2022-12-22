#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define N 1024

// INICIALITZACIÓ VARIABLES
int file, desc1, desc2, bytes=1;
char arxiu[N], contingut[N];

// MAIN
int main(){
  scanf("%s",arxiu); //scanf escaneja el nom de l'arxiu que li posem (%s indica un string) 
  desc1=open(arxiu, O_RDONLY); // nomes volem llegir l'arxiu, ja que hi farem una còpia, comanda per obrir el fitxer
  
  if (desc1==-1){ // si al executar l'open dona -1 significa que hi ha un error a l'obrir-lo
    printf("Error: L'arxiu no existeix \n");
  }

  else{
    desc2=open( "copia.fi", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU );  //creant el fitxer on copiarem l'arxiu 
    while (bytes!=0){ //mentres que no arribi al final de l'arxiu continua llegint-lo:
       bytes=read(desc1, contingut, N); //llegeix el contingut de l'arxiu
     
       write(desc2, contingut, bytes); // escriu el contingut de l'arxiu al nou fitxer creat anteriorment
     }
  }
  close(desc1); //tanquem l'arxiu introduit pel teclat
  close(desc2); //tanquem l'arxiu creat
}
