function phase_img = phase(img)
    frequency_map = fft2(img);
    frequency_map_shifted = fftshift(frequency_map);
    figure, imshow(log(abs(frequency_map_shifted) + 1), []);
    figure, imagesc(log(abs(frequency_map_shifted) + 1)), colormap jet;
    phase_img = 1;
end