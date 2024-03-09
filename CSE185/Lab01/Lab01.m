% load
I = imread('01.jpg');
I1 = imread('01.jpg');
I2 = imread('02.jpg');
I3 = imread('03.jpg');
I4 = imread('04.jpg');
green = I;
avg1 = imread('05.jpg');
avg2 = imread('06.jpg');

% modify
green(:,:,2) = 0;

gray = 0.299*I(:,:,1) + 0.589*I(:,:,2) + 0.114*I(:,:,3);

rotate = imrotate(I, 90);

crop = imcrop(I,[30,100,270,300]);

flip = flipdim(I,2); %using flip normally did not work, I had to used flipdim

combine = zeros(300*2+10, 400*2+10,3,'uint8'); %uint8 is to do a weight of a full byte, if this is not added, the image will not look correct.
combine(1:300,1:400,:) = I1;
combine(1:300,416:815,:) = I2;
combine(316:615,416:815,:) = I4;
combine(316:615,1:400,:) = I3;

avg1 = avg1(:);
avg2 = avg2(:);
avg1 = reshape(avg1, 375, 1242, 3);
avg2 = reshape(avg2, 375, 1242, 3);
average = (avg1 + avg2)/2;


% show
figure, imshow(I);
figure, imshow(green);
figure, imshow(gray);
figure, imshow(rotate);
figure, imshow(crop);
figure, imshow(flip);
figure, imshow(combine);
figure, imshow(average);

% save
imwrite(green,'green.jpg');
imwrite(gray,'gray.jpg');
imwrite(rotate,'rotate.jpg');
imwrite(crop,'crop.jpg');
imwrite(flip,'flip.jpg');
imwrite(combine,'combine.jpg');
imwrite(average,'average.jpg');