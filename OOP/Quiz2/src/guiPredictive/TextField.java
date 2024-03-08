package guiPredictive;

import java.util.Observer;
import java.util.Observable;
import javax.swing.JTextArea;

public class TextField extends JTextArea implements Observer {
    private Model model;

    //Constructor to assign the model
    public TextField(Model model) {
        super();
        super.setEditable(false);
        super.setLineWrap(true);
        this.model = model;
    }

    //update method for appends word to the current message
    @Override
    public void update(Observable arg0, Object arg1) {
        setText(model.getMessage() + model.getCurrentWord());
    }
}
