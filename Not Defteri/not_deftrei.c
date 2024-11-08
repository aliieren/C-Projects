#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_NOT_SAYISI 100
#define MAX_NOT_UZUNLUGU 256

typedef struct {
    char icerik[MAX_NOT_UZUNLUGU];
} Not;

Not notlar[MAX_NOT_SAYISI];
int notSayisi = 0;

void notEkle() {
	
	setlocale(LC_ALL, "Turkish");
	
    if (notSayisi >= MAX_NOT_SAYISI) {
        printf("Maksimum not say�s�na ula��ld�.\n");
        return;
    }

    printf("Yeni notunuzu girin: ");
    getchar();  
    fgets(notlar[notSayisi].icerik, MAX_NOT_UZUNLUGU, stdin);
    notlar[notSayisi].icerik[strcspn(notlar[notSayisi].icerik, "\n")] = '\0'; 

    notSayisi++;
    printf("Not ba�ar�yla eklendi!\n");
}

void notlariGoruntule() {
	setlocale(LC_ALL, "Turkish");
    if (notSayisi == 0) {
        printf("Kaydedilmi� not bulunmuyor.\n");
        return;
    }

	int i;
    for ( i = 0; i < notSayisi; i++) {
        printf("\n %d. Not: %s\n", i + 1, notlar[i].icerik);
    }
}

void notSil() {
	setlocale(LC_ALL, "Turkish");
    int silinecekNot;
    printf("\nSilmek istedi�iniz notun numaras�n� girin: ");
    scanf("%d", &silinecekNot);

    if (silinecekNot < 1 || silinecekNot > notSayisi) {
        printf("Ge�ersiz not numaras�.\n");
        return;
    }
	
	int i;
	
    for ( i = silinecekNot - 1; i < notSayisi - 1; i++) {
        notlar[i] = notlar[i + 1];
    }
    notSayisi--;
    printf("Not ba�ar�yla silindi!\n");
}



int main() {
	
	setlocale(LC_ALL, "Turkish");
	
    int secim;

    do {
        printf("\n--- Not Defteri Uygulamas� ---\n");
        printf("1. Not Ekle\n");
        printf("2. Notlar� G�r�nt�le\n");
        printf("3. Not Sil\n");
        printf("4. ��k��\n");
        printf("Se�iminizi girin: ");
        scanf("%d\n", &secim);

        switch (secim) {
            case 1:
                notEkle();
                break;
            case 2:
                notlariGoruntule();
                break;
            case 3:
                notSil();
                break;
            case 4:
                printf("Uygulamadan ��k�l�yor...\n");
                break;
            default:
                printf("Ge�ersiz se�im! L�tfen tekrar deneyin.\n");
        }
    } while (secim != 4);

    return 0;
}


