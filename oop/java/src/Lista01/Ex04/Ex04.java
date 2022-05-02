package Lista01.Ex04;

import Lista01.KeyboardInput;

public class Ex04 {
    public void printTree(Integer height) {
        for (int currentHeight = height; currentHeight > 0; currentHeight--)
            System.out.println(
                " ".repeat(height - currentHeight) + "*".repeat(currentHeight)
            );
    }

    public static void main(String[] args) {
        Ex04 inverseTreePrinter = new Ex04();
        KeyboardInput keyboardInput = new KeyboardInput(System.in);

        System.out.println("Provide the inverse tree height: ");
        Integer input = keyboardInput.readPositiveInteger();

        inverseTreePrinter.printTree(input);
    }
}
