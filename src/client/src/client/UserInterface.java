package client;

import javax.swing.*;

import java.util.Map;
import java.util.Map.Entry;
//import java.awt.event.KeyEvent;
import java.util.Iterator;

public class UserInterface {
	
	JFrame frame;
	JMenu menu, subMenu;
	JMenuItem menuItem;
	JMenuBar menuBar;
	
	private void createGUI(String title) {
		//frame setup
		frame = new JFrame(title);
		
	}
	
	private void setupBar(Map<String[], Action[]> menuFuncs) {
		menuBar = new JMenuBar();
		
		Iterator<Entry<String[], Action[]>> it = menuFuncs.entrySet().iterator();
		
		while(it.hasNext()) {
			Map.Entry<String[], Action[]> menuItemConfig = (Map.Entry<String[], Action[]>)it.next();
			
			String names[] = menuItemConfig.getKey();
			
			Action cmds[] = menuItemConfig.getValue();
			
			menu = new JMenu(names[0]);
			
			for(int i = 1; i < names.length; i++) {
				menuItem = new JMenuItem(names[i]);
				
				if(cmds[i] != null) {
					menuItem.setAction(cmds[i]);
				}
				
				menu.add(menuItem);
			}
			
			menuBar.add(menu);
			
		}
		
		it.remove();
		
		frame.setJMenuBar(menuBar);
	}
	
	public UserInterface(String title, Map<String[], Action[]> menuFuncs) {
		createGUI(title);
		setupBar(menuFuncs);
		frame.pack();
		frame.setVisible(true);
	}
}
