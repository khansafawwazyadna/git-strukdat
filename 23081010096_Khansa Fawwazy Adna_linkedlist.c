#include <stdio.h>//linked list
#include <conio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
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
void insertNode(node **head, node *pPre, node *pNew);

int main()
{
    node *head;
    char pilih;

    head = NULL;
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
        fflush(stdin);
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
                getch();
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
        pNew->next = *head;
        *head = pNew;
    } else {
        printf("Alokasi memori gagal");
        getch();
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

    pCur = *head;
    while (pCur != NULL && pCur->data != pos) {
        pCur = pCur->next;
    }

    pNew = (node *)malloc(sizeof(node));

    if (pCur == NULL) {
        printf("\nNode tidak ditemukan");
        getch();
    } else if (pNew == NULL) {
        printf("\nAlokasi memori gagal");
        getch();
    } else {
        pNew->data = bil;
        pNew->next = pCur->next;
        pCur->next = pNew;
    }
}

void tambahAkhir(node **head) {
    int bil;
    node *pNew, *pCur;

    system("cls");
    printf("Masukkan bilangan : ");
    scanf("%d", &bil);
    pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL) {
        pNew->data = bil;
        pNew->next = NULL;

        if (*head == NULL) {
            *head = pNew;
        } else {
            pCur = *head;
            while (pCur->next != NULL) {
                pCur = pCur->next;
            }
            pCur->next = pNew;
        }
    } else {
        printf("Alokasi memori gagal");
        getch();
    }
}

void hapusAwal(node **head) {
    node *pTemp;

    if (*head != NULL) {
        pTemp = *head;
        *head = (*head)->next;
        free(pTemp);
        printf("Data awal berhasil dihapus");
    } else {
        printf("List kosong");
    }
    getch();
}

void hapusTengah(node **head) {
    int nilai;
    node *pCur, *pPre;

    system("cls");
    tranverse(*head);
    printf("\nMasukkan nilai yang akan dihapus: ");
    scanf("%d", &nilai);

    pPre = NULL;
    pCur = *head;

    while (pCur != NULL && pCur->data != nilai) {
        pPre = pCur;
        pCur = pCur->next;
    }

    if (pCur == NULL) {
        printf("Data tidak ditemukan");
    } else {
        if (pPre == NULL) {
            *head = pCur->next;
        } else {
            pPre->next = pCur->next;
        }
        free(pCur);
        printf("Data berhasil dihapus");
    }
    getch();
}

void hapusAkhir(node **head) {
    node *pCur, *pPre;

    if (*head == NULL) {
        printf("List kosong");
    } else if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        printf("Data akhir berhasil dihapus");
    } else {
        pPre = NULL;
        pCur = *head;
        while (pCur->next != NULL) {
            pPre = pCur;
            pCur = pCur->next;
        }
        pPre->next = NULL;
        free(pCur);
        printf("Data akhir berhasil dihapus");
    }
    getch();
}

void cariData(node *head) {
    int nilai, posisi = 1;
    node *pCur;

    system("cls");
    printf("Masukkan nilai yang dicari: ");
    scanf("%d", &nilai);

    pCur = head;
    while (pCur != NULL) {
        if (pCur->data == nilai) {
            printf("Data %d ditemukan pada posisi ke-%d", nilai, posisi);
            getch();
            return;
        }
        pCur = pCur->next;
        posisi++;
    }
    printf("Data tidak ditemukan");
    getch();
}

void hitungJumlahData(node *head) {
    int jumlah = 0;
    node *pCur = head;

    while (pCur != NULL) {
        jumlah++;
        pCur = pCur->next;
    }
    printf("Jumlah data dalam linked list: %d", jumlah);
    getch();
}

void jumlahkanData(node *head) {
    int total = 0;
    node *pCur = head;

    while (pCur != NULL) {
        total += pCur->data;
        pCur = pCur->next;
    }
    printf("Total penjumlahan semua data: %d", total);
    getch();
}

void tranverse(node *head) {
    node *pWalker;

    system("cls");
    pWalker = head;
    while (pWalker != NULL) {
        printf("%d", pWalker->data);
        pWalker = pWalker->next;
        if (pWalker != NULL) {
            printf(" -> ");
        }
    }
    printf(" -> NULL");
}

void insertNode(node **head, node *pPre, node *pNew) {
    if (pPre == NULL) {
        pNew->next = *head;
        *head = pNew;
    } else {
        pNew->next = pPre->next;
        pPre->next = pNew;
    }
}
