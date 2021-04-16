public class InitTask implements Task{
    int a,b,x,y;
    @Override
    public void execute(Game game) {
        game.getMap().init(a,b);
        game.setUnit(x, y);
    }
    InitTask(String[] args) {
        if (args.length >= 4) {
            a = Integer.parseInt(args[0]);
            b = Integer.parseInt(args[1]);
            x = Integer.parseInt(args[2]);
            y = Integer.parseInt(args[3]);
        } //else throw
    }
}
