#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct node
{
    int data;
    struct node *next;
};
struct node *place[SIZE];

void input();
void view();

int main(){
    char pilihan;
    int jumlh, data;
    menu:
    printf("=== PROGRAM OPEN HASHING ===\n\n");
    for (int i = 0; i < SIZE; i++)
    {
        place[i] = NULL;
    }
    printf("Menu: \n"
           "1. Input Data\n2. View Data\n3. Cari Data\n4. Keluar\n"
           "Masukan Pilihan: ");
           scanf("%c", &pilihan);
    switch (pilihan)
    {
    case '1':
        printf("Jumlah Data : ");scanf("%d", &jumlh);
        for (int i = 0; i < jumlh; i++)
        {
            printf("Masukan Data: ");scanf("%d", &data);
            input(data);
        }
        getchar();getchar();
        goto menu;
        break;
    case '2':
        view();
    default:
        break;
    }
}

void input(int inputan){
    int key;
    struct node *new = malloc(sizeof(struct node));
    new->data = input;
    new->next = NULL;
    key = inputan % SIZE;

    if(place[key] == NULL)
    {
        place[key] = new;
    } 
    else
    {
        struct node *temp = place[key];
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = new;
    }
}

void view(){
    for (int i = 0; i < SIZE; i++)
    {
        struct node *temp  = place[i];
        printf("place[%d]-->", i+1);
        while (temp)
        {
            printf("%d-->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
    
}