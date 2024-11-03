#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} Stack;


void initStack(Stack *s) {
    s->top = -1;
}


int isEmpty(Stack *s) {
    return s->top == -1;
}


int isFull(Stack *s) {
    return s->top == MAX - 1;
}


void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack penuh!\n");
    } else {
        s->data[++(s->top)] = value;
        printf("Elemen %d ditambahkan ke stack.\n", value);
    }
}


void pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack kosong!\n");
    } else {
        printf("Elemen %d dihapus dari stack.\n", s->data[(s->top)--]);
    }
}


void top(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack kosong!\n");
    } else {
        printf("Elemen teratas adalah %d.\n", s->data[s->top]);
    }
}


void destroyStack(Stack *s) {
    s->top = -1;
    printf("Stack telah dikosongkan.\n");
}

int main() {
    Stack stack;
    int choice, value;

    initStack(&stack);

    do {
        printf("\nMenu Operasi Stack:\n");
        printf("1. Push (Tambah elemen)\n");
        printf("2. Pop (Hapus elemen)\n");
        printf("3. Top (Lihat elemen teratas)\n");
        printf("4. Cek Apakah Stack Kosong\n");
        printf("5. Destroy Stack\n");
        printf("6. Keluar\n");
        printf("Pilih operasi: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Masukkan nilai yang ingin ditambahkan: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                pop(&stack);
                break;
            case 3:
                top(&stack);
                break;
            case 4:
                if (isEmpty(&stack)) {
                    printf("Stack kosong.\n");
                } else {
                    printf("Stack tidak kosong.\n");
                }
                break;
            case 5:
                destroyStack(&stack);
                break;
            case 6:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (choice != 6);

    return 0;
}

