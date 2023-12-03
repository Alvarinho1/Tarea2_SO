CXX=g++
CXXFLAGS=-std=c++11 -Wall -Wextra -pedantic -O3
LIBS=$(shell pkg-config --cflags --libs opencv4)

TARGET=cambio_color

all: $(TARGET)

$(TARGET): cambio_color.cpp image_processing.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

clean:
	rm -f $(TARGET)

