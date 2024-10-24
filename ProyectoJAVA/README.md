# Sistema de Gestión de Productos con Regresión Lineal

## Descripción del Proyecto

Este proyecto implementa un sistema de gestión de productos en Java, utilizando principios de programación orientada a objetos. El sistema permite a los usuarios registrar productos, incluyendo electrónicos, alimenticios y de ropa, cada uno con atributos específicos como nombre, precio base, cantidad disponible, talla y color. También permite registrar ventas, mostrar la lista de productos, y calcular el precio de productos a través de predicciones utilizando regresión lineal.

El sistema incluye una interfaz gráfica que facilita la interacción con el usuario, permitiendo registrar productos de manera intuitiva y realizar predicciones de precios basadas en datos históricos.

## Funcionalidades

- *Registro de Productos*: Permite registrar productos con atributos como nombre, precio base y cantidad disponible.
- *Categorías de Productos*: Soporta productos electrónicos, alimenticios y de ropa, cada uno con atributos específicos (por ejemplo, talla y color para ropa).
- *Visualización de Productos*: Muestra la lista de productos registrados junto con sus detalles.
- *Registro de Ventas*: Permite llevar un control de las ventas de productos.
- *Predicción de Precios*: Utiliza un modelo de regresión lineal para predecir precios de productos basados en datos históricos.
- *Interfaz Gráfica*: Ofrece una experiencia de usuario intuitiva para registrar y gestionar productos.


### Estructura del Proyecto y Descripción de Clases

- *Producto.java*: Clase base que define los atributos comunes de todos los productos.
- *ProductoElectronico.java*: Clase derivada que extiende Producto para productos electrónicos.
- *ProductoAlimenticio.java*: Clase derivada que extiende Producto para productos alimenticios.
- *Ropa.java*: Clase derivada que extiende Producto para productos de ropa, incluyendo atributos como talla y color.
- *PrediccionPrecios.java*: Clase para manejar la conexión con la lógica de regresión lineal implementada en C++.
- *GestionProductos.java*: Clase que gestiona el registro y la visualización de productos.
- *RegresionLineal.java*: Clase que implementa la lógica de regresión lineal.
- *InterfazGrafica.java*: Clase que proporciona la interfaz gráfica para la interacción del usuario.

## Resumen

Al ejecutar el programa, los usuarios pueden registrar productos de diferentes categorías (electrónicos, alimenticios y ropa) y visualizarlos en una lista. Además, se puede realizar una predicción del precio de un producto en función de los datos históricos de precios y cantidades utilizando regresión lineal. Esto permite estimar precios futuros de manera efectiva, facilitando la toma de decisiones en la gestión de inventario y ventas.

El sistema ha sido probado y funciona correctamente, proporcionando resultados precisos en las predicciones de precios basadas en los datos ingresados.