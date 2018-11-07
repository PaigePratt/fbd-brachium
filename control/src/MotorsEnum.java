import java.util.AbstractMap;

public enum MotorsEnum {
    TURNTABLE (0),
    SHOULDER (1),
    FOREARM (2);

    private int port;

    MotorsEnum(int port) {
        this.port = port;
    }

    public int getPort() {
        return port;
    }

    public void setVoltage(double voltage) {
        Robot.motorQueue.add(new AbstractMap.SimpleEntry<>(this, voltage));
    }
}
