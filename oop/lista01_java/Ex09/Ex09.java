package Lista01.Ex09;

import Lista01.KeyboardInput;

public class Ex09 {
    static final Double ERROR = 10e-7;
    private Integer iterator = 0;

    private Double calculateBaseEquation(Double x) {
        return Math.pow(x, 3) - Math.pow(x, 2) - 13*x + 8;
    }

    private Double deriveBaseEquation(Double x) {
        return 3 * Math.pow(x, 2) - 2 * x - 13;
    }

    public Integer getLastOperationTotalIterations() { return this.iterator; }

    public Double solveByNewtonRaphson(Double attempt) {
        Double previousAttempt;
        do {
            previousAttempt = attempt;
            attempt -= calculateBaseEquation(attempt) / deriveBaseEquation(attempt);
            this.iterator++;
        } while (previousAttempt - attempt >= ERROR);

        return attempt;
    }

    public static void main(String[] args) {
        Ex09 newtonRaphsonCalculator = new Ex09();
        KeyboardInput keyboardInput = new KeyboardInput(System.in);

        System.out.println("Provide the desired attempt: ");
        Double input = keyboardInput.readDouble();

        System.out.printf("Solution by Newton-Raphson: %f\n", newtonRaphsonCalculator.solveByNewtonRaphson(input));
        System.out.printf("%d total iterations", newtonRaphsonCalculator.getLastOperationTotalIterations());
    }
}