package Lista01.Ex08;

import Lista01.KeyboardInput;

public class Ex08 {
    static final Double ERROR = 10e-7;
    private Integer iterator = 0;

    private Double calculateBaseEquation(Double x) {
        return Math.pow(x, 3) - Math.pow(x, 2) - 13*x + 8;
    }

    public Integer getLastOperationTotalIterations() { return this.iterator; }

    public Double solveByBisection(Double a, Double b) {
        if (calculateBaseEquation(a) * calculateBaseEquation(b) >= 0) return a;

        Double c = a;
        this.iterator = 0;
        while (b - a >= ERROR) {
            c = (a + b) / 2;
            if (calculateBaseEquation(c) == 0.0) break;
            else if (calculateBaseEquation(c) * calculateBaseEquation(a) < 0) b = c;
            else a = c;

            this.iterator++;
        }

        return c;
    }

    public static void main(String[] args) {
        Ex08 bisectionCalculator = new Ex08();
        KeyboardInput keyboardInput = new KeyboardInput(System.in);

        System.out.println("Provide the desired interval: ");
        Double a = keyboardInput.readDouble();
        Double b = keyboardInput.readDouble();

        System.out.printf("Solution by Bisection: %.4f\n", bisectionCalculator.solveByBisection(a, b));
        System.out.printf("%d total iterations", bisectionCalculator.getLastOperationTotalIterations());
    }
}
