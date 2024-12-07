abstract class EcosystemEntity {
    protected String name;
    protected int energy;
    protected int x, y;
    protected double survivalRate;
    protected int generation;

    public EcosystemEntity(String name, int energy, int x, int y, double survivalRate) {
        this.name = name;
        this.energy = energy;
        this.x = x;
        this.y = y;
        this.survivalRate = survivalRate;
        this.generation = 0;
    }

    public String getName() {
        return name;
    }

    public boolean isAlive() {
        return energy > 0;
    }

    public abstract void act(Ecosystem ecosystem);
}