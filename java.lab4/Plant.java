import java.util.Random;

public class Plant extends EcosystemEntity implements Interaction {
    private int generation;

    public Plant(String name, int energy, int x, int y, int generation) {
        super(name, energy, x, y, 1.0);
        this.generation = generation;
    }

    @Override
    public void act(Ecosystem ecosystem) {
        grow();
        System.out.println(name + " at (" + x + ", " + y + ") is growing, increasing energy by 10.");
        reproduce(ecosystem);
    }

    private void grow() {
        energy += 10;
    }

    @Override
    public void attack(Animal prey) {
    }

    @Override
    public void reproduce(Ecosystem ecosystem) {
        if (energy > 50) {
            int newX = Math.max(0, Math.min(9, x + (new Random().nextInt(3) - 1)));
            int newY = Math.max(0, Math.min(9, y + (new Random().nextInt(3) - 1)));

            String newPlantName = "Plant " + (generation + 1);
            ecosystem.addEntity(new Plant(newPlantName, 20, newX, newY, generation + 1));
            energy -= 20;
            System.out.println(newPlantName + " has been added to the ecosystem at coordinates (" + newX + ", " + newY + ").");
        }
    }
}
