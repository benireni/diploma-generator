package Lista01.Ex02;

import Lista01.KeyboardInput;

import java.util.Arrays;
import java.util.HashMap;

public class Ex02 {
    private final KeyboardInput keyboardInput = new KeyboardInput(System.in);

    private HashMap<Character, Double> readEquation() {
        System.out.println("Provide coefficients 'a', 'b' and 'c' separated by line breaks:");
        return new HashMap<>() {{
            put('a', keyboardInput.readDouble());
            put('b', keyboardInput.readDouble());
            put('c', keyboardInput.readDouble());
        }};
    }

    public Double[] solveQuadraticEquation(HashMap<Character, Double> equation) {
        Double det = Math.pow(equation.get('b'), 2) - (4 * equation.get('a') * equation.get('c'));
        Double detSqrt = Math.sqrt(det);

        if (det > 0) return new Double[]{
            (-equation.get('b') + detSqrt)/(2*equation.get('a')),
            (-equation.get('b') - detSqrt)/(2*equation.get('a'))
        };

        else if (det == 0) return new Double[]{
            (-equation.get('b') + detSqrt)/(2*equation.get('a'))
        };

        else return new Double[]{};
    }

    public static void main(String[] args) {
        Ex02 quadraticSolver = new Ex02();

        HashMap<Character, Double> equation = quadraticSolver.readEquation();

        Double[] solution = quadraticSolver.solveQuadraticEquation(equation);

        System.out.println("\nSolution: " + Arrays.toString(solution));
    }
}
