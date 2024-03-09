I1 = imread("01.jpg");
I2 = zeros(300,400,3,'uint8');
I3 = zeros(300,400,3,'uint8');
img1 = imread('lena_noisy.jpg');

%x2 = cos(pi/4)*()

%forward warping rotate by 45 degrees
for d = 1:3
    for y1 = 1:300
        for x1 = 1:400
            x2 = cos(pi/4)*(x1-(400/2)) + sin(pi/4)*(y1-(300/2)) + (400/2);
            y2 = -sin(pi/4)*(x1-(400/2)) + cos(pi/4)*(y1-(300/2)) + (300/2);
            x2 = round(x2);
            y2 = round(y2);
            if y2 >= 1 && y2 <= 300 && x2 >= 1 && x2 <= 400
                I2(y2, x2, d) = I1(y1, x1, d);
            end
        end
    end
end    
%end of forward rotate by 45 degrees

%backwards warping rotate by 45 degrees
for d = 1:3
    for y1 = 1:300
        for x1 = 1:400
            x3 = cos(pi/4)*(x1-(400/2)) - sin(pi/4)*(y1-(300/2)) + (400/2);
            y3 = sin(pi/4)*(x1-(400/2)) + cos(pi/4)*(y1-(300/2)) + (300/2);
            x3 = round(x3);
            y3 = round(y3);
            if y3 >= 1 && y3 <= 300 && x3 >= 1 && x3 <= 400
                I3(y1, x1, d) = I1(y3, x3, d);
            end
        end
    end
end    
%backwards rotate fills every pixel by getting the values from the original
%photo, that is why it does not make any holes

%end of backwards rotate

median1 = median_filter(img1, 3);
imwrite(median1, 'median_0.jpg');

median2 = median_filter(img1, 5);
imwrite(median2, 'median_1.jpg');

%median3 = median_filter(img1, 100);

%rot0 = imrotate(I, 45,"nearest",'crop');

figure, imshow(I2);
figure, imshow(I3);
figure, imshow(median1);
figure, imshow(median2);
%figure, imshow(median3);

imwrite(I2,'rotate_0.jpg');
imwrite(I3, 'rotate_1.jpg');
