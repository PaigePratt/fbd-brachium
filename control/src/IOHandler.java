public class IOHandler extends Thread {
    private static IOHandler ourInstance = new IOHandler();

    public static synchronized IOHandler getInstance() {
        return ourInstance;
    }

    private IOHandler() {
    }

    public void run() {
    }
}
