import java.util.HashMap;
import java.util.Map;

public class EcosystemReport {
    private Map<String, Long> populationCounts = new HashMap<>();
    private StringBuilder interactions = new StringBuilder();

    public void recordPopulation(String entityType) {
        populationCounts.put(entityType, populationCounts.getOrDefault(entityType, 0L) + 1);
    }

    public void recordInteraction(String interaction) {
        interactions.append(interaction).append("\n");
    }

    public void generateReport() {
        System.out.println("\n~~~ Final Ecosystem Report ~~~");
        for (Map.Entry<String, Long> entry : populationCounts.entrySet()) {
            System.out.println(entry.getKey() + " population: " + entry.getValue());
        }
        System.out.println("\n~~~ Observed Interactions ~~~");
        System.out.println(interactions.toString());
    }
}
