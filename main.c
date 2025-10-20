#include <stdio.h>

// Girdi tamponunu temizleyen fonksiyon
void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // Boş döngü: tüm karakterleri okur ve yok eder
    }
}

int main(void) {
    double yatirim_getirisi, risksiz_faiz, standart_sapma, sharpe_orani;

    printf("=== Sharpe Orani Hesaplayici ===\n");

    printf("Yatirim getirisi (%% cinsinden): ");
    if (scanf("%lf", &yatirim_getirisi) != 1) {
        printf("Gecersiz giris! Lütfen sayi giriniz.\n");
        return 1;
    }
    clearInputBuffer();

    printf("Risksiz faiz orani (%% cinsinden): ");
    if (scanf("%lf", &risksiz_faiz) != 1) {
        printf("Gecersiz giris! Lütfen sayi giriniz.\n");
        return 1;
    }
    clearInputBuffer();

    printf("Portfoyun standart sapmasi (%% cinsinden): ");
    if (scanf("%lf", &standart_sapma) != 1) {
        printf("Gecersiz giris! Lütfen sayi giriniz.\n");
        return 1;
    }
    clearInputBuffer();

    // Negatif veya sıfır standart sapma kontrolü
    if (standart_sapma <= 0) {
        printf("Standart sapma 0 veya negatif olamaz.\n");
        return 1;
    }

    // Sharpe oranı hesaplama
    sharpe_orani = (yatirim_getirisi - risksiz_faiz) / standart_sapma;

    printf("\nSharpe Orani = %.2f\n", sharpe_orani);

    // Yorumsal değerlendirme
    if (sharpe_orani < 0)
        printf("-> Sharpe orani %.2f: Yatirim, risksiz getiriye gore daha kotu performans gostermis.\n", sharpe_orani);
    else if (sharpe_orani == 0)
        printf("-> Sharpe orani %.2f: Yatirim, sadece risksiz getiri kadar kazandirmis. Ekstra getirisi yok.\n", sharpe_orani);
    else if (sharpe_orani < 1)
        printf("-> Sharpe orani %.2f: Risk-getiri orani dusuk. Iyi gunler.\n", sharpe_orani);
    else if (sharpe_orani < 2)
        printf("-> Sharpe orani %.2f: Iyi bir performans. Iyi gunler.\n", sharpe_orani);
    else if (sharpe_orani < 3)
        printf("-> Sharpe orani %.2f: Cok iyi bir performans. Iyi gunler.\n", sharpe_orani);
    else if (sharpe_orani >= 3)
        printf("-> Sharpe orani %.2f: Mukemmel bir performans! Iyi gunler.\n", sharpe_orani);

    return 0;
}

