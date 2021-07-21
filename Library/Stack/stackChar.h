#ifndef STACK_CHAR_H
#define STACK_CHAR_H

#define Nil NULL
#define Info(P) (P)->info
#define Next(P) (P)->next
#define Top(S)  ((S).top)

#include<stdio.h>
#include<stdlib.h>
#include "../Boolean/boolean.h"

typedef char infotypeStackChar;
typedef struct tElmSC *addressStackChar;

typedef struct tElmSC{
    infotypeStackChar info;
    addressStackChar next;
}elmStackChar;

typedef struct{
    addressStackChar top;
}stackChar;

boolean isEmptyStackChar(stackChar S);
/* Mengembalikan true jika Stack Char kosong. */
/* I.S   : S terdefinisi.					  */
/* F.S   : S diketahui kosong atau tidaknya.  */

void createStackChar(stackChar *S);
/* Membuat sebuah Stack Char kosong.							 */
/* I.S   : S belum terdefinisi.									 */
/* F.S   : Menghasilkan Stack Char kosong jika alokasi berhasil. */

addressStackChar alokasiStackChar(infotypeStackChar X);
/* Menghasilkan address hasil alokasi Stack Char.		*/
/* I.S   : X belum dialokasi.							*/
/* F.S   : Menghasilkan address X yang sudah dialokasi.	*/

void dealokasiStackChar(addressStackChar P);
/* Membebaskan address P.			*/
/* I.S   : P sudah dialokasi.		*/
/* F.S   : P berhasil didealokasi.	*/

void pushStackChar(stackChar *S, infotypeStackChar X);
/* Melakukan push elemen ke bagian Top Stack Char.	*/
/* I.S   : S terdefinisi.							*/
/* F.S   : Elemen X ditambahkan ke bagian Top S.	*/ 

void popStackChar(stackChar *S, infotypeStackChar *X);
/* Menghapus elemen dari bagian Top Stack Char.  */
/* I.S   : Top S tidak kosong dan X elemen S.	 */
/* F.S   : Elemen X dihapuskan dari Top S.		 */ 

#endif
