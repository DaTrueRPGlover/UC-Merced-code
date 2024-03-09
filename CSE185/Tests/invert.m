function output = invert(img)
    %% Color channels
    redChannel = img(:,:,1);
    greenChannel = img(:,:,2);
    blueChannel = img(:,:,3);

    %% Black template
    zeroTemplate = zeros(size(img, 1), size(img, 2),"uint8");

    invertedImg = zeroTemplate + (255 - redChannel) + (255 - blueChannel) + (255 - greenChannel);

    output = invertedImg;
end