
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

void ekle();  
void goster();
void duzenle();  
void sil();
void ara();

struct musteridetayi   
{
	char odanumarasi[10];
	char isim[20];
	char adres[25];
	char telefonnumarasi[15];
	char milliyeti[15];	
	char e_posta[20];
	char sure[10];
	char gelistarihi[10];
}s;



void giris()
{
	
	int i=0;
    char ad[10],c=' '; 
    char sifre[10];
    char kullanici[10]="yağmur";
    char parola[10]="emre";
    

	system("cls");
	
    printf("\n  \t}-----------------------------{+} |GIRIS FORMU| {+}--------------------------------{   ");
    printf(" \n\n                       KULLANICI ADI GIRINIZ:-");
	scanf("%s", &ad); 
    printf(" \n\n                       PAROLANIZI GIRINIZ:-");
	while(i<10)
	{
	    sifre[i]=getch();
	    c=sifre[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	sifre[i]='\0';
	
	i=0;
	 
		if(strcmp(ad,kullanici)==0 && strcmp(sifre,parola)==0)
	{
	printf("  \n\n\n       HOSGELDINIZ !!!! GIRIS BASARILI");
	
	
	}
	else
	{
		printf("\n        UZGUNUZ !!!!  GIRIS BASARISIZ");
		exit(0);
		
		getch();
		
	}
}


int main(){     	
	
	int i=0;
	
	char sec;

	system("cls");   
	
 	printf("\t\t|       -----------------------------           |\n");
	printf("\t\t|        OTEL NIRVANAYA HOSGELDINIZ             |\n");
	printf("\t\t|       -----------------------------           |\n");
		
	printf(" \nDevam etmek icin herhangi bir tusa basin:");
	
	getch();	
    system("cls");
    giris();
    system("cls");
	
	while (1)
	{
	        system("cls");
		
		 
		printf("\t}-----------------------------{+} |ANA MENU| {+}--------------------------------{  \n");
		
		
		printf("\n\t\t\t\t {1} -> Oda rezervasyonu yapin");
		printf("\n\t\t\t\t {2} -> Musteri Kaydini Goruntule");
		printf("\n\t\t\t\t {3} -> Musteri kaydini sil");
		printf("\n\t\t\t\t {4} -> Musteri kaydini ara");
		printf("\n\t\t\t\t {5} -> Kaydi duzenleme");
	        printf("\n\t\t\t\t {6} -> Cikis");
		
		printf("\n\n\tMenuden sectiginiz bolumun numarasini giriniz:");
		
		sec=getche();
		
		switch(sec)           
		{	
			case '1':
				ekle();
				break;
			case '2':
				goster();
				break;
			case '3':
				sil();
				break;
			case '4':
				ara();
				break;
			case '5':
				duzenle();
				break;
			case '6':
				system("cls");
				printf("\n\n\t *****HIZMETIMIZE GUVENDIGINIZ ICIN TESEKKUR EDERIZ*****");
	
			
				exit(0);
				break;
			default:
				system("cls");
				printf("Yanlis giris");
				printf("\n Devam etmek icin herhangi bir tusa basin");
				getch();
		}
	}
}


void ekle()
{
	FILE *f;
	char test;
	f=fopen("nirvana.txt","a+");
	if(f==0)
	{   f=fopen("nirvana.txt","w+");
		system("cls");
		printf("Lutfen biz bilgisayarinizda veritabanimizi kurarken bekleyiniz!!");
		printf("\n Islem tamamlandi. Devam etmek icin herhangi bir tusa basiniz.!! ");
		getch();
	}
	while(1)
	{
		system("cls");
		printf("\n Musteri ayrintilarini giriniz :");
		printf("\n**************************");
		printf("\n Oda numarasini giriniz :\n");
		scanf("\n%s",s.odanumarasi);
		fflush(stdin);
		printf("Isim giriniz :\n");
		scanf("%s",s.isim);
		printf("Adres giriniz :\n");
		scanf("%s",s.adres);
		printf("Telefon numarasini giriniz :\n");
		scanf("%s",s.telefonnumarasi);
		printf("Milliyetini giriniz :\n");
		scanf("%s",s.milliyeti);
		printf("E-postayi giriniz :\n");
		scanf(" %s",s.e_posta);
		printf("Sureyi giriniz : (\'x\'days):\n");
		scanf("%s",&s.sure);
		printf("Gelis tarihini giriniz : (dd\\mm\\yyyy):\n");
		scanf("%s",&s.gelistarihi);
		fwrite(&s,sizeof(s),1,f);
		fflush(stdin);
		printf("\n\nOda basariyla rezerve edildi.!!");
		printf("\n Cikmak icin esc tusuna, baska bir musteri ayrintisi eklemek icin baska bir tusa basiniz.:");
		test=getche();
		if(test==27)
			break;
			
	}
	fclose(f);
}


void goster()
{
	FILE *f;
	int i;
	if((f=fopen("nirvana.txt","r"))==NULL)
		exit(0);
	system("cls");
	printf("ODA    ");
	printf("ISIM\t ");
	printf("\tADRES ");
	printf("\tTELEFON NUMARASI ");
	printf("\tMILLIYETI ");
	printf("\tE_POSTA ");
	printf("\t\t  SURE ");
	printf("\t GELIS TARIHI \n");
	
	
	while(fread(&s,sizeof(s),1,f)==1)
	{
		
		printf("\n%s \t%s \t\t%s \t\t%s \t%s  \t%s  \t     %s  \t  %s",s.odanumarasi, s.isim , s.adres , s.telefonnumarasi ,s.milliyeti ,s.e_posta,s.sure,  s.gelistarihi);
	}
	

	fclose(f);
	getch();
}


void sil()
{
	FILE *f,*t;
	int i=1;
	char odanumarasi[20];
	if((t=fopen("temp.txt","w"))==NULL)
	exit(0);
	if((f=fopen("nirvana.txt","r"))==NULL)
	exit(0);
	system("cls");
	printf("Veri tabanindan silinecek otelin Oda Numarasini giriniz: \n");
	fflush(stdin);
	scanf("%s",odanumarasi);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.odanumarasi,odanumarasi)==0)
		{       i=0;
			continue;
		}
		else
			fwrite(&s,sizeof(s),1,t);
	}
	if(i==1)
	{       
		printf("\n\n Bu Oda numarasindaki Musteri kayitlari bulunamadi!!");
		getch();
		fclose(f);
		fclose(t);
		main();
	}
	fclose(f);
	fclose(t);
	remove("nirvana.txt");
	rename("temp.txt","nirvana.txt");
	printf("\n\nMusteri basariyla kaldirildi....");
	fclose(f);
	fclose(t);
	getch();
}


