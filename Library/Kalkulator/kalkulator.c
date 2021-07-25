#include "kalkulator.h"

BinTree BuildExpressionTree(infotypeTree postfix) {
	//Membuat sebuah Expression Tree dari ekspresi postfix.	
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
	// Menampilkan menu untuk kalkulator
	
	String input, postfix;
	BinTree ex;
	
	system("cls");
	puts("\n\t\t*** Kalkulator ***\n\n");
	printf("||=======||=======||=======||||=======||=======||\n");
	printf("||   1   ||   2   ||   3   ||||  Enter to back ||\n");
	printf("||=======||=======||=======||||=======||=======||\n");
	printf("||   4   ||   5   ||   6   ||||   *   ||   /   ||\n");
	printf("||=======||=======||=======||||=======||=======||\n");
	printf("||   7   ||   8   ||   9   ||||   +   ||   -   ||\n");
	printf("||=======||=======||=======||||=======||=======||\n");
	printf("||   0   ||       =        ||||  DEL  ||   ^   ||\n");
	printf("||=======||=======||=======||||=======||=======||\n\n\n");
	printf("Masukkan Operasi Perhitungan :\n\n"); scanf(" %s",input);
	InfixToPostfix(input, postfix);
	printf("\n");
	ex = BuildExpressionTree(postfix);
	printf("= %.2f\n", CalculateTree(ex)); 
}

void petunjuk(){
	//Menampilkan petunjuk penggunaan aplikasi
	system("CLS");
	printf("\n\t\t\t*** Cara Menggunakan Aplikasi ***\n");
	printf("\n1. Bilangan yang digunakan dalam kalkulator ini adalah bilangan bulat. \n (bilangan negatif, nol, dan bilangan positif) dan bilangan desimal.");
	printf("\n2. Operator yang dapat digunakan :\n");
	printf("\t a) + (pertambahan)\n");
	printf("\t b) - (pengurangan)\n");
	printf("\t c) * atau x (pengkalian)\n");
	printf("\t d) : atau / (pembagian)\n");
	printf("\t e) ^ (perpangkatan)");
	printf("\n3. Dapat menambahkan '(' dan ')' ke dalam operasi perhitungan");
	printf("\n4. Setiap perhitungan akan tersimpan pada riwayat kalkulator.");
	printf("\n5. Setiap perhitungan yang error tidak akan dimasukan pada rekapan.");
	printf("\n6. Riwayat perhitungan hanya dapat dihapus ketika user memilih menu hapus riwayat");
	printf("\n\n");
}

void about(){
	// Menampilkan informasi mengenai aplikasi 
	system("CLS");
	printf("\n\t\t\t*** Tentang Aplikasi ***\n");
	puts("Program aplikasi kalkulator ini dibuat oleh Kelompok Kalkulaten untuk memenuhi salah satu tugas besar");
	puts("Struktur Data dan Algoritma Praktikum. Berikut anggota kalkulaten :\n");
	puts("1. Caturiani Pratidina Bintari");
	puts("2. Decia Safira Alfitri");
	puts("3. Faizal Abdul Hakim");
}

void kalkulatorProgrammerMenu(){
	//fitur aplikasi kalkulator programmer
	bool repeat = true;

	while (repeat)
	{
		system("cls");
		puts("\n\t\t\t*** Kalkulator Programmer***\n");
		puts("1. Konversi Desimal Ke Biner");
		puts("2. Konversi Desimal Ke Oktal");
		puts("3. Konversi Desimal Ke Hexadecimal");
		puts("4. Konversi Biner Ke Desimal");
		puts("5. Konversi Oktal Ke Desimal");
		puts("6. Konversi Hexadecimal Ke Desimal");
		puts("7. Kembali Ke Main Menu\n");
		puts("Masukkan nomor pilihan Anda : ");
		switch (getchar())
		{
		case '1' :
			decToBiner();
			break;
		case '2' :
			decToOctal();
			break;
		case '3' :
			decToHexa();
			break;
		case '4' :
			binerToDec();
			break;
		case '5' :
			octalToDec();
			break;	
		case '6' :
			hexaToDec();
			break;	
		case '7' :
			system("cls");
			repeat = false;
			mainMenu();
			break;
		default :
			puts("\nNomor yang Anda masukkan tidak valid!");
		}
	}

}

int mainMenu() {
	//Menampilkan menu utama aplikasi ini
	
	int i = 0;
	
	while(i<=100) {
		system("COLOR E1");
		puts("\n==================== WELCOME TO KALKULATOR KALKULATEN ===================");
		puts("\n***** MENU *****\n");
		puts("1. Kalkulator");		
		puts("2. Kalkulator Programmer");
		puts("3. Cara Menggunakan Aplikasi");
		puts("4. Tentang");
		puts("5. Exit");
		puts("Masukkan pilihan sesuai nomor : ");
		switch(getchar()) {	
		    case '1' :
		    	kalkulatorMenu();
		    	system("pause");
				break;	
			case '2':
				kalkulatorProgrammerMenu();
				system("pause");
				break;
			case '3'	:
				petunjuk();
				system("pause");
				break;
			case '4' :
				about();
				system("pause");
				break;
			case '5' :
				system("cls");
				puts("\nTerima Kasih. Stay safe and healthy everyone^^. Salam Kalkulaten.");
				return 0;
			default :
				puts("\nNomor yang Anda masukkan tidak valid!");
		}
		system("cls");
	}
}

