import java.util.List;

 {

    // Método para calcular la pendiente (m)
    public static double calcularPendiente(List<Double> x, List<Double> y) {
        int n = x.size();
        double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;

        for (int i = 0; i < n; i++) {
            sumX += x.get(i);
            sumY += y.get(i);
            sumXY += x.get(i) * y.get(i);
            sumX2 += x.get(i) * x.get(i);
        }

        return (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    }

    // Método para calcular la intersección (b)
    public static double calcularInterseccion(List<Double> x, List<Double> y, double pendiente) {
        int n = x.size();
        double sumX = 0, sumY = 0;

        for (int i = 0; i < n; i++) {
            sumX += x.get(i);
            sumY += y.get(i);
        }

        return (sumY - pendiente * sumX) / n;
    }

    // Método para predecir un valor y dado un x
    public static double predecir(double x, double pendiente, double interseccion) {
        return pendiente * x + interseccion;
}
}