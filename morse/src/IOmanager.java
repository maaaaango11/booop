import java.io.*;
import java.util.Scanner;

public class IOmanager {
    private final Dictionary dictionary;
    private final StatTable statTable;

    IOmanager(Dictionary dict, StatTable table){
        dictionary = dict;
        statTable = table;
        
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
                    text.append(dictionary.lookForDecode(temp));
                    statTable.addElem(new StatElem(dictionary.lookForDecode(temp)));
                    //restructure this
                }
            }
            if(command.equals("code")){
                while(scanner.hasNext()){
                    temp = scanner.next();
                    for(int i = 0; i<temp.length(); i++){
                        char idx = temp.charAt(i);
                        text.append(dictionary.lookForCode(String.valueOf(idx)));
                        statTable.addElem(new StatElem(String.valueOf(idx)));
                    }
                    //restructure this
                }
            }
            writer.write(text.toString());

        } catch (IOException e){
            e.printStackTrace();
        }
    }
    public void statPrint(){
        StringBuilder text = new StringBuilder();
        try{
            BufferedWriter writer = new BufferedWriter(new FileWriter("stat")); //auto generate this
            for(StatElem elem: statTable.getStatTable()){
                text.append(elem.getL());
                text.append("\\s");
                text.append(elem.getCount());
                text.append("\n");
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
                    statPrint();
                }
            }
        } catch (IOException e){
            e.printStackTrace();
        }
    }
}
//pattern
//how to clear and when?