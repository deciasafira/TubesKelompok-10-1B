#include "kalkulatorProgrammer.h"

void decToBiner(){
	int a[10],n,i;
	    
	system("CLS");
	printf("=============== DECIMAL TO BINAIR ===============\n\n");
	printf("Masukan Nilai Decimal Yang Ingin Diubah : ");    
	scanf("%d",&n);    
	for(i=0;n>0;i++){    
		a[i]=n%2;    
		n=n/2;    
	}    
	
	printf("Nilai Binernya = ");    
	for(i=i-1;i>=0;i--){    
		printf("%d",a[i]);    
	}   
	printf("\n");
	system("pause");
}

