package Lista01.Ex03;

import Lista01.KeyboardInput;

public class Ex03 {
    public void printTree(Integer height) { for (; height > 0; height--) System.out.println("*".repeat(height)); }

    public static void main(String[] args) {
        Ex03 treePrinter = new Ex03();
        KeyboardInput keyboardInput = new KeyboardInput(System.in);

        System.out.println("Provide the tree high: ");
        Integer input = keyboardInput.readPositiveInteger();

        treePrinter.printTree(input);
    }
}
