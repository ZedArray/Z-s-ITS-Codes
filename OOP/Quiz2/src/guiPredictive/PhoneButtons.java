package guiPredictive;

import wordTree.MainNode;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;
import javax.swing.JButton;
import javax.swing.JPanel;

public class PhoneButtons extends JPanel{
    //create array of buttons
    private JButton[][] buttons;
    private final int buttonRows = 4;
    private final int buttonColumns = 3;

    //helper class
    MainNode conv = new MainNode();

    //Constructor, creates all necessary buttons and its action listener
    public PhoneButtons(final Model model) {
        setLayout(new GridLayout(buttonRows, buttonColumns));
        buttons = new JButton[buttonRows][buttonColumns];

        //start from number 1
        int k = 1;

        for (int i = 0; i < buttonRows - 1; i++) {
            for (int j = 0; j < buttonColumns; j++) {
                String s = new String();

                if(k != 1){
                    s += String.valueOf(k);
                }
                else{
                    s = "1";
                }

                //for button number 1, no functionality(no addActionListener)
                if (k == 1){
                    buttons[i][j] = new JButton(s);
                }

                //for button number 2-9, needs to create 2 JLabel to add to the button for the number and the corresponding alphabet
                //Also add ActionListener to each button
                if(k != 1){
                    buttons[i][j] = new JButton();
                    buttons[i][j].setLayout(new BorderLayout());
                    JLabel label1 = new JLabel(s, SwingConstants.CENTER);
                    JLabel label2 = new JLabel(conv.angkaKeHuruf(k), SwingConstants.CENTER);
                    buttons[i][j].add(BorderLayout.NORTH,label1);
                    buttons[i][j].add(BorderLayout.SOUTH,label2);
                    buttons[i][j].addActionListener(new ButtonListener(k, model));
                }
                k++;
            }
        }


        //for bottom rows of the buttons
        buttons[3][0] = new JButton("*");

        buttons[3][0].addActionListener(new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent e) {
                model.nextWord();
            }//for next predicted word
        });

        buttons[3][1] = new JButton();
        buttons[3][1].setLayout(new BorderLayout());
        JLabel label1 = new JLabel("0", SwingConstants.CENTER);
        JLabel label2 = new JLabel("_", SwingConstants.CENTER);
        buttons[3][1].add(BorderLayout.NORTH,label1);
        buttons[3][1].add(BorderLayout.SOUTH,label2);

        buttons[3][1].addActionListener(new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent e) {
                model.newWord();//for next word in the text field
            }
        });

        buttons[3][2] = new JButton("#");

        buttons[3][2].addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                model.backSpace();
            }//for delete the last input
        });

        //add all buttons
        for (int i = 0; i < buttonRows; i++) {
            for (int j = 0; j < buttonColumns; j++) {
                add(buttons[i][j]);
            }
        }

    }
}
