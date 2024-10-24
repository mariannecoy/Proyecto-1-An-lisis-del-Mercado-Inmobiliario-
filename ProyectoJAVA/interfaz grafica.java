import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.List;

public class InterfazGrafica extends JFrame {
    private JTextField nombreTextField;
    private JTextField precioTextField;
    private JTextField cantidadTextField;
    private JTextField tallaTextField;
    private JTextField colorTextField;
    private GestionProductos gestionProductos;

    public InterfazGrafica() {
        gestionProductos = new GestionProductos();
        setTitle("Gestión de Productos");
        setSize(500, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Configurar los componentes
        JLabel nombreLabel = new JLabel("Nombre del Producto:");
        nombreTextField = new JTextField();

        JLabel precioLabel = new JLabel("Precio Base:");
        precioTextField = new JTextField();

        JLabel cantidadLabel = new JLabel("Cantidad Disponible:");
        cantidadTextField = new JTextField();

        JLabel tallaLabel = new JLabel("Talla (Sólo para Ropa):");
        tallaTextField = new JTextField();

        JLabel colorLabel = new JLabel("Color (Sólo para Ropa):");
        colorTextField = new JTextField();

        JButton registrarProductoButton = new JButton("Registrar Producto");
        JButton mostrarProductosButton = new JButton("Mostrar Productos");
        JButton predecirPrecioButton = new JButton("Predecir Precio");

        // Layout de la interfaz
        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(7, 2));
        panel.add(nombreLabel);
        panel.add(nombreTextField);
        panel.add(precioLabel);
        panel.add(precioTextField);
        panel.add(cantidadLabel);
        panel.add(cantidadTextField);
        panel.add(tallaLabel);
        panel.add(tallaTextField);
        panel.add(colorLabel);
        panel.add(colorTextField);
        panel.add(registrarProductoButton);
        panel.add(mostrarProductosButton);
        panel.add(predecirPrecioButton);

        // Añadir panel a la ventana
        add(panel);

        // Acción para registrar producto
        registrarProductoButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String nombre = nombreTextField.getText();
                String precioText = precioTextField.getText();
                String cantidadText = cantidadTextField.getText();
                String talla = tallaTextField.getText();
                String color = colorTextField.getText();

                if (nombre.isEmpty() || precioText.isEmpty() || cantidadText.isEmpty()) {
                    JOptionPane.showMessageDialog(null, "Todos los campos deben ser llenados.");
                    return;
                }

                try {
                    double precio = Double.parseDouble(precioText);
                    int cantidad = Integer.parseInt(cantidadText);

                    if (!talla.isEmpty() && !color.isEmpty()) {
                        gestionProductos.registrarProducto(new Ropa(nombre, precio, cantidad, talla, color));
                        JOptionPane.showMessageDialog(null, "Producto de Ropa registrado.");
                    } else {
                        gestionProductos.registrarProducto(new Producto(nombre, precio, cantidad));
                        JOptionPane.showMessageDialog(null, "Producto registrado.");
                    }

                } catch (NumberFormatException ex) {
                    JOptionPane.showMessageDialog(null, "Error: Asegúrate de que el precio y la cantidad sean números válidos.");
                }
            }
        });

        // Acción para mostrar productos
        mostrarProductosButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                gestionProductos.mostrarProductos();
            }
        });

        // Acción para predecir precio
        predecirPrecioButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                // Simulación de datos históricos para un producto
                List<Double> preciosHistoricos = new ArrayList<>();
                preciosHistoricos.add(10.0);
                preciosHistoricos.add(12.0);
                preciosHistoricos.add(14.0);
                preciosHistoricos.add(16.0);

                List<Double> cantidadesHistoricas = new ArrayList<>();
                cantidadesHistoricas.add(1.0);
                cantidadesHistoricas.add(2.0);
                cantidadesHistoricas.add(3.0);
                cantidadesHistoricas.add(4.0);

                double nuevaCantidad = 5.0;  // Cantidad para la que queremos predecir el precio

                if (gestionProductos.productos.isEmpty()) {
                    JOptionPane.showMessageDialog(null, "No hay productos registrados.");
                } else {
                    Producto producto = gestionProductos.productos.get(0);  // Solo como ejemplo, usamos el primer producto
                    gestionProductos.predecirPrecio(producto, preciosHistoricos, cantidadesHistoricas, nuevaCantidad);
                }
            }
        });
    }

    public static void main(String[] args) {
        InterfazGrafica frame = new InterfazGrafica();
        frame.setVisible(true);
}
}