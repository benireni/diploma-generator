public class Dice {

    private Integer value;
    private final Integer sides;

    private final RandomNumberGenerator randomNumberGenerator = new RandomNumberGenerator();

    public Dice() { this.sides = 6; }
    public Dice(int sides) { this.sides = sides; }

    public Integer getLastValue() { return this.value; }

    public Integer roll() {
        this.value = this.randomNumberGenerator.getRandInt(this.sides) + 1;
        return this.value;
    }

    @Override
    public String toString() {
        if(this.sides != 6) return this.sides.toString();

        // Delimiter
        String formattedOutput = "+-----+\n";

        // First line
        if(this.value >= 4) formattedOutput += "|*   *|\n";
        else if(this.value >= 2) formattedOutput += "|*    |\n";
        else formattedOutput += "|     |\n";

        // Second line
        if(this.value == 6) formattedOutput += "|*   *|\n";
        else if(this.value % 2 == 1) formattedOutput += "|  *  |\n";
        else formattedOutput += "|     |\n";

        // Third line
        if(this.value >= 4) formattedOutput += "|*   *|\n";
        else if(this.value >= 2) formattedOutput += "|    *|\n";
        else formattedOutput += "|     |\n";

        // Delimiter
        formattedOutput += "+-----+";

        return formattedOutput;
    }
}
