function kernel = gKernel(hSize, sigma)
    [h1, h2] = meshgrid(-(hSize-1)/2 : (hSize-1)/2, -(hSize-1)/2 : (hSize-1)/2);
    hg = exp(- (h1 .^ 2 + h2 .^ 2) / (2 * sigma^2));
    kernel = hg ./ sum(hg(:));
end