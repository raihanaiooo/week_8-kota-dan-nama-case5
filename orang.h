#ifndef ORANG_H
#define ORANG_H

#include <stdio.h>

typedef char infotype[100];
typedef struct orang *address;
typedef struct orang {
    infotype nama;
    address p;
} Orang;
typedef address List;

void menuOrang(int index);
void Alokasi(address *a, infotype data);
void Dealokasi(address *a);
#endif