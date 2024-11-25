#include <stdio.h>

typedef struct f{
	float base;
	float altura;
	float area;
}Figura;

int main() {
    
	FILE *inputFile, *outputFile;
    Figura triangulo;

    
    inputFile = fopen("triang.in", "r");
    if (inputFile == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }

    outputFile = fopen("triang.out", "w");
    if (outputFile == NULL) {
        printf("Erro ao abrir o arquivo de saída.\n");
        fclose(inputFile);
        return 1;
    }

    while (fscanf(inputFile, "%f %f", &triangulo.base, &triangulo.altura) == 2) {
    
        if (triangulo.base == 0 || triangulo.altura == 0) {
            break;
        }

        triangulo.area = (triangulo.base * triangulo.altura) / 2;

        fprintf(outputFile, "Base: %.2f, Altura: %.2f, Área: %.2f\n", triangulo.base, triangulo.altura, triangulo.area);
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Calculo de areas concluido. Resultados armazenados em triang.out\n");

    return 0;
}

