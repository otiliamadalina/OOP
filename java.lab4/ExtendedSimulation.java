import java.util.Random;
import java.util.Scanner;

public class ExtendedSimulation {
    private Ecosystem ecosystem;
    private Random random;
    private int randomEventProbability;
    private int newSpeciesProbability;
    private Scanner scanner;

    public ExtendedSimulation(Ecosystem ecosystem) {
        this.ecosystem = ecosystem;
        this.random = new Random();
        this.randomEventProbability = 10;
        this.newSpeciesProbability = 20;
        this.scanner = new Scanner(System.in);
    }

    public void run(int steps) {
        for (int i = 0; i < steps; i++) {
            System.out.println("\n~~~ Simulation Step " + (i + 1) + " ~~~");
            ecosystem.simulateStep();

            if (random.nextInt(100) < randomEventProbability) {
                ecosystem.triggerRandomEvent();
            }

            if (random.nextInt(100) < newSpeciesProbability) {
                ecosystem.introduceNewSpecies();
            }

            ecosystem.displayMatrix();

            System.out.println("\nPress Enter to proceed to the next step.");
            scanner.nextLine();
        }
        ecosystem.generateFinalReport();
    }
}
