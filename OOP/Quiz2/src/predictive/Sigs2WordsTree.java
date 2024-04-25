package predictive;

import java.util.Scanner;

/**
 * This method is used to run the Sig2Words Implementation in Tree-type
 */
public class Sigs2WordsTree {
    public static void main(String[] args) {
        //Create Dictionary type variable with DictionaryTreeImpl instance
        Dictionary dictTree = new DictionaryTreeImpl("D:/words");

        try(Scanner scan = new Scanner(System.in)){
            //try to scan all input from console than converts it to the corresponds words
            while (scan.hasNextLine()){
                String input = scan.next();
                System.out.println(input + ": " + dictTree.signatureToWords(input));
            }
        }
    }
}
