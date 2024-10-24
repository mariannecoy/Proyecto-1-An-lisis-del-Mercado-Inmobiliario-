#ifndef ANALISISPROPIEDADES_H
#define ANALISISPROPIEDADES_H

#include <string>
#include <vector>

using namespace std;

// Estructura que representa una propiedad
struct Propiedad {
    string fechaInicio;
    string fechaFin;
    string fechaCreacion;
    double latitud;
    double longitud;
    string ubicacion1;
    string ubicacion2;
    string ubicacion3;
    double totalHabitaciones;
    double numDormitorios;
    double numBaños;
    double superficieTotal;
    double superficieConstruida;
    double precio;
    string moneda;
    string descripcion;
    string tipoPropiedad;
    string tipoOperacion;
};

// Estructura para el modelo de regresión lineal
struct RegresionLineal {
    double coeficiente;
    double interseccion;
};

// Funciones
vector<Propiedad> cargarPropiedades(const string& archivoDatos);
void mostrarPropiedades(const vector<Propiedad>& propiedades);
RegresionLineal generarModelo(const vector<double>& x, const vector<double>& y);
double estimarValor(const RegresionLineal& modelo, double x);
double calcularMSE(const vector<double>& x, const vector<double>& y, const RegresionLineal& modelo);
double calcularR2(const vector<double>& x, const vector<double>& y, const RegresionLineal& modelo);

#endif
