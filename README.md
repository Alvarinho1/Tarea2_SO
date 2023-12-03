# Tarea2 Sistemas Operativos

Integrantes: Matías Lagos y Álvaro

# Introducción

Este trabajo aborda la implementación de un programa en C++ para procesar imágenes a color, aplicando un filtro de conversión a escala de grises. La tarea se realizará de manera secuencial y paralela, utilizando hebras a través de la clase thread y la API OpenMP. La motivación radica en aprovechar el procesamiento paralelo para mejorar la eficiencia y rendimiento del sistema.

# Instrucciones para su compilación
Ver las Carpetas de cada implementacion; Secuencial, Thread y OpenMP con el comando ls

Navegar al directorio donde está el código fuente y las imágenes

# Para la carpeta Secuencial:

Ejecutar el comando "make"

Ejecutar el comando "./cambio_color_secuencial nombre_imagen.jpg nombre_imagen_gris.jpg"

reemplazar el nombre_imagen.jpg por el nombre de la imagen deseada, reemplazar el nombre_imagen_gris.jpg por cualquier nombre para la imagen convertida en gris, mantiendo el mismo formato (png, jpg, etc).

# Para la carpeta Thread:

Ejecutar el comando "make"

Ejecutar el comando "./cambio_color_secuencial nombre_imagen.jpg nombre_imagen_gris.jpg 4"

reemplazar el nombre_imagen.jpg por el nombre de la imagen deseada, reemplazar el nombre_imagen_gris.jpg por cualquier nombre para la imagen convertida en gris, mantiendo el mismo formato (png, jpg, etc) y reemplazar el numero 4 por la cantidad de hilos deseada.

# Para la carpeta OpenMP:

Ejecutar el comando "make"

Ejecutar el comando "./cambio_color_secuencial nombre_imagen.jpg nombre_imagen_gris.jpg"

reemplazar el nombre_imagen.jpg por el nombre de la imagen deseada, reemplazar el nombre_imagen_gris.jpg por cualquier nombre para la imagen convertida en gris, mantiendo el mismo formato (png, jpg, etc).

# Para Limpiar los archivos generados:

make clean

