#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Mahasiswa {
    char nama[50];
    char jenis_kelamin;
    struct Mahasiswa *next;
} Mahasiswa;

Mahasiswa *headLaki = NULL, *headPerempuan = NULL;
int jumlahLaki = 0, jumlahPerempuan = 0, maxLingkaran = 20;

void tambah_mahasiswa(char *nama, char jenis_kelamin) {
    Mahasiswa **head = (jenis_kelamin == 'L') ? &headLaki : &headPerempuan;
    int *jumlah = (jenis_kelamin == 'L') ? &jumlahLaki : &jumlahPerempuan;

    if (*jumlah >= maxLingkaran) {
        printf("Lingkaran %s sudah penuh.\n", (jenis_kelamin == 'L') ? "laki-laki" : "perempuan");
        return;
    }

    Mahasiswa *baru = (Mahasiswa*)malloc(sizeof(Mahasiswa));
    strcpy(baru->nama, nama);
    baru->jenis_kelamin = jenis_kelamin;

    if (*head == NULL) {
        *head = baru;
        baru->next = baru;
    } else {
        Mahasiswa *temp = *head;
        while (temp->next != *head) temp = temp->next;
        temp->next = baru;
        baru->next = *head;
    }

    (*jumlah)++;
    printf("%s (%c) bergabung ke lingkaran.\n", nama, jenis_kelamin);
}

void tampilkan_lingkaran(Mahasiswa *head) {
    if (head == NULL) {
        return;
    }

    Mahasiswa *temp = head;
    do {
        printf("%s (%c) -> ", temp->nama, temp->jenis_kelamin);
        temp = temp->next;
    } while (temp != head);
}

void tampilkan_lingkaran_gabungan() {
    printf("Lingkaran Gabungan:\n");
    if (headLaki != NULL) {
        tampilkan_lingkaran(headLaki);
    }
    if (headPerempuan != NULL) {
        tampilkan_lingkaran(headPerempuan);
    }
    printf("Kembali ke awal.\n");
}

void tampilkan_lingkaran_terpisah() {
    printf("Lingkaran Laki-laki:\n");
    tampilkan_lingkaran(headLaki);
    printf("\nLingkaran Perempuan:\n");
    tampilkan_lingkaran(headPerempuan);
    printf("Kembali ke awal.\n");
}

void hapus_mahasiswa(char *nama, char jenis_kelamin) {
    Mahasiswa **head = (jenis_kelamin == 'L') ? &headLaki : &headPerempuan;
    int *jumlah = (jenis_kelamin == 'L') ? &jumlahLaki : &jumlahPerempuan;

    if (*head == NULL) {
        printf("Lingkaran kosong.\n");
        return;
    }

    Mahasiswa *temp = *head, *prev = NULL;
    if (strcmp(temp->nama, nama) == 0) {
        if (temp->next == temp) {
            free(temp);
            *head = NULL;
        } else {
            while (temp->next != *head) temp = temp->next;
            temp->next = (*head)->next;
            free(*head);
            *head = temp->next;
        }
        (*jumlah)--; 
        printf("%s telah keluar dari lingkaran.\n", nama);
        return;
    }

    do {
        prev = temp;
        temp = temp->next;
    } while (temp != *head && strcmp(temp->nama, nama) != 0);

    if (temp != *head) {
        prev->next = temp->next;
        free(temp);
        (*jumlah)--; 
        printf("%s telah keluar dari lingkaran.\n", nama);
    } else {
        printf("Mahasiswa tidak ditemukan.\n");
    }
}

int main() {
    int pilihan;
    char nama[50], jenis_kelamin;

    printf("Selamat datang di acara api unggun!\n");

    while (1) {
        printf("\nMenu:\n1. Tambah Mahasiswa\n2. Hapus Mahasiswa\n3. Tampilkan Gabungan\n4. Tampilkan Terpisah\n5. Keluar\nPilih opsi: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                printf("Masukkan nama: ");
                scanf("%s", nama);
                printf("Masukkan jenis kelamin (L/P): ");
                scanf(" %c", &jenis_kelamin);
                tambah_mahasiswa(nama, jenis_kelamin);
                break;
            case 2:
                printf("Masukkan nama: ");
                scanf("%s", nama);
                printf("Masukkan jenis kelamin (L/P): ");
                scanf(" %c", &jenis_kelamin);
                hapus_mahasiswa(nama, jenis_kelamin);
                break;
            case 3:
                tampilkan_lingkaran_gabungan();
                break;
            case 4:
                tampilkan_lingkaran_terpisah();
                break;
            case 5:
                printf("Terima kasih, acara selesai!\n");
                return 0;
            default:
                printf("Pilihan tidak valid.\n");
        }
    }

    return 0;
}

