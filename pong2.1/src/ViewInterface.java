import java.awt.*;
import java.awt.geom.Line2D;
import java.util.ArrayList;
import java.util.Map;
import javax.swing.*;

public class ViewInterface extends JFrame{
    private int width;
    private int height;
    ViewContent viewContent;
    public ViewInterface(int w, int h){
        width = w;
        height = h;
    }

    public void initial(Map<Line2D, Double> edges){
        Container contentPane = getContentPane();
        viewContent = new ViewContent(width, height);
        viewContent.addContent(edges);
        contentPane.add(viewContent);
        contentPane.setBackground(Color.BLACK);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        pack();
        setVisible(true);
    }
    public void update(Ball ball, ArrayList<Line2D> bats){
        viewContent.addContent(ball, bats);
        viewContent.repaint();
    }
}
