close all; clear all; clc;
% image loading
filename = 'resim17';
resimOrijinal = dlmread([ filename 'degerler.txt']);
resimOnisleme = dlmread([ filename 'onisleme.txt']);
resimKenarlar = dlmread([ filename 'kenarlar.txt']);
A = uint8(resimOrijinal);
B = uint8(resimOnisleme);
C = uint8(resimKenarlar);
imwrite(A,['..\Sonhaller\' filename 'orijinal.jpg']);
imwrite(B,['..\Sonhaller\' filename 'onisleme.jpg']);
imwrite(C,['..\Sonhaller\' filename 'kenarlar.jpg']);
