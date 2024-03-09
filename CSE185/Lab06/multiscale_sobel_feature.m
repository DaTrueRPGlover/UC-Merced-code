function feature = multiscale_sobel_feature(img, scale)
    
feature = [];

    for i = 1:scale

        [~, f] = sobel_feature(img);

        feature = cat(1, feature, f(:));

        img = imresize(img,(0.5));

    end
end