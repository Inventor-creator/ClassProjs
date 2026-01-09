
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.util.Scanner;



public class Main
 {

     public static void main(String[] args) {
         Frame f = new Frame("1");
         f.setSize(2000, 1000);
         Label label = new Label("something");
         Button button = new Button(label.getText());
         button.setBounds(50, 100, 120, 30);


         button.addActionListener(new ActionListener() {
             @Override
             public void actionPerformed(ActionEvent e) {
                 System.out.println("new frame generated");
                 Frame f2 = new Frame("2");
                 f2.setSize(200,200);
                 f.setVisible(false);
                 f2.addWindowListener(new WindowAdapter() {
                     @Override
                     public void windowClosing(WindowEvent e) {
                         f2.dispose();
                     }
                 });
                 f2.setVisible(true);
             }
         });

         f.add(button);
         f.addWindowListener(new WindowAdapter() {
             @Override
             public void windowClosing(WindowEvent e) {
                 f.dispose();
             }
         });


         f.setVisible(true);


     }

}