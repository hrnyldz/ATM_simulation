#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_BOYUT 999
FILE *dosya;
typedef struct musteri{
    char ad[20];
    char soyad[20];
    int hesap_no;
    int sifre;
    struct para{
                int miktar;
                char cins[10];
                }money;
}musteri;
musteri dizi[MAX_BOYUT];
int static diziboyu=0;
void hesapekle(int y){

        if ((dosya = fopen("test.txt", "r")) == NULL) {
		printf("dosya acilamadi!\n");
		exit(1);
	}
        FILE *tp = fopen("test.txt", "a");
        printf("Adinizi giriniz : ");       scanf("%s", &dizi[y].ad);
        printf("Soyadinizi giriniz : ");   scanf("%s", &dizi[y].soyad);
        printf("Para biriminizi giriniz : "); scanf("%s", &dizi[y].money.cins);

        int r,k;
        srand(time(NULL));
        r=100000+rand()%899999;//8haneli
        k=1000+rand()%8999;      //4haneli
        dizi[y].hesap_no=r;
        printf("hesap numaraniz: %d", dizi[y].hesap_no);
        dizi[y].sifre=k;
        printf("\nsifreniz: %d", dizi[y].sifre);
        fprintf(tp,"%s-%s-%d-%d-%s-%d\n",dizi[y].ad,dizi[y].soyad,dizi[y].hesap_no,dizi[y].sifre,dizi[y].money.cins,dizi[y].money.miktar);
        fclose(tp);

}
void sifre_degistir(struct musteri *dizi,int y){

    int k, yenisifre1, yenisifre2;

    printf("Eski sifreyi giriniz.\n");
    scanf("%d",&k);
        if(dizi[y].sifre==k){
          printf("Yeni sifreyi giriniz.\n");
          scanf("%d",&yenisifre1);
          printf("Yeni sifreyi tekrar giriniz.\n");
        scanf("%d",&yenisifre2);
    if(yenisifre1==yenisifre2){
       printf("Sifre degistirildi\n");
       dizi[y].sifre=yenisifre1;
       FILE *fp;
       fp=fopen("test2.txt","w");
            for(y=1;y<=diziboyu;y++)
                fprintf(fp,"%s-%s-%d-%d-%s-%d\n",dizi[y].ad,dizi[y].soyad,dizi[y].hesap_no,dizi[y].sifre,dizi[y].money.cins,dizi[y].money.miktar);
       fclose(fp);
       remove("C:\\Users\\harun yıldız\\Desktop\\staj\\2\\ATM_simulation\\test.txt");
       rename("test2.txt","test.txt");

    }

    else{
        printf("Sifreler uyusmuyor\n.");
    }

    }
    else {
        printf("Eski sifrenizi dogru giriniz\n");
    }

}

void get_para(struct musteri*dizi,int i){
    int miktar,y;
    printf("Cekmek istediginiz para tutarini giriniz.\n");
    scanf("%d",&miktar);
    dizi[i].money.miktar=dizi[i].money.miktar-miktar;
           FILE *fp;
       fp=fopen("test2.txt","w");
            for(y=1;y<=diziboyu;y++)
                fprintf(fp,"%s-%s-%d-%d-%s-%d\n",dizi[y].ad,dizi[y].soyad,dizi[y].hesap_no,dizi[y].sifre,dizi[y].money.cins,dizi[y].money.miktar);
       fclose(fp);
       remove("C:\\Users\\harun yıldız\\Desktop\\staj\\2\\ATM_simulation\\test.txt");
       rename("test2.txt","test.txt");

}

void set_para(struct musteri*dizi, int i){
    int miktar,y;
    printf("Yatirmak istediginiz para tutarini giriniz.\n");
    scanf("%d",&miktar);
    dizi[i].money.miktar=dizi[i].money.miktar+miktar;
           FILE *fp;
       fp=fopen("test2.txt","w");
            for(y=1;y<=diziboyu;y++)
                fprintf(fp,"%s-%s-%d-%d-%s-%d\n",dizi[y].ad,dizi[y].soyad,dizi[y].hesap_no,dizi[y].sifre,dizi[y].money.cins,dizi[y].money.miktar);
       fclose(fp);
       remove("C:\\Users\\harun yıldız\\Desktop\\staj\\2\\ATM_simulation\\test.txt");
       rename("test2.txt","test.txt");
}

