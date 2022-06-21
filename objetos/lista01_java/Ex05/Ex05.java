package Lista01.Ex05;

import Lista01.KeyboardInput;

public class Ex05 {
    public Integer getLesserDivisor(Integer n) {
        Integer divisor = 1;
        while(n % ++divisor != 0 && divisor < ((int) Math.sqrt(n)));
        return n % divisor == 0 ? divisor : null;
    }

    public static void main(String[] args) {
        Ex05 lesserDivisorCalculator = new Ex05();
        KeyboardInput keyboardInput = new KeyboardInput(System.in);

        System.out.println("Provide the base number: ");
        Integer input = keyboardInput.readPositiveInteger();

        Integer divisor = lesserDivisorCalculator.getLesserDivisor(input);
        if (divisor == null) System.out.println(input + " is a prime number.");
        else System.out.printf("%d is not a prime and it's lesser divisor is %d.%n", input, divisor);
    }
}
