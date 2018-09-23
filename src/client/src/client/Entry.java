package client;

import java.util.*;
import javax.swing.*;

//main entry point for the client program

public class Entry {
	
	private static Map<String[], Action[]> generateMenuBar() {
		
		Map<String[], Action[]> MenuBar = new LinkedHashMap<>();
		
		//A semi-simple means of setting up a menu bar as such with the first index being the root
		//0
		//-1
		//-...
		
		MenuBar.put(new String[] { "File", "Save" , "Load"},
				new Action[] {
						null, null, null
				} );
		
		MenuBar.put(new String[] {"Edit"}, new Action[] {null});
		
		MenuBar.put(new String[] {"Tools", "Upload"}  , new Action [] {null, null});
		
		return MenuBar;
	}
	
	
	
	public static void main(String[] args) {
		javax.swing.SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				
				UserInterface theUI = new UserInterface("FBD-Arm Client", generateMenuBar());
			}
		});
	}

}
