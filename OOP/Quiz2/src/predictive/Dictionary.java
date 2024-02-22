package predictive;

import java.util.Set;

/**
 * This interface will be the blueprint of the word and signature manipulation for
 * every type of implementation
 */
public interface Dictionary {
    //Data path for the location of the file, InCase will be use later
    String dictionaryPath = "E:/words";

    //Method for converting words to signature
    String wordToSignature(String word);

    //Method for converting signature to the corresponded words
    Set<String> signatureToWords(String signature);
}
