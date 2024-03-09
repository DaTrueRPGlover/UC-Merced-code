function [output, match] = template_matching_normcorr(img, template, threshold)
    output = zeros(size(img,1), size(img,2), 1);
    for u = 1 + floor((size(template, 2)/2)) : size(img, 2) - floor((size(template, 2)/2))
        for v = 1 + floor((size(template, 1)/2)) : size(img, 1) - floor((size(template, 1)/2))

            x1 = u - floor(size(template, 2)/2); x2 = u + floor(size(template, 2)/2);
            y1 = v - floor(size(template, 1)/2); y2 = v + floor(size(template, 1)/2);
            patch = img(y1:y2, x1:x2);

            % Normalized Cross Correlation
            vector_patch = patch(:);
            vector_template = template(:);

            sub_mean_patch = vector_patch - mean(vector_patch);
            sub_mean_template  = vector_template - mean(vector_template);

            mag_patch = norm(sub_mean_patch);
            mag_template = norm(sub_mean_template);

            norm_patch = sub_mean_patch / mag_patch;
            norm_template = sub_mean_template / mag_template;

            value = sum(sum(norm_patch .* norm_template));

            output(v, u) = value;

        end
    end

match = (output > threshold); 
end
    