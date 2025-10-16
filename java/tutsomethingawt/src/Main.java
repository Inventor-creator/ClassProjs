import java.awt.*;
import java.awt.event.*;

public class Main extends Frame implements ActionListener {
    Label nameLabel, rollLabel, deptLabel, resultLabel;
    TextField nameField, rollField, deptField;
    Button submitButton;

    public Main() {

        setTitle("Student Information Form");


        nameLabel = new Label("Name:");
        rollLabel = new Label("Roll Number:");
        deptLabel = new Label("Department:");
        resultLabel = new Label("");


        nameField = new TextField();
        rollField = new TextField();
        deptField = new TextField();


        submitButton = new Button("Submit");
        submitButton.addActionListener(this);


        setLayout(new GridLayout(5, 2, 10, 10));
        add(nameLabel);     add(nameField);
        add(rollLabel);     add(rollField);
        add(deptLabel);     add(deptField);
        add(submitButton);  add(resultLabel);

        setSize(350, 250);
        setVisible(true);


        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent we) {
                dispose();
            }
        });
    }

    public void actionPerformed(ActionEvent e) {

        String name = nameField.getText();
        String roll = rollField.getText();
        String dept = deptField.getText();
        String info = "Name: " + name + ", Roll: " + roll + ", Dept: " + dept;
        resultLabel.setText(info);







    }

    public static void main(String args[]) {
        new Main();

    }
}
