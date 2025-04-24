import java.util.Random;

public class Herbivore extends Animal implements Interaction {
    private int generation;

    public Herbivore(String name, int energy, int x, int y, double survivalRate, int speed, int generation) {
        super(name, energy, x, y, survivalRate, speed, "Herbivore");
        this.generation = generation;
    }

    @Override
    public void eat(Ecosystem ecosystem) {
        Plant plant = ecosystem.findNearestPlant(x, y);
        if (plant != null && isNear(plant)) {
            System.out.println(name + " at (" + x + ", " + y + ") eats " + plant.name + "!");
            ecosystem.getReport().recordInteraction(name + " ate " + plant.name + " at (" + x + ", " + y + ").");
            energy += plant.energy;
            ecosystem.removeEntity(plant);
        }
    }

    @Override
    public void act(Ecosystem ecosystem) {
        move();
        System.out.println(name + " at (" + x + ", " + y + ") is acting... Moving to (" + x + ", " + y + ").");
        eat(ecosystem);
        reproduce(ecosystem);
    }

    private boolean isNear(EcosystemEntity entity) {
        return Math.abs(entity.x - x) <= 1 && Math.abs(entity.y - y) <= 1;
    }

    @Override
    public void attack(Animal prey) {}

    @Override
    public void reproduce(Ecosystem ecosystem) {
        if (energy > 100) {
            int newX = Math.max(0, Math.min(9, x + (new Random().nextInt(3) - 1)));
            int newY = Math.max(0, Math.min(9, y + (new Random().nextInt(3) - 1)));

            String newHerbivoreName = "Herbivore " + (generation + 1);

            ecosystem.addEntity(new Herbivore(newHerbivoreName, 50, newX, newY, survivalRate, speed, generation + 1));
            energy -= 50;
            System.out.println(newHerbivoreName + " has been added to the ecosystem at coordinates (" + newX + ", " + newY + ").");
        }
    }
}
