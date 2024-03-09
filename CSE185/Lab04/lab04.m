%% Task 1: Split Frequency
img = im2double(imread('lena.jpg'));
I1 = im2double(imread('marilyn.jpg'));
I2 = im2double(imread('einstein.jpg'));
NY = im2double(imread('new_york.jpg'));
FW = im2double(imread('flowers.jpg'));

r1 = 0.1;

[low_pass1, high_pass1] = separate_frequency(img, r1);

figure, imshow(low_pass1);
figure, imshow(high_pass1 + 0.5);
imwrite(low_pass1, 'lena_low_0.1.jpg');
imwrite(high_pass1 + 0.5, 'lena_high_0.1.jpg');

r2 = 0.2;
[low_pass2, high_pass2] = separate_frequency(img, r2);

figure, imshow(low_pass2);
figure, imshow(high_pass2 + 0.5);
imwrite(low_pass2, 'lena_low_0.2.jpg');
imwrite(high_pass2 + 0.5, 'lena_high_0.2.jpg');

%% Hybrid images
r3 = 0.2;

[hybrid1, hybrid2] = hybrid_image(I1, I2, r3);

figure, imshow(hybrid1);
figure, imshow(hybrid2);
imwrite(hybrid1, 'hybrid_1.jpg');
imwrite(hybrid2, 'hybrid_2.jpg');

%% Phase test
phase1 = phase_images(NY);
phase2 =phase_images(FW);
