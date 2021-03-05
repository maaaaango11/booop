import java.io.*;
import java.util.Scanner;
public class IOmanager {
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

        } catch (IOException e){
            e.printStackTrace();
        }
    }
    private void decode(File inFile, File outFile, String command){
        String temp;
        StringBuilder text = new StringBuilder();
        try{
            Scanner scanner = new Scanner(inFile);
            BufferedWriter writer = new BufferedWriter(new FileWriter(outFile));
            if(command.equals("decode")){
                while(scanner.hasNext()){
                    temp = scanner.next();
                    text.append(dictionary.lookFor(new Literal(temp)));
                }
            }
            if(command.equals("code")){
                while(scanner.hasNext()){
                    temp = scanner.next();
                    text.append(dictionary.lookFor(temp).getS());
                }
            }
            writer.write(text.toString());

        } catch (IOException e){
            e.printStackTrace();
        }
    }
    public void consoleRead(){
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        try{
            String line = reader.readLine();
            if(line.split("\\s")[0].equals("code") || line.split("\\s")[0].equals("decode")){
                if(!line.split("\\s")[1].equals("")){
                    decode(new File(line.split("\\s")[1]), new File("out.txt"), line.split("\\s")[0]);
                }
            }
        } catch (IOException e){
            e.printStackTrace();
        }
    }
}
