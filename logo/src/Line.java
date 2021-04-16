public class Line {
    private int startX, startY, endX, endY;
    Line(int a, int b, int x, int y){
        startX = a;
        startY = b;
        endX = x;
        endY = y;
    }

    public int getStartX() {
        return startX;
    }

    public int getStartY() {
        return startY;
    }

    public int getEndX() {
        return endX;
    }

    public int getEndY() {
        return endY;
    }
}
