function output = median_filter(I, s)
    I2 = zeros(size(I), 'uint8');
    for u = 1 + round(s/2) : size(I, 2) - round(s/2)
        for v = 1 + round(s/2) : size(I, 1) - round(s/2)
            x1 = u - round(s/2); x2 = u + round(s/2);
            y1 = v - round(s/2); y2 = v + round(s/2);
            patch = I(y1:y2, x1:x2);
            patch2 = median(patch);
            value = median(patch2);
            I2(v, u) = value;
        end
    end
    output = I2;
end