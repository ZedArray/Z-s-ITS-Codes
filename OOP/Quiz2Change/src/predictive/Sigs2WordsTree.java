package predictive;

import java.util.Scanner;

/**
 * This class is a command-line program to test the signatureToWords method in DictionaryTreeImpl.
 */
public class Sigs2WordsTree {
    public static void main(String[] args) {
        // Create Dictionary type variable with DictionaryTreeImpl instance
        Dictionary dictTree = new DictionaryTreeImpl("C:\\Users\\Admin\\OneDrive\\Documents\\GitHub\\Z-s-ITS-Codes\\OOP\\Quiz2Change\\src\\predictive\\words\\");

        try (Scanner scan = new Scanner(System.in)) {
            // Scan input from the console and convert it to corresponding words
            while (scan.hasNextLine()) {
                String input = scan.next();
                System.out.println(input + ": " + dictTree.signatureToWords(input));
            }
        }
    }
}

