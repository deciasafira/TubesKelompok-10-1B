#include "kalkulatorProgrammer.h"

void decToBiner(){
	int a[10],n,i;
	    
	system("CLS");
	printf("\n  *** Decimal To Biner ***\n\n");
	printf("||=======||=======||=======||\n");
	printf("||   1   ||   2   ||   3   ||\n");
	printf("||=======||=======||=======||\n");
	printf("||   4   ||   5   ||   6   ||\n");
	printf("||=======||=======||=======||\n");
	printf("||   7   ||   8   ||   9   ||\n");
	printf("||=======||=======||=======||\n");
	printf("||   0   ||     BINER      ||\n");
	printf("||=======||=======||=======||\n\n\n");
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
	printf("\n  *** Decimal To Octal ***\n\n");
	printf("||=======||=======||=======||\n");
	printf("||   1   ||   2   ||   3   ||\n");
	printf("||=======||=======||=======||\n");
	printf("||   4   ||   5   ||   6   ||\n");
	printf("||=======||=======||=======||\n");
	printf("||   7   ||   8   ||   9   ||\n");
	printf("||=======||=======||=======||\n");
	printf("||   0   ||     OCTAL      ||\n");
	printf("||=======||=======||=======||\n\n\n");
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
	printf("\n  *** Decimal To Hexadecimal ***\n\n");
	printf("||=======||=======||=======||\n");
	printf("||   1   ||   2   ||   3   ||\n");
	printf("||=======||=======||=======||\n");
	printf("||   4   ||   5   ||   6   ||\n");
	printf("||=======||=======||=======||\n");
	printf("||   7   ||   8   ||   9   ||\n");
	printf("||=======||=======||=======||\n");
	printf("||   0   ||      HEXA      ||\n");
	printf("||=======||=======||=======||\n\n\n");
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

void binerToDec(){
	 // declaration of variables  
    int num, binary_num, decimal_num = 0, base = 1, rem;  
    
    system("CLS");
	printf("\n  *** Biner To Decimal***\n\n");
	printf("||========== || ===========||\n");
	printf("||     0     ||      1     ||\n");
	printf("||========== || ===========||\n");
	printf("||         DECIMAL         ||\n");
	printf("||========== || ===========||\n\n\n");
    printf("Masukan kombinasi number 0 dan 1 Yang Ingin Diubah : ");
    scanf ("%d", &num); // accept the binary number (0s and 1s)  
  
    binary_num = num; // assign the binary number to the binary_num variable  
      
      
    while ( num > 0)  
    {  
        rem = num % 10; /* divide the binary number by 10 and store the remainder in rem variable. */  
        decimal_num = decimal_num + rem * base;  
        num = num / 10; // divide the number with quotient  
        base = base * 2;  
    }  
  
    printf ("\nNilai Desimal nya = %d \t", decimal_num); // print the decimal   
    printf("\n\n");
    system("pause");
    
}

void octalToDec(){
	long int octal, decimal = 0;
    int i = 0;
 
    system("CLS");
	printf("\n  *** Octal To Decimal ***\n\n");
	printf("||=======||=======||=======||\n");
	printf("||   1   ||   2   ||   3   ||\n");
	printf("||=======||=======||=======||\n");
	printf("||   4   ||   5   ||   6   ||\n");
	printf("||=======||=======||=======||\n");
	printf("||   7   ||   8   ||   9   ||\n");
	printf("||=======||=======||=======||\n");
	printf("||   0   ||     DECIMAL    ||\n");
	printf("||=======||=======||=======||\n\n\n");
    printf("Masukan kombinasi number 0 sampai 7 Yang Ingin Diubah : ");
    scanf("%ld", &octal);
    while (octal != 0)
    {
        decimal =  decimal +(octal % 10)* pow(8, i++);
        octal = octal / 10;
    }
    printf("\nNilai desimalnya = %ld",decimal);
    
    printf("\n\n");
    system("pause");
}

void hexaToDec(){
	char hex[20];
    long long decimal = 0, base = 1;
    int i = 0, value, length;
    /* Get hexadecimal value from user */
    system("CLS");
	printf(" *** Hexadecimal To Decimal ***\n\n\n");
	printf("||=======||=======||=======||\n");
	printf("||   1   ||   2   ||   3   ||\n");
	printf("||=======||=======||=======||\n");
	printf("||   4   ||   5   ||   6   ||\n");
	printf("||=======||=======||=======||\n");
	printf("||   7   ||   8   ||   9   ||\n");
	printf("||=======||=======||=======||\n");
	printf("||   0   ||     DECIMAL    ||\n");
	printf("||=======||=======||=======||\n\n\n");
	printf("HEXADECIMAL NUMBER   = 0,1,2,3,4,5,6,7,8,9\n");
	printf("HEXADECIMAL ALPHABET = A, B, C, D, E, F\n\n");
    printf("Masukan kombinasi number hexa Yang Ingin Diubah : ");
    fflush(stdin);
    fgets(hex,20,stdin);
    length = strlen(hex);
    for(i = length--; i >= 0; i--)
    {
        if(hex[i] >= '0' && hex[i] <= '9')
        {
            decimal += (hex[i] - 48) * base;
            base *= 16;
        }
        else if(hex[i] >= 'A' && hex[i] <= 'F')
        {
            decimal += (hex[i] - 55) * base;
            base *= 16;
        }
        else if(hex[i] >= 'a' && hex[i] <= 'f')
        {
            decimal += (hex[i] - 87) * base;
            base *= 16;
        }
    }
    printf("\nNilai Desimal nya = %lld\n", decimal);
    
    printf("\n\n");
    system("pause");
}

void sumBiner(){
	long binary1, binary2;
    int i = 0, remainder = 0, sum[20];
 
    printf("Enter the first binary number: ");
    scanf("%ld", &binary1);
    printf("Enter the second binary number: ");
    scanf("%ld", &binary2);
    while (binary1 != 0 || binary2 != 0)
    {
        sum[i++] =(binary1 % 10 + binary2 % 10 + remainder) % 2;
        remainder =(binary1 % 10 + binary2 % 10 + remainder) / 2;
        binary1 = binary1 / 10;
        binary2 = binary2 / 10;
    }
    if (remainder != 0)
        sum[i++] = remainder;
    --i;
    printf("Sum of two binary numbers: ");
    while (i >= 0)
        printf("%d", sum[i--]);
}

