public class DrawTask implements Task{
    @Override
    public void execute(Game game) {
        game.setDraw(true);
    }
    DrawTask(String[] args){

    }
}
