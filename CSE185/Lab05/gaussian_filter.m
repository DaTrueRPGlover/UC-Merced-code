function output = gaussian_filter(img, hsize, sigma)
    %H = fspecial('gaussian', hsize, sigma);
    H = gaussian_kernel(hsize, sigma);
    I2 = zeros(size(img), 'double');
    for u = 1 +  floor(hsize/2): size(img, 2) - floor(hsize/2)
        for v = 1 + floor(hsize/2) : size(img, 1) - floor(hsize/2)
            x1 = u - floor(hsize/2); x2 = u + floor(hsize/2);
            y1 = v - floor(hsize/2); y2 = v + floor(hsize/2);
            patch = img(y1:y2, x1:x2);
            npatch = patch(:);
            nH = H(:);
            nH = nH';
            result = nH * npatch;
            I2(v, u) = result;
        end
    end
    output = I2;
end