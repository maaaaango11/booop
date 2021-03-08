import java.util.HashSet;

public class StatTable {
    private final HashSet<StatElem> statTable = new HashSet<>();
    public void addElem(StatElem elem){
        statTable.add(elem);
    }
    public HashSet<StatElem> getStatTable() {
        return statTable;
    }
}
