import javax.swing.*;
import java.awt.*;
import java.awt.geom.Line2D;
import java.awt.geom.Rectangle2D;
import java.util.ArrayList;
import java.util.Map;

public class ViewContent extends JComponent {
    private Ball ball = new Ball(90,90,0,0);
    private ArrayList<Line2D> bats;
    private Map<Line2D, Double> content;
    private final int width;
    private final int height;

    protected void paintComponent(Graphics g){
        Graphics2D g2d = (Graphics2D) g;
        int size = ball.getSize();
        g2d.setColor(Color.CYAN);
        for (Line2D line: content.keySet().toArray(new Line2D[0])) {
            g2d.draw(line);
        }
        Rectangle2D.Double r = new Rectangle2D.Double(ball.getX()-size, ball.getY()-size, size*2,size*2);
        for (Line2D bat : bats){
            g2d.draw(bat);
        }
        g2d.draw(r);
    }
    public void addContent(Ball b, ArrayList<Line2D> bats){
        this.ball = b;
        this.bats = bats;
    }
    public void addContent(Map<Line2D, Double> c){
        content = c;
    }
    public ViewContent(int w, int h){
        width = w;
        height = h;
        setPreferredSize(new Dimension(width-5, height-5));
    }
}
