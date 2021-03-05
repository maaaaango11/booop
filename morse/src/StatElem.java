public class StatElem {
    private final Literal literal;
    private final int count;

    StatElem(Literal l, int c){
        literal = l;
        count = c;
    }
    public Literal getL(){
        return literal;
    }
    public int getCount(){
        return count;
    }
}
