import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 * A simple Swing GUI application that creates a registration form.
 */
public class Main extends JFrame {

    // Declare all the Swing components
    private final JTextField nameField;
    private final JTextField idField;
    private final JTextField salaryField;
    private final JTextField ageField;
    private final JButton submitButton;

    public Main() {
        // --- 1. Setup the Frame (the main window) ---
        setTitle("User Registration Form");
        setSize(400, 250); // Set window width and height
        setLocationRelativeTo(null); // Center the window on the screen
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // Close program on window exit

        // --- 2. Create a Panel and Set a Layout Manager ---
        // A JPanel acts as a container for other components.
        // GridLayout arranges components in a grid of rows and columns.
        JPanel panel = new JPanel(new GridLayout(5, 2, 10, 10));
        // Add some padding around the panel
        panel.setBorder(BorderFactory.createEmptyBorder(15, 15, 15, 15));

        // --- 3. Initialize and Add Components to the Panel ---
        // For each input, we add a JLabel (static text) and a JTextField (input box).

        // Name
        panel.add(new JLabel("Name:"));
        nameField = new JTextField(20); // 20 is the preferred column width
        panel.add(nameField);

        // ID
        panel.add(new JLabel("ID:"));
        idField = new JTextField(20);
        panel.add(idField);

        // Salary
        panel.add(new JLabel("Salary:"));
        salaryField = new JTextField(20);
        panel.add(salaryField);

        // Age
        panel.add(new JLabel("Age:"));
        ageField = new JTextField(20);
        panel.add(ageField);

        // Submit Button
        submitButton = new JButton("Submit");
        panel.add(new JLabel()); // An empty label for grid spacing
        panel.add(submitButton);

        // --- 4. Add the Panel to the Frame ---
        this.add(panel);

        // --- 5. Add an Action Listener for the Button Click ---
        submitButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                // This code runs when the button is clicked
                displayInput();
            }
        });
    }

    /**
     * Retrieves text from input fields and displays it in a dialog box.
     */
    private void displayInput() {
        // Get the text from each input field
        String name = nameField.getText();
        String id = idField.getText();
        String salary = salaryField.getText();
        String age = ageField.getText();

        // Simple validation to ensure fields are not empty
        if (name.isEmpty() || id.isEmpty() || salary.isEmpty() || age.isEmpty()) {
            JOptionPane.showMessageDialog(this,
                    "Please fill in all fields.",
                    "Input Error",
                    JOptionPane.WARNING_MESSAGE);
            return; // Stop the method if any field is empty
        }

        // Build the message string for display
        String message = "Registration Successful!\n" +
                "--------------------------\n" +
                "Name: " + name + "\n" +
                "ID: " + id + "\n" +
                "Salary: $" + salary + "\n" +
                "Age: " + age;

        // Display the collected information in a pop-up dialog
        JOptionPane.showMessageDialog(this,
                message,
                "Registration Details",
                JOptionPane.INFORMATION_MESSAGE);
    }


    /**
     * The main method to run the application.
     */
    public static void main(String[] args) {
        // It's best practice to create and show the GUI on the Event Dispatch Thread (EDT)
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                // Create an instance of the form and make it visible
                new Main().setVisible(true);
            }
        });
    }
}