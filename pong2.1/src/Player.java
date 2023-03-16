import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

public class Player {
    private int id;
    private Supervisor game;

    public void setGame(Supervisor game) {
        this.game = game;
    }

    public void setId(int id) {
        this.id = id;
    }

    public void setKeyListener(ViewInterface i){
        KeyListener keyListener = new KeyListener() {
            @Override
            public void keyTyped(KeyEvent e) {

            }
            @Override
            public void keyPressed(KeyEvent e) {
                int keyCode = e.getKeyCode();
                if(keyCode == KeyEvent.VK_UP) game.setDir(-1);
                if(keyCode == KeyEvent.VK_DOWN) game.setDir(1);
            }
            @Override
            public void keyReleased(KeyEvent e) {
                int keyCode = e.getKeyCode();
                if(keyCode == KeyEvent.VK_UP) game.setDir(0);
                if(keyCode == KeyEvent.VK_DOWN) game.setDir(0);
            }
        };
        i.addKeyListener(keyListener);
    }
}
