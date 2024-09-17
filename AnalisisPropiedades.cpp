#include "AnalisisPropiedades.h"
#include <fstream>
#include <sstream>
#include <iostream>

vector<Propiedad> cargarPropiedades(const string& archivoDatos) {
    ifstream archivo(archivoDatos);
    vector<Propiedad> propiedades;

    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo: " << archivoDatos << endl;
        return propiedades;
    }

    string linea;
    getline(archivo, linea); // Leer la cabecera

    while (getline(archivo, linea)) {
        stringstream ss(linea);
        Propiedad propiedad;

        getline(ss, propiedad.fechaInicio, ',');
        getline(ss, propiedad.fechaFin, ',');
        getline(ss, propiedad.fechaCreacion, ',');
        ss >> propiedad.latitud; ss.ignore();
        ss >> propiedad.longitud; ss.ignore();
        getline(ss, propiedad.ubicacion1, ',');
        getline(ss, propiedad.ubicacion2, ',');
        getline(ss, propiedad.ubicacion3, ',');
        ss >> propiedad.totalHabitaciones; ss.ignore();
        ss >> propiedad.numDormitorios; ss.ignore();
        ss >> propiedad.numBaños; ss.ignore();
        ss >> propiedad.superficieTotal; ss.ignore();
        ss >> propiedad.superficieConstruida; ss.ignore();
        ss >> propiedad.precio; ss.ignore();
        getline(ss, propiedad.moneda, ',');
        getline(ss, propiedad.descripcion, ',');
        getline(ss, propiedad.tipoPropiedad, ',');
        getline(ss, propiedad.tipoOperacion);

        propiedades.push_back(propiedad);
    }

    archivo.close();
    return propiedades;
}

void mostrarPropiedades(const vector<Propiedad>& propiedades) {
    for (const auto& propiedad : propiedades) {
        cout << "Fecha de inicio: " << propiedad.fechaInicio << endl;
        cout << "Fecha de fin: " << propiedad.fechaFin << endl;
        cout << "Fecha de creación: " << propiedad.fechaCreacion << endl;
        cout << "Ubicación: " << propiedad.ubicacion1 << ", " << propiedad.ubicacion2 << ", " << propiedad.ubicacion3 << endl;
        cout << "Habitaciones: " << propiedad.totalHabitaciones << endl;
        cout << "Precio: " << propiedad.precio << " " << propiedad.moneda << endl;
        cout << "-------------------------------------" << endl;
    }
}

RegresionLineal generarModelo(const vector<double>& x, const vector<double>& y) {
    int n = x.size();
    double sumaX = 0, sumaY = 0, sumaXY = 0, sumaXCuadrado = 0;

    for (int i = 0; i < n; ++i) {
        sumaX += x[i];
        sumaY += y[i];
        sumaXY += x[i] * y[i];
        sumaXCuadrado += x[i] * x[i];
    }

    double pendiente = (n * sumaXY - sumaX * sumaY) / (n * sumaXCuadrado - sumaX * sumaX);
    double intercepto = (sumaY - pendiente * sumaX) / n;

    return {pendiente, intercepto};
}

double estimarValor(const RegresionLineal& modelo, double x) {
    return modelo.coeficiente * x + modelo.interseccion;
}

double calcularMSE(const vector<double>& x, const vector<double>& y, const RegresionLineal& modelo) {
    double sumaErrores = 0;
    int n = x.size();

    for (int i = 0; i < n; ++i) {
        double prediccion = estimarValor(modelo, x[i]);
        sumaErrores += (prediccion - y[i]) * (prediccion - y[i]);
    }

    return sumaErrores / n;
}

double calcularR2(const vector<double>& x, const vector<double>& y, const RegresionLineal& modelo) {
    double promedioY = 0;
    int n = y.size();

    for (double valor : y) {
        promedioY += valor;
    }
    promedioY /= n;

    double sumaTotal = 0, sumaResiduos = 0;
    for (int i = 0; i < n; ++i) {
        double prediccion = estimarValor(modelo, x[i]);
        sumaTotal += (y[i] - promedioY) * (y[i] - promedioY);
        sumaResiduos += (y[i] - prediccion) * (y[i] - prediccion);
    }

    return 1 - (sumaResiduos / sumaTotal);
}
