public class IOHandler extends Thread {
    private static IOHandler ourInstance = new IOHandler();

    public static IOHandler getInstance() {
        return ourInstance;
    }

    private IOHandler() {
    }

    public void run() {
    }
}
