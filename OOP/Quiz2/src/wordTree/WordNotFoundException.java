package wordTree;

/**
 * This class is used to store Exception when a word not found
 */
@SuppressWarnings("serial")
public class WordNotFoundException extends Exception{
    public WordNotFoundException(){
        super();
    }

    //helper method for exceptions
    public WordNotFoundException(String s){
        super(s);
    }
}
