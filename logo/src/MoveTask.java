public class MoveTask implements Task{
    int x = 0;
    int y = 0;
    @Override
    public void execute(Game game) {
        game.moveUnit(x,y);
    }
    MoveTask(String[] args){
        if(args.length >=2){
            switch (args[0]) {
                case "U" -> y = Integer.parseInt(args[1]);
                case "D" -> y = -Integer.parseInt(args[1]);
                case "L" -> x = -Integer.parseInt(args[1]);
                case "R" -> x = Integer.parseInt(args[1]);
            } //else throw
        } //else throw
    }
}
