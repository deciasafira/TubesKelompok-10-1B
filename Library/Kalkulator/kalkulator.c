#include "kalkulator.h"

BinTree BuildExpressionTree(infotypeTree postfix) {
	/* Membuat sebuah Expression Tree dari ekspresi postfix.	*/
	/* I.S   : postfix terdefinisi.								*/
	/* F.S   : Expression Tree dikembalikan.					*/
	
	int i=0, j, k; 
	stackTree StackT; //
	BinTree ExpTree, Right, Left;
	infotypeStackTree emptyDel;
	infotypeTree tempOpr, tempStr;
 	
 	createStackTree(&StackT);
 	
	while (i<strlen(postfix)) {
		// Jika bukan operator dan spasi
		// untuk bilangan puluhan dan seterusnya
		if (!isOperator(postfix[i]) && postfix[i]!=' ') {
			j=0;
			tempStr[j]=postfix[i];
			while(!isOperator(postfix[i+1]) && postfix[i+1]!=' ') {
				tempStr[j+1]=postfix[i+1];
				j++;
				i++;
			}
			newNodeTree(&ExpTree, tempStr);
			// reset tempStr
			for(k=0; k<strlen(tempStr); k++) {
				tempStr[k]=' ';
			}
			pushStackTree(&StackT, ExpTree);
		} 
		else if(postfix[i]=='-' && isOperator(postfix[i-4])) { 
			tempOpr[0]=postfix[i];
			newNodeTree(&ExpTree, tempOpr);
		
			Right = Info(Top(StackT));
			popStackTree(&StackT, &emptyDel);
							 
			Left = Info(Top(StackT));
			popStackTree(&StackT, &emptyDel);
			
			MakeTree(tempOpr, Left, Right, &ExpTree);
			
			pushStackTree(&StackT, ExpTree); 
		} 
		else if((postfix[i]=='-' && postfix[i-1]==' ' && postfix[i+1]!=' ' && postfix[i+2]!=' ' && !isOperator(postfix[i+2])) || 
				(postfix[i]=='-' && postfix[i-1]!=' ' && postfix[i+1]==' ') || 
				(postfix[i]=='-' && postfix[i-1]!=' ' && isOperator(postfix[i+1])) ||
				(postfix[i]=='-' && postfix[i-1]==' ' && postfix[i+1]==' ') ||
				(postfix[i]=='-' && postfix[i-1]==' ' && postfix[i+1]!=' ' && isOperator(postfix[i+2])) ||
				(postfix[i]=='-' && postfix[i-1]!=' ' && isOperator(postfix[i+1]) && isOperator(postfix[i+2]) )) { 
			tempOpr[0]=postfix[i];
			newNodeTree(&ExpTree, tempOpr);
		
			Right = Info(Top(StackT));
			popStackTree(&StackT, &emptyDel);
							 
			newNodeTree(&Left, "0");
			
			MakeTree(tempOpr, Left, Right, &ExpTree);
			
			pushStackTree(&StackT, ExpTree); 
		}
		// untuk operator
		else if(postfix[i]!=' ') { 
			tempOpr[0]=postfix[i];
			newNodeTree(&ExpTree, tempOpr);
		
			Right = Info(Top(StackT));
			popStackTree(&StackT, &emptyDel);
							 
			Left = Info(Top(StackT));
			popStackTree(&StackT, &emptyDel);
			
			MakeTree(tempOpr, Left, Right, &ExpTree);
			
			pushStackTree(&StackT, ExpTree); 
		} 
		i++;
	} 
	ExpTree = Info(Top(StackT)); 
	popStackTree(&StackT, &ExpTree); 
	return ExpTree; 
}

void kalkulatorMenu() {
	/* Menampilkan menu untuk kalkulator.			*/
	/* I.S   : Sembarang.							*/
	/* F.S   : Menu untuk kalkulator ditampilkan.	*/
	
	String input, postfix;
	BinTree ex;
	
	system("cls");
	//system("MODE 69,20");
	puts("\n\t\t\t# KALKULATOR #\n");
	printf("PETUNJUK : ");
	printf("\n1. Gunakan simbol '^' --> melakukan operasi perpangkatan.");
	printf("\n2. Gunakan simbol '*' atau 'x' --> melakukan operasi perkalian.");
	printf("\n3. Gunakan simbol ':' atau '/' --> melakukan operasi pembagian.");
	printf("\n4. Gunakan simbol '+' --> melakukan operasi penjumlahan.");
	printf("\n5. Gunakan simbol '-' --> melakukan operasi pengurangan.");
	printf("\n6. Dapat menambahkan '(' dan ')' ke dalam operasi perhitungan.");
	printf("\n7. Bilangan yang digunakan dalam operasi perhitungan adalah bilangan bulat \n (bilangan negatif, nol, dan bilangan positif) dan bilangan desimal.");
	printf("\n\n");
	system("PAUSE");
	system("cls");
	puts("\n\t\t\t# KALKULATOR #\n");
	printf("LAKUKAN PERHITUNGAN :\n\n"); scanf(" %s",input);
	InfixToPostfix(input, postfix);
	printf("\n");
	ex = BuildExpressionTree(postfix);
	printf("= %.2f\n", CalculateTree(ex)); 
}

void about(){
	system("CLS");
	printf("Tentang Aplikasi\n");
	puts("1. \n");
	puts("2. \n");
	puts("3. \n");
}

int mainMenu() {
	/* Menampilkan menu utama aplikasi ini.			*/
	/* I.S   : Sembarang.							*/
	/* F.S   : Menu utama aplikasi ditampilkan.		*/
	
	int i;
	
	while(i<=100) {
		//system("MODE 57,20");
		puts("\n=`=`=`=`=`=`=`=`=` APLIKASI KALULATOR `=`=`=`=`=`=`=`=`=");
		puts("\n*** MAIN MENU ***\n");
		puts("1. Kalkulator");
		puts("2. About");
		puts("3. Exit");
		puts("Masukkan pilihan sesuai nomor : ");
		switch(getchar()) {	
		    case '1' :
		    	kalkulatorMenu();
				break;		
			case '2' :
				about();
				break;
			case '3' :
				system("cls");
				puts("\nTerima Kasih");
				return 0;
			default :
				puts("\nNomor yang Anda masukkan tidak valid!");
		}
		printf("\n");
		system("PAUSE");
		system("cls");
	}
}
