import java.awt.geom.Line2D;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Map;

public class Server {
    private Game game;
    private ServerSocket ss;
    private Ball ball = new Ball(0,0,0,0);
    private final int maxPlayers;
    private int currPlayers = 0;
    private ArrayList<Socket> sockets =  new ArrayList<>();
    private ArrayList<ReadFromClient> readers = new ArrayList<>();
    private ArrayList<WriteToClient> writers = new ArrayList<>();
    private Map<Line2D, Double> edges;
    private ArrayList<Line2D> bats;
    public Server(int n, Game game){
        maxPlayers = n;
        this.game = game;
        try{
            ss = new ServerSocket(25565);
        } catch (IOException e){
            System.out.println("death on start");
        }
    }
    public void acceptConnections(){
        try{
            while (currPlayers<maxPlayers){
                Socket s = ss.accept();
                DataInputStream in = new DataInputStream(s.getInputStream());
                DataOutputStream out = new DataOutputStream(s.getOutputStream());
                System.out.println("connected player #" + currPlayers);
                out.writeInt(maxPlayers);
                out.writeInt(currPlayers);
                out.writeInt(edges.size());
                for(Map.Entry<Line2D, Double> line : edges.entrySet()){
                    out.writeDouble(line.getKey().getX1());
                    out.writeDouble(line.getKey().getY1());
                    out.writeDouble(line.getKey().getX2());
                    out.writeDouble(line.getKey().getY2());
                    System.out.println("send edge");
                }
                sockets.add(s);
                readers.add(new ReadFromClient(currPlayers,in));
                writers.add(new WriteToClient(currPlayers, out));
                currPlayers++;
            }
            System.out.println("full");
            for(WriteToClient writer: writers){
                writer.output.writeUTF("start");
            }

            ThreadPool writeExecutor = new ThreadPool(maxPlayers);
            for (WriteToClient writer: writers){
                writeExecutor.execute(writer);
            }

            ThreadPool readExecutor = new ThreadPool(maxPlayers);
            for (ReadFromClient reader: readers){
                readExecutor.execute(reader);
            }
            game.start();

        } catch (IOException e){
            System.out.println("death on connections");
        }
    }
    public void setEdges(Map<Line2D, Double> edges){
        this.edges = edges;
    }
    public void setBats(ArrayList<Line2D> bats){
        this.bats = bats;
    }
    public void setBall(Ball ball){
        this.ball = ball;
    }

    private class ReadFromClient implements Runnable{
        private final int id;
        private final DataInputStream input;
        public ReadFromClient(int pid, DataInputStream in){
            id = pid;
            input = in;
        }
        @Override
        public void run() {
            try{
                while (true){
                    int dir = input.readInt();
                    game.moveBat(dir, id);
                }
            } catch (IOException e){
                System.out.println("death reading from client");
            }

        }
    }
    private class WriteToClient implements Runnable{
        private final int id;
        private final DataOutputStream output;
        public WriteToClient(int pid, DataOutputStream out){
            output = out;
            id = pid;
        }
        @Override
        public void run() {
            try{
                while (true){
                    output.writeDouble(ball.getX());
                    output.writeDouble(ball.getY());
                    output.writeDouble(ball.getDirection());
                    for(Line2D bat:bats){
                        output.writeDouble(bat.getX1());
                        output.writeDouble(bat.getY1());
                        output.writeDouble(bat.getX2());
                        output.writeDouble(bat.getY2());
                    }
                    output.flush();
                    try {
                        Thread.sleep(30);
                    } catch (InterruptedException e){
                        System.out.println("interrupted writing to client");
                    }
                }
            } catch (IOException e){
                System.out.println("death writing to client");
            }
        }
    }

    public static void main(String args[]){
        Game game = new Game(2);
        Server server = new Server(2, game);
        game.setServer(server);
        server.acceptConnections();
    }
}
