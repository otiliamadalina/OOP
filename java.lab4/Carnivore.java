import java.util.Random;

public class Carnivore extends Animal implements Interaction {
    private int generation;

    public Carnivore(String name, int energy, int x, int y, double survivalRate, int speed, int generation) {
        super(name, energy, x, y, survivalRate, speed, "Carnivore");
        this.generation = generation;
    }

    @Override
    public void act(Ecosystem ecosystem) {
        move();
        System.out.println(name + " at (" + x + ", " + y + ") is acting... Moving to (" + x + ", " + y + ").");
        eat(ecosystem);
        reproduce(ecosystem);
    }

    @Override
    public void eat(Ecosystem ecosystem) {
        Animal prey = ecosystem.findNearestPrey(x, y);
        if (prey != null && isNear(prey)) {
            System.out.println(name + " at (" + x + ", " + y + ") is eating " + prey.getName() + "!");
            ecosystem.getReport().recordInteraction(name + " ate " + prey.getName() + " at (" + x + ", " + y + ").");
            energy += prey.getEnergy();
            ecosystem.removeEntity(prey);
        }
    }

    private boolean isNear(EcosystemEntity entity) {
        return Math.abs(entity.x - x) <= 1 && Math.abs(entity.y - y) <= 1;
    }

    @Override
    public void attack(Animal prey) {
        System.out.println(name + " is attacking prey " + prey.getName() + "!");
        energy += prey.getEnergy();
    }

    @Override
    public void reproduce(Ecosystem ecosystem) {
        if (energy >= 75) {
            int newX = Math.max(0, Math.min(9, x + (new Random().nextInt(3) - 1)));
            int newY = Math.max(0, Math.min(9, y + (new Random().nextInt(3) - 1)));

            String newCarnivoreName = "Carnivore " + (generation + 1);

            ecosystem.addEntity(new Carnivore(newCarnivoreName, 75, newX, newY, survivalRate, speed, generation + 1));
            energy -= 75;
            System.out.println(name + " has created a new carnivore: " + newCarnivoreName);
        }
    }
}
