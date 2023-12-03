#include "image_processing.h"
#include <iostream>
#include <chrono>
#include "/usr/include/opencv4/opencv2/opencv.hpp"

// Función para convertir RGB a escala de grises utilizando el método de luminosidad
auto rgb_to_gray = [](const cv::Vec3b& pixel) {
    return 0.299 * pixel[2] + 0.587 * pixel[1] + 0.114 * pixel[0];
};

void process_image(const std::string& input_image, const std::string& output_image) {
    // Iniciar la medición del tiempo
    auto start_time = std::chrono::high_resolution_clock::now();

    // Cargar la imagen a color usando OpenCV
    cv::Mat image = cv::imread(input_image, cv::IMREAD_COLOR);

    if (image.empty()) {
        std::cerr << "Error al cargar la imagen: " << input_image << std::endl;
        return;
    }

    // Obtener las dimensiones de la imagen
    int rows = image.rows;
    int cols = image.cols;

    // Crear una nueva imagen en escala de grises
    cv::Mat gray_image(rows, cols, CV_8UC1);

    // Procesar la imagen de manera secuencial
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            gray_image.at<uchar>(r, c) = static_cast<uchar>(rgb_to_gray(image.at<cv::Vec3b>(r, c)));
        }
    }

    // Detener la medición del tiempo
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();

    // Guardar la nueva imagen en escala de grises
    cv::imwrite(output_image, gray_image);

    // Imprimir el tiempo tomado para procesar la imagen
    std::cout << "Tiempo transcurrido (secuencial): " << duration << " milisegundos" << std::endl;

    // Mostrar la nueva imagen en una ventana llamada "Output"
    cv::imshow("Output", gray_image);
    cv::waitKey(0); // Esperar hasta que el usuario presione una tecla antes de cerrar la ventana
}
