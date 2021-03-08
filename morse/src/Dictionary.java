import java.util.HashMap;

public final class Dictionary {
    private final HashMap<String, String> morseToEng = new HashMap<>();
    private final HashMap<String, String> engToMorse = new HashMap<>();

    public void putEntry(String l, String s){
        morseToEng.put(s, l);
        engToMorse.put(l, s);
    }

    public String lookForDecode(String s){ //check w equals
        return morseToEng.get(s);
    }

    public String lookForCode(String l){ //check w equals
        return engToMorse.get(l);
    }
}
