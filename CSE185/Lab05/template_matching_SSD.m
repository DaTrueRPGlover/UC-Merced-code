function [output, match] = template_matching_SSD(img, template, threshold)
    output = zeros(size(img,1), size(img,2), 1);
    for u = 1 + floor((size(template, 2)/2)) : size(img, 2) - floor((size(template, 2)/2))
        for v = 1 + floor((size(template, 1)/2)) : size(img, 1) - floor((size(template, 1)/2))

            x1 = u - floor(size(template, 2)/2); x2 = u + floor(size(template, 2)/2);
            y1 = v - floor(size(template, 1)/2); y2 = v + floor(size(template, 1)/2);
            patch = img(y1:y2, x1:x2);

            % SSD
            value = sum(sum((patch - template).^2));
            output(v, u) = value;

        end
    end

match = (output < threshold);    