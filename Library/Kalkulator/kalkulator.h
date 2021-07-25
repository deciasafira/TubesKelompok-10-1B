#ifndef KALKULATOR_H
#define KALKULATOR_H

#include "../Tree/bintree.h"
#include "../Stack/stackTree.h"
#include "../kalkulatorProgrammer/kalkulatorProgrammer.h"

// Membuat sebuah Expression Tree dari ekspresi postfix.
BinTree BuildExpressionTree(infotypeTree postfix);


//Menampilkan menu untuk kalkulator.
void kalkulatorMenu();

//Menampilkan petunjuk penggunaan aplikasi
void petunjuk();

// Menampilkan informasi mengenai aplikasi 
void About();

//Menu utama kalkulator
int mainMenu();

#endif
