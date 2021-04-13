#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#define VUOTO 0
#define ROSSO 1
#define GIALLO 2
#define PAREGGIO 0
#define NON_TERMINATA -1

#define R 6
#define C 7

/*
  SEPARIAMO CIO' CHE CONTIENE LA MATRICE DA 
  CIO' CHE VIENE STAMPATO A VIDEO
*/

//svuotare il campo
void svuotaCampo(int campo[R][C]){
  int r;
  int c;
  
  for(c=0;c<C;c++){    
    for(r=0;r<R;r++){
      //Nella cella r-c ci metto VUOTO
      campo[r][c] = VUOTO;
    }
  }
}

//stampare il campo
void stampaCampo(int campo[R][C]){
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int colore;
  int i, r, c;
  for(i = 0; i < C*2+2; i++){
  		if(i==0){
  			printf("%c",201);
		  }
		  else if(i==(C*2+1)){
		  	printf("%c",187);
		  }
		  else{
		  	printf("%c",205);
		  }
  }
  
  printf("\n");
  
  for(r = 0; r < R; r++){
    
    for(c = -1; c < C+1; c++){
		if(c==C){
			printf("%c",186);
		}
		else if(c==-1){
			printf("%c",186);
		}
		else{
	    if(campo[r][c] == ROSSO){
	    colore=7;
	    SetConsoleTextAttribute(hConsole, colore);
        printf("%c",186);
	    colore=4;
	    SetConsoleTextAttribute(hConsole, colore);
		printf("O"); 
	    colore=7;
	    SetConsoleTextAttribute(hConsole, colore);	   
	       
      } 
	  else if(campo[r][c] == GIALLO) {
	    colore=7;
	    SetConsoleTextAttribute(hConsole, colore);	  	
        printf("%c",186);
	    colore=6;
	    SetConsoleTextAttribute(hConsole, colore);    
		printf("O");
	    colore=7;
	    SetConsoleTextAttribute(hConsole, colore);	 
	 		
      } 
	  else {
	  	colore=7;
	  	SetConsoleTextAttribute(hConsole, colore);
        printf("%c",186);
 	  	colore=8;
	  	SetConsoleTextAttribute(hConsole, colore); 
		printf("O");
	    colore=7;
	    SetConsoleTextAttribute(hConsole, colore);			        
      }		
	}
	
 } 
    
    printf("\n");
    for(i = 0; i < C*2+2; i++){
    	if(i==0){
    		printf("%c",186);
		}
		else if(i==(C*2+1)){
			printf("%c",185);
		}	
		else{
			 printf("%c",205);
		}
    }
    printf("\n");
  }
}

/*Controllo se il giocatore di un certo colore (ROSSO/GIALLO) ha messo in fila orizzontalmente 4 gettoni*/
int controlloFilaOrizzontale(int campo[R][C]){
  int r,c;
  for(r=0;r<R;r++){
  	for(c=0;c<C-3;c++){
  		if(campo[r][c]!=VUOTO){
  			if(campo[r][c]==GIALLO && campo[r][c+1]==GIALLO && campo[r][c+2]==GIALLO && campo[r][c+3]==GIALLO){
  				 return 2;
			  }
			 if(campo[r][c]==ROSSO && campo[r][c+1]==ROSSO && campo[r][c+2]==ROSSO && campo[r][c+3]==ROSSO){
				 return 1;
			}  
		  }
	  }
  }
    for(r=0;r<R;r++){
  	for(c=0;c<C;c++){
  		if(campo[r][c]==VUOTO){
  			return -1;
		  }
	  }
   } 
  return 0;
  }



/*Controllo se il giocatore di un certo colore (ROSSO/GIALLO) ha messo in fila verticalmente 4 gettoni*/
int controlloFilaVerticale(int campo[R][C]){
   int r,c;
  for(r=0;r<R-3;r++){
  	for(c=0;c<C;c++){
  		if(campo[r][c]!=VUOTO){
 			if(campo[r][c]==GIALLO && campo[r+1][c]==GIALLO && campo[r+2][c]==GIALLO && campo[r+3][c]==GIALLO){
  				return 2;
			}
			 if(campo[r][c]==ROSSO && campo[r+1][c]==ROSSO && campo[r+2][c]==ROSSO && campo[r+3][c]==ROSSO){
				 return 1;
			}   			
		  }
  		}
	}
  for(r=0;r<R;r++){
  	for(c=0;c<C;c++){
  		if(campo[r][c]==VUOTO){
  			return -1;
		  }
	  }
   } 
  return 0;
}

/*Controllo se il giocatore di un certo colore (ROSSO/GIALLO) ha messo in fila diagonalmente '/' 4 gettoni*/
int controlloFilaDiagonale1(int campo[R][C]){
	int r,c;
  	for(r=R;r>3;r--){
  		for(c=0;c<C-3;c++){
  			if(campo[r][c]!=VUOTO){
 				if(campo[r][c]==GIALLO && campo[r-1][c+1]==GIALLO && campo[r-2][c+2]==GIALLO && campo[r-3][c+3]==GIALLO){
					return 2;
 				}
				if(campo[r][c]==ROSSO && campo[r-1][c+1]==ROSSO && campo[r-2][c+2]==ROSSO  && campo[r-3][c+3]==ROSSO ){
					return 1;
 				} 				
			}   			
		}
  	}
  for(r=0;r<R;r++){
  	for(c=0;c<C;c++){
  		if(campo[r][c]==VUOTO){
  			return -1;
		  }
	  }
   } 
  return 0; 		
  
}



