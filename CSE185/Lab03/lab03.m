img = im2double(imread('lena.jpg'));

%% Sobel Filter
H = [1, 2, 1; 0, 0, 0; -1, -2, -1];% horizontal edge
V = [1, 0, -1; 2, 0, -2; 1, 0, -1];% vertical edge

%% Gaussian filter
hsize = 5; sigma = 2;
hsize2 = 9; sigma2 = 4;

img_gaussian_5 = gaussian_filter(img, hsize, sigma);
img_gaussian_9 = gaussian_filter(img, hsize2, sigma2);


img_sobel_horizontal = sobel_filter(img, H);
img_sobel_vertical = sobel_filter(img, V);

%test = img_sobel_horizontal + img_sobel_vertical;

%figure, imshow(img_sobel_horizontal);
%figure, imshow(img_sobel_vertical);
%figure, imshow(test);
figure, imshow(img_gaussian_5);
figure, imshow(img_gaussian_9);

imwrite(img_sobel_horizontal, 'sobel_h.jpg');
imwrite(img_sobel_vertical, 'sobel_v.jpg');
imwrite(img_gaussian_5, 'gaussian_5.jpg');
imwrite(img_gaussian_9, 'gaussian_9.jpg');