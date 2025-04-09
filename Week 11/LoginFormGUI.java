import javax.swing.*;

public class LoginFormGUI{
    public static void main(String[] args) {
        JFrame frame=new JFrame("Login Form");
        JLabel userLabel=new JLabel("Username: ");
        JTextField userField=new JTextField(15);
        JLabel passLabel=new JLabel("Password: ");
        JPasswordField passwordField=new JPasswordField(15);
        JButton loginButton=new JButton("Login");

        loginButton.addActionListener(e->{
            String username=userField.getText();
            String password=new String(passwordField.getPassword());
            JOptionPane.showMessageDialog(frame,"Welcome, "+username+"!");
        });

        JPanel panel=new JPanel();
        panel.add(userLabel);
        panel.add(userField);
        panel.add(passLabel);
        panel.add(passwordField);
        panel.add(loginButton);

        frame.add(panel);
        frame.setSize(300,200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}