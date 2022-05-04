package Lista01.Ex01;

import Lista01.KeyboardInput;

import java.util.Random;

public class Ex1 {
    private final Random rand = new Random();

    public Double sqrt(Double n) {
        Double attempt = (double) rand.nextInt(n.intValue()) + 1;
        while (attempt - (attempt = (attempt + n/attempt)/2) > 0.00000001);
        return attempt;
    }

    public static void main(String[] args) {
        Ex1 squareRooter = new Ex1();
        KeyboardInput keyboardInput = new KeyboardInput(System.in);

        System.out.println("Provide a number: ");
        Double input = keyboardInput.readDouble();

        System.out.println("Square root: " + squareRooter.sqrt(input));
    }
}

