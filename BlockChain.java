import java.util.LinkedList;

public class BlockChain{
    private LinkedList<Block> chain;
    
    public BlockChain(){
        chain = new LinkedList<>();
        String[] genesisTransactions = {"A sends 10 coins to B", "B send 5 coins to C"};
        chain.add(new Block(genesisTransactions, "0"));
    }

    public void addBlock(String[] transactions){
        String previousHash = chain.getLast().getBlockHash();
        chain.add(new Block(transactions, previousHash));
    }
}