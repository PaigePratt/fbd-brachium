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

    private Queue<AbstractMap.SimpleEntry<String, Double>> motorQueue = new ConcurrentLinkedQueue<>();
    private Map<String, Double> sensorMap = new ConcurrentHashMap<>();

    private Robot() {

    }
}
