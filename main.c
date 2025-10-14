#include <stdio.h>  // giriş çıkış işlemleri için atadik
#include <stdbool.h> // c dilinde bool veri tipini kullanmak icin atadık true,false gibi kontrolleri saglar

// Girdi tamponunu temizleyen küçük yardımcı fonksiyon
void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // boş döngü: tüm karakterleri okur ve çöpe atar
    }
}

int main(void) {
    char ch1, ch2; // kullanicinin girdigi karakterler
    int num1, num2, sum; // num1 ve num2 bu karakterlerin sayiya cevrilmis halleri sum ise toplanmis hali

    printf("6-Bit Kodlama Simulasyonu (stdbool.h versiyonu)\n");

    while (1) {  // ana döngü,dogru giris yapılana kadar tekrar tekrar çalisir
        bool isValid = true;  // gecerli giris kontrolu

        printf("Birinci rakami giriniz (0-9): "); // kullanıicidan karakter alinir
        if (scanf(" %c", &ch1) != 1) {
            printf("Hata: Girdi okunamadi.\n\n"); // eger girilen karakter rakam degilse hata verir döngü basa döner
            clearInputBuffer(); // fazla karakterleri temizlemek için kullanilir
            continue;
        }

        // fazladan karakter girildiyse tamponu temizler,hala daha rakam disinda 12,d gibi karakterler varsa temizler ve hata verir
        if (getchar() != '\n') {
            printf("Hata: Tek bir rakam girmelisiniz.\n\n");
            clearInputBuffer();
            continue;
        }

        num1 = ch1 - '0';  // "0" karakterinin ASCII değeri çıkarılarak karakterden sayı elde edilir. örn; 3-0=3
        if (num1 < 0 || num1 > 9) {
            printf("Hata: Ilk girdi 0-9 araliginda tek haneli rakam olmali.\n\n");
            continue;
        }

        printf("Ikinci rakami giriniz (0-9): ");  // aynı işlemler 2. girilen karakter içinde uygulanır
        if (scanf(" %c", &ch2) != 1) {
            printf("Hata: Girdi okunamadi.\n\n");
            clearInputBuffer();
            continue;
        }

        // yine fazladan karakter kontrolü
        if (getchar() != '\n') {
            printf("Hata: Tek bir rakam girmelisiniz.\n\n");
            clearInputBuffer();
            continue;
        }

        num2 = ch2 - '0';
        if (num2 < 0 || num2 > 9) {
            printf("Hata: Ikinci girdi 0-9 araliginda tek haneli rakam olmali.\n\n");
            continue;
        }

        sum = num1 + num2;

        if (sum > 9) {  // toplam tek haneli degilse hata verir aynı zamanda sonucu da ekrana yazar
            printf("Hata: Sonuc %d oldu, 9'dan buyuk! Tek haneli toplam bekleniyor.\n\n", sum);
            continue;
        }

        printf("Toplam sonucu (6-bit simule): %c\n", sum + '0'); // toplam tekrar karaktere cevrilir
        break;
    }

    return 0; // sonlanir
}
