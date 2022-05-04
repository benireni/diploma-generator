import java.util.Calendar;
import java.util.Random;

public class RandomNumberGenerator {

    private final Random random = new Random();

    public RandomNumberGenerator() { this.random.setSeed(Calendar.getInstance().getTimeInMillis()); }
    public RandomNumberGenerator(long seed) { this.random.setSeed(seed); }

    public Integer getRandInt(Integer max) {
        return this.random.nextInt(max);
    }

    public Double getRand() {
        return this.random.nextDouble();
    }

    public void setSeed(long seed) {
        this.random.setSeed(seed);
    }
}
