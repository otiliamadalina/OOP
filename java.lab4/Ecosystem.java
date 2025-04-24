import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class Ecosystem {
    private List<EcosystemEntity> entities = new ArrayList<>();
    private final int gridSize = 10;
    private final Random random = new Random();
    private final double randomEventProbability = 0.2;
    private EcosystemReport report = new EcosystemReport();

    public Ecosystem(int nrOfPlants, int nrOfHerbivores, int nrOfOmnivores, int nrOfCarnivores) {
        for (int i = 0; i < nrOfPlants; i++) {
            int x = random.nextInt(gridSize);
            int y = random.nextInt(gridSize);
            Plant newPlant = new Plant("Plant", 50, x, y, 1);
            addEntity(newPlant);
        }
        for (int i = 0; i < nrOfHerbivores; i++) {
            int x = random.nextInt(gridSize);
            int y = random.nextInt(gridSize);
            Herbivore newHerbivore = new Herbivore("Herbivore", 80, x, y, 0.6, 2, 1);
            addEntity(newHerbivore);
        }
        for (int i = 0; i < nrOfOmnivores; i++) {
            int x = random.nextInt(gridSize);
            int y = random.nextInt(gridSize);
            Omnivore newOmnivore = new Omnivore("Omnivore", 100, x, y, 0.7, 2, 1);
            addEntity(newOmnivore);
        }
        for (int i = 0; i < nrOfCarnivores; i++) {
            int x = random.nextInt(gridSize);
            int y = random.nextInt(gridSize);
            Carnivore newCarnivore = new Carnivore("Carnivore", 120, x, y, 0.8, 3, 1);
            addEntity(newCarnivore);
        }
    }

    public EcosystemReport getReport() {
        return report;
    }

    public void addEntity(EcosystemEntity entity) {
        entities.add(entity);
        report.recordPopulation(entity.getClass().getSimpleName());
        report.recordInteraction(entity.getName() + " added in Ecosystem.");
    }

    public void removeEntity(EcosystemEntity entity) {
        entities.remove(entity);
        report.recordInteraction(entity.getName() + " deleted from Ecosystem.");
    }

    private int distance(int x1, int y1, int x2, int y2) {
        return Math.abs(x1 - x2) + Math.abs(y1 - y2);
    }

    public void simulateStep() {
        List<EcosystemEntity> currentEntities = new ArrayList<>(entities);

        for (EcosystemEntity entity : currentEntities) {
            if (entity.isAlive()) {
                entity.act(this);
            }
        }

        entities.removeIf(e -> !e.isAlive());

        if (random.nextDouble() < randomEventProbability) {
            triggerRandomEvent();
        }
    }

    public void triggerRandomEvent() {
        int eventType = random.nextInt(3);
        switch (eventType) {
            case 0 -> storm();
            case 1 -> drought();
            case 2 -> introduceNewSpecies();
        }
    }

    private void drought() {
        System.out.println("\n== Random Event: Drought! ==");
        for (EcosystemEntity entity : entities) {
            if (entity instanceof Plant) {
                entity.energy -= 30;
                if (!entity.isAlive()) {
                    System.out.println(entity.name + " died due to the drought.");
                }
            }
        }
    }

    private void storm() {
        System.out.println("\n~~~ Random Event: Storm! ~~~");
        for (EcosystemEntity entity : new ArrayList<>(entities)) {
            if (random.nextDouble() > entity.survivalRate) {
                System.out.println(entity.name + " was lost in the storm.");
                entities.remove(entity);
                report.recordInteraction(entity.name + " was lost in the storm.");
            }
        }
    }

    public void introduceNewSpecies() {
        System.out.println("\n~~~ Random Event: New Species Appeared! ~~~");
        int x = random.nextInt(gridSize);
        int y = random.nextInt(gridSize);

        int speciesType = random.nextInt(4);
        switch (speciesType) {
            case 0:
                Plant newPlant = new Plant("Plant", 50, x, y, 1);
                addEntity(newPlant);
                System.out.println("A new species of plant appeared at (" + x + ", " + y + ").");
                break;
            case 1:
                Herbivore newHerbivore = new Herbivore("Herbivore", 80, x, y, 0.6, 2, 1);
                addEntity(newHerbivore);
                System.out.println("A new species of herbivore appeared at (" + x + ", " + y + ").");
                break;
            case 2:
                Omnivore newOmnivore = new Omnivore("Omnivore", 100, x, y, 0.7, 2, 1);
                addEntity(newOmnivore);
                System.out.println("A new species of omnivore appeared at (" + x + ", " + y + ").");
                break;
            case 3:
                Carnivore newCarnivore = new Carnivore("Carnivore", 120, x, y, 0.8, 3, 1);
                addEntity(newCarnivore);
                System.out.println("A new species of carnivore appeared at (" + x + ", " + y + ").");
                break;
            default:
                break;
        }
    }

    public void generateFinalReport() {
        for (EcosystemEntity entity : entities) {
            String type = entity.getClass().getSimpleName();
            report.recordPopulation(type);
        }
        report.generateReport();
    }

    public Animal findNearestPrey(int x, int y) {
        return entities.stream()
                .filter(e -> (e instanceof Herbivore || e instanceof Omnivore))
                .map(e -> (Animal) e)
                .min((a1, a2) -> distance(x, y, a1.x, a1.y) - distance(x, y, a2.x, a2.y))
                .orElse(null);
    }

    public Plant findNearestPlant(int x, int y) {
        return entities.stream()
                .filter(e -> e instanceof Plant)
                .map(e -> (Plant) e)
                .min((p1, p2) -> distance(x, y, p1.x, p1.y) - distance(x, y, p2.x, p2.y))
                .orElse(null);
    }

    public void displayState() {
        System.out.println("\n~~~ Ecosystem State ~~~");
        for (EcosystemEntity entity : entities) {
            System.out.println(entity.name + " at (" + entity.x + ", " + entity.y + ") with energy: " + entity.energy);
        }
    }

    public void displayMatrix() {
        char[][] grid = new char[gridSize][gridSize];
        System.out.println("\n~~~ Ecosystem Matrix ~~~");

        for (int i = 0; i < gridSize; i++) {
            for (int j = 0; j < gridSize; j++) {
                grid[i][j] = '.';
            }
        }

        for (EcosystemEntity entity : entities) {
            if (entity.x >= 0 && entity.x < gridSize && entity.y >= 0 && entity.y < gridSize) {
                char symbol = entity instanceof Plant ? 'P' :
                        entity instanceof Herbivore ? 'H' :
                                entity instanceof Carnivore ? 'C' : 'O';
                grid[entity.x][entity.y] = symbol;
            }
        }

        for (int i = 0; i < gridSize; i++) {
            for (int j = 0; j < gridSize; j++) {
                System.out.print(grid[i][j] + " ");
            }
            System.out.println();
        }
    }
}