void ara()
{
system("cls");
	FILE *f;
	char odanumarasi[20];
	int flag=1;
	f=fopen("nirvana.txt","r+");
	if(f==0)
		exit(0);
	fflush(stdin);
	printf("Ayrintilarini aramak icin musterinin oda numarasini girin: \n");
	scanf("%s", odanumarasi);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.odanumarasi,odanumarasi)==0){
			flag=0;
			printf("\n\t****Kayit Bulundu****\n ");
			printf("\nOda numarasi :\t%s",s.odanumarasi);
			printf("\nIsim:\t%s",s.isim);
			printf("\nAdres:\t%s",s.adres);
			printf("\nTelefon numarasi:\t%s",s.telefonnumarasi);
			printf("\nMilliyeti:\t%s",s.milliyeti);
			printf("\nE-Posta:\t%s",s.e_posta);
			printf("\nSure:\t%s",s.sure);
			printf("\nGelis Tarihi:\t%s",s.gelistarihi);
			flag=0;
			break;
		}
	}
	if(flag==1){	
		printf("\n\tIstenen Musteri bulunamadi!");
	}
	getch();
	fclose(f);
}


void duzenle()
{
	FILE *f;
	int k=1;
	char odanumarasi[20];
	long int size=sizeof(s);
	if((f=fopen("nirvana.txt","r+"))==NULL)
		exit(0);
	system("cls");
	printf("Duzenlemek icin musterinin Oda numarasini girin:\n\n");
	scanf("%[^\n]",odanumarasi);
	fflush(stdin);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.odanumarasi,odanumarasi)==0)
		{
			k=0;
			printf("\nOda numarasini girin     :");
			gets(s.odanumarasi);
			printf("\nIsim giriniz.   :");
			fflush(stdin);
			scanf("%s",&s.isim);
			printf("\nAdres giriniz.       :");
			scanf("%s",&s.adres);
			printf("\nTelefon numarasi giriniz. :");
			scanf("%s",&s.telefonnumarasi);
			printf("\nMilliyetinizi giriniz. :");
			scanf("%s",&s.milliyeti);
			printf("\nE-Postanizi giriniz :");
			scanf("%s",&s.e_posta);
			printf("\nSurenizi giriniz :");
			scanf("%s",&s.sure);
			printf("\nGelis tarihinizi giriniz :");
			scanf("%s",&s.gelistarihi);
			fseek(f,size,SEEK_CUR);  
			fwrite(&s,sizeof(s),1,f);
			break;
		}
	}
	if(k==1){
		printf("\n\nKAYIT MEVCUT DEGIL!!!!");
		fclose(f);
		getch();
	}else{
	fclose(f);
	printf("\n\n\t\tKAYDINIZ BASARIYLA DUZENLENDI!!!");
	getch();
}
}



