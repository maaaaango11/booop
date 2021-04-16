import java.util.ArrayList;
public class Game {
    final private Performer unit = new Performer();
    final private Grid map = new Grid();
    private boolean draw = false;
    final private ConsoleManager consoleManager = new ConsoleManager();
    final private Visual visual = new Visual();
    final private ArrayList<Line> lines = new ArrayList<>();

    public void start(){
        while(true){
            Task task = consoleManager.read();
            //if initialised () else check for init -- if init successful -> initialised
            task.execute(this); // this can be done using another class but meh..
            //
            visual.update();
        }
    }

    public void moveUnit(int x, int y){
        if(unit.getX()+x > map.getX()){
            unit.setX((unit.getX()+x) % map.getX());
        } else if(unit.getX()+x < 0){
            unit.setX(map.getX()-((unit.getX()+x) % map.getX()));
        } else unit.setX(unit.getX()+x);
        if(unit.getY()+y > map.getY()){
            unit.setY((unit.getY()+y) % map.getY());
        } else if(unit.getY()+y < 0) {
            unit.setY(map.getY() - ((unit.getY() + y) % map.getY()));
        } else unit.setY(unit.getY()+y);
        if(draw){ //but if move through border there will be mistake;
            lines.add(new Line(unit.getOldX(), unit.getOldY(), unit.getX(), unit.getY())); //array of 'lines' to draw in visual
        }
    }

    public void setUnit(int x, int y){
        if(x<=map.getX() && y<=map.getY() && y>=0 && x>=0){
            unit.setX(x);
            unit.setY(y);
        } //else throw
    }

    public Grid getMap() {
        return map;
    }

    public void setDraw(boolean a){
        draw = a;
    }
}