/*Controllo se il giocatore di un certo colore (ROSSO/GIALLO) ha messo in fila diagonalmente '\' 4 gettoni*/
int controlloFilaDiagonale2(int campo[R][C]){
  	int r,c;
  	for(r=0;r<R-3;r++){
  		for(c=0;c<C-3;c++){
  			if(campo[r][c]!=VUOTO){
 				if(campo[r][c]==GIALLO && campo[r+1][c+1]==GIALLO && campo[r+2][c+2]==GIALLO && campo[r+3][c+3]==GIALLO){
					return 2;
 				}
				if(campo[r][c]==ROSSO && campo[r+1][c+1]==ROSSO && campo[r+2][c+2]==ROSSO  && campo[r+3][c+3]==ROSSO ){
					return 1;
 				} 				
			}   			
		}
  	}
  for(r=0;r<R;r++){
  	for(c=0;c<C;c++){
  		if(campo[r][c]==VUOTO){
  			return -1;
		  }
	  }
   } 
  return 0; 	
}

int chiediposizione(int campo[R][C],int numerogiocatore){
	int scelta;
	int r;
	if(numerogiocatore==ROSSO){
		printf("\n scegli su quale colonna mettere il gettone, ROSSO");
	}
	else{
		printf("\n scegli su quale colonna mettere il gettone, GIALLO");
	}
	do{
		printf("\n da 1 a 7\n");
		scanf("%d",&scelta);
	}while(scelta<1 || scelta>7);
	scelta--;
	if(campo[0][scelta]!=0){
		printf("\nquesta mossa e stata inutile");
		getch();
	}
	return scelta;
}

void inseriscigettone(int campo[R][C],int colonnascelta,int numerogiocatore){
	int r;
	int fatto;
	fatto=0;
	if(campo[R-1][colonnascelta]==0){
		campo[R-1][colonnascelta]=numerogiocatore;
	}
	else{
		for(r=0;fatto==0;r++){
			if(campo[r][colonnascelta]==VUOTO && campo[r+1][colonnascelta]!=VUOTO){
				campo[r][colonnascelta]=numerogiocatore;
				fatto=1;
			}
		}		
	}
}
																

int controlloVittoria(int campo[R][C]){
  //1. Controllo se il campo ? riempito oppure no
  //2. Controllo chi ha vinto
    //2.1 controllo se ha vinto in orizzontale
    int control_orizzontale;
	control_orizzontale=controlloFilaOrizzontale(campo);
	if(control_orizzontale==ROSSO){
		return 1;
	}
	else if(control_orizzontale==GIALLO){
		return 2;
	}
    //2.2 controllo se ha vinto in verticale
    int control_verticale;
    control_verticale=controlloFilaVerticale(campo);
    if(control_verticale==ROSSO){
    	return 1;
	}
	else if(control_verticale==GIALLO){
		return 2;
	}
    //2.3 controllo se ha vinto in diagonale 
    int diag1 = controlloFilaDiagonale1(campo);
    if(diag1==ROSSO){
    	return 1;
	}
	else if(diag1==GIALLO){
		return 2;
	}
    //2.4 controllo se ha vinto in diagonale 
    int diag2 = controlloFilaDiagonale2(campo);
    if(diag2==ROSSO){
    	return 1;
	}
	else if(diag2==GIALLO){
		return 2;
	}
  //4. Fornisco il risultato finale
    if(control_verticale==-1 || control_orizzontale==-1 || diag1==-1 || diag2==-1){
    	return -1;
	}
	return 0;
}

 main(){
int campo[R][C];
	int numerogiocatore = ROSSO; //il numero di giocatore
  	svuotaCampo(campo);//per svuotare il campo di gioco
  	int finepartita = NON_TERMINATA;
  	printf(" BENVENUTO A FORZA 4!");
  	printf("\n premi un tasto qualsiasi per continuare\n");
  	getch();
  while(finepartita==NON_TERMINATA){
  	system("cls");
  	stampaCampo(campo);//stampare il campo
  	int colonnascelta = chiediposizione(campo,numerogiocatore);	
  	inseriscigettone(campo,colonnascelta,numerogiocatore); 		
  	finepartita = controlloVittoria(campo);
  	numerogiocatore++;
  	if(numerogiocatore>2){
		numerogiocatore = ROSSO;
  	}	
  }
  system("cls");
  stampaCampo(campo);
  switch(finepartita){
		case ROSSO:{
			printf("IL ROSSO HA VINTO");
			break;
		}
		case GIALLO:{
			printf("IL GIALLO HA VINTO");
			break;
		}
		case PAREGGIO:{
			printf("PAREGGIO");
			break;
		}
  }

}
