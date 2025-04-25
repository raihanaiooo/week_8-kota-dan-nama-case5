#ifndef KOTA_H
#define KOTA_H

#include "orang.h"

typedef struct {
    infotype nama;
    Orang *q;
} Kota;

extern Kota *A;
extern int jumlah_kota;
extern int kapasitas_kota;

void entryKota(infotype nama_kota);
void deleteKota(infotype nama_kota);
void tampilkanKota();
void PrintList(int index);
void InsertAfter(address prec, infotype namaOrang);
address SearchPrec(int index, infotype namaOrang);
void InsertLast(int index, infotype namaOrang);
void InsertFirst(int index, infotype namaOrang);
void inisialisasiKota();
void realokasiKota();

#endif
