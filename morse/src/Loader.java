import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public class Loader {
    public void load(Dictionary dictionary, File charset){
        String temp;
        try{
            Scanner scanner = new Scanner(charset);
            while(scanner.hasNextLine()){
                temp = scanner.nextLine();
                dictionary.putEntry(temp.split("\\s")[0], temp.split("\\s")[1]);//
            }

        } catch (IOException e){
            e.printStackTrace();
        }
    }
}
