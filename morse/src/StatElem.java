import java.util.Objects;

public class StatElem {
    private final String literal;
    private int count = 0;

    StatElem(String l){
        literal = l;
    }
    public String getL(){
        return literal;
    }
    public int getCount(){
        return count;
    }
    //add "comparable" but its never used;
    public boolean equals(Object obj){
        if(literal == null || obj == null) return true;
        StatElem s = (StatElem) obj;
        if(literal.equals(s.getL())){
            count++;
            return true;
        }
        return false;
    }

//    @Override
//    public int hashCode() {
//        return Objects.hash(literal, count);
//    }
}
//hashSet add will do equals of this and in this override