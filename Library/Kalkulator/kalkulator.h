#ifndef KALKULATOR_H
#define KALKULATOR_H

#include "../Tree/bintree.h"
#include "../Stack/stackTree.h"
#include "../kalkulatorProgrammer/kalkulatorProgrammer.h"

BinTree BuildExpressionTree(infotypeTree postfix);
/* Membuat sebuah Expression Tree dari ekspresi postfix.	*/
/* I.S   : postfix terdefinisi.								*/
/* F.S   : Expression Tree dikembalikan.					*/

void kalkulatorMenu();
/* Menampilkan menu untuk kalkulator.			*/
/* I.S   : Sembarang.							*/
/* F.S   : Menu untuk kalkulator ditampilkan.	*/

void fiturDatarMenu();
/* Menampilkan menu untuk bangun datar.			*/
/* I.S   : Sembarang.							*/
/* F.S   : Menu untuk bangun datar ditampilkan.	*/

void fiturRuangMenu();
/* Menampilkan menu untuk bangun ruang.			*/
/* I.S   : Sembarang.							*/
/* F.S   : Menu untuk bangun ruang ditampilkan.	*/

void About();
/* Menampilkan informasi mengenai aplikasi dan developer.			*/
/* I.S   : Sembarang.												*/
/* F.S   : Informasi mengenai aplikasi dan developer ditampilkan.	*/

int mainMenu();
/* Menampilkan menu utama aplikasi ini.			*/
/* I.S   : Sembarang.							*/
/* F.S   : Menu utama aplikasi ditampilkan.		*/

#endif
