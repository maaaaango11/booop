public class Performer {
    private int x;
    private int y;
    private int oldX;
    private int oldY;

    public void setX(int x) {
        oldX = this.x;
        this.x = x;
    }

    public void setY(int y) {
        oldY = this.y;
        this.y = y;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public int getOldX() {
        return oldX;
    }

    public int getOldY() {
        return oldY;
    }
}
