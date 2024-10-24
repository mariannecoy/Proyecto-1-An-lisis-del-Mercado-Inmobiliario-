import javax.swing.*;
import java.util.ArrayList;
import java.util.List;

public class GestionProductos {
    private ArrayList<Producto> productos;

    public GestionProductos() {
        productos = new ArrayList<>();
    }

    public void registrarProducto(Producto producto) {
        productos.add(producto);
    }

    public void mostrarProductos() {
        if (productos.isEmpty()) {
            JOptionPane.showMessageDialog(null, "No hay productos registrados.");
        } else {
            StringBuilder listaProductos = new StringBuilder("Lista de Productos:\n");
            for (Producto producto : productos) {
                listaProductos.append(producto.toString()).append("\n");
            }
            JOptionPane.showMessageDialog(null, listaProductos.toString());
        }
    }

    // Método para predecir precios basado en la regresión lineal
    public void predecirPrecio(Producto producto, List<Double> preciosHistoricos, List<Double> cantidadesHistoricas, double nuevaCantidad) {
        if (preciosHistoricos.size() < 2 || cantidadesHistoricas.size() < 2) {
            JOptionPane.showMessageDialog(null, "No hay suficientes datos para realizar la predicción.");
            return;
        }

        double pendiente = RegresionLineal.calcularPendiente(cantidadesHistoricas, preciosHistoricos);
        double interseccion = RegresionLineal.calcularInterseccion(cantidadesHistoricas, preciosHistoricos, pendiente);

        // Predecimos el nuevo precio para la nueva cantidad
        double precioPredicho = RegresionLineal.predecir(nuevaCantidad, pendiente, interseccion);

        JOptionPane.showMessageDialog(null, "El precio predicho para el producto " + producto.getNombre() + " es: $" + precioPredicho);
}
}
