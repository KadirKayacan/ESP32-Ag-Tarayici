# ESP32 Ağ Tarayıcısı

## Genel Bakış

Bu proje, ESP32 mikrodenetleyicisi üzerinde çalışan, C++ ile geliştirilmiş bir **kablosuz ağ tarayıcısı** aracıdır. ESP32'nin Wi-Fi yeteneklerini kullanarak çevredeki erişim noktalarını (AP) tarar, sinyal gücünü (RSSI) ölçer, açık/şifreli ağları tespit eder ve MAC adresi, kanal, şifreleme türü gibi bilgileri toplar. Amaç, gömülü sistemler üzerinde siber güvenlik ve kablosuz ağ analizi konularında öğrenme ve yetkili güvenlik testleri yapmaktır.

## Özellikler

- Çevredeki tüm Wi-Fi ağlarını (SSID, BSSID/MAC, kanal, RSSI) tarama
- Açık ve şifreli ağların (WPA/WPA2/WPA3/WEP) ayrımını yapma
- Seri port üzerinden gerçek zamanlı çıktı ve tarama sonuçlarının listelenmesi
- Web arayüzü (ESP32 dahili HTTP sunucusu) üzerinden tarama sonuçlarını görüntüleme
- Belirli bir SSID veya kanal aralığına göre filtreleme
- Tekrarlı (interval) tarama modu
- Opsiyonel: SD karta veya SPIFFS'e tarama kayıtlarını (log) yazma

## Teknolojiler

- C++ (Arduino framework / ESP-IDF)
- ESP32 (ESP-WROOM-32 veya benzeri)
- PlatformIO veya Arduino IDE
- Kütüphaneler:
  - `WiFi.h` (ESP32 dahili Wi-Fi kütüphanesi)
  - `WebServer.h` (ESP32 dahili HTTP sunucusu)
  - `SPIFFS.h` / `SD.h` (log kayıt için)
  - `ArduinoJson` (web arayüzü için JSON çıktısı)
  - `ESPAsyncWebServer` (opsiyonel, daha performanslı web sunucusu)

## Kurulum

```bash
git clone https://github.com/USERNAME/esp32-network-scanner.git
cd esp32-network-scanner

# PlatformIO kullanıyorsan
pio run

# Arduino IDE kullanıyorsan
# 1. Arduino IDE'yi aç
# 2. ESP32 board paketini Board Manager'dan kur
# 3. Gerekli kütüphaneleri Library Manager'dan yükle
# 4. esp32_network_scanner.ino dosyasını aç ve yükle
```

## Kullanım

```bash
# PlatformIO ile derleme ve yükleme
pio run --target upload

# Seri monitörü aç (115200 baud)
pio device monitor -b 115200
```

Cihaz açıldıktan sonra seri porttan aşağıdaki komutlar kullanılabilir:

```text
scan              # Tek seferlik ağ taraması başlat
scan --interval 10 # 10 saniyede bir otomatik tarama
scan --channel 1-6 # Sadece 1-6 kanallarını tara
scan --open-only  # Sadece açık ağları listele
list              # Son tarama sonuçlarını göster
clear             # Ekranı/sonuçları temizle
help              # Komut listesi
```

Web arayüzüne erişim için: Cihaz bağlandıktan sonra seri portta yazan IP adresini tarayıcıda açın (ör. `http://192.168.4.1`).

## Proje Yapısı

```text
esp32-network-scanner/
├── src/
│   ├── main.cpp              # Ana uygulama giriş noktası
│   ├── wifi_scanner.cpp      # Wi-Fi tarama mantığı
│   ├── wifi_scanner.h
│   ├── web_server.cpp        # Web arayüzü ve API endpoint'leri
│   ├── web_server.h
│   ├── logger.cpp            # SPIFFS/SD log kayıtları
│   └── logger.h
├── include/
│   └── config.h              # Wi-Fi, pin ve sabit tanımları
├── data/
│   └── index.html            # Web arayüzü HTML dosyası
├── platformio.ini            # PlatformIO yapılandırması
├── requirements.txt          # (Python yardımcı scriptler için)
├── README.md
├── .gitignore
└── LICENSE
```

## Güvenlik ve Sorumlu Kullanım

Bu aracı yalnızca **sahibi olduğunuz** veya **test izni aldığınız** sistemlerde kullanın. Başkalarına ait kablosuz ağları izinsiz taramak, dinlemek veya müdahale etmek çoğu ülkede yasalara aykırıdır. Bu proje yalnızca eğitim ve yetkili güvenlik araştırması amacıyla geliştirilmiştir. Kullanıcı, aracın kullanımından doğacak tüm yasal sorumluluğu kabul eder.


