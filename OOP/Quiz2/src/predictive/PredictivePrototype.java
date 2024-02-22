package predictive;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

/**
 * PredictivePrototype Class
 * This class is used to store methods used for words and signature manipulation
 */
public class PredictivePrototype {

    /**
     * A method used to change a word to a signature numbers
     * 
     * @param word
     *      A word with string datatype that the user wanted to change
     * @return
     *      A string of signature numbers that represents the word
     */
    public static String wordToSignature(String word){
        // We use StringBuffer instead of String datatype because String datatype is immutable.
        // Immutable means that everytime we alter the string, a new object created.
        // That makes the String datatype less efficient than mutable datatype like StringBuffer
        StringBuffer signature = new StringBuffer("");

        // Every input has to be lower cased
        String input = word.toLowerCase();

        // For every character inside the word gets their own signature numbers
        int i = 0;
        int totalHuruf = input.length();

        // We traverse the word from the 0 index to the last index and append every signature to
        // signature variable
        while (totalHuruf > 0){
            // current variable is used to point where the current traversed index was
            char current = input.charAt(i);
            if (current == 'a' || current == 'b' || current == 'c'){
                signature.append('2');
            }
            else if (current == 'd' || current == 'e' || current == 'f'){
                signature.append('3');
            }
            else if (current == 'g' || current == 'h' || current == 'i'){
                signature.append('4');
            }
            else if (current == 'j' || current == 'k' || current == 'l'){
                signature.append('5');
            }
            else if (current == 'm' || current == 'n' || current == 'o'){
                signature.append('6');
            }
            else if (current == 'p' || current == 'q' || current == 'r' || current == 's'){
                signature.append('7');
            }
            else if (current == 't' || current == 'u' || current == 'v'){
                signature.append('8');
            }
            else if (current == 'w' || current == 'x' || current == 'y' || current == 'z'){
                signature.append('9');
            }
            // When user inputing unique character, their signature character will be whitespace
            else {
                signature.append(' ');
            }
            // Increment every traversal
            i++;
            totalHuruf--;
        }

        // Return signature variable in the form of String datatype
        return signature.toString();
    }
    //the above method can be implemented more efficient using the maps implementation, but we decided to not use it because the step by step progression

    /**
     * Method for converts signature to the corresponding words in the dictionary
     * 
     * @param signature
     *      A signature variable with String datatype that wanted to be processed
     * @return
     *      A set of words that have the same signature that given in the input parameter
     */
    public static Set<String> signatureToWords(String signature){
        // We use BufferedReader object to read a file from another file path
        BufferedReader br = null;

        // This stringList is used to save all the words from the "D:/words" file
        List<String> stringList = new ArrayList<String>();
        // We use try and catch to handle errors
        try {
            String currentLine;
            br = new BufferedReader(new FileReader("E:/words"));
            // We read all the words till the end of line
            while ((currentLine = br.readLine()) != null){
                if (isValidWord(currentLine)){
                    stringList.add(currentLine.toLowerCase());
                }
            }
        }catch (IOException e){
            // Print the details such as line number and class name where the error occured
            e.printStackTrace();
        }finally {
            try {
                if (br != null){
                    br.close();
                }
            }catch (IOException ex){
                ex.printStackTrace();
            }
        }

        // This set is used to store all the words that have the same signature that equals with inputed signature
        Set<String> result = new TreeSet<String>();
        for (String s : stringList){
            if (wordToSignature(s).equals(signature)){
                result.add(s);// for all the result that qualified, store it in a Set
            }
        }

        // Return the set of words
        return result;
    }

    /**
     * A checker method for validating a word is alphabetic or not
     * 
     * @param word
     *      A String that will be checked wheter the word is valid or not
     * @return
     *      A boolean that tells wheter the word is valid or not
     */
    private static boolean isValidWord(String word) {
        // We first set the checker to false so that when the word is actually valid
        // we could set it to true
        int len = word.length();
        boolean checker = false;
        int i = 0;
        
        // We traverse the word from the first index till the last index wheter the character is in lowercased alphabet or not
        while(len > 0) {
            if((word.charAt(i) >= 97 && word.charAt(i) <= 122) || (word.charAt(i) >= 65 && word.charAt(i) <= 90)) {
                checker = true;
            }
            else {
                checker = false;
                break;
            }
            len--;
            i++;
        }

        // We return the condition wheter the word is valid or not
        return checker;
    }


}
