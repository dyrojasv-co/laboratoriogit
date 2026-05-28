#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

// Leer CSV y guardar en matriz 5x12
void cargarCSV(string nombreArchivo, int matriz[5][12]) {
    ifstream archivo(nombreArchivo);
    string linea;
    int fila = 0;

    while (getline(archivo, linea) && fila < 5) {
        stringstream ss(linea);
        string valor;
        int columna = 0;

        while (getline(ss, valor, ',') && columna < 12) {
            matriz[fila][columna] = stoi(valor);
            columna++;
        }
        fila++;
    }
}

// Sumar cada fila (ganancia anual por empresa)
void sumarFilas(int matriz[5][12], int resultados[5]) {
    int fila = 0;
    while (fila < 5) {
        int suma = 0;
        int columna = 0;
        while (columna < 12) {
            suma += matriz[fila][columna];
            columna++;
        }
        resultados[fila] = suma;
        fila++;
    }
}

int main() {
    int ano1[5][12], ano2[5][12], ano3[5][12];
    int totalAno1[5], totalAno2[5], totalAno3[5];
    int totalGeneral[5];

ofstream archivoSalida("output/Resultados.txt");
    // Cargar los tres archivos
    cargarCSV("input/ingresos-2023.csv", ano1);
    cargarCSV("input/ingresos-2024.csv", ano2);
    cargarCSV("input/ingresos-2025.csv", ano3);

    // Calcular totales por año
    sumarFilas(ano1, totalAno1);
    sumarFilas(ano2, totalAno2);
    sumarFilas(ano3, totalAno3);

    // Calcular total de los tres años por empresa
    for (int i = 0; i < 5; i++) {
        totalGeneral[i] = totalAno1[i] + totalAno2[i] + totalAno3[i];
    }

    // Mostrar resultados
    
    for (int i = 0; i < 5; i++) {
        archivoSalida<< "Empresa " << i + 1 << ": ";
        archivoSalida<< "Año 2023 = " << totalAno1[i] << ", ";
        archivoSalida<< "Año 2024 = " << totalAno2[i] << ", ";
        archivoSalida<< "Año 2025 = " << totalAno3[i] << ", ";
    	archivoSalida<< "Total 3 años = " << totalGeneral[i] << endl;
    }
cout << "Archivo generado con exito" << endl;
    return 0;
}

