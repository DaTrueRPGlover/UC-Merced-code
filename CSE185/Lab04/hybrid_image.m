function [img_merged1, img_merged2] = hybrid_image(img1, img2, ratio)
    %% Split img 1 and img2 into low/high frequency maps
    [img1_low, img1_high] = separate_frequency(img1, ratio);
    [img2_low, img2_high] = separate_frequency(img2, ratio);
    img_merged1 = img1_low + img2_high;
    img_merged2 = img2_low + img1_high;
end