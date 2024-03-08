package predictive;

import java.util.Scanner;

/**
 * This class is a command-line program for the PredictivePrototype class to test the signatureToWords method
 */
public class Sigs2WordsProto {
    public static void main(String[] args) {
        //try to scan all input from console than converts it to the corresponds words
        try(Scanner scan = new Scanner(System.in)){
            while (scan.hasNextLine()){
                String input = scan.next();
                System.out.println(input + ": " + PredictivePrototype.signatureToWords(input));
            }
        }
    }
}