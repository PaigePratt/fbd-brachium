package client;

import java.util.*;
import javax.swing.*;

//main entry point for the client program

public class Entry {
	
	private static void SaveFile() {
		//TODO file save
		System.out.print("File save called\n");
	}
	
	private static void LoadFile() {
		//TODO file load
		System.out.print("File Load Called\n");
	}
	
	public static void main(String[] args) {
		javax.swing.SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				
				Map<String[], Action[]> MenuBar = new HashMap<>();
				
				//A semi-simple means of setting up a menu bar as such with the first index being the root
				//0
				//-1
				//-...
				
				
				MenuBar.put(new String[] { "File", "Save" , "Load"},
						new Action[] {
								null, null, null
						} );
				
				MenuBar.put(new String[] {"Edit"}, new Action[] {null});
				
				
				UserInterface theUI = new UserInterface("FBD-Arm Client", MenuBar);
			}
		});
	}

}
