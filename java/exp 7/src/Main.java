import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Main extends JFrame {

    private JTextField nameField;
    private JTextField emailField;
    private JTextField countryField;
    private JPasswordField passwordField;
    private JTextArea addressArea;
    private JRadioButton maleRadio;
    private JRadioButton femaleRadio;
    private JSlider ageSlider;
    private JButton submitButton;
    private JButton clearButton;

    public Main() {

        setTitle("Registration Form");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(500, 500);
        setLocationRelativeTo(null);

        // Create main panel with padding
        JPanel mainPanel = new JPanel();
        mainPanel.setLayout(new BoxLayout(mainPanel, BoxLayout.Y_AXIS));
        mainPanel.setBorder(BorderFactory.createEmptyBorder(20, 20, 20, 20));

        // Create form panel with grid layout
        JPanel formPanel = new JPanel(new GridLayout(0, 2, 10, 10));

        // Add form components
        addFormComponents(formPanel);

        // Create button panel
        JPanel buttonPanel = new JPanel();
        buttonPanel.setLayout(new FlowLayout(FlowLayout.CENTER, 20, 10));

        // Create and add buttons
        submitButton = new JButton("Submit");
        submitButton.setBackground(new Color(70, 130, 180));
        submitButton.setForeground(Color.WHITE);
        submitButton.setFocusPainted(false);
        submitButton.addActionListener(new SubmitButtonListener());

        clearButton = new JButton("Clear");
        clearButton.setBackground(new Color(220, 20, 60));
        clearButton.setForeground(Color.WHITE);
        clearButton.setFocusPainted(false);
        clearButton.addActionListener(new ClearButtonListener());

        buttonPanel.add(submitButton);
        buttonPanel.add(clearButton);

        // Add panels to main panel
        mainPanel.add(new JLabel("Registration Form", JLabel.CENTER));
        mainPanel.add(Box.createRigidArea(new Dimension(0, 15)));
        mainPanel.add(formPanel);
        mainPanel.add(Box.createRigidArea(new Dimension(0, 15)));
        mainPanel.add(buttonPanel);

        // Add main panel to frame
        add(mainPanel);

        setVisible(true);
    }

    private void addFormComponents(JPanel panel) {
        // Name field
        panel.add(new JLabel("Full Name:"));
        nameField = new JTextField();
        panel.add(nameField);

        // Email field
        panel.add(new JLabel("Email:"));
        emailField = new JTextField();
        panel.add(emailField);

        // Password field
        panel.add(new JLabel("Password:"));
        passwordField = new JPasswordField();
        panel.add(passwordField);

        // Country field
        panel.add(new JLabel("Country:"));
        countryField = new JTextField();
        panel.add(countryField);

        // Gender radio buttons
        panel.add(new JLabel("Gender:"));
        JPanel genderPanel = new JPanel(new FlowLayout(FlowLayout.LEFT));
        maleRadio = new JRadioButton("Male", true);
        femaleRadio = new JRadioButton("Female");
        ButtonGroup genderGroup = new ButtonGroup();
        genderGroup.add(maleRadio);
        genderGroup.add(femaleRadio);
        genderPanel.add(maleRadio);
        genderPanel.add(femaleRadio);
        panel.add(genderPanel);

        // Age slider
        panel.add(new JLabel("Age:"));
        JPanel agePanel = new JPanel(new BorderLayout());
        ageSlider = new JSlider(13, 100, 25);
        ageSlider.setMajorTickSpacing(10);
        ageSlider.setMinorTickSpacing(5);
        ageSlider.setPaintTicks(true);
        ageSlider.setPaintLabels(true);
        agePanel.add(ageSlider, BorderLayout.CENTER);
        panel.add(agePanel);

        // Address area
        panel.add(new JLabel("Address:"));
        addressArea = new JTextArea(3, 20);
        addressArea.setLineWrap(true);
        panel.add(new JScrollPane(addressArea));
    }

    private class SubmitButtonListener implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            // Collect data from form
            StringBuilder data = new StringBuilder();
            data.append("=== REGISTRATION DETAILS ===\n\n");

            // Name
            data.append("Name: ").append(nameField.getText()).append("\n");

            // Email
            data.append("Email: ").append(emailField.getText()).append("\n");

            // Password
            data.append("Password: ").append(new String(passwordField.getPassword())).append("\n");

            // Country
            data.append("Country: ").append(countryField.getText()).append("\n");

            // Gender
            String gender = maleRadio.isSelected() ? "Male" : "Female";
            data.append("Gender: ").append(gender).append("\n");

            // Age
            data.append("Age: ").append(ageSlider.getValue()).append("\n");

            // Address
            data.append("Address: ").append(addressArea.getText()).append("\n");

            // Display the collected data
            JTextArea displayArea = new JTextArea(data.toString(), 15, 40);
            displayArea.setEditable(false);
            displayArea.setCaretPosition(0);

            JScrollPane scrollPane = new JScrollPane(displayArea);

            JOptionPane.showMessageDialog(Main.this, scrollPane, "Registration Details", JOptionPane.INFORMATION_MESSAGE);

        }
    }

    private class ClearButtonListener implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            // Clear all fields
            nameField.setText("");
            emailField.setText("");
            passwordField.setText("");
            countryField.setText("");
            maleRadio.setSelected(true);
            ageSlider.setValue(25);
            addressArea.setText("");
        }
    }

    public static void main(String[] args) {
        // Set look and feel to system default for better appearance
        try {
            UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
        } catch (Exception e) {
            e.printStackTrace();
        }

        // Create the GUI on the Event Dispatch Thread
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new Main();

            }
        });
    }
}