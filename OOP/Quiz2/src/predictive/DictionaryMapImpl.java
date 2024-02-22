package predictive;

import java.io.BufferedReader;
import java.util.*;
import java.io.FileReader;
import java.io.IOException;

public class DictionaryMapImpl implements  Dictionary{
    // using HashMap to store the pair of signatures and the corresponding words
    // We use HashMap because it will be more efficient, the detailed information will be written in the report
    private Map<String, Set<String>> dictionary = new HashMap<String, Set<String>>();

    // Class Constructor
    public DictionaryMapImpl() {
        //read file using BufferedReader and store it in a stringList
        BufferedReader br = null;
        List<String> stringList = new ArrayList<String>();
        try {
            String currentLine;
            br = new BufferedReader(new FileReader("E:/words"));
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
        
        // We store data with a pair of one signature with all words that can be represented by the same signature
        // First we trace all the words
        for (String s : stringList){
            // Next, we find the signature
            String signature = wordToSignature(s);
        
            // If the signature is already in the dictionary, we add the word to
            // the set of words with the same key signature
            if (dictionary.containsKey(signature)){
                if (!dictionary.get(signature).contains(s)){
                    dictionary.get(signature).add(s);
                }
            }

            // If the signature is not in the dictionary, we made new pair
            // of new signature and the set of words
            else {
                Set<String> baru = new TreeSet<String>();
                baru.add(s);
                dictionary.put(signature, baru);
            }
        }
    }


    //using override because the method is implementation from the Dictionary interface
    @Override
    public String wordToSignature(String word) {
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

    //using override because the method is implementation from the Dictionary interface
    @Override
    public Set<String> signatureToWords(String signature) {
        if(dictionary.containsKey(signature)){
            return dictionary.get(signature);
        }
        else {
            System.out.println("Word not in the dictionary");
            return new TreeSet<>();
        }
    }


    //to check whether the input word is alphabetic
    private boolean isValidWord(String word) {
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
