package predictive;

import java.util.Scanner;

/**
 * This method is used to run the Sig2Words Implementation in Map-type
 */
public class Sigs2WordsMap {
    public static void main(String[] args) {
        //Create Dictionary type variable with DictionaryMapImpl instance
        Dictionary dictMap = new DictionaryMapImpl();

        try(Scanner scan = new Scanner(System.in)){
            //try to scan all input from console than converts it to the corresponds words
            while (scan.hasNextLine()){
                String input = scan.next();
                System.out.println(input + ": " + dictMap.signatureToWords(input));
            }
        }
    }
}
