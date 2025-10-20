#include <stdio.h> // girdi çıkış işlemleri için atadık
#include <stdbool.h> // c dilinde bool veri tipini kullanmak için atadık true,false gibi kontrolleri sağlar

// Girdi tamponu temizleyen küçük yardımcı fonksiyon
void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // boş döngü: tüm karakterleri okur ve çöpe atar
    }
}

int main(void) {
    char ch1, ch2; // kullanıcının girdiği karakterler
    int num1, num2, sum; // num1 ve num2 bu karakterlerin sayıya çevrilmiş halleri sum ise toplanmış hali

    printf("6-Bit Kodlama Simulasyonu (stdbool.h versiyonu)\n");

    while (1) { // ana döngü,doğru girdi yapılana kadar tekrar tekrar çalışır
        bool isValid = true; // geçerli giriş kontrolü

        printf("Birinci rakamı giriniz (0-9) : ");  //kullanicidan karakter alinir
        if (scanf(" %c", &ch1) != 1) {
            printf("Hata: Girdi okunamadı.\n\n"); // eğer girilen karakter rakam değilse hata verir döngü başa döner
            clearInputBuffer(); // fazla karakterleri temizlemek için kullanılır
            continue;
        }

        // fazladan karakter girildiyse tamponu temizler, hala daha rakam dışında 12,d gibi karakterler varsa temizler ve hata verir
        if (getchar() != '\n') {
            printf("Hata: Tek bir rakam girmelisiniz.\n\n");
            clearInputBuffer();
            continue;
        }

        num1 = ch1 - '0'; // '0' karakterinin ASCII değeri çıkarılarak karakterden sayı elde edilir. örn; 3-0=3
        if (num1 < 0 || num1 > 9) {
            printf("Hata: İlk girdi 0-9 aralığında tek haneli rakam olmalı.\n\n");
            continue;
        }

        printf("Ikinci rakamı giriniz (0-9): "); // aynı işlemler 2. girilen karakter içinde uygulanır
        if (scanf(" %c", &ch2) != 1) {
            printf("Hata: Girdi okunamadı.\n\n");
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
            printf("Hata: İkinci girdi 0-9 aralığında tek haneli rakam olmalı.\n\n");
            continue;
        }

        sum = num1 + num2;

        if (sum > 9) { // toplam tek haneli değilse hata verir aynı zamanda sonucu da ekrana yazar
            printf("Hata: Sonuç %d oldu, 9'dan büyük! Tek haneli toplam bekleniyor.\n\n", sum);
            continue;
        }

        printf("Toplam sonucu (6-bit simule): %c\n", sum + '0'); // toplam tekrar karaktere çevrilir
        break;
    }

    return 0; // sonlanır
}
