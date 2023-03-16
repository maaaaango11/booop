import java.awt.geom.Line2D;
import java.util.ArrayList;
import java.util.Map;

public class Translator {
    private ViewInterface viewInterface;
    public Translator(ViewInterface i){
        viewInterface = i;
    }
    public void initCommand(Map<Line2D, Double> edges){

        viewInterface.initial(edges);
    }
    public void alert(Ball ball, ArrayList<Line2D> bats){
        viewInterface.update(ball, bats);
    }
}
