/* File    : bintree.c 					*/
/* Desk    : Body primitif Binary Tree secara rekursif 	*/
/* Oleh    : ANI RAHMANI / 23501007			*/
/* Tgl	   : 21 / 11 / 2001	  			*/
/* Mod     : Faizal Abdul Hakim */
/* Tgl Mod : 21 /07 / 2021 */

#include "bintree.h"

addressTree AlokasiTree(infotypeTree X) {
	/* Menghasilkan address hasil alokasi Expression Tree	*/
	/* I.S   : X belum dialokasi.							*/
	/* F.S   : Menghasilkan address X yang sudah dialokasi.	*/
	
   	addressTree P;

   	P=(addressTree)malloc(sizeof(ElmtNode));   
	if(P!=Nil) {
		strcpy(Info(P),X);
		Left(P)=Nil;
		Right(P)=Nil;	 
   	}
   	return P;
}

boolean IsEmptyTree(BinTree P) {
	/* Mengembalikan true jika Expression Tree kosong.	*/
	/* I.S   : P terdefinisi.					  		*/
	/* F.S   : P diketahui kosong atau tidaknya.  		*/
	
	return (P==Nil);
}

BinTree GetLeft(BinTree P) { 
	/* Mengembalikan anak kiri Expression Tree.	*/
	/* I.S   : P terdefinisi.				  	*/
	/* F.S   : Anak kiri P dikembalikan.	  	*/

    return Left(P); 	
}

BinTree GetRight(BinTree P) {
	/* Mengembalikan anak kanan Expression Tree.	*/
	/* I.S   : P terdefinisi.				  		*/
	/* F.S   : Anak kanan P dikembalikan.	  		*/
	
    return Right(P);
}

void newNodeTree(BinTree *P, infotypeTree X) {  
	/* Membuat sebuah node Expression Tree baru.	*/
	/* I.S   : P dan X terdefinisi.					*/
	/* F.S   : P berhasil dibuat dengan infotype X.	*/
 
	*P=AlokasiTree(X);
	if(*P!=Nil) {
		strcpy(Info(*P),X);
	    Left(*P)=Right(*P)=Nil;
	} 
} 

void MakeTree(infotypeTree X, BinTree L, BinTree R, BinTree *P) {
	/* Membuat sebuah Expression Tree.								*/
	/* I.S   : P, L, R  dan X terdefinisi.						 	*/
	/* F.S   : Menghasilkan Expression Tree P dengan anak kiri L,
			   anak kanan R dan infotype X.							*/
			   
	*P=AlokasiTree(X);
	if(*P!=Nil) {
		strcpy(Info(*P),X);
	   	Left(*P)=L;
		Right(*P)=R;	
	}
}

void PrintInfoTree(BinTree P) {
	/* Menampilkan semua info dari setiap node pada Expression Tree.	*/
	/* I.S   : Pohon P terdefinisi.										*/
	/* F.S   : Info-info dari setiap node pada pohon P ditampilkan.		*/
	
	BinTree L, R, Px;
	
	if(P != Nil) {
		PrintInfoTree(Left(P)); 
		printf("Info Node\t: %s\n",Info(P));
		if(GetLeft(P)!=Nil) {
			L = GetLeft(P);
			printf("Left Son\t: %s\n",Info(L));
		}
		else {
			printf("Left Son\t: null\n");
		}
		if(GetRight(P)!=Nil) {
			R = GetRight(P);
			printf("Right Son\t: %s\n",Info(R));
		}
		else{
			printf("Right Son\t: null\n");
		}	
		printf("\n");  
		PrintInfoTree(Right(P));
	}
}

float toFloat(String X) {
	/* Melakukan casting terhadap sebuah String menjadi integer,
	   lalu mengembalikannya.										*/
	/* I.S   : X adalah String terdefinisi.							*/
	/* F.S   : Integer hasil casting terhadap X dikirimkan.			*/
	
	return atof(X);
}

boolean isOperator(char c) { 
	/* Mengirimkan true jika karakter yang diperiksa merupakan operator.	*/
	/* I.S   : Karakter yang diperiksa terdefinisi.							*/
	/* F.S   : Karakter yang diperiksa diketahui operator atau bukan.		*/
	 
	return(c=='+' || c=='-' || c=='*' || c=='x' || c=='/' || c ==':' || c =='^');
} 

