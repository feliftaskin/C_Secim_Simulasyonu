# Seçim Simülasyonu

## 📌 Proje Hakkında
Bu proje, bir seçim simülasyonu oluşturarak kullanıcılardan alınan oy verilerine göre milletvekili dağılımını hesaplar. Ayrıca, en çok oy alan partiyi belirler ve iktidar ile ana muhalefet partilerini tespit eder.

## 🛠️ Teknolojiler ve Gereksinimler
- **Programlama Dili:** C
- **IDE:** Dev-C++, Code::Blocks
- **İşletim Sistemi:** Windows
- **Derleyici:** GCC


## 📖 Kullanım Adımları
1. Kullanıcı, 5 il ve 6 parti için oy bilgilerini girer.
2. Kullanıcı her il için milletvekili kontenjanlarını belirler.
3. Sistem, en fazla oy alan partilere milletvekili atamalarını yapar.
4. Oylar yarıya düşürülerek milletvekili atama süreci tamamlanır.
5. Sonuçlar görüntülenir:
   - Her ilde en çok oy alan parti belirlenir.
   - Partilerin toplam milletvekili sayısı hesaplanır.
   - İktidar ve ana muhalefet partileri belirlenir.

## 🔍 Algoritma
1. Kullanıcıdan parti oylarını ve milletvekili kontenjanlarını al.
2. Her ilde en çok oy alan partiyi belirle.
3. En çok oy alan partiye bir milletvekili ata.
4. Partinin oy sayısını yarıya düşür.
5. Tüm kontenjanlar dolana kadar 3. ve 4. adımları tekrarla.
6. Ülke genelinde toplam milletvekili ve oy yüzdelerini hesapla.
7. En fazla oyu alan parti iktidar olur, ikinci parti ana muhalefet olur.

## 🤝 Katkıda Bulunma
Katkıda bulunmak isterseniz, lütfen bir **issue** açın veya bir **pull request** gönderin.

## 📜 Lisans
Bu proje **MIT Lisansı** altında sunulmaktadır.

---
**📌 Not:** Bu proje eğitim amaçlı geliştirilmiştir ve gerçek seçim sistemlerini yansıtmaz.

