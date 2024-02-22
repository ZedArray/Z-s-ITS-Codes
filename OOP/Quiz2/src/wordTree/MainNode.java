package wordTree;

import java.util.Collection;
import java.util.HashSet;
import java.util.Set;

/**
 * This class is used to store data of the tree nodes
 */
public class MainNode {
    //Array type MainNode to store the tree's child
    private MainNode[] children = new MainNode[8];

    //Depth of the current node
    private final int nodeDepth;

    // Set of strings to store the words in the dictionary
    Set<String> words = new HashSet<String>();

    //Class Constructor
    public MainNode() {
        this.nodeDepth = 0;
    }

    // Special constructor that only be used in this class
    // This constructor will be use to implements the methods only inside this class
    protected MainNode(int nodeDepth) {
        this.nodeDepth = nodeDepth;
    }

    /**
     * This method is used to trim a String to a new trimmed String
     * This method can also be used to backspace words
     * 
     * @param word
     *      This is the word that will be trimmed
     * @return
     *      Return the new trimmed String
     */
    private String trimWord(String word) {
        return word.substring(0, nodeDepth);
    }

    /**
     * This method is used to insert the new word to the tree
     * @param word
     *      A word that will be added to the tree
     */
    public void insertWord(String word) {
        //if it's not in the root, store the words to the node and then trim the word 
        if (this.nodeDepth != 0){
            words.add(trimWord(word));
        }

        if (word.length() > nodeDepth) {
            // Convert the character to numbers
            int charValue = hurufKeAngka(word.charAt(nodeDepth)) - 2;
            // If the child is null then is need to be created
            if (children[charValue] == null) {
                children[charValue] = new MainNode(nodeDepth + 1);
            }
            // Recursive call to this function
            children[charValue].insertWord(word);
        }

    }

    //method to return words corresponds to the signature
    public Collection<String> getWordsFromSig(String sig) throws WordNotFoundException {
        //Base case for the recursive method
        if (sig.isEmpty()) {
            return words;
        } else {
            int childNumber = Character.getNumericValue(sig.charAt(0)) - 2;
            if (children[childNumber] != null) {
                //Recall the method with string from the 2nd char of the current string
                return children[childNumber].getWordsFromSig(sig.substring(1));
            } else {
                throw new WordNotFoundException("Your word was not in the dictionary");
            }
        }

    }

    //getter words
    public Collection<String> getWords() {
        return words;
    }

    //to return the current node child
    public MainNode getChild(int i) {
        return children[i];
    }

    //Helper method to convert alphabetic character to numbers
    public int hurufKeAngka(char x){
        char current = x;
        if (current == 'a' || current == 'b' || current == 'c'){
            return 2;
        }
        else if (current == 'd' || current == 'e' || current == 'f'){
            return 3;
        }
        else if (current == 'g' || current == 'h' || current == 'i'){
            return 4;
        }
        else if (current == 'j' || current == 'k' || current == 'l'){
            return 5;
        }
        else if (current == 'm' || current == 'n' || current == 'o'){
            return 6;
        }
        else if (current == 'p' || current == 'q' || current == 'r' || current == 's'){
            return 7;
        }
        else if (current == 't' || current == 'u' || current == 'v'){
            return 8;
        }
        else if (current == 'w' || current == 'x' || current == 'y' || current == 'z'){
            return 9;
        }
        else {
            return 0;
        }
    }

    //Helper method to convert numbers to alphabetic character
    public String angkaKeHuruf(int x){

        if (x == 2){
            return "abc";
        }
        else if (x == 3){
            return "def";
        }
        else if (x == 4){
            return "ghi";
        }
        else if (x == 5){
            return "jkl";
        }
        else if (x == 6){
            return "mno";
        }
        else if (x == 7){
            return "pqrs";
        }
        else if (x == 8){
            return "tuv";
        }
        else if (x == 9){
            return "wxyz";
        }
        else{
            return "";
        }
    }
}
