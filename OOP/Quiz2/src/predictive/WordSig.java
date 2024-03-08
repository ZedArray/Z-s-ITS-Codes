package predictive;

/**
 * This class is used to store a pair of string and its signature
 * This class implements Comparable class so that this class could Override compareTo method
 */
public class WordSig implements Comparable<WordSig>{

    // Variables for the class constructure
    private String words;
    private String signature;

    /**
     * Class constructure
     * 
     * @param wordz
     * @param signaturez
     *      A pair of word and signature that represents each other
     */
    public WordSig(String wordz, String signaturez){
        this.words = wordz;
        this.signature = signaturez;
    }

    // This metod is used to return the word
    public String getWords() {
        return words;
    }

    // This metod is used to return the signature
    public String getSignature() {
        return signature;
    }

    /**
     * We override compareTo method to compare the 2 WordSig object
     * @param ws
     *      A WordSig object that will be compared with another WordSig object
     */
    @Override
    public int compareTo(WordSig ws){
        if (this.getSignature().length() == ws.getSignature().length()) {
            //compare all the numerical from the 2 signatures
            for (int i = 0; i < this.getSignature().length(); i++) {
                if (this.getSignature().charAt(i) > ws.getSignature().charAt(i)) {
                    return 1;
                } else if (this.getSignature().charAt(i) < ws.getSignature().charAt(i)) {
                    return -1;
                }
            }
        } else {
            //if the word length not the same, find the shortest one
            return (this.getSignature().length() - ws.getSignature().length());
        }
        // Return 0 if the signature is same
        return 0;
    }
}
