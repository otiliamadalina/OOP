import java.util.Random;

abstract class Animal extends EcosystemEntity {
    protected int speed;
    protected String foodType;

    public Animal(String name, int energy, int x, int y, double survivalRate, int speed, String foodType) {
        super(name, energy, x, y, survivalRate);
        this.speed = speed;
        this.foodType = foodType;
    }

    public abstract void eat(Ecosystem ecosystem);

    public void move() {
        Random rand = new Random();
        int newX = Math.max(0, Math.min(9, x + rand.nextInt(2 * speed + 1) - speed));
        int newY = Math.max(0, Math.min(9, y + rand.nextInt(2 * speed + 1) - speed));
        x = newX;
        y = newY;
    }

    public int getEnergy() {
        return energy;
    }
}