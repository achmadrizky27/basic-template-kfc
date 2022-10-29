#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	int nilai;
	char nama[20];
	char nim[20];
	struct node *next;
	struct node *prev;
};

typedef struct node *mynode;

mynode create_node(int nilai, char nama[2], char nim[20]){
	mynode new_node;
	new_node = (mynode)malloc(sizeof(struct node));
	new_node -> nilai = nilai;
	strcpy(new_node->nama,nama);
	strcpy(new_node->nim,nim);
	new_node -> next = NULL;
	new_node -> prev = NULL;
	return(new_node);
}

mynode insert_node(mynode head, int nilai, char nama[20], char nim[2]){
	mynode new_node = create_node(nilai,nama,nim);
	//head = null
	if (head==NULL){
		head=new_node;
		return(head);
	}
	//mencari posisi
	mynode cursor=head;
	mynode precursor;
	
	//menambahkan head
	if (cursor -> nilai <= nilai){
		new_node -> next = head;
		head -> prev = new_node;
		head = new_node;
	}else {
		while(cursor -> next != NULL){
			if (cursor -> nilai > nilai){
				precursor = cursor;
				cursor = cursor -> next;
			}else break;
		}
		//menambahkan tail
		if (cursor-> nilai > nilai){
			cursor -> next = new_node;
			new_node -> prev = cursor;
		}else if (cursor -> nilai <= nilai){ //menambahkan bagian tengah
			precursor -> next = new_node;
			new_node -> next = cursor;
			cursor -> prev = new_node;
			new_node -> prev = precursor;
			
		}
	}
	return(head);
}

mynode remove_node (mynode head, int nilai){
	mynode cursor = head;
	
	if (cursor == NULL){
		printf ("LIST TIDAK ADA");
		return(head);
		}
	
	if (cursor -> nilai == nilai){
		if (head -> next == NULL){
			head = NULL;
			return(head);
		}
		head = head -> next;
		cursor -> next = NULL;
		head -> prev = NULL;
		free (cursor);
		}
	else{
		while (cursor -> nilai > nilai){
			if (cursor -> next != NULL)
				cursor = cursor -> next;
			else
				break;
		}
		
		if (cursor -> nilai == nilai){
			//tail merupakan node yang telah dihapus
		if (cursor -> next == NULL){
			mynode tail = cursor -> prev;
			tail -> next = NULL;
			cursor -> prev = NULL;
			free (cursor);
		}
		//node yang telah dihapus ada diantara node
		else {
			cursor -> prev -> next = cursor -> next;
			cursor -> next -> prev = cursor -> prev;
			cursor -> prev = NULL;
			cursor -> next = NULL;
			free (cursor);
		}
		}
	}
	return (head);
}

void tampil_node(mynode head){
	mynode n=head;
	printf("==================================================\n");
	printf("|NAMA                  |NPM           |TUGAS      \n");
	printf("==================================================\n");
	while(n!=NULL){
		printf("| %-18s  | %-10s  |  %-4d  |\n", n -> nama, n -> nim, n -> nilai);
		printf("==================================================\n");
		n = n -> next;
		
	}
}

void menu(){
	printf("==================================================\n");
	printf("                    PILIHAN MENU                  \n");
	printf("==================================================\n");
	printf("1. MENAMBAHKAN DATA NILAI MAHASISWA               \n");
	printf("2. MENGHAPUS DATA MAHASISWA                       \n");
	printf("3. MENAMPILKAN TAMPILAN NODE                      \n");
	printf("4. EXIT                                         \n\n");
}

int main(){
	int pilih, nilai;
	char nama[20];
	char nim[20];
	mynode head = NULL;
	
	do {
		menu();
		do {
			printf("PILIHAN ANDA = ");
			scanf("%d", &pilih);
		}while ((pilih < 1) || (pilih > 4));
		
		switch (pilih) {
			case 1:
				printf("\nNAMA MAHASISWA      = ");
				scanf("%s", nama);
				printf("\nNPM MAHASISWA       = ");
				scanf("%s", nim);
				printf("\nNILAI STRUKTUR DATA = ");
				scanf("%d", &nilai);
				head = insert_node (head, nilai, nama, nim);
				break;
			case 2:
				printf("\nNILAI MAHASISWA YANG INGIN DIDELETE = ");
				scanf("%d", &nilai);
				head = remove_node (head, nilai);
				break;
			case 3:
				tampil_node(head);
		}
	}while (pilih != 4);
}
