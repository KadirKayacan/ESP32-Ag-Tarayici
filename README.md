# ESP32 Ağ Tarayıcısı

## Genel Bakış

Bu proje, ESP32 mikrodenetleyicisi üzerinde çalışan, C++ ile geliştirilmiş bir **kablosuz ağ tarayıcısı** aracıdır. ESP32'nin Wi-Fi yeteneklerini kullanarak çevredeki erişim noktalarını (AP) tarar, sinyal gücünü (RSSI) ölçer, açık/şifreli ağları tespit eder ve MAC adresi, kanal, şifreleme türü gibi bilgileri toplar. Amaç, gömülü sistemler üzerinde siber güvenlik ve kablosuz ağ analizi konularında öğrenme ve yetkili güvenlik testleri yapmaktır.

## Özellikler

- Çevredeki tüm Wi-Fi ağlarını SSID, RSSI ve şifreleme türü ile birlikte tarama
- Açık ağları (WIFI_AUTH_OPEN) otomatik olarak "Açık Ağ (Riskli!)" şeklinde işaretleme
- Şifreli ağları (WPA/WPA2/WPA3/WEP) tespit etme
- Seri port (115200 baud) üzerinden gerçek zamanlı, numaralandırılmış çıktı
- 5 saniyede bir otomatik tekrarlı tarama döngüsü
- ESP32'yi Station (STA) moduna alıp önceki bağlantıları temizleyerek temiz bir tarama ortamı sağlama

## Teknolojiler

- C++ (Arduino framework / ESP-IDF)
- ESP32 (ESP-WROOM-32 veya benzeri)
- PlatformIO veya Arduino IDE
- Kütüphaneler:
  - WiFi.h (ESP32 dahili Wi-Fi kütüphanesi)
  -  Arduino.h (Temel Arduino fonksiyonları)

## Kurulum

```bash
git clone https://github.com/USERNAME/esp32-network-scanner.git
cd esp32-network-scanner

# PlatformIO kullanıyorsan:
pio run --target upload

# Arduino IDE kullanıyorsan:
# 1. Arduino IDE'yi aç
# 2. Board Manager'dan "esp32" paketini kur
# 3. Karta "ESP32 Dev Module" seç
# 4. esp32_network_scanner.ino dosyasını aç ve yükle
```

## Kullanım

```bash
# PlatformIO ile derleme ve yükleme
pio run --target upload

# Seri monitörü aç (115200 baud)
pio device monitor -b 115200
```

Cihaz açıldıktan sonra herhangi bir komut girmeye gerek yoktur; kod otomatik olarak 5 saniyede bir tarama yapar. Seri porttan aşağıdaki gibi bir çıktı görürsünüz:

```text
Ağ tarayıcı başlatıldı. Güvenlik testleri için hazır...
Çevredeki ağlar taranıyor...
5 adet ağ tespit edildi:
1: EvWiFi (-45 dBm) - Şifreli
2: Cafe_Free (-72 dBm) - Açık Ağ (Riskli!)
3: Ofis_5G (-58 dBm) - Şifreli
4: Misafir (-80 dBm) - Açık Ağ (Riskli!)
5: IoT_Node (-66 dBm) - Şifreli
----------------------------------------------
```

## Proje Yapısı

```text
esp32-network-scanner/
├── src/
│   └── main.cpp          # Ana uygulama (setup + loop)
├── platformio.ini        # PlatformIO yapılandırması
├── requirements.txt      # (Boş / yalnızca geliştirme araçları)
├── README.md
├── .gitignore
└── LICENSE
```

## Güvenlik ve Sorumlu Kullanım

Bu aracı yalnızca **sahibi olduğunuz** veya **test izni aldığınız** sistemlerde kullanın. Başkalarına ait kablosuz ağları izinsiz taramak, dinlemek veya müdahale etmek çoğu ülkede yasalara aykırıdır. Bu proje yalnızca eğitim ve yetkili güvenlik araştırması amacıyla geliştirilmiştir. Kullanıcı, aracın kullanımından doğacak tüm yasal sorumluluğu kabul eder.


