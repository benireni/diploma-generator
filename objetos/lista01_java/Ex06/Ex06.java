package Lista01.Ex06;

import Lista01.KeyboardInput;

public class Ex06 {
    private Boolean isPrime(Integer n) {
        Integer divisor = 1;
        while(n % ++divisor != 0 && divisor < ((int) Math.sqrt(n)));
        return n % divisor != 0;
    }

    public Integer getPrimePredecessor(Integer n) {
        while (n > 1) if (isPrime(--n)) return n;
        return null;
    }

    public static void main(String[] args) {
        Ex06 predecessorPrimeCalculator = new Ex06();
        KeyboardInput keyboardInput = new KeyboardInput(System.in);

        System.out.println("Provide the base number: ");
        Integer input = keyboardInput.readPositiveInteger();

        Integer divisor = predecessorPrimeCalculator.getPrimePredecessor(input);
        System.out.println(divisor + " is the first prime number lower than the input.");
    }
}
