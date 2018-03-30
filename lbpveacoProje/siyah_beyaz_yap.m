function [ sonuc ] = siyah_beyaz_yap( dosya_adi )
% sonuc fonksiyonuna'siyah_beyaz_yap' komutuyla islem yaptiriyoruz.

%resim dosyasini acalim
A= imread(dosya_adi);
%resmi siyah beyaza dondur ve sonuc'a kaydet
sonuc = rgb2gray(A);

return;

end