#include <stdio.h>
#include<time.h>
#define N 10

int partition(int vet[N],int start,int stop){
	int pivot=vet[stop];						//in questo quicksort il pivot sarà alla fine
	int i=start;
	int e=stop-1;
	int scambio;
	while(i<e){
		while(vet[i]<pivot&&i<e){
			i++;
		}
		while(vet[e]>=pivot&&i<e){
			e--;
		}
		scambio=vet[i];
		vet[i]=vet[e];
		vet[e]=scambio;
		//scambio (vet[i],vet[e]
	}
	scambio=vet[i];
	vet[i]=vet[stop];
	vet[stop]=scambio;
	//scambio(vett[i],vet[stop]
	return i;
}

void quicksort(int vet[N],int start,int stop){
	if(start>=stop){
		return;
	} else{
	int pivot_pos=partition(vet,start,stop);
	quicksort(vet,start,pivot_pos-1);
	quicksort(vet,pivot_pos+1,stop);
	}
}

main(){
	srand(time(0));
	int vett[N],i;
	for(i=0;i<N;i++){
		vett[i]=rand()%100;
		printf(" %d",vett[i]);
	}
	int start=0;
	int stop=N-1;
	quicksort(vett,start,stop);
	printf("\n");
	for(i=0;i<N;i++){
		printf(" %d",vett[i]);
	}	
}
