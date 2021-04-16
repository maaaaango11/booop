public class TaskFactory { //how to cache?
    public Task create(String name, String[] args){
        Task basicTask =null;
        if("init".equals(name)){
            basicTask = new InitTask(args);
        } else if("move".equals(name)){
            basicTask = new MoveTask(args);
        } else if("draw".equals(name)){
            basicTask = new DrawTask(args);
        } else if("ward".equals(name)){
            basicTask = new WardTask(args);
        } else if("teleport".equals(name)){
            basicTask = new TeleportTask(args);
        } //else throw exception;
        return basicTask;
    }
}
