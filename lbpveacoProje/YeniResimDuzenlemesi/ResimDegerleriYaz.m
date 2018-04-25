close all; clear all; clc;
% image loading
filename = 'resim17';
img = imread([filename '.jpg'])
resizedimage = imresize(img, [200 300]);
if size(resizedimage,3)==3
    sonuc = rgb2gray(resizedimage);
else
    sonuc = resizedimage;
end   

imwrite(sonuc,['..\resimler\' filename '.jpg']);
dlmwrite(['..\resimdegerleri\' filename 'degerler.txt'], sonuc , ' ');