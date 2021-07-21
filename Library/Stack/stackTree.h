#ifndef STACK_TREE_H
#define STACK_TREE_H

#define Nil NULL
#define Info(P) (P)->info
#define Next(P) (P)->next
#define Top(S)  ((S).top)

#include<stdio.h>
#include<stdlib.h>
#include "../Tree/bintree.h"

typedef BinTree infotypeStackTree;
typedef struct tElmST *addressStackTree;
typedef struct tElmST{
    infotypeStackTree info;
    addressStackTree next;
}elmStackTree;
typedef struct{
    addressStackTree top;
}stackTree;

boolean isEmptyStackTree(stackTree S);
/* Mengembalikan true jika Stack Tree kosong.	*/
/* I.S   : S terdefinisi.					 	*/
/* F.S   : S diketahui kosong atau tidaknya. 	*/

void createStackTree(stackTree *S);
/* Membuat sebuah Stack Tree kosong.								*/
/* I.S   : S belum terdefinisi.										*/
/* F.S   : Menghasilkan Stack Tree kosong jika alokasi berhasil.	*/

addressStackTree alokasiStackTree(infotypeStackTree X);
/* Menghasilkan address hasil alokasi Stack Tree.		 */
/* I.S   : X belum dialokasi.							 */
/* F.S   : Menghasilkan address X yang sudah dialokasi.	 */

void dealokasiStackTree(addressStackTree P);
/* Membebaskan address P.			*/
/* I.S   : P sudah dialokasi.		*/
/* F.S   : P berhasil didealokasi.	*/

void pushStackTree(stackTree *S, infotypeStackTree X);
/* Melakukan push elemen ke bagian Top Stack Tree.	*/
/* I.S   : S terdefinisi.							*/
/* F.S   : Elemen X ditambahkan ke bagian Top S.	*/ 

void popStackTree(stackTree *S, infotypeStackTree *X);
/* Menghapus elemen dari bagian Top Stack Tree.	 */
/* I.S   : Top S tidak kosong dan X elemen S.	 */
/* F.S   : Elemen X dihapuskan dari Top S.		 */ 

#endif
