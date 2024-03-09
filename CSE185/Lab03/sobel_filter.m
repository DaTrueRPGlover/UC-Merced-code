function output = sobel_filter(img, kernel)
    I2 = zeros(size(img), 'double');
    for u = 2 : size(img, 2) - 1
        for v = 2 : size(img, 1) - 1
            x1 = u - 1; x2 = u + 1;
            y1 = v - 1; y2 = v + 1;
            patch = img(y1:y2, x1:x2);
            npatch = reshape(patch,[9,1]);
            nkernel = reshape(kernel,[1,9]);
            result = nkernel * npatch;
            I2(v, u) = result;
        end
    end
    output = I2;
end


