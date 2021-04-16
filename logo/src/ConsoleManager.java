import java.io.*;
public class ConsoleManager {
    final private TaskFactory factory = new TaskFactory();
    public Task read(){
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        Task task = null;
        try{
            String line = reader.readLine();
            String name = line.split("\\s")[0];
            String[] args = line.substring(name.length()-1).split("\\s"); //without name
            task = factory.create(name, args);
        } catch (IOException e){
            e.printStackTrace();
        }
        return task;
    }
}
