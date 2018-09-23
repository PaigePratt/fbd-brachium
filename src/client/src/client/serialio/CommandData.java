package client.serialio;

//class definition for CommandData

public class CommandData {
	private byte controlCode;
	private int argCount;
	
	public CommandData(byte CC, int ac) {
		controlCode = CC;
		argCount = ac;
	}
	
	public void SendControlData(CommandData data) {
		//TODO add serial communications 
	}
}
