#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

// Nama  : Putu Ode Irfan Ardika
// Kelas : B
// NIM   : 2108561083

struct node
{
    int data;
    struct node *next;
};
struct node *place[SIZE];

void input();
void view();
void search();

int main(){
    int jumlh, data;
    char pilihan;
    for (int i = 0; i < SIZE; i++) //set array to NULL
    {
        place[i] = NULL;
    }
    menu:
    system("cls");
    printf("=== PROGRAM OPEN HASHING ===\n\n");
    printf("Menu: \n"
           "1. Input Data\n2. View Data\n3. Cari Data\n4. Keluar\n"
           "Masukan Pilihan: ");
           scanf("%c", &pilihan);
    switch (pilihan)
    {
    case '1':
        input();
        while(getchar() != '\n');
        system("pause");
        goto menu;
        break;
    case '2':
        view();
        while(getchar() != '\n');
        system("pause");
        goto menu;
        
    case '3':
        search();
        while(getchar() != '\n');
        system("pause");
        goto menu;
    case '4':
        return 0;
        break;
    default:
        printf("\nPilihan Tidak Ada\n");
        getchar();getchar();
        goto menu;
        break;
    }
}

void input(){
    int jumlh,nilai;
    int key;
    printf("Jumlah Data : ");
    scanf("%d", &jumlh);
    for (int i = 0; i < jumlh; i++)
    {
        printf("Masukan Data: ");scanf("%d", &nilai);
        //create a new node
        struct node *new = malloc(sizeof(struct node)); 
        new->data = nilai;
        new->next = NULL;
        //find a array to put the data
        key = nilai % SIZE;
        if(place[key] == NULL)
        {
            //check if the array is empty
            place[key] = new; 
        } 
        else
        {
            struct node *temp = place[key];
            //finding the last node before NULL
            while (temp->next)
            {
                temp = temp->next;
            }
            temp->next = new; //new -> new(new data)-> NULL
        }
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

void search(){
    int check = 0,data;
    printf("Masukan Data yang dicari: ");
    scanf("%d", &data);
    int key = data % SIZE;
    struct node *temp = place[key];
    while (temp)
    {
        if (temp->data == data) check = 1;
        temp = temp->next;
    }
    if(check == 1)
    {
        printf("Data ada di dalam --> place[%d]\n",key);
    }
    if(check == 0)
    {
        printf("Data tidak ditemukan\n");
    }
}