int Priority(char x) {
	/* Mengembalikan nilai prioritas dari sebuah operator, 
	   nilai berbanding lurus dengan prioritas.				*/
	/* I.S   : X terdefinisi.								*/
	/* F.S   : Nilai prioritas X dikirimkan.				*/
	
		switch(x) {
			case ')': return 0;
			case '(': return 0;
			case '+': return 1;
			case '-': return 1;
			case '*': return 2;
			case 'x': return 2;
			case '/': return 2;
			case ':': return 2;
			case '^': return 3;    
		}
}

boolean isPriority(char a, char b) {
	/* Mengembalikan true jika operator1 memiliki prioritas yang
	   lebih tinggi dibanding operator2.								*/
	/* I.S   : a dan b terdeinisi.										*/
	/* F.S   : Diketahui operator mana yang memiliki prioritas tinggi.	*/
	
    return (Priority(a)>=Priority(b));
}

void InfixToPostfix(String infix, String postfix) {
	/* Mengkonversi ekspresi infix ke postfix.			*/
	/* I.S   : infix terdefinisi.						*/
	/* F.S   : infix berhasil dikonversi ke postfix.	*/
	
    int i, index=0, size;
	char tmpchar;
    stackChar tmp;
    
    createStackChar(&tmp);
	
    size=strlen(infix);
    for(i=0; i<size; i++) {
        switch(infix[i]) {
        	case '.':
            case '0':
            case '1': 
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                postfix[index]=infix[i];
                index++;
                break;
            case '+':
            case '-':
            case '*':
            case 'x':
            case '/':
            case ':':
            case '^':
                postfix[index]=' ';
                index++;        
				// JIka StackChar kosong    
                if(isEmptyStackChar(tmp)){
                    pushStackChar(&tmp,infix[i]);
                }
				// Jika Top StackChar < infix[i]
				else if(!isPriority(Info(Top(tmp)),infix[i])){
                    pushStackChar(&tmp,infix[i]);
                }
				else{
					// Selama StackChar tidak kosong & Top StackChar >= infix[i]
                    while(!isEmptyStackChar(tmp)&&isPriority(Info(Top(tmp)),infix[i])){
                        popStackChar(&tmp,&tmpchar);
                        postfix[index]=tmpchar;
                        index++;
                    }                
                    pushStackChar(&tmp,infix[i]);
                }
                break;
            case ')':
				// Jika StackChar tidak nil & Top != (
                while(!isEmptyStackChar(tmp)&&Info(Top(tmp))!='('){
                    popStackChar(&tmp,&tmpchar);
                    postfix[index]=tmpchar;
                    index++;                    
                }
                popStackChar(&tmp,&tmpchar);
                break;
            case '(':
                pushStackChar(&tmp,infix[i]);
                break;
        }
    }
	// Jika stackchar tidak kosong
    while(!isEmptyStackChar(tmp)) {
        popStackChar(&tmp,&tmpchar);
		// printf("\nini tmpchar = %s", tmpchar);
        postfix[index]=tmpchar;
        index++;                  
    }    
	// tambahkan null diakhir agar aman
    postfix[index]='\0';
}

float CalculateTree(BinTree P) {
	/* Mengembalikan hasil kalkuasi dari Expression Tree.	*/
	/* I.S   : P terdefinisi.								*/
	/* F.S   : Hasil kalkulasi dari P dikembalikan.			*/
	
	int i;
	float tmp=1.0;
	  
    if (IsEmptyTree(P)) {
        return 0;  
	}
    else if (IsEmptyTree(Left(P)) && IsEmptyTree(Right(P))) {
        return toFloat(Info(P));  
    }
  
	// Rekursif inorder
    float left = CalculateTree(Left(P));  
    float right = CalculateTree(Right(P));  
    
    if(strcmp(Info(P),"+")==0) {
		return left+right;
	}
	else if(strcmp(Info(P),"-")==0) {
		return left-right;
	}
	else if(strcmp(Info(P),"*")==0) {
		return left*right;
	}
	else if(strcmp(Info(P),"x")==0) {
		return left*right;
	}
	else if(strcmp(Info(P),"/")==0) {
		if(right!=0.00){
			return left/right;
		}
		else{
			puts ("can't divide by zero");
			return 0;
		}
	}
	else if(strcmp(Info(P),":")==0) {
		if(right!=0.00){
			return left/right;
		}
		else{
			puts ("can't divide by zero");
			return 0;
		}
	}
	for(i=0; i<right; i++) {
		tmp *= left;
	}
	return tmp;
}
