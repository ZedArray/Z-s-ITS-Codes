package predictive;

import java.util.Scanner;

/**
 * This class is a command-line program for the PredictivePrototype class to test the wordToSignature method
 */
public class Words2SigProto {
    public static void main(String[] args) {
        // try to scan all input from console than converts it to signature
        try(Scanner scan = new Scanner(System.in)){
            while (scan.hasNextLine()){
                String input = scan.next();
                // We prints all the testcase according to the problem given
                System.out.println(input + ": " + PredictivePrototype.wordToSignature(input));
            }
        }
    }
}
