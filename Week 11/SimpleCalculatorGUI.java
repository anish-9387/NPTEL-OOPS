import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class SimpleCalculatorGUI{
    public static void main(String[] args) {
        JFrame frame=new JFrame("Calculator");
        JTextField textField=new JTextField();
        JButton buttonAdd=new JButton("+");
        JButton buttonSub=new JButton("-");
        JLabel result=new JLabel("Result: 0");

        buttonAdd.addActionListener(e->{
            int num=Integer.parseInt(textField.getText());
            result.setText("Result: "+(num+1));
        });

        buttonSub.addActionListener(e->{
            int num=Integer.parseInt(textField.getText());
            result.setText("Result: "+(num-1));
        });

        JPanel panel=new JPanel();
        panel.add(textField);
        panel.add(buttonAdd);
        panel.add(buttonSub);
        panel.add(result);

        frame.add(panel);
        frame.setSize(400,150);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}