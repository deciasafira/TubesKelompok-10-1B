/* File    : StackChar.c
Author : Caturiani Pratidina Bintari*/
#include "stackChar.h"

/* Mengecek apakah stcakchar penuh dan mengembalikan true jika Stack Char kosong
I.S   : S terdefinisi.					  
F.S   : S diketahui kosong atau tidaknya.  
Algoritma : 
boolean isEmpty(stackChar S)
    if(StackChar.top == 0)
       return 1
    else 
       return 0 */
boolean isEmptyStackChar(stackChar S) {
    return (Top(S)==Nil);
}

/* Membuat sebuah Stack Char kosong							 
I.S   : S belum terdefinisi.									 
F.S   : Menghasilkan Stack Char kosong jika alokasi berhasil. 
Algoritma :
void createStackChar(stackChar *S)
    StackChar.top = 0 */
void createStackChar(stackChar *S) {
    Top(*S)=Nil;
}

/* Mengalokasikan addres StackChar
I.S   : X belum dialokasi.						
F.S   : Menghasilkan address X yang sudah dialokasi 
Algoritma : 
addressStackChar alokasi(infotypeStackChar X)
  	addrStackChar P; //deklarasi
	P = (addrStackChar) malloc(sizeof(elmStackChar))
		if (P!= Nil){
			P->Info = X
			P->Next = Nil
		}
return P */
addressStackChar alokasiStackChar(infotypeStackChar X) {
    addressStackChar P; 
    
    P=(addressStackChar)malloc(sizeof(elmStackChar));
    if(P!=Nil) {
        Info(P)=X;
        Next(P)=Nil;
    }
    return P;
}

/* Membebaskan address P.
I.S   : P sudah dialokasi.
F.S   : P berhasil didealokasi.	
Algoritma :
void dealokasiStackChar(addressStackChar P)
	dealokasi(P)  */
void dealokasiStackChar(addressStackChar P) {
    free(P);
}

/* Menambahkan elemen ke bagian Top Stack Char
I.S   : S terdefinisi.							
F.S   : Elemen X ditambahkan ke bagian Top S.	
Algoritma :
void pushStackChar(stackChar *S, infotypeStackChar X){
	addrStackChar P; //deklarasi
	P = alokasiStackChar(X)
	P -> Next = Top(*S)
	Top(*S) = P
}*/ 
void pushStackChar(stackChar *S, infotypeStackChar X) {

    addressStackChar P; 
    P=alokasiStackChar(X);
    Next(P)=Top(*S);
    Top(*S)=P;
}

/* Menghapus elemen dari bagian Top StackChar.  
I.S   : Top S tidak kosong dan X elemen S.	 
F.S   : Elemen X dihapuskan dari Top S.		 
Algoritma :
void popStackChar (stackChar *S, infotypeStackChar *X){
	addrStackChar P; //deklarasi
	if(!StackChar(*S){ // Jika StackChar ada
		P = Top(*S)
		Top(*S) = P -> next
		*X = P -> Info
		dealokasi(P)
	else
		write(layar) "StackChar Kosong"  */ 
void popStackChar(stackChar *S, infotypeStackChar *X) {
	
    addressStackChar P;
    
    // Jika StackChar ada
    if(!isEmptyStackChar(*S)) {
        P=Top(*S);
        Top(*S)=Next(P);
        *X=Info(P);
        dealokasiStackChar(P);
    }
	else {
        printf("\nStackChar kosong!\n");
    }
}
