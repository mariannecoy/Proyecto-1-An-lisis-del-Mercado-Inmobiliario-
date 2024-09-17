
# Análisis del Mercado Inmobiliario con Regresión Lineal

Este proyecto implementa un modelo de regresión lineal simple para analizar propiedades inmobiliarias. Utiliza datos de un archivo CSV que contiene información sobre propiedades, tales como el número de habitaciones, ubicación y precio, para predecir el precio en función del número de habitaciones.

## Funcionalidades
- Carga y muestra los datos de propiedades desde un archivo CSV.
- Divide los datos en un conjunto de entrenamiento (75%) y de prueba (25%).
- Ajusta un modelo de regresión lineal simple con los datos de entrenamiento.
- Evalúa el modelo usando métricas como el Error Cuadrático Medio (MSE) y el Coeficiente de Determinación (R²).
- Genera un archivo de resultados que resume el rendimiento del modelo.

## Estructura del Proyecto
El proyecto está compuesto por los siguientes archivos:

### 1. main.cpp
Este es el archivo principal del proyecto y realiza el flujo completo del análisis.

**Funciones principales:**
- Carga los datos desde un archivo CSV usando la función `cargarPropiedades`.
- Filtra las propiedades con datos válidos (número de habitaciones y precio mayor a cero).
- Divide los datos en conjuntos de entrenamiento y prueba.
- Ajusta el modelo de regresión lineal con los datos de entrenamiento usando la función `generarModelo`.
- Calcula métricas de desempeño como el MSE y R² tanto para el conjunto de entrenamiento como para el de prueba.
- Genera un archivo de salida `analisis_resultados.txt` con un resumen de los resultados obtenidos y un análisis del modelo.

### 2. AnalisisPropiedades.cpp
Este archivo contiene las funciones encargadas de procesar los datos de las propiedades y realizar el análisis de regresión lineal.

**Funciones principales:**
- `cargarPropiedades`: Lee el archivo CSV, procesa cada línea y extrae la información de cada propiedad en una estructura `Propiedad`.
- `mostrarPropiedades`: Imprime en consola los detalles de cada propiedad cargada, mostrando atributos como el número de habitaciones, ubicación y precio.
- `generarModelo`: Calcula los coeficientes del modelo de regresión lineal (pendiente e intercepto) utilizando los datos de entrenamiento.
- `calcularMSE`: Calcula el Error Cuadrático Medio (MSE) para medir la precisión del modelo en las predicciones.
- `calcularR2`: Calcula el Coeficiente de Determinación (R²), que mide qué tan bien se ajustan los datos al modelo de regresión.

### 3. AnalisisPropiedades.h
Este archivo define las estructuras de datos y las funciones que se utilizan en el análisis.

**Estructuras:**
- `Propiedad`: Representa una propiedad con atributos como ubicación, número de habitaciones, precio, etc.
- `RegresionLineal`: Representa el modelo de regresión lineal con sus parámetros (coeficiente y punto de intersección).

**Funciones:**
- Prototipos de las funciones utilizadas en AnalisisPropiedades.cpp, como `cargarPropiedades`, `generarModelo`, `calcularMSE`, y `calcularR2`.

### 4. Análisis de resultados
El modelo ajustado muestra un coeficiente de determinación R² de 0.0169958 en el conjunto de entrenamiento y -0.0307938 en el conjunto de prueba. Un valor de R² más cercano a 1 indica un mejor ajuste del modelo.

El Error Cuadrático Medio (MSE) en el conjunto de prueba es 6.0275e+09, lo que indica el promedio de los errores de predicción en unidades cuadráticas.

Si el MSE es significativamente mayor en el conjunto de prueba que en el de entrenamiento, podría haber un problema de sobreajuste. En este caso, los resultados muestran que el modelo podría estar sobreajustado.

- **Bajo poder predictivo:** El R² del modelo es muy bajo (0.01699 en entrenamiento y -0.03079 en prueba), indicando que apenas explica la variabilidad de los precios.
- **Simplicidad del modelo:** Usar solo el número de habitaciones como predictor es insuficiente. Factores como la ubicación y el tamaño de la propiedad deben ser considerados.
- **Mejora necesaria:** Se recomienda incluir más variables y probar con modelos más complejos para mejorar la precisión del modelo.

## AUTORES Y CRÉDITOS

**Autores:**
- Marianne Coy
- Andres Pabon
- Matias Mendoza
- Sebastian Velasquez

**Créditos:**
- Fran Valuch
