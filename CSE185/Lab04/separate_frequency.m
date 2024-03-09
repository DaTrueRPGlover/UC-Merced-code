function [low_pass_img, high_pass_img] = split_frequency(img, ratio) 
    %% Use fft2() to apply fast Fourier Transformation
    frequency_map = fft2(img);
    %% Use fftshift() to rearrange the frequency map
    frequency_map_shifted = fftshift(frequency_map);
    %% Compute a low-frequency mask
    centerY = size(img, 1)/2;
    centerX = size(img, 2)/2;
    y1 = centerY - (ratio * size(img, 1)/2);
    y2 = centerY + (ratio * size(img, 1)/2);
    x1 = centerX - (ratio * size(img, 2)/2);
    x2 = centerX + (ratio * size(img, 2)/2);
    mask = zeros(size(img));
    mask(round(y1) : round(y2), round(x1) : round(x2), :) = 1;
    %% Split low-frequency and high-frequency parts
    low_frequency_map_shifted = frequency_map_shifted .* mask;
    high_frequency_map_shifted = frequency_map_shifted .* (1 - mask);
    %% Use ifftshift() to shift frequency map back
    low_frequency_map = ifftshift(low_frequency_map_shifted);
    high_frequency_map = ifftshift(high_frequency_map_shifted);
    %% Use ifft2() to convert from frequency domain to image domain
    low_pass_img = real(ifft2(low_frequency_map));
    high_pass_img = real(ifft2(high_frequency_map));
end
