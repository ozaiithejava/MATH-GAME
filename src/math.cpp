#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Fonksiyon prototipleri
int generateRandomNumber();
void askQuestion(int& num1, int& num2, char& operation);
bool checkAnswer(int num1, int num2, char operation, int userAnswer);

int main() {
    srand(static_cast<unsigned int>(time(0))); // Rastgele sayı üretimi için seed ayarı

    int score = 0; // Skor
    const int totalQuestions = 5; // Toplam soru sayısı
    const int timeLimit = 10; // Her soru için zaman sınırı (saniye)

    for (int i = 0; i < totalQuestions; ++i) {
        int num1, num2;
        char operation;
        askQuestion(num1, num2, operation);

        // Soruyu sorma işlemi
        time_t startTime = time(0); // Başlangıç zamanı
        int userAnswer;
        cout << "Cevabinizi girin: ";
        cin >> userAnswer;
        time_t endTime = time(0); // Bitiş zamanı

        // Cevabın doğruluğunu kontrol etme
        if (checkAnswer(num1, num2, operation, userAnswer) && (endTime - startTime) <= timeLimit) {
            cout << "Dogru! +1 puan\n";
            score++;
        } else {
            cout << "Yanlis veya sure asimi! Cevap: " << (operation == '+' ? num1 + num2 : (operation == '-' ? num1 - num2 : num1 * num2)) << "\n";
        }

        // Bir sonraki soruya geçmeden önce bekleme
        cout << "Bir sonraki soruya gecmek icin Enter'a basin.";
        cin.ignore(); // Önceki Enter'ı temizle
        cin.get();
    }

    // Oyun sonu mesajı
    cout << "Oyun bitti! Toplam Puan: " << score << "/" << totalQuestions << "\n";

    return 0;
}

// Rastgele bir sayı üretme fonksiyonu
int generateRandomNumber() {
    return rand() % 10 + 1; // 1 ile 10 arasında rastgele bir sayı üretir
}

// Soru sorma fonksiyonu
void askQuestion(int& num1, int& num2, char& operation) {
    num1 = generateRandomNumber();
    num2 = generateRandomNumber();
    operation = rand() % 3 == 0 ? '*' : (rand() % 2 == 0 ? '+' : '-');
    cout << "Soru: " << num1 << " " << operation << " " << num2 << "\n";
}

// Cevabın doğruluğunu kontrol etme fonksiyonu
bool checkAnswer(int num1, int num2, char operation, int userAnswer) {
    return operation == '+' ? (num1 + num2 == userAnswer) : (operation == '-' ? (num1 - num2 == userAnswer) : (num1 * num2 == userAnswer));
}
