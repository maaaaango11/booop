public class WardTask implements Task{
    @Override
    public void execute(Game game) {
        game.setDraw(false);
    }
    WardTask(String[] args){

    }
}