void hesap_ozeti(struct musteri *dizi ,int y){

printf("\nad: %s \nsoyad: %s \nhesap no: %d\n sifre: %d\nhesapturu: %s\nbakiye: %d",dizi[y].ad,dizi[y].soyad,dizi[y].hesap_no,dizi[y].sifre,dizi[y].money.cins,dizi[y].money.miktar);

}


int main(){
int i,secim=0,secim2, y=1;
    char *strng, *strng2, satir[MAX_BOYUT];

        srand(time(NULL));
        FILE *tp = fopen("test.txt", "r");
        strng = fgets(satir,MAX_BOYUT,tp);
        strng = fgets(satir,MAX_BOYUT,tp);
            while(strng != NULL){
                strng2 = strtok(satir, "-");
                strcpy(dizi[y].ad, strng2);
                strng2 = strtok(NULL, "-");
                strcpy(dizi[y].soyad, strng2);
                strng2 = strtok(NULL, "-");
                sscanf(strng2,"%d", &dizi[y].hesap_no);
                strng2 = strtok(NULL, "-");
                sscanf(strng2,"%d", &dizi[y].sifre);
                strng2 = strtok(NULL, "-");
                strcpy(dizi[y].money.cins, strng2);
                strng2 = strtok(NULL, "\n");
                sscanf(strng2,"%d", &dizi[y].money.miktar);
                y++;
                diziboyu++;
                strng = fgets(satir,MAX_BOYUT,tp);
        }
        fclose(dosya);
        int h_no,h_sifre;
int a=0;int k=0;
        while(secim !=-1){
        printf("\nIslem seciniz:\n1.Giris\n2.Yeni hesap\nCikis yapmak icin -1 giriniz\n");
        scanf("%d", &secim);
        switch(secim){
        case 1://giriþ

                printf("Lutfen hesap no'nuzu giriniz:");
                scanf("%d", &h_no);
                printf("Lutfen hesap sifresini giriniz:");
                scanf("%d", &h_sifre);


                for(i=1;i<=diziboyu;i++)
                    {
                        if(dizi[i].hesap_no==h_no&&dizi[i].sifre==h_sifre){
                            a=1;
                            break;
                        }
                    }
                k++;
                if(k==3)
                printf("Sifreniz Bloke oldu.\nBaşka bir hesapla ");
                if(a==1){
                printf("\n\nGiris yapildi");
                while(secim2 !=-1){
                printf("\nCikis islemi icin -1 e basiniz");
                printf("\nYapmak istediginiz islemi seciniz\n");
                printf("Sifre degistimek icin 3 e basiniz\n");
                printf("Para cekmek icin 4 e basiniz\n");
                printf("Para yatirmak icin 5 e basiniz\n");
                printf("Hesap ozetini gormek icin 6 e basiniz\n");
                scanf("%d", &secim2);
                            switch(secim2){
                            case 3:
                            sifre_degistir(dizi,i);
                            break;
                            case 4:
                            get_para(dizi,i);
                            break;
                            case 5:
                            set_para(dizi,i);
                            break;
                            case 6:
                                printf("Hesap no : %d\n",dizi[i].hesap_no);
                            printf("Adi : %d\n",dizi[i].ad);
                            printf("Soyadi : %d\n",dizi[i].soyad);
                            printf("Hesap Bakiyesi : %d\n",dizi[i].money.miktar);
                                hesap_ozeti(dizi,i);
                            break;


                    }       }
                }

                else
                  printf("Giris yapilamadi");

        break;
        case 2:
        hesapekle(y);
            FILE *tp = fopen("test.txt", "r");
            strng = fgets(satir,MAX_BOYUT,tp);
            strng = fgets(satir,MAX_BOYUT,tp);
            while(strng != NULL){
                strng2 = strtok(satir, "-");
                strcpy(dizi[y].ad, strng2);
                strng2 = strtok(NULL, "-");
                strcpy(dizi[y].soyad, strng2);
                strng2 = strtok(NULL, "-");
                sscanf(strng2,"%d", &dizi[y].hesap_no);
                strng2 = strtok(NULL, "-");
                sscanf(strng2,"%d", &dizi[y].sifre);
                strng2 = strtok(NULL, "-");
                strcpy(dizi[y].money.cins, strng2);
                strng2 = strtok(NULL, "\n");
                sscanf(strng2,"%d", &dizi[y].money.miktar);
                y++;
                diziboyu++;
                strng = fgets(satir,MAX_BOYUT,tp);
        }
        fclose(dosya);

        break;


        }

}






return 0;
}
