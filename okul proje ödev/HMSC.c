#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>

void add();  //Fonksiyon
void list();
void edit();  //GLOBALLY DECLARED FUNCTIONS N VARIABLE
void delete1();
void search();

/*void setcolor(int ForgC)
{ WORD wColor;
HANDLE hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO csbi;

if(GetConsoleScreenBufferInfo(hStdOut,&csbi))
{
	wColor=(csbi.wAttributes & 0xB0)+(ForgC & 0x0B);
//	SetConsoleTextAttributes(hStdOut,wColor);
	SetConsoleTextAttribute(hStdOut,wColor);
	
}
}*/

void login()
{
	
	int a=0,i=0;
    char ad[10],c=' '; 
    char sifre[10],code[10];
    char kullanici[10]="emre";
    char parola[10]="akyol";
    do
{
	system("cls");
	
    printf("\n  **************************  GIRIS FORMU  **************************  ");
    printf(" \n                       KULLANICI ADI GIRINIZ:-");
	scanf("%s", &ad); 
	printf(" \n                       PAROLANIZI GIRINIZ:-");
	while(i<10)
	{
	    sifre[i]=getch();
	    c=sifre[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	sifre[i]='\0';
	//char code=sifre;
	i=0;
	//scanf("%s",&sifre); 
		if(strcmp(ad,kullanici)==0 && strcmp(sifre,parola)==0)
	{
	printf("  \n\n\n       HOSGELDINIZ !!!! GIRIS BASARILI");
	
	break;
	}
	else
	{
		printf("\n        UZGUNUZ !!!!  GIRIS BASARISIZ");
		a++;
		
		getch();
		
	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nUzgunuz, dort kez yanlis kullanici adi ve sifre girdiniz!!!");
		
		getch();
		
		}
		system("cls");	
}

struct CustomerDetails   //STRUCTURE DECLARATION
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

int main(){     // ANA FONKSİYON	
	int i=0;
	
	time_t t;
	time(&t);
	char customername;
	char choice;

	system("cls");   // EKRANİ TEMİZLEMEK İCİN
	//setcolor(15);
 	printf("\t\t*************************************************\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*       -----------------------------           *\n");
	printf("\t\t*        OTEL NİRVANAYA HOŞ GELDİNİZ.           *\n");
	printf("\t\t*       -----------------------------           *\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*************************************************\n\n\n");
		for(i=0;i<80;i++)
		printf("-");
	    printf("\nGuncel tarih ve saat : %s",ctime(&t));
	    for(i=0;i<80;i++)
		printf("-");
	printf(" \nDevam etmek icin herhangi bir tusa basin:");
	
	getch();	
    system("cls");
    login();
    system("cls");
	while (1)      
	{
		system("cls");
		//setcolor(10);
		 for(i=0;i<80;i++)
		printf("-");
		printf("\n");
		printf("   ******************************  |ANA MENU|  ***************************** \n");
		for(i=0;i<80;i++)
		printf("-");
		printf("\n");
		//setcolor(10);
		printf("\t\t *Lutfen menu seciminizi girin*:");
		printf("\n\n");
		printf(" \n 1'i sec -> Oda rezervasyonu yapin");
		printf("\n------------------------");
		printf(" \n 2'yi sec -> Musteri Kaydini Goruntule");
		printf("\n----------------------------------");
		printf(" \n 3'u sec -> Musteri kaydini sil");
		printf("\n-----------------------------------");
		printf(" \n 4'u sec -> Musteri kaydini ara");
		printf("\n-----------------------------------");
		printf(" \n 5'i sec -> Kaydi duzenleme");
		printf("\n-----------------------");
		printf(" \n 6'yi sec -> Cikis");
		printf("\n-----------------");
		printf("\n");
		for(i=0;i<80;i++)
		printf("-");
	    printf("\nGuncel tarih ve zaman : %s",ctime(&t));
	    for(i=0;i<80;i++)
		printf("-");
		
		choice=getche();
		choice=toupper(choice);
		switch(choice)           
		{	
			case '1':
				add();break;
			case '2':
				list();break;
			case '3':
				delete1();break;
			case '4':
				search();break;
			case '5':
				edit();break;
			case '6':
				system("cls");
				printf("\n\n\t *****HIZMETIMIZE GUVENDIGINIZ ICIN TESEKKUR EDERIZ*****");
	
			//	Sleep(2000);
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

void add()
{
	FILE *f;
	char test;
	f=fopen("add.txt","a+");
	if(f==0)
	{   f=fopen("add.txt","w+");
		system("cls");
		printf("Lutfen biz bilgisayarinizda veritabanimizi kurarken bekleyiniz!!");
		printf("\n Islem tamamlandi. Devam etmek icin herhangi bir tusa basiniz.!! ");
		getch();
	}
	while(1)
	{
		system("cls");
		printf("\n Musteri ayrintilarini girin. :");
		printf("\n**************************");
		printf("\n Oda numarasini girin.:\n");
		scanf("\n%s",s.odanumarasi);
		fflush(stdin);
		printf("Isim giriniz.:\n");
		scanf("%s",s.isim);
		printf("Adres giriniz.:\n");
		scanf("%s",s.adres);
		printf("Telefon numarasini giriniz.:\n");
		scanf("%s",s.telefonnumarasi);
		printf("Milliyetini giriniz.:\n");
		scanf("%s",s.milliyeti);
		printf("E-postayi giriniz.:\n");
		scanf(" %s",s.e_posta);
		printf("Sureyi giriniz.(\'x\'days):\n");
		scanf("%s",&s.sure);
		printf("Gelis tarihini giriniz.(dd\\mm\\yyyy):\n");
		scanf("%s",&s.gelistarihi);
		fwrite(&s,sizeof(s),1,f);
		fflush(stdin);
		printf("\n\n1 Oda basariyla rezerve edildi.!!");
		printf("\n Cikmak icin esc tusuna, baska bir musteri ayrintisi eklemek icin baska bir tusa basiniz.:");
		test=getche();
		if(test==27)
			break;
			
	}
	fclose(f);
}

void list()
{
	FILE *f;
	int i;
	if((f=fopen("add.txt","r"))==NULL)
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
	
	for(i=0;i<118;i++)
		printf("-");
	while(fread(&s,sizeof(s),1,f)==1)
	{
		/*printf("ODANUMARASİ :\t%s\n",s.odanumarasi);
		printf("İSİM:\t%s\n",,s.isim);
		printf("ADRES:\t%s\n",s.adres);
		printf("TELEFONNUMARASİ:\t%s\n",s.telefonnumarasi);
		printf("MİLLİYETİ \n");*/
		printf("\n%s \t%s \t\t%s \t\t%s \t%s  \t%s  \t     %s  \t  %s",s.odanumarasi, s.isim , s.adres , s.telefonnumarasi ,s.milliyeti ,s.e_posta,s.sure,  s.gelistarihi);
	}
	printf("\n");
	for(i=0;i<118;i++)
		printf("-");

	fclose(f);
	getch();
}

void delete1()
{
	FILE *f,*t;
	int i=1;
	char odanumarasi[20];
	if((t=fopen("temp.txt","w"))==NULL)
	exit(0);
	if((f=fopen("add.txt","r"))==NULL)
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
		//remove("E:/file.txt");
	   //rename("E:/temp.txt","E:/file.txt");
		getch();
		fclose(f);
		fclose(t);
		main();
	}
	fclose(f);
	fclose(t);
	remove("add.txt");
	rename("temp.txt","add.txt");
	printf("\n\nMusteri basariyla kaldirildi....");
	fclose(f);
	fclose(t);
	getch();
}

void search()
{
system("cls");
	FILE *f;
	char odanumarasi[20];
	int flag=1;
	f=fopen("add.txt","r+");
	if(f==0)
		exit(0);
	fflush(stdin);
	printf("Ayrintilarini aramak icin müsterinin oda numarasini girin: \n");
	scanf("%s", odanumarasi);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.odanumarasi,odanumarasi)==0){
			flag=0;
			printf("\n\tRecord Found\n ");
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

void edit()
{
	FILE *f;
	int k=1;
	char odanumarasi[20];
	long int size=sizeof(s);
	if((f=fopen("add.txt","r+"))==NULL)
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
			scanf("%f",&s.telefonnumarasi);
			printf("\nMilliyetinizi giriniz. :");
			scanf("%s",&s.milliyeti);
			printf("\nE-Postanizi giriniz :");
			scanf("%s",&s.e_posta);
			printf("\nSurenizi giriniz :");
			scanf("%s",&s.sure);
			printf("\nGelis tarihinizi giriniz :");
			scanf("%s",&s.gelistarihi);
			fseek(f,size,SEEK_CUR);  //istenen pozisyona gitmek icin
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
