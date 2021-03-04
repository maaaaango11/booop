import java.io.File;
public class Main {
    Main(){
    Dictionary dictionary = new Dictionary();
    IOmanager manager = new IOmanager(dictionary, new File("charset"));
    }
}
