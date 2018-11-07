import java.util.AbstractMap;
import java.util.Map;
import java.util.Queue;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.ConcurrentLinkedQueue;

public class Robot {
    private static Robot robot = new Robot();

    public static Robot getInstance() {
        return robot;
    }

    public static Queue<AbstractMap.SimpleEntry<MotorsEnum, Double>> motorQueue = new ConcurrentLinkedQueue<>();
    public static Map<SensorsEnum, Integer> sensorMap = new ConcurrentHashMap<>();

    private Robot() {
    }
}
