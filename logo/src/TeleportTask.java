public class TeleportTask implements Task{
    int x = 0;
    int y = 0;
    @Override
    public void execute(Game game) {
        game.setUnit(x,y);
    }
    TeleportTask(String[] args){
        if(args.length >=2){
            x = Integer.parseInt(args[0]);
            y = Integer.parseInt(args[1]);
        } //else throw
    }
}
