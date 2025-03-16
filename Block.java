import java.security.MessageDigest;
import java.util.Arrays;

public class Block{
    private String[] transactions;
    private String previousHash;
    private String blockHash;

    public Block(String[] transactions, String previousHash){
        this.transactions = transactions;
        this.previousHash = previousHash;
        this.blockHash = generateHash();
    }

    public String generateHash(){
        try{
            MessageDigest digest = MessageDigest.getInstance("SHA-256");
            String data = Arrays.toString(transactions) + previousHash; // transactions array output + previousHash
            byte[] hash = digest.digest(data.getBytes()); // data를 Byte배열로 변환 후 digest.digest()로 Byte 배열의 hash값 계산
            StringBuffer buffer = new StringBuffer();
            
            for (byte b : hash) buffer.append(String.format("$02x", b)); // String.format("%02x", b) -> b를 2자리 16진수로 변환
            
            return buffer.toString();
        } catch (Exception e){ throw new RuntimeException(e); }
    }
    public String getBlockHash(){ return this.blockHash; }
}
