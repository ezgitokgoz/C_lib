#include <stdio.h>
#include <stdlib.h>

struct dugum{       //yapı olusturma
	int veri;
	struct dugum * gosterici;
};

struct dugum * bas = NULL;   //bas ve gecici isimli son dugumler olusturduk
struct dugum * gecici = NULL;

void sonaEkle ( int sayi ){ //bizim giris yapacağımız veri için fonksiyonla dugum olusturduk
	
	struct dugum * eklenecek;
	eklenecek = (struct dugum*) malloc (sizeof(struct dugum));
	eklenecek->veri=sayi;
	eklenecek->gosterici=NULL; //sondan ekleyecegimiz için göstericinin null olması gerekiyor
	
	if(bas==NULL){ //eger hic dugum yoksa ilk dugum bizim yazdıgımız olacak
		bas=eklenecek;
	}
	else{               //fakat hali hazırda bir düğüm varsa 
		gecici=bas;     
		
		while(gecici->gosterici!=NULL){ //gecici düğüm son düğüm değilse
		    gecici=gecici->gosterici;  //son göstericiye kadar devam etmesi için
	    }
	    gecici->gosterici=eklenecek;
    }
}

void yazdir() {
	gecici=bas;
	while(gecici->gosterici!=NULL){ //son dugume gelene kadar
		printf("%d - ",gecici->veri); //sondan önceki değerleri yazdıracak
		gecici=gecici->gosterici;
	}
	printf("%d",gecici->veri); //son dugumu yazdıracak
}

int main(){
	int adet=0;
	while(adet != 5){
		int sayi;
		printf("bir sayi giriniz: ");
		scanf("%d", &sayi);
		sonaEkle(sayi);
		adet++;
	}
	yazdir();
	return 0;
}






