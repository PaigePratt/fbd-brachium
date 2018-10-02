import util.MotorMessage;

import javax.swing.*;
import javax.swing.border.Border;
import java.awt.*;
import java.lang.reflect.Type;

public class Main {
	//main entry point for the program

	//serial stuff
	static int BaudRate;

	//command definition
	static MotorMessage motorCommands[];

	private static void setMotorCommands() {
		motorCommands = new MotorMessage[] {
				null, //there better not be a call to position one
				new MotorMessage(1 , new int[] {1 ,1}, "Motor articulation Request\n\tMotor: %d\tValue: %d")
		};
	}

	//swing shit
	static JFrame frame;
	static int width = 800, height = 600;
	static String title = "SerialCommTest";
	static JMenuBar menuBar;
	static JMenu menu;
	static JMenuItem menuItem;

	static JTextArea textArea;
	static JPanel panel;


	private static void createGUI() {
		frame = new JFrame(title);

		//The menu bar
		menuBar = new JMenuBar();

		menu = new JMenu("File");
		menuBar.add(menu);

		menuItem = new JMenuItem("Save");

		menu.add(menuItem);

		menuItem = new JMenuItem("Load");
		menu.add(menuItem);

		menu = new JMenu("Edit");
		menuBar.add(menu);

		menuItem = new JMenuItem("Preferences");
		menu.add(menuItem);

		textArea = new JTextArea();
		//textArea.setSize(width / 2, height);

		textArea.setLineWrap(true);
		textArea.setEditable(false);
		textArea.setVisible(true);

		panel = new JPanel();
		panel.setSize(400,400);
		panel.setAlignmentY(JPanel.RIGHT_ALIGNMENT);
		panel.add(textArea);

		frame.add(panel);

		//configuring the frame
		frame.setJMenuBar(menuBar);

		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setSize(new Dimension(width, height));
		frame.setVisible(true);
	}

	public static void main(String[] args) {

		setMotorCommands();

		javax.swing.SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				createGUI();
			}
		});
	}
}
