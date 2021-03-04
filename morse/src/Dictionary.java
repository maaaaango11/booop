import java.util.HashMap;

public final class Dictionary {
    private final HashMap<String, Literal> morseToEng = new HashMap<>();
    private final HashMap<Literal, String> engToMorse = new HashMap<>();

    public void putEntry(Literal l, String s){
        morseToEng.put(s, l);
        engToMorse.put(l, s);
    }

    public Literal lookFor(String s){ //check w equals
        return morseToEng.get(s);
    }

    public String lookFor(Literal l){ //check w equals
        return engToMorse.get(l);
    }
}
