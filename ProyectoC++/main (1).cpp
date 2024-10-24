#include "AnalisisPropiedades.h"
#include <iostream>
#include <fstream>
#include <random>
#include <vector>

using namespace std;

int main() {
    string archivoDatos = "DS_Proyecto_01_Datos_Properati.csv";
    string archivoResultados = "analisis_resultados.txt";

    // Cargar y mostrar los datos desde el archivo CSV
    vector<Propiedad> listaPropiedades = cargarPropiedades(archivoDatos);
    mostrarPropiedades(listaPropiedades);

    if (!listaPropiedades.empty()) {
        vector<double> listaHabitaciones;
        vector<double> listaPrecios;

        // Extraer los datos de habitaciones y precios válidos
        for (const auto& propiedad : listaPropiedades) {
            if (propiedad.totalHabitaciones > 0 && propiedad.precio > 0) {  // Filtrar valores válidos
                listaHabitaciones.push_back(propiedad.totalHabitaciones);
                listaPrecios.push_back(propiedad.precio);
            }
        }

        // Dividir los datos en entrenamiento y prueba
        vector<double> datosEntrenamientoHabitaciones, datosPruebaHabitaciones;
        vector<double> datosEntrenamientoPrecios, datosPruebaPrecios;

        random_device dispositivo;
        mt19937 generador(dispositivo());
        uniform_int_distribution<> distribucion(0, 99);

        for (size_t i = 0; i < listaHabitaciones.size(); ++i) {
            if (distribucion(generador) < 75) {  // 75% entrenamiento, 25% prueba
                datosEntrenamientoHabitaciones.push_back(listaHabitaciones[i]);
                datosEntrenamientoPrecios.push_back(listaPrecios[i]);
            } else {
                datosPruebaHabitaciones.push_back(listaHabitaciones[i]);
                datosPruebaPrecios.push_back(listaPrecios[i]);
            }
        }

        // Ajustar el modelo lineal
        RegresionLineal modelo = generarModelo(datosEntrenamientoHabitaciones, datosEntrenamientoPrecios);

        // Calcular métricas de desempeño
        double mseEntrenamiento = calcularMSE(datosEntrenamientoHabitaciones, datosEntrenamientoPrecios, modelo);
        double r2Entrenamiento = calcularR2(datosEntrenamientoHabitaciones, datosEntrenamientoPrecios, modelo);

        double msePrueba = calcularMSE(datosPruebaHabitaciones, datosPruebaPrecios, modelo);
        double r2Prueba = calcularR2(datosPruebaHabitaciones, datosPruebaPrecios, modelo);

        // Generar reporte de resultados
        ofstream archivo(archivoResultados);
        if (archivo.is_open()) {
            archivo << "Resultados en el conjunto de entrenamiento:" << endl;
            archivo << "Pendiente del modelo: " << modelo.coeficiente << endl;
            archivo << "Intercepto: " << modelo.interseccion << endl;
            archivo << "Error Cuadrático Medio (MSE): " << mseEntrenamiento << endl;
            archivo << "Coeficiente de Determinación (R²): " << r2Entrenamiento << endl;

            archivo << "\nResultados en el conjunto de prueba:" << endl;
            archivo << "Error Cuadrático Medio (MSE): " << msePrueba << endl;
            archivo << "Coeficiente de Determinación (R²): " << r2Prueba << endl;

            // Análisis de los resultados
            archivo << "\nAnálisis de los resultados:" << endl;
            archivo << "El modelo ajustado muestra un coeficiente de determinación R² de " << r2Entrenamiento 
                    << " en el conjunto de entrenamiento y " << r2Prueba 
                    << " en el conjunto de prueba. Un valor de R² más cercano a 1 indica un mejor ajuste del modelo." << endl;
            archivo << "El Error Cuadrático Medio (MSE) en el conjunto de prueba es " << msePrueba 
                    << ", lo que indica el promedio de los errores de predicción en unidades cuadráticas." << endl;
            archivo << "Si el MSE es significativamente mayor en el conjunto de prueba que en el de entrenamiento, "
                    << "podría haber un problema de sobreajuste. En este caso, los resultados muestran que el modelo "
                    << (msePrueba > mseEntrenamiento ? "podría estar sobreajustado." : "generaliza bien.") << endl;

            archivo.close();
            cout << "El archivo de resultados ha sido generado correctamente en: " << archivoResultados << endl;
        } else {
            cout << "No se pudo abrir el archivo para guardar los resultados." << endl;
        }

    } else {
        cout << "No se encontraron propiedades en el archivo." << endl;
    }

    return 0;
}
