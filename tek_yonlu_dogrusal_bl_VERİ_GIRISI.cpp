#include <stdio.h>
#include <stdlib.h>

struct dugum{                   //yapı olusturma
	int veri;
	struct dugum *gosterici;
};

int main(){
	struct dugum *birincidugum;                                       //dugum olusturma
	birincidugum = (struct dugum *) malloc (sizeof (struct dugum));  //bellekte yer ayır
	
	struct dugum*ikincidugum;
	ikincidugum = (struct dugum *) malloc (sizeof (struct dugum));
	
	struct dugum*ucuncudugum;
	ucuncudugum = (struct dugum *) malloc (sizeof (struct dugum));
	
	struct dugum*dorduncudugum;
	dorduncudugum = (struct dugum *) malloc (sizeof (struct dugum));
	
	birincidugum->veri=11;                    //veri girşi yaptık
	birincidugum->gosterici=ikincidugum;      //bir sonraki dugumu gösterdik
	
	ikincidugum->veri=22;
	ikincidugum->gosterici=ucuncudugum;
	
	ucuncudugum->veri=33;
	ucuncudugum->gosterici=dorduncudugum;
	
	dorduncudugum->veri=44;
	dorduncudugum->gosterici=NULL;
	
	printf("%d - %d - %d - %d",birincidugum->veri,ikincidugum->veri,ucuncudugum->veri,dorduncudugum->veri);
	
	return 0;
}














