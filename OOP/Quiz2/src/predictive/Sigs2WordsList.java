package predictive;

import java.util.Scanner;

/**
 * This method is used to run the Sig2Words Implementation in List-type
 */
public class Sigs2WordsList {
    public static void main(String[] args) {
        //Create DictionaryListImpl instance to fills the dictionary data from its constructor
        DictionaryListImpl dict = new DictionaryListImpl();

        try(Scanner scan = new Scanner(System.in)){
            //try to scan all input from console than converts it to the corresponds words
            while (scan.hasNextLine()){
                String input = scan.next();
                System.out.println(input + ": " + DictionaryListImpl.signatureToWords(input));
            }
        }
    }
}
