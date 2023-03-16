import java.awt.geom.Line2D;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.util.ArrayList;
import java.util.HashMap;

public class Supervisor {
    private int n;
    private int id;
    private Socket socket;
    private ReadFromServer rfs;
    private WriteToServer wts;
    private HashMap<Line2D, Double> edges = new HashMap<>();
    private ArrayList<Line2D> bats = new ArrayList<>();
    private Ball ball = new Ball(0,0,0,0);
    private int dir;
    private ViewInterface viewInterface;

    public void setViewInterface(ViewInterface viewInterface) {
        this.viewInterface = viewInterface;
    }
    public void setDir(int dir){
        this.dir = dir;
    }
    private void connectToServer(){
        try{
            socket = new Socket("localhost", 25565);
            DataInputStream in = new DataInputStream(socket.getInputStream());
            DataOutputStream out = new DataOutputStream(socket.getOutputStream());
            n = in.readInt();
            id = in.readInt();
            int len = in.readInt();
            for(int a = 0; a<len; a++){
                double x1 = in.readDouble();
                double y1 = in.readDouble();
                double x2 = in.readDouble();
                double y2 = in.readDouble();
                edges.put(new Line2D.Double(x1,y1,x2,y2), 0.0);
                System.out.println("receive edge");
                bats.add(new Line2D.Double(0,0,0,0));
            }
            rfs = new ReadFromServer(in);
            wts = new WriteToServer(out);
        } catch (IOException e){
            System.out.println("death connecting");
        }
    }

    private class ReadFromServer implements Runnable{
        private final DataInputStream input;
        public ReadFromServer(DataInputStream in){
            input = in;
        }
        @Override
        public void run() {
            try{
                while(true){
                    ball.setX(input.readDouble());
                    ball.setY(input.readDouble());
                    ball.setDirection(input.readDouble());
                    for(int i = 0; i<n; i++){
                        double x1 = input.readDouble();
                        double y1 = input.readDouble();
                        double x2 = input.readDouble();
                        double y2 = input.readDouble();
                        bats.set(i, new Line2D.Double(x1,y1,x2,y2));
                         //!!!!!!!!!!!!!!
                        //game.updateBats(id, a, b);
                    }
                    viewInterface.update(ball, bats);
                }
            } catch (IOException e){
                System.out.println("death reading from server");
            }

        }
    }
    private class WriteToServer implements Runnable{
        private final DataOutputStream output;
        public WriteToServer(DataOutputStream out){
            output = out;
        }
        @Override
        public void run() {
            try{
                while (true){
                    output.writeInt(dir);
                    output.flush();
                    try {
                        Thread.sleep(10);
                    } catch (InterruptedException e){
                        System.out.println("interrupted writing to server");
                    }
                }

            } catch (IOException e){
                System.out.println("death sending to server");
            }
        }
    }
    private void waitForStart(){
        try{
            String msg = rfs.input.readUTF();
            viewInterface.initial(edges);
            Thread readTread = new Thread(rfs);
            Thread writeTread = new Thread(wts);
            readTread.start();
            writeTread.start();
        } catch (IOException e){
            System.out.println("error reading startMsg");
        }
    }

    public static void main(String args[]){
        Player p = new Player();
        ViewInterface viewInterface = new ViewInterface(640, 480);
        Supervisor s = new Supervisor();
        s.connectToServer();
        s.setViewInterface(viewInterface);
        p.setId(s.id);
        p.setGame(s);
        p.setKeyListener(viewInterface);
        s.waitForStart();
    }
}
