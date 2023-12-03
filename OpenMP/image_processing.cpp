#include "image_processing.h"
#include <iostream>
#include <chrono>
#include <omp.h>

auto rgb_to_gray = [](const cv::Vec3b& pixel) {
    return 0.299 * pixel[2] + 0.587 * pixel[1] + 0.114 * pixel[0];
};

void process_image_part(const cv::Mat& input_image, cv::Mat& output_image, int start_row, int end_row) {
    int cols = input_image.cols;
    for (int r = start_row; r < end_row; ++r) {
        for (int c = 0; c < cols; ++c) {
            output_image.at<uchar>(r, c) = static_cast<uchar>(rgb_to_gray(input_image.at<cv::Vec3b>(r, c)));
        }
    }
}

void process_image(const std::string& input_image, const std::string& output_image, int num_threads) {
    auto start_time = std::chrono::high_resolution_clock::now();

    cv::Mat image = cv::imread(input_image, cv::IMREAD_COLOR);

    if (image.empty()) {
        std::cerr << "Error al cargar la imagen: " << input_image << std::endl;
        return;
    }

    int rows = image.rows;
    int cols = image.cols;

    cv::Mat gray_image(rows, cols, CV_8UC1);

    omp_set_num_threads(num_threads);

    #pragma omp parallel for
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            gray_image.at<uchar>(r, c) = static_cast<uchar>(rgb_to_gray(image.at<cv::Vec3b>(r, c)));
        }
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();

    cv::imwrite(output_image, gray_image);

    std::cout << "Tiempo transcurrido: " << duration << " milisegundos" << std::endl;

    cv::imshow("Output", gray_image);
    cv::waitKey(0);
}
