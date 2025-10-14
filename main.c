#include <stdio.h>
#include <stdbool.h>

// Girdi tamponunu temizleyen küçük yardımcı fonksiyon
void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // boş döngü: tüm karakterleri okur ve çöpe atar
    }
}

int main(void) {
    char ch1, ch2;
    int num1, num2, sum;

    printf("6-Bit Kodlama Simulasyonu (stdbool.h versiyonu)\n");

    while (1) {
        bool isValid = true;

        printf("Birinci rakami giriniz (0-9): ");
        if (scanf(" %c", &ch1) != 1) {
            printf("Hata: Girdi okunamadi.\n\n");
            clearInputBuffer();
            continue;
        }

        // fazladan karakter girildiyse tamponu temizle
        if (getchar() != '\n') {
            printf("Hata: Tek bir rakam girmelisiniz.\n\n");
            clearInputBuffer();
            continue;
        }

        num1 = ch1 - '0';
        if (num1 < 0 || num1 > 9) {
            printf("Hata: Ilk girdi 0-9 araliginda tek haneli rakam olmali.\n\n");
            continue;
        }

        printf("Ikinci rakami giriniz (0-9): ");
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

        if (sum > 9) {
            printf("Hata: Sonuc %d oldu, 9'dan buyuk! Tek haneli toplam bekleniyor.\n\n", sum);
            continue;
        }

        printf("Toplam sonucu (6-bit simule): %c\n", sum + '0');
        break;
    }

    return 0;
}

