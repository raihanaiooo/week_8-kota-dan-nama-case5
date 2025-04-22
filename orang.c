#include <stdlib.h>
#include <string.h>
#include "orang.h"
#include "kota.h"

extern Kota A[10];
extern int jumlah_kota;
void menuOrang(int index) {
    int pilihan_orang;
    infotype nama_orang, target_nama;
    address prec;

    do {
        printf("\n=== MENU ORANG UNTUK KOTA %s ===\n", A[index].nama);
        printf("1. Tambah di awal\n");
        printf("2. Tambah di akhir\n");
        printf("3. Tambah setelah nama tertentu\n");
        printf("4. Tampilkan daftar orang\n");
        printf("5. Kembali ke menu utama\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan_orang);
        getchar();

        switch (pilihan_orang) {
            case 1:
                printf("Masukkan nama orang: ");
                fgets(nama_orang, sizeof(nama_orang), stdin);
                nama_orang[strcspn(nama_orang, "\n")] = '\0';
                InsertFirst(index, nama_orang);
                break;

            case 2:
                printf("Masukkan nama orang: ");
                fgets(nama_orang, sizeof(nama_orang), stdin);
                nama_orang[strcspn(nama_orang, "\n")] = '\0';
                InsertFirst(index, nama_orang);
                break;

            case 3:
                printf("Masukkan nama orang yang ingin ditambahkan: ");
                fgets(nama_orang, sizeof(nama_orang), stdin);
                nama_orang[strcspn(nama_orang, "\n")] = '\0';
                printf("Setelah nama siapa? ");
                fgets(target_nama, sizeof(target_nama), stdin);
                target_nama[strcspn(target_nama, "\n")] = '\0';
                prec = SearchPrec(index, target_nama);
                if (prec != NULL) {
                    InsertAfter(prec, nama_orang);
                } else {
                    printf("Nama %s tidak ditemukan.\n", target_nama);
                }
                break;

            case 4:
                PrintList(index);
                break;

            case 5:
                printf("Kembali ke menu utama...\n");
                break;

            default:
                printf("Pilihan tidak valid.\n");
        }

    } while (pilihan_orang != 5);
}

void Alokasi(address *a, infotype data) {
    *a = (address)malloc(sizeof(Orang));
    if (*a != NULL) {
        strcpy((*a)->nama, data);
        (*a)->p = NULL;
    }
}

void Dealokasi(address *a) {
    free(*a);
    *a = NULL;
}


