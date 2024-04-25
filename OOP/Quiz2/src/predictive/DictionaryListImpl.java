package predictive;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

/**
 * This class is used to implements the dictionary and the word-signature manipulations efficiently
 */
public class DictionaryListImpl{
    public static List<WordSig> myList = new ArrayList<>();//To stores the signature

    // Class Constructor
    DictionaryListImpl(){
        //try to open file using BufferedReader and store the words to the stringList
        BufferedReader br = null;
        List<String> stringList = new ArrayList<String>();
        try {
            String currentLine;
            br = new BufferedReader(new FileReader("E:/words"));
            // We read all the words until the end of the file
            while ((currentLine = br.readLine()) != null){
                if (isValidWord(currentLine)){
                    stringList.add(currentLine.toLowerCase());
                }
            }
        }catch (IOException e){
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

        //for all the qualified words, add them paired with their signature to the myList in the form of WordSig object
        for (String s : stringList){
            String signature = wordToSignature(s);
            WordSig hasil = new WordSig(s, signature);
            myList.add(hasil);
        }
        //sort the list so that binary search can be implemented
        Collections.sort(myList);
    }

    /**
     * method to converts word to signature
     * 
     * @param word
     *      A word with string datatype that the user wanted to change
     * @return
     *      A string of signature numbers that represents the word
     */
    public static String wordToSignature(String word){
        // This methods used the same implementations like wordToSignature methods in PredictivePrototype class
        StringBuffer signature = new StringBuffer("");
        String input = word.toLowerCase();
        int i = 0;
        int totalHuruf = input.length();
        while (totalHuruf > 0){
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
            else {
                signature.append(' ');
            }
            i++;
            totalHuruf--;
        }
        return signature.toString();
    }

    /**
     * Method to converts signatures to the corresponding words using List of WordSig
     * 
     * @param signature
     *      A signature variable with String datatype that wanted to be processed
     * @return
     *      A set of words that have the same signature that given in the input parameter
     */
    public static Set<String> signatureToWords(String signature){
        Set<String> result = new TreeSet<String>();

        // We use Collection.binarySearch to find the suitable words with binary searching
        int indexFinder = Collections.binarySearch(myList, new WordSig(null, signature));

        // Check wheter the word is available or not
        if(indexFinder < 0) System.out.println("Words unavailable");
        if(indexFinder >= 0) {
            result.add(myList.get(indexFinder).getWords());
        }

        // Check to the incremented index wheter the word having the same signature or not
        int upperIndex = indexFinder + 1;
        while(myList.get(upperIndex).getSignature().equals(signature)) {
            result.add(myList.get(upperIndex).getWords());
            upperIndex++;
        }

        // Check to the decremented index wheter the word having the same signature or not
        int lowerIndex = indexFinder - 1;
        while(myList.get(lowerIndex).getSignature().equals(signature)) {
            result.add(myList.get(lowerIndex).getWords());
            lowerIndex--;
        }

        // Return the set of words that have the same signature
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
        // This is the same method that used in PredictivePrototype class
        int len = word.length();
        boolean checker = false;
        int i = 0;
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

        return checker;
    }
}
