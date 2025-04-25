//Bonne pratique, pour les includes systemes toujours utiliser <> et "" pour les includes de votre projet.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "utils.h"
#include "stb_image.h"
#include "stb_image_write.h"

#define HEAP_SIZE 2048 * 2048 * 4
static uint8_t* heap = NULL;
static size_t heap_top = 0;
void* allocate(size_t size) {
	size_t old_top = heap_top;
	heap_top += size;
	assert(heap_top <= HEAP_SIZE);
	return &heap[old_top];
}

int main(int argc, char** argv) {
	heap = (uint8_t*)malloc(HEAP_SIZE);
	assert(heap != NULL);
	
	int width, height, channels;

	unsigned char* img = stbi_load("../Labyrinthe/31.bmp", &width, &height, &channels, 0);
	if (img == NULL) {
		printf("Error in loading image \n");
		exit(1);
	}
	printf("Loaded image with a width of %dpx, a height of %dpx and %d channels\n", width, height, channels);

	int pixel_count = width * height;

	for (int i = 0; i < pixel_count; i++) {
		int x = i % width;
		int y = i / width;

		unsigned char* pixel = img + i * channels;
		printf("Pixel at (%d, %d): Red = %d\n", x, y, pixel[0]);
	}
}