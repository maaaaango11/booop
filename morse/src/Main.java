import java.io.File;
public final class Main {
    Main(){
    Dictionary dictionary = new Dictionary();
    Loader loader = new Loader();
    loader.load(dictionary, new File("charset"));
    StatTable statTable = new StatTable();
    IOmanager manager = new IOmanager(dictionary, statTable);
    manager.consoleRead();
    }
}
