#include <Arduino.h>
#include "WiFi.h"

void setup() {
  // Bilgisayar ile ESP32 arasındaki haberleşme hızı (Baud Rate)
  Serial.begin(115200);
  
  // ESP32'yi Wi-Fi İstasyon (Station) moduna alıyoruz
  WiFi.mode(WIFI_STA);
  
  // Mevcut bir bağlantı varsa koparıyoruz
  WiFi.disconnect();
  delay(100);
  
  Serial.println("Ağ tarayıcı başlatıldı. Güvenlik testleri için hazır...");
}

void loop() {
  Serial.println("Çevredeki ağlar taranıyor...");
  
  // Çevredeki ağların sayısını döndürür
  int n = WiFi.scanNetworks();
  
  if (n == 0) {
    Serial.println("Hiç ağ bulunamadı.");
  } else {
    Serial.print(n);
    Serial.println(" adet ağ tespit edildi:");
    
    for (int i = 0; i < n; ++i) {
      // SSID: Ağ adı | RSSI: Sinyal gücü | Encryption: Şifreleme türü
      Serial.printf("%d: %s (%d dBm) - %s\n", 
                    i + 1, 
                    WiFi.SSID(i).c_str(), 
                    WiFi.RSSI(i), 
                    (WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? "Açık Ağ (Riskli!)" : "Şifreli");
      delay(10);
    }
  }
  Serial.println("----------------------------------------------");
  
  // 5 saniyede bir yeniden tara
  delay(5000);
}