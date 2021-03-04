import java.io.*;
import java.util.Scanner;
public class IOmanager {
    //private InputStreamReader reader;
    private final Dictionary dictionary;

    IOmanager(Dictionary dict, File charset){
        String temp;
        dictionary = dict;
        try{
            Scanner scanner = new Scanner(charset);
            while(scanner.hasNextLine()){
                temp = scanner.nextLine();
                dictionary.putEntry(new Literal(temp.split("\\s")[0]), temp.split("\\s")[1]);//
            }
            //reader = new InputStreamReader(new FileInputStream("charset"));
            //reader.readLine();
        } catch (IOException e){
            e.printStackTrace();
        }
    }
    public void decode(File inFile, File outFile){
        String temp;
        StringBuilder text = new StringBuilder();
        try{
            Scanner scanner = new Scanner(inFile);
            BufferedWriter writer = new BufferedWriter(new FileWriter(outFile));
            while(scanner.hasNext()){
                temp = scanner.next();
                text.append(dictionary.lookFor(new Literal(temp)));
            }
            writer.write(text.toString());

        } catch (IOException e){
            e.printStackTrace();
        }
    }
    public void encode(File inFile, File outFile){

    }
}
