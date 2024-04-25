package guiPredictive;

import java.awt.BorderLayout;

import javax.swing.JPanel;

import predictive.Dictionary;

/**
 * This class represents all the components of the main frame
 */
public class Components extends JPanel {
    //Constructor, a helper class to add all the necessary components
    @SuppressWarnings("deprecation")
	public Components(Dictionary dict) {
        // add super component to draw the components
        super();

        // Call Model of the program called model
        Model model = new Model(dict);

        // Textfield where the user an input the words
        TextField textField = new TextField(model);

        model.addObserver(textField);

        // PhoneButtons object are the clicked buttons in the frame
        PhoneButtons buttons = new PhoneButtons(model);

        // We use BorderLayout for Layouting necessity
        setLayout(new BorderLayout());

        // Add all the components with BorderLayout Layouting Regulation
        add(textField, BorderLayout.CENTER);
        add(buttons, BorderLayout.SOUTH);

    }
}
