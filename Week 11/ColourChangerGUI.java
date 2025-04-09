import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class ColourChangerGUI{
    public static void main(String[] args) {
        JFrame frame = new JFrame("Colour Changer");
        JButton button = new JButton("Change Colour");
        JPanel panel = new JPanel();

        button.addActionListener(e->{
            Color newColour=new Color((int)(Math.random() * 255), (int)(Math.random() * 255), (int)(Math.random() * 255));
            panel.setBackground(newColour);
        });     
        
        panel.add(button);
        frame.add(panel);
        frame.setSize(300,200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}