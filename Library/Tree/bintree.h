/* File    : bintree.h 	*/
/* Desk    : Deklarasi Binary Tree secara rekursif  	*/
/* Oleh    : ANI RAHMANI / 23501007  			*/
/* Tgl	   : 21 / 11 / 2001	     			*/
/* Mod     : Mohammad Rizky Maulidhan */
/* Tgl Mod : 12 /07 / 2020 */

#ifndef BINTREE_H
#define BINTREE_H

#define Nil NULL
#define Info(P) (P)->info
#define Left(P) (P)->left
#define Right(P) (P)->right
#define Next(P) (P)->next

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../Stack/stackChar.h"
#include "../Boolean/boolean.h"

typedef char String[50];

typedef char infotypeTree[10];
typedef struct tElmtNode *addressTree;
typedef struct tElmtNode {
			infotypeTree info;
			addressTree left;
			addressTree right;
		} ElmtNode;
typedef addressTree BinTree;

addressTree AlokasiTree(infotypeTree X);
/* Menghasilkan address hasil alokasi Expression Tree	*/
/* I.S   : X belum dialokasi.							*/
/* F.S   : Menghasilkan address X yang sudah dialokasi.	*/

boolean IsEmptyTree(BinTree P);
/* Mengembalikan true jika Expression Tree kosong.	*/
/* I.S   : P terdefinisi.					  		*/
/* F.S   : P diketahui kosong atau tidaknya.  		*/

BinTree GetLeft(BinTree P);
/* Mengembalikan anak kiri Expression Tree.	*/
/* I.S   : P terdefinisi.				  	*/
/* F.S   : Anak kiri P dikembalikan.	  	*/

BinTree GetRight(BinTree P);
/* Mengembalikan anak kanan Expression Tree.	*/
/* I.S   : P terdefinisi.				  		*/
/* F.S   : Anak kanan P dikembalikan.	  		*/

void newNode(BinTree *P, infotypeTree X);
/* Membuat sebuah node Expression Tree baru.	*/
/* I.S   : P dan X terdefinisi.					*/
/* F.S   : P berhasil dibuat dengan infotype X.	*/

void newNodeTree(BinTree *P, infotypeTree X);
	/* Membuat sebuah node Expression Tree baru.	*/
	/* I.S   : P dan X terdefinisi.					*/
	/* F.S   : P berhasil dibuat dengan infotype X.	*/

void MakeTree(infotypeTree X, BinTree L, BinTree R, BinTree *P);
/* Membuat sebuah Expression Tree.								*/
/* I.S   : P, L, R  dan X terdefinisi.						 	*/
/* F.S   : Menghasilkan Expression Tree P dengan anak kiri L,
		   anak kanan R dan infotype X.							*/

void PrintInfoTree(BinTree P);
/* Menampilkan semua info dari setiap node pada Expression Tree.	*/
/* I.S   : Pohon P terdefinisi.										*/
/* F.S   : Info-info dari setiap node pada pohon P ditampilkan.		*/

float toFloat(String X);
/* Melakukan casting terhadap sebuah String menjadi integer,
   lalu mengembalikannya.										*/
/* I.S   : X adalah String terdefinisi.							*/
/* F.S   : Integer hasil casting terhadap X dikirimkan.			*/

boolean isOperator(char c);
/* Mengembalikan true jika karakter yang diperiksa merupakan operator.	*/
/* I.S   : Karakter yang diperiksa terdefinisi.							*/
/* F.S   : Karakter yang diperiksa diketahui operator atau bukan.		*/ 

int Priority(char x);
/* Mengembalikan nilai prioritas dari sebuah operator, 
   nilai berbanding lurus dengan prioritas.				*/
/* I.S   : X terdefinisi.								*/
/* F.S   : Nilai prioritas X dikirimkan.				*/

boolean isPriority(char a, char b);
/* Mengembalikan true jika operator1 memiliki prioritas yang
   lebih tinggi dibanding operator2.								*/
/* I.S   : a dan b terdeinisi.										*/
/* F.S   : Diketahui operator mana yang memiliki prioritas tinggi.	*/

void InfixToPostfix(String infix, String postfix);
/* Mengkonversi ekspresi infix ke postfix.			*/
/* I.S   : infix terdefinisi.						*/
/* F.S   : infix berhasil dikonversi ke postfix.	*/

float CalculateTree(BinTree P);
/* Mengembalikan hasil kalkuasi dari Expression Tree.	*/
/* I.S   : P terdefinisi.								*/
/* F.S   : Hasil kalkulasi dari P dikembalikan.			*/


#endif
