#include "image_processing.h"
#include <iostream>

int main(int argc, char* argv[]) {
    std::string input_image;
    std::string output_image;

    if (argc == 3) {
        input_image = argv[1];
        output_image = argv[2];
    } else {
        std::cerr << "Uso: " << argv[0] << " <imagen_color> <imagen_gris>" << std::endl;
        return 1;
    }

    std::cout << "Cargando imagen..." << std::endl;

    // Llama a la función de procesamiento de imágenes de manera secuencial
    process_image(input_image, output_image);

    return 0;
}
