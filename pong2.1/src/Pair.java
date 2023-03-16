import java.awt.geom.Line2D;

public class Pair {
    private Line2D key;
    private double value;

    public double getValue() {
        return value;
    }

    public Line2D getKey() {
        return key;
    }
    public Pair(Line2D k, double v){
        key = k;
        value = v;
    }
}
