#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10

void selectionsort(int vett[N]){
	int i,pa,ma,pm,temp;
	for(pm=0;pm<N-1;pm++){
    pa=pm; 
    ma=vett[pm];  
    
		for(i=pm+1;i<N;i++){
			if(vett[i]<ma){ 
				ma=vett[i]; 
				pa=i; 
			}
		}
		if(pa!=pm){  
			temp=vett[pm]; 
			vett[pm]=vett[pa]; 
			vett[pa]=temp; 
		}
	}	
}
int main(){
	srand(time(0));
	printf("numeri iniziali:\n\n");
	int vett[N],i;
	for(i=0;i<N;i++){
		vett[i]=rand()%100;
		printf("%d ",vett[i]);
	}	
	selectionsort(vett);
  printf("\nORDINATO:\n\n");
  for(i=0;i<N;i++){
		printf("%d ",vett[i]);
	}	
  
  return 0;
}
