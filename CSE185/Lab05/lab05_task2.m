img_names = {'einstein1.jpg', 'einstein2.jpg'}; % List of image filenames

for i = 1:numel(img_names)
    img_name = img_names{i};
    [~, img_name_only, ~] = fileparts(img_name); % Extract file name without extension
    img = im2double(imread(img_name));
    template = im2double(imread('template.jpg'));
    
    %% SSD
    ssd_threshold = 25; % Threshold for SSD method
    [ssd_output, ssd_match] = template_matching_SSD(img, template, ssd_threshold);
    
    figure, imshow(ssd_output ./ max(ssd_output(:))); title('SSD output');
    figure, imshow(ssd_match); title('SSD match');
    
    imwrite(ssd_output ./ max(ssd_output(:)), sprintf('%s_ssd_output.jpg', img_name_only));
    imwrite(ssd_match, sprintf('%s_ssd_match.jpg', img_name_only));
    
    %% Normalized Cross-Correlation
    normcorr_threshold = 0.5; % Threshold for Normalized Cross-Correlation method
    [normcorr_output, normcorr_match] = template_matching_normcorr(img, template, normcorr_threshold);
    
    figure, imshow(normcorr_output ./ max(normcorr_output(:))); title('NormCorr output');
    figure, imshow(normcorr_match); title('NormCorr match');
    
    imwrite(normcorr_output ./ max(normcorr_output(:)), sprintf('%s_normcorr_output.jpg', img_name_only));
    imwrite(normcorr_match, sprintf('%s_normcorr_match.jpg', img_name_only));
end
