package util;

import java.lang.reflect.Type;

public class MotorMessage {
	private static byte address;
	private static int[] argumentSizes;
	private String callBackStringFormat;

	public MotorMessage(int addr, int[] valfmt, String cbs) {
		address = (byte) addr;
		argumentSizes = valfmt;
		callBackString = cbs;
	}

	public byte getAddress() {
		return address;
	}

	public int[] getValueFormats() {
		return argumentSizes;
	}

	public int getValueCount() {
		return argumentSizes.length;
	}

	public String getCallBackString() {
		return callBackString;
	}
}
