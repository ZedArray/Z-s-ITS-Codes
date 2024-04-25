package guiPredictive;

import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class ButtonListener implements ActionListener {
    private Model model;
    private int sig;

    //Constructor to assign model and current char signature
    public ButtonListener(int n, Model model) {
        this.model = model;
        this.sig = n;
    }

    //using override because its implemented from ActionListener interface
    //perform addSigChar to the current model's state
    @Override
    public void actionPerformed(ActionEvent e) {
        model.addSigChar(sig);
    }
}
