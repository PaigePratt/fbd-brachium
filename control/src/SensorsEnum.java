public enum SensorsEnum {
    TURNTABLE (0),
    SHOULDER (1),
    FOREARM (2);

    private int port;

    SensorsEnum(int port) {
        this.port = port;
    }

    public int getPort() {
        return port;
    }

    public int getTicks() {
        return Robot.sensorMap.get(this);
    }
}
