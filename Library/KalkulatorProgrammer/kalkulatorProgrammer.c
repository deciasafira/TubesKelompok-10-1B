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
	printf("\n\n");
	system("pause");
}

void decToOctal()
{
    long decimalnum, remainder, quotient;
    int octalNumber[100], i = 1, j;
 
 	system("CLS");
	printf("=============== DECIMAL TO OCTAL ===============\n\n");
    printf("Masukan Nilai Decimal Yang Ingin Diubah : ");
    scanf("%ld", &decimalnum);
    quotient = decimalnum;
    while (quotient != 0)
    {
        octalNumber[i++] = quotient % 8;
        quotient = quotient / 8;
    }
    printf("Nilai Octal = ");
    for (j = i - 1; j > 0; j--)
        printf("%d", octalNumber[j]);
        
    printf("\n\n");
    system("pause");
}

void decToHexa(){
    int d,i;
    char Hexa[50] = {};
    char H[20] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    
    system("CLS");
	printf("=============== DECIMAL TO HEXADECIMAL ===============\n\n");
    printf("Masukan Nilai Decimal Yang Ingin Diubah : ");
    scanf("%d", &d);

    while(d){
        Hexa[i] = H[d % 16];
        d = d / 16;
        i++;
    }
    
    printf("Nilai Hexadecimal nya = ");
    for ( i = strlen(Hexa)-1; i >= 0; i--){
        printf("%c", Hexa[i]);
    }
    
	printf("\n\n");
    system("pause");
}

