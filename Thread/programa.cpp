#include "image_processing.h"
#include <iostream>
#include <chrono>

int main(int argc, char* argv[]) {
    std::string input_image;
    std::string output_image;
    int num_threads = 4;  // Número de hilos para el procesamiento

    if (argc == 3) {
        input_image = argv[1];
        output_image = argv[2];
    } else if (argc == 4) {
        input_image = argv[1];
        output_image = argv[2];
        num_threads = std::stoi(argv[3]);
    } else {
        std::cerr << "Uso: " << argv[0] << " <imagen_color> <imagen_gris> [num_threads]" << std::endl;
        return 1;
    }

    std::cout << "Cargando imagen..." << std::endl;

    // Inicia el cronómetro
    auto start_time = std::chrono::high_resolution_clock::now();

    // Llama a la función de procesamiento de imágenes
    process_image(input_image, output_image, num_threads);

    // Detiene el cronómetro
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();

    std::cout << "Tiempo total transcurrido: " << duration << " milisegundos" << std::endl;

    return 0;
}
