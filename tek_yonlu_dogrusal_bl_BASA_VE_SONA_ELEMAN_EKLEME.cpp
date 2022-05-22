#include <stdio.h>
#include <stdlib.h>

struct node{              //node yapısının olusumu, ezbere bilmemiz gerekiyor 
	int data;
	struct node * next;    // next gostericimiz
};

struct node* head=NULL;    
struct node* temp=NULL;

void basaEkle(int num){
	struct node* x;                                // node olusturma
	x=(struct node*)malloc(sizeof(struct node));
	x->data=num;   
	x->next=head; //başa ekleyeceğimiz için göstericinin değeri baş olacak
	head=x;       //artık değerimiz (x) ilk eleman olduğu için bu atamayı yaptık
}

void sonaEkle(int num){
	struct node* x;
	x=(struct node*)malloc(sizeof(struct node));
	x->data=num;
	x->next=NULL; //sona ekleyeceğimiz için göstericinin değeri null olacak (son eleman olma şartı göstericinin null olmasıdır)
	
	if(head==NULL){ //ilk değer yoksa
		head=x;     // değerimiz ilk değer olacak
	}
	
	else{               //ilk değer varsa
		temp=head;      //head değerinin degişmemesi için geçici 'tepm' değişkenine atıyoruz
		while(temp->next!=NULL){   //döngü şartı: temp değerinin göstericisi sona gelene kadar
			temp=temp->next;       //temp'in göstericisi, temp'in değeri oluyor, bu işlem ilerlemeyi sağlar ***önemli***
		}
		temp->next=x;  //sona geldiğinde döngüden çıkıp temp'in göstericisini(next) bizim değerimiz yapıyor = sona ekliyor
	}
}

void yazdir(){
	temp=head;   
	while(temp->next!=NULL){ //döngü şartı: temp'in göstericisi null değilse yani sona gelinmemdiyse
		printf("%d",temp->data); //datayı yazdırıyoruz
		temp=temp->next; 
	}
	printf("%d",temp->data); //son elemana geldiğinde döngüden çıktığı için, sonuncu veriyi yazdırması için
}

int main(){
	int num,piece=0,sel;
	while(piece!=6){
		printf("\n\nbasa eleman eklemek icin 1");
		printf("\nsona eleman eklemek icin 2");
		printf("\nseciminizi yapiniz: ");  scanf("%d",&sel);
		
		switch(sel){
			case 1: printf("\nbasa eklenecek elemani giriniz: "); scanf("%d",&num);
			basaEkle(num);
			yazdir();
			break;
			case 2: printf("\nsona eklenecek elemani giriniz: "); scanf("%d",&num);
			sonaEkle(num);
			yazdir();
			break;
		}
		piece ++;
	}
	return 0;
}









