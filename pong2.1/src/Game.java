import java.awt.geom.Point2D;
import java.util.ArrayList;
import java.awt.geom.Line2D;
import java.util.HashMap;
import java.util.Map;
import java.util.concurrent.atomic.AtomicBoolean;

public class Game {
    private final Ball ball = new Ball(Math.random()*500,Math.random()*500, Math.acos(Math.random()), 5f);
    double spd = 5f;
    private Server server;
    private HashMap<Line2D, Double> edges = new HashMap<>();
    private HashMap<Line2D, Integer> deathZone = new HashMap<>();
    private HashMap<Integer, Pair> batters = new HashMap<>(); //playerNum , bat + its normal;
    public Game(int n){
        if(n==1){
            edges.put(new Line2D.Double(0,0,640,0), Math.PI*3/2);
            edges.put(new Line2D.Double(640,0,640,480), Math.PI);
            edges.put(new Line2D.Double(640,480,0,480), Math.PI/2);
            deathZone.put(new Line2D.Double(0, 480, 0, 0), 0);
            batters.put(0,new Pair(new Line2D.Double(5,50,5,100), 0));
        } else if(n==2){
            edges.put(new Line2D.Double(0,0,640,0), Math.PI*3/2);
            deathZone.put(new Line2D.Double(640,0,640,480), 1);
            edges.put(new Line2D.Double(640,480,0,480), Math.PI/2);
            deathZone.put(new Line2D.Double(0, 480, 0, 0), 0);
            batters.put(0,new Pair(new Line2D.Double(5,50,5,100), 0));
            batters.put(1,new Pair(new Line2D.Double(635,50,635,100), 0));
        } else if(n>2){
            deathZone.put(new Line2D.Double(0,0,640,0), 1);
        }
    }

    public void setServer(Server server) {
        this.server = server;
        init();
    }

    public void init(){
        server.setEdges(edges);
        alert();
    }
    public void alert(){
        ArrayList<Line2D> bats = new ArrayList<>();
            for (Map.Entry<Integer, Pair> pair: batters.entrySet()){
                bats.add(pair.getValue().getKey());
            }
            server.setBats(bats);
            server.setBall(ball);
    }
    public void start(){
         final Thread gameLoop = new Thread(new Runnable() {
             private final AtomicBoolean running = new AtomicBoolean(false);
            @Override
            public void run() {
                running.set(true);
                while (running.get()){
                    int a = calculateMove();
                    if(a != -1){
                        running.set(false);
                        System.out.println("Player "+a + "won!");
                    }
                    try{
                        Thread.sleep(50);
                    } catch (InterruptedException e){
                        System.out.println("Game loop interrupted");
                    }
                }
            }
        });
        gameLoop.start();
    }

    public void moveBat(int dir, int id){
            Line2D bat = batters.get(id).getKey();
            if(bat.getY1()+dir*spd>0 && bat.getY2()+dir*spd<480){
                bat.setLine(bat.getX1(),bat.getY1()+dir*spd, bat.getX2(), bat.getY2()+dir*spd);
            }
    }

    private int calculateMove(){
        Point2D pointPredict = new Point2D.Double(Math.round(ball.predictX()), Math.round(ball.predictY()));
        for(Map.Entry<Line2D, Double> line : edges.entrySet()){
            if(line.getKey().ptSegDist(pointPredict)<=ball.getSize()&&(line.getKey().relativeCCW(pointPredict))<0){
                ball.bounce(line.getValue());
            }
        }
        for(Map.Entry<Line2D, Integer> death: deathZone.entrySet()){
            if(death.getKey().ptSegDist(pointPredict)<=ball.getSize()){
                return death.getValue();
            }
        }
        for(Map.Entry<Integer,Pair> bat: batters.entrySet()){
            if(bat.getValue().getKey().ptSegDist(pointPredict)<=ball.getSize()){
                ball.bounce(bat.getValue().getValue());
            }
        }
        ball.move();
        alert();
        return -1;
    }
}
