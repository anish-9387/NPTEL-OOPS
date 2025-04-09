import javax.swing.*;

public class CounterApplicationGUI{
    public static void main(String[] args) {
        JFrame frame=new JFrame("Counter");
        JLabel counterLabel=new JLabel("Count: 0");
        JButton incrementButton=new JButton("Increment");
        JButton reseButton=new JButton("Reset");

        final int[] counter={0};
        incrementButton.addActionListener(e->{
            counter[0]++;
            counterLabel.setText("Count: "+counter[0]);
        });

        reseButton.addActionListener(e->{
            counter[0]=0;
            counterLabel.setText("Count: "+counter[0]);
        });

        JPanel panel=new JPanel();
        panel.add(counterLabel);
        panel.add(incrementButton);
        panel.add(reseButton);

        frame.add(panel);
        frame.setSize(300,150);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}