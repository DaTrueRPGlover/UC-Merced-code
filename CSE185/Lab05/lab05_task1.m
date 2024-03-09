img1 = im2double(imread('lena.jpg'));
%% Gaussian Pyramid
sigma = 2.0;
hsize = 7;
scale = 5;

I2 = img1;
for s = 1 : scale
    I2 = gaussian_filter(I2, hsize, sigma);
    %figure, imshow(I2);
    imwrite(I2, sprintf('Gaussian_scale%d.jpg', s));
    I2 = imresize(I2,(0.5));
end

%% Laplacian Pyramid
I3 = img1;
I3o = img1;
for s = 1 : scale
    I3 = gaussian_filter(I3, hsize, sigma);
    I4 = I3o - I3;
    %figure, imshow(I4 + 0.5);
    imwrite(I4 + 0.5, sprintf('Laplacian_scale%d.jpg', s))
    I3o = imresize(I3,(0.5));
    I3 = imresize(I3,(0.5));
end