package predictive;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

import wordTree.MainNode;
import wordTree.WordNotFoundException;

/**
 * This class is used to stores dictionary with Tree-type implementation
 */
public class DictionaryTreeImpl implements Dictionary{
    private MainNode tree; // Instance of tree with 8 child
    private String filePathz; // Using filePath variable

    // Class Constructor
    public DictionaryTreeImpl(String path) {
        filePathz = path;
        tree = new MainNode();//Create new instance of tree

        //Using BufferedReader to read file and stores it in stringList
        BufferedReader br = null;
        List<String> stringList = new ArrayList<String>();
        try {
            String currentLine;
            br = new BufferedReader(new FileReader(filePathz));
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
        for (String s : stringList){
            //for every qualified words, insert it to the tree
            tree.insertWord(s);
        }
    }

    //Using override because the method is implementation from the Dictionary interface
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

    //Using override because the method is implementation from the Dictionary interface
    @Override
    public Set<String> signatureToWords(String signature) {
        try {
            return (Set<String>) tree.getWordsFromSig(signature);
        } catch (WordNotFoundException e) {
            System.out.println("Word not in the dictionary");
            return new TreeSet<String>();
        }
    }

    //method to check whether the input words is alphabetic
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
