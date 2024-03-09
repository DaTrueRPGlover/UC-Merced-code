function [magnitude, orientation] = sobel_feature(img)
    
    % horizontal edge
    Hy = [1, 2, 1; 0, 0, 0; -1, -2, -1];
    % vertical edge
    Hx = [1, 0, -1; 2, 0, -2; 1, 0, -1];

    %% Sobel filtering
    sobel_img_horizontal = sobel_filter(img, Hy);
    sobel_img_vertical = sobel_filter(img, Hx);

    %% Magnitude and Orientation
    magnitude = sqrt((sobel_img_horizontal).^2 + (sobel_img_vertical).^2);
    orientation = atan2(sobel_img_horizontal, sobel_img_vertical);

end

