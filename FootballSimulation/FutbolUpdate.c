#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int enbuyuk(int dizi[]){
int i,maxpuan,result=0,temp;
maxpuan= dizi[0];
 for(i=1;i<19;i++){
	if(dizi[i]>maxpuan){
		maxpuan= dizi[i];
		result =i;
}
}
return result;
}
int main(int argc, char *argv[]) {

int temp,i,j,bitir=1,gol1,gol2,n,a,gol[19],beraberlik[19],galibiyet[19],yenilgi[19],puan[19];

char *takimlar[19]={"Fenerbahce         ","Gatasaray          ","Besiktas           ","Trabzonspor        ","Sivasspor          ","Adana_Demirspor    ","Istanbul_Basaksehir","Konyaspor          ","Kayseri            ","Gaziantep          ","Kastamonu          ","Fatih_Karagumruk   ","Alanyaspor         ","Antalyaspor        ","Giresunspor        ","Istanbulspor       ","Ankaragucu         ","Hatayspor          ","Umraniyespor       "};
while(bitir==1){
gol1=gol2=0;
for(i=0;i<19;i++){
	gol[i]=beraberlik[i]=galibiyet[i]=yenilgi[i]=puan[i]=0;
}
a=1;
printf("Bir takim seciniz\n");
for(i=0;i<19;i++){
	printf("	%d %s\n",a,takimlar[i]);
	a++;
}
scanf("%d",&n);
while(n<1 || n>19){
	printf("Yalnizca ekrandaki rakamlardan birini girebilirsiniz.\nTekrar deneyiniz.\n");
	scanf("%d",&n);
}
printf("Sectiginiz takim %s\n",takimlar[n-1]);
srand(time(NULL));
for(i=0;i<19;i++){	
	for(j=0;j<19;j++){
		if(takimlar[i]==takimlar[j])continue;
		
		gol1=1+rand()%5;
		gol2=1+rand()%5;
		
		gol[i]+=gol1;
		gol[j]+=gol2;
		if(gol1>gol2){
			galibiyet[i]++;
			yenilgi[j]++;
			puan[i]+=3;
		}
		else if(gol2>gol1){
			galibiyet[j]++;
			yenilgi[i]++;
			puan[j]+=3;
		}
		else if(gol1==gol2){
			beraberlik[i]++;
			beraberlik[j]++;
			puan[i]++;
			puan[j]++;
		}
		printf("%s %d-%d %s \n\n",takimlar[i],gol1,gol2,takimlar[j]);
	}
}

printf("			ATILAN GOLLER   GALIBIYET    BERABERLIK    YENILGI        PUAN\n\n");
for(i=0;i<19;i++){
printf("%s:%13d%13d%13d%13d%13d\n",takimlar[i],gol[i],galibiyet[i],beraberlik[i],yenilgi[i],puan[i]);
}


printf("\n\n----------SAMPIYON %s \n\n",takimlar[enbuyuk(puan)]);
if(enbuyuk(puan)==n-1)
printf("	Takiminiz sampiyon oldu!\n\n");
printf("Bir sezon daha oynamak icin 1'e bitirmek icin 0'a basiniz \n\n");
scanf("%d",&bitir);
}
	return 0;
}