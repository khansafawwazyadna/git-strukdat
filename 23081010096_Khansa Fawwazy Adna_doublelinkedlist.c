#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node node;

void tambahAwal(node **head);
void tambahData(node **head);
void tambahAkhir(node **head);
void hapusAwal(node **head);
void hapusTengah(node **head);
void hapusAkhir(node **head);
void cariData(node *head);
void hitungJumlahData(node *head);
void jumlahkanData(node *head);
void tranverse(node *head);

int main()
{
    node *head = NULL;
    char pilih;

    do {
        system("cls");
        printf("Masukkan pilihan:\n");
        printf("1. Tambah data di awal\n");
        printf("2. Tambah data di tengah list\n");
        printf("3. Tambah data di akhir list\n");
        printf("4. Hapus data di awal\n");
        printf("5. Hapus data di tengah\n");
        printf("6. Hapus data di akhir\n");
        printf("7. Cari data\n");
        printf("8. Hitung jumlah data\n");
        printf("9. Jumlahkan semua data\n");
        printf("0. Cetak isi list\n");
        printf("MASUKKAN PILIHAN (tekan q untuk keluar) : ");
        scanf(" %c", &pilih);

        switch(pilih) {
            case '1': tambahAwal(&head); break;
            case '2': tambahData(&head); break;
            case '3': tambahAkhir(&head); break;
            case '4': hapusAwal(&head); break;
            case '5': hapusTengah(&head); break;
            case '6': hapusAkhir(&head); break;
            case '7': cariData(head); break;
            case '8': hitungJumlahData(head); break;
            case '9': jumlahkanData(head); break;
            case '0': 
                tranverse(head);
                getchar();
                getchar();
                break;
        }
    } while (pilih != 'q');
  
    return 0;
}

void tambahAwal(node **head) {
    int bil;
    node *pNew;

    system("cls");
    printf("Masukkan bilangan : ");
    scanf("%d", &bil);
    pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL) {
        pNew->data = bil;
        if (*head == NULL) {
            pNew->next = pNew;
            pNew->prev = pNew;
            *head = pNew;
        } else {
            pNew->next = (*head)->next;
            pNew->prev = *head;
            (*head)->next->prev = pNew;
            (*head)->next = pNew;
        }
    } else {
        printf("Alokasi memori gagal");
        getchar();
        getchar();
    }
}

void tambahData(node **head) {
    int pos, bil;
    node *pNew, *pCur;

    system("cls");
    tranverse(*head);
    printf("\nPosisi penyisipan setelah data bernilai : ");
    scanf("%d", &pos);
    printf("Bilangan : ");
    scanf("%d", &bil);

    if (*head == NULL) {
        printf("\nList kosong");
        getchar();
        getchar();
        return;
    }

    pCur = *head;
    do {
        if (pCur->data == pos) {
            pNew = (node *)malloc(sizeof(node));
            if (pNew == NULL) {
                printf("\nAlokasi memori gagal");
                getchar();
                getchar();
                return;
            }
            pNew->data = bil;
            pNew->next = pCur->next;
            pNew->prev = pCur;
            pCur->next->prev = pNew;
            pCur->next = pNew;
            return;
        }
        pCur = pCur->next;
    } while (pCur != *head);

    printf("\nNode tidak ditemukan");
    getchar();
    getchar();
}

void tambahAkhir(node **head) {
    int bil;
    node *pNew;

    system("cls");
    printf("Masukkan bilangan : ");
    scanf("%d", &bil);
    pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL) {
        pNew->data = bil;
        if (*head == NULL) {
            pNew->next = pNew;
            pNew->prev = pNew;
            *head = pNew;
        } else {
            pNew->next = (*head)->next;
            pNew->prev = *head;
            (*head)->next->prev = pNew;
            (*head)->next = pNew;
            *head = pNew;
        }
    } else {
        printf("Alokasi memori gagal");
        getchar();
        getchar();
    }
}

void hapusAwal(node **head) {
    node *pTemp;

    if (*head == NULL) {
        printf("List kosong");
    } else if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
        printf("Data awal berhasil dihapus (list sekarang kosong)");
    } else {
        pTemp = (*head)->next;
        (*head)->next = pTemp->next;
        pTemp->next->prev = *head;
        free(pTemp);
        printf("Data awal berhasil dihapus");
    }
    getchar();
    getchar();
}

void hapusTengah(node **head) {
    int nilai;
    node *pCur;

    system("cls");
    tranverse(*head);
    printf("\nMasukkan nilai yang akan dihapus: ");
    scanf("%d", &nilai);

    if (*head == NULL) {
        printf("List kosong");
        getchar();
        getchar();
        return;
    }

    pCur = (*head)->next;

    do {
        if (pCur->data == nilai) {
            pCur->prev->next = pCur->next;
            pCur->next->prev = pCur->prev;
            if (pCur == *head) {
                *head = pCur->prev;
            }
            free(pCur);
            printf("Data berhasil dihapus");
            getchar();
            getchar();
            return;
        }
        pCur = pCur->next;
    } while (pCur != (*head)->next);

    printf("Data tidak ditemukan");
    getchar();
    getchar();
}

void hapusAkhir(node **head) {
    node *pCur;

    if (*head == NULL) {
        printf("List kosong");
    } else if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
        printf("Data akhir berhasil dihapus (list sekarang kosong)");
    } else {
        pCur = *head;
        pCur->prev->next = pCur->next;
        pCur->next->prev = pCur->prev;
        *head = pCur->prev;
        free(pCur);
        printf("Data akhir berhasil dihapus");
    }
    getchar();
    getchar();
}

void cariData(node *head) {
    int nilai, posisi = 1;
    node *pCur;

    system("cls");
    printf("Masukkan nilai yang dicari: ");
    scanf("%d", &nilai);

    if (head == NULL) {
        printf("List kosong");
        getchar();
        getchar();
        return;
    }

    pCur = head->next;
    do {
        if (pCur->data == nilai) {
            printf("Data %d ditemukan pada posisi ke-%d", nilai, posisi);
            getchar();
            getchar();
            return;
        }
        pCur = pCur->next;
        posisi++;
    } while (pCur != head->next);

    printf("Data tidak ditemukan");
    getchar();
    getchar();
}

void hitungJumlahData(node *head) {
    int jumlah = 0;
    node *pCur;

    if (head == NULL) {
        printf("Jumlah data dalam linked list: 0");
    } else {
        pCur = head->next;
        do {
            jumlah++;
            pCur = pCur->next;
        } while (pCur != head->next);
        printf("Jumlah data dalam linked list: %d", jumlah);
    }
    getchar();
    getchar();
}

void jumlahkanData(node *head) {
    int total = 0;
    node *pCur;

    if (head == NULL) {
        printf("List kosong, total: 0");
    } else {
        pCur = head->next;
        do {
            total += pCur->data;
            pCur = pCur->next;
        } while (pCur != head->next);
        printf("Total penjumlahan semua data: %d", total);
    }
    getchar();
    getchar();
}

void tranverse(node *head) {
    node *pWalker;

    system("cls");
    if (head == NULL) {
        printf("List kosong");
    } else {
        pWalker = head->next;
        do {
            printf("%d", pWalker->data);
            pWalker = pWalker->next;
            if (pWalker != head->next) {
                printf(" -> ");
            }
        } while (pWalker != head->next);
        printf(" -> NULL ");
    }
}

