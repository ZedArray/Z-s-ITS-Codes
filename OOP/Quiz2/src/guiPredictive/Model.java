package guiPredictive;

import java.util.Collection;
import java.util.Iterator;
import java.util.Observable;

import predictive.Dictionary;

/**
 * This class is a model class to handle every component updates
 */
@SuppressWarnings("deprecation")
public class Model extends Observable{
    private Collection<String> words;
    private Iterator<String> i;
    private Dictionary model;
    private String workingSig = new String();
    private String currMessage;
    private String currWord;

    //Constructor to get Dictionary
    public Model(Dictionary model) {
        super();
        this.model = model;
        currMessage = new String();
    }

    //method to gets recommended words
    public void getWordsFromSig() {
        words = model.signatureToWords(workingSig);
        setupIterator();
        nextWord();
        setChanged();
        notifyObservers();
    }

    //method to set current to next word
    public void nextWord() {
        try {
            if (i.hasNext()) {
                currWord = i.next();
            } else {
                setupIterator();
                if (i.hasNext())
                    currWord = i.next();
            }
            setChanged();
            notifyObservers();
        }
        //to prevent error when its on the end
        catch (NullPointerException e) {
        }
    }

    //helper method to create new iterator
    private void setupIterator() {
        i = words.iterator();
    }

    //getter for currentWord
    public String getCurrentWord() {
        return currWord;
    }

    //method to process when signature is been added to the current one
    public void addSigChar(int k) {
        workingSig += String.valueOf(k);
        getWordsFromSig();
    }

    //getter for workingSignature
    public String getWorkingSig() {
        return workingSig;
    }

    //method to create a new word
    public void newWord() {
        currWord += " ";
        currMessage += currWord;
        currWord = new String();
        workingSig = new String();
        setupIterator();
        setChanged();
        notifyObservers();

    }

    //getter for currentMessage
    public String getMessage() {
        return currMessage;
    }

    //method to delete last char of the current signature
    public void backSpace() {
        workingSig = workingSig.substring(0, workingSig.length() - 1);
        getWordsFromSig();
    }
}
