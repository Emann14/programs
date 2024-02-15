package Module_8_Critical_Thinking;
import java.lang.InterruptedException;
import java.io.File;

public class CounterApplication {
    private static volatile boolean isCountingUp = true;

    public static void main(String[] args) {
        Thread counterUpThread = new Thread(() -> {
            for (int i = 1; i <= 20; i++) {
                System.out.println("Counting up: " + i);
                if (i == 20) {
                    isCountingUp = false;
                }
                try {
                    Thread.sleep(500); // Simulate some work
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        });

        Thread counterDownThread = new Thread(() -> {
            while (isCountingUp) {
                // Wait until the counting up thread finishes
            }
            for (int i = 20; i >= 0; i--) {
                System.out.println("Counting down: " + i);
                try {
                    Thread.sleep(500); // Simulate some work
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        });

        counterUpThread.start();
        counterDownThread.start();
    }
}
