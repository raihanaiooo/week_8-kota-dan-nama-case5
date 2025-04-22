#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "kota.h"
#include "orang.h"

extern Kota A[10];
extern int jumlah_kota;

int main() {
    int pilihan;
    infotype nama_kota, nama_orang;

    // Input minimal 5 kota dulu
    printf("=== INPUT MINIMAL 5 KOTA TERLEBIH DAHULU ===\n");
    while (jumlah_kota < 5) {
        printf("\nMasukkan nama kota ke-%d: ", jumlah_kota + 1);
        fgets(nama_kota, sizeof(nama_kota), stdin);
        nama_kota[strcspn(nama_kota, "\n")] = '\0';
        entryKota(nama_kota);
    }

    // Menu utama setelah minimal 5 kota diinput
    while (1) {
        printf("\n=== MENU UTAMA ===\n");
        printf("1. Tambah Kota\n");
        printf("2. Hapus Kota\n");
        printf("3. Tampilkan Semua Kota\n");
        printf("4. Kelola Orang dalam Kota\n");
        printf("5. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);
        getchar();

        switch (pilihan) {
            case 1: {
                if (jumlah_kota >= 10) {
                    printf("Jumlah maksimal kota telah tercapai!\n");
                    break;
                }

                printf("Masukkan nama kota: ");
                fgets(nama_kota, sizeof(nama_kota), stdin);
                nama_kota[strcspn(nama_kota, "\n")] = '\0';
                entryKota(nama_kota);

                int index = jumlah_kota - 1;
                int opsi_orang;
                do {
                    printf("Masukkan nama orang: ");
                    fgets(nama_orang, sizeof(nama_orang), stdin);
                    nama_orang[strcspn(nama_orang, "\n")] = '\0';
                    InsertLast(index, nama_orang);

                    printf("Tambah orang lagi? (1 = Ya, 0 = Kembali ke menu kota): ");
                    scanf("%d", &opsi_orang);
                    getchar();
                } while (opsi_orang == 1);

                break;
            }

            case 2: {
                printf("Masukkan nama kota yang ingin dihapus: ");
                fgets(nama_kota, sizeof(nama_kota), stdin);
                nama_kota[strcspn(nama_kota, "\n")] = '\0';
                deleteKota(nama_kota);
                break;
            }

            case 3:
                tampilkanKota();
                break;

            case 4: {
                printf("Masukkan nama kota yang ingin dikelola: ");
                fgets(nama_kota, sizeof(nama_kota), stdin);
                nama_kota[strcspn(nama_kota, "\n")] = '\0';

                int index = -1;
                for (int i = 0; i < jumlah_kota; i++) {
                    if (strcmp(A[i].nama, nama_kota) == 0) {
                        index = i;
                        break;
                    }
                }

                if (index != -1) {
                    menuOrang(index);
                } else {
                    printf("Kota tidak ditemukan.\n");
                }

                break;
            }

            case 5:
                printf("Terima kasih. Program selesai.\n");
                exit(0);

            default:
                printf("Pilihan tidak valid.\n");
        }
    }
    return 0;
}
