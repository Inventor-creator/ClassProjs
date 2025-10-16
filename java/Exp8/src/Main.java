import java.awt.*;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.sql.*;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.sql.*;

public class Main extends JFrame implements ActionListener {


    JTextField nameField, emailField, ageField;
    JButton submitButton, clearButton;


    Connection conn;
    PreparedStatement stmt;

    public Main() {
        setTitle("User Registration Form");
        setSize(400, 300);
        setLayout(new GridLayout(5, 2, 10, 10));
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);


        JLabel nameLabel = new JLabel("Name:");
        JLabel emailLabel = new JLabel("Email:");
        JLabel ageLabel = new JLabel("Age:");


        nameField = new JTextField();
        emailField = new JTextField();
        ageField = new JTextField();


        submitButton = new JButton("Submit");
        clearButton = new JButton("Clear");

        submitButton.addActionListener(this);
        clearButton.addActionListener(this);


        add(nameLabel);
        add(nameField);
        add(emailLabel);
        add(emailField);
        add(ageLabel);
        add(ageField);
        add(submitButton);
        add(clearButton);


        connectDB();

        setVisible(true);
    }

    void connectDB() {
        try {




            this.conn = DriverManager.getConnection("jdbc:postgresql://localhost:5432/javaExp", "postgres", "postgres");
            System.out.println("Database connected successfully!");
        } catch (Exception e) {
            JOptionPane.showMessageDialog(this, "Database Connection Failed: " + e.getMessage());
        }
    }

    public void actionPerformed(ActionEvent ae) {
        if (ae.getSource() == submitButton) {
            try {
                String name = nameField.getText();
                String email = emailField.getText();
                int age = Integer.parseInt(ageField.getText());

                stmt = conn.prepareStatement("INSERT INTO users (name, email, age) VALUES (?, ?, ?)");
                stmt.setString(1, name);
                stmt.setString(2, email);
                stmt.setInt(3, age);

                int rows = stmt.executeUpdate();
                if (rows > 0) {
                    JOptionPane.showMessageDialog(this, "Data Inserted Successfully!");
                    nameField.setText("");
                    emailField.setText("");
                    ageField.setText("");
                }

            } catch (Exception e) {
                JOptionPane.showMessageDialog(this, "Error: " + e.getMessage());
            }
        } else if (ae.getSource() == clearButton) {
            nameField.setText("");
            emailField.setText("");
            ageField.setText("");
        }
    }

    public static void main(String[] args) {
        new Main();
    }
}
