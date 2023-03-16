import java.lang.Math;
public class Ball {
    private double x;
    private double y;
    private int size;
    private double speed;
    private double direction;
    public Ball(double x, double y, double dir, double spd){
        this.x = x;
        this.y = y;
        this.direction = dir;
        this.speed = spd;
        size = 5;
    }

    public double getX() {
        return x;
    }

    public void setX(double x) {
        this.x = x;
    }

    public void setY(double y) {
        this.y = y;
    }

    public void setDirection(double direction) {
        this.direction = direction;
    }

    public double getDirection() {
        return direction;
    }

    public double getY() {
        return y;
    }

    public int getSize() {
        return size;
    }
    public void accelerate(double val){
        speed+=val;
    }
    public void move(){
        this.x = this.x + (this.speed*Math.cos(this.direction));
        this.y = this.y + (this.speed*Math.sin(this.direction));
    }
    public double predictX(){
        return this.x + (this.speed*Math.cos(this.direction));
    }
    public double predictY(){
        return this.y + (this.speed*Math.sin(this.direction));
    }
    public void bounce(double normal){
        this.direction = Math.PI - this.direction + 2*normal; // maybe mod 2pi
        //accelerate(0.1f);
    }
}
