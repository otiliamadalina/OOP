import java.util.Scanner;

public class EcosystemSimulation {
    public static void main(String[] args) {
        Ecosystem ecosystem = new Ecosystem(5, 5, 3, 2);
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.println("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
            System.out.println("    ECOSYSTEM SIMULATION        ");
            System.out.println("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
            System.out.println("(1) Add a Plant |");
            System.out.println("(2) Add a Herbivore |");
            System.out.println("(3) Add a Carnivore |");
            System.out.println("(4) Add an Omnivore |");
            System.out.println("(5) Simulate a Step |");
            System.out.println("(6) Display Ecosystem |");
            System.out.println("(7) Final Report |");
            System.out.println("(8) Extended Simulation |");
            System.out.println("(0) EXIT |");
            System.out.println("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
            System.out.print("Choose an option: ");

            int choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    addPlant(scanner, ecosystem);
                    break;
                case 2:
                    addHerbivore(scanner, ecosystem);
                    break;
                case 3:
                    addCarnivore(scanner, ecosystem);
                    break;
                case 4:
                    addOmnivore(scanner, ecosystem);
                    break;
                case 5:
                    ecosystem.simulateStep();
                    System.out.println("Simulation advanced by one step.");
                    break;
                case 6:
                    ecosystem.displayState();
                    break;
                case 7:
                    ecosystem.generateFinalReport();
                    System.out.println("Final report successfully generated.");
                    break;
                case 8:
                    runExtendedSimulation(scanner, ecosystem);
                    break;
                case 0:
                    System.out.println("The simulation program has been closed.");
                    scanner.close();
                    return;
                default:
                    System.out.println("Invalid option. Please enter a valid number");
            }
        }
    }

    private static void addPlant(Scanner scanner, Ecosystem ecosystem) {
        System.out.print("Enter the plant's name: ");
        String plantName = scanner.next();
        System.out.print("Enter the plant's energy: ");
        int plantEnergy = scanner.nextInt();
        System.out.print("Enter the plant's coordinates (x y): ");
        int plantX = scanner.nextInt();
        int plantY = scanner.nextInt();

        int generation = 1;
        ecosystem.addEntity(new Plant(plantName, plantEnergy, plantX, plantY, 1));
        System.out.println("Plant added: " + plantName);
    }

    private static void addHerbivore(Scanner scanner, Ecosystem ecosystem) {
        System.out.print("Enter the herbivore's name: ");
        String herbivoreName = scanner.next();
        System.out.print("Enter the herbivore's energy: ");
        int herbivoreEnergy = scanner.nextInt();
        System.out.print("Enter the herbivore's coordinates (x y): ");
        int herbivoreX = scanner.nextInt();
        int herbivoreY = scanner.nextInt();
        System.out.print("Enter the herbivore's speed: ");
        int herbivoreSpeed = scanner.nextInt();
        ecosystem.addEntity(new Herbivore(herbivoreName, herbivoreEnergy, herbivoreX, herbivoreY, 0.8, herbivoreSpeed, 1));
        System.out.println("Herbivore added: " + herbivoreName);
    }

    private static void addCarnivore(Scanner scanner, Ecosystem ecosystem) {
        System.out.print("Enter the carnivore's name: ");
        String carnivoreName = scanner.next();
        System.out.print("Enter the carnivore's energy: ");
        int carnivoreEnergy = scanner.nextInt();
        System.out.print("Enter the carnivore's coordinates (x y): ");
        int carnivoreX = scanner.nextInt();
        int carnivoreY = scanner.nextInt();
        System.out.print("Enter the carnivore's speed: ");
        int carnivoreSpeed = scanner.nextInt();
        ecosystem.addEntity(new Carnivore(carnivoreName, carnivoreEnergy, carnivoreX, carnivoreY, 0.6, carnivoreSpeed, 1));
        System.out.println("Carnivore added: " + carnivoreName);
    }

    private static void addOmnivore(Scanner scanner, Ecosystem ecosystem) {
        System.out.print("Enter the omnivore's name: ");
        String omnivoreName = scanner.next();
        System.out.print("Enter the omnivore's energy: ");
        int omnivoreEnergy = scanner.nextInt();
        System.out.print("Enter the omnivore's coordinates (x y): ");
        int omnivoreX = scanner.nextInt();
        int omnivoreY = scanner.nextInt();
        System.out.print("Enter the omnivore's speed: ");
        int omnivoreSpeed = scanner.nextInt();

        ecosystem.addEntity(new Omnivore(omnivoreName, omnivoreEnergy, omnivoreX, omnivoreY, 0.7, omnivoreSpeed, 1));

        System.out.println("Omnivore added: " + omnivoreName);
    }

    private static void runExtendedSimulation(Scanner scanner, Ecosystem ecosystem) {
        System.out.print("Enter the number of steps for the extended simulation: ");
        int steps = scanner.nextInt();
        ExtendedSimulation extendedSimulation = new ExtendedSimulation(ecosystem);
        extendedSimulation.run(steps);
        System.out.println("Extended simulation completed for " + steps + " steps.");
    }
}
