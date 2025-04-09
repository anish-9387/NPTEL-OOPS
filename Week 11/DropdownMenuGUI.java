import javax.swing.*;

public class DropdownMenuGUI{
    public static void main(String[] args) {
        JFrame frame=new JFrame("Dropdown Menu");
        JLabel label=new JLabel("Select an option");
        JComboBox<String> dropdown=new JComboBox<>(new String[]{
            "Option 1","Option 2","Option 3"
        });

        dropdown.addActionListener(e->{
            String selected=(String)dropdown.getSelectedItem();
            JOptionPane.showMessageDialog(frame,"You selected: "+selected);
        });

        JPanel panel=new JPanel();
        panel.add(label);
        panel.add(dropdown);

        frame.add(panel);
        frame.setSize(300,150);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}