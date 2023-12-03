#ifndef IMAGE_PROCESSING_H
#define IMAGE_PROCESSING_H

#include <string>
#include <opencv2/opencv.hpp>

void process_image(const std::string& input_image, const std::string& output_image, int num_threads);
void process_image_part(const cv::Mat& input_image, cv::Mat& output_image, int start_row, int end_row);

#endif  // IMAGE_PROCESSING_H
