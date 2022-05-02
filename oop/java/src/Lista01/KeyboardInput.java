package Lista01;

import java.io.InputStream;
import java.util.Scanner;

public class KeyboardInput {

    private final Scanner sc;

    public KeyboardInput(InputStream inputSource) {
         this.sc = new Scanner(inputSource);
    }

    public Integer readInteger() {
        while (!sc.hasNextInt()) {
            System.out.println("The input must be an integer.");
            sc.next();
        }
        return sc.nextInt();
    }

    public Integer readPositiveInteger() {
        Integer input;
        while (!sc.hasNextInt()) {
            System.out.println("The input must be an integer.");
            sc.next();
        }

        if ((input = sc.nextInt()) <= 0) throw new IllegalArgumentException("Number must be positive.");
        return input;
    }

    public Double readDouble() {
        while (!sc.hasNextDouble()) {
            System.out.println("The input must be a double.");
            sc.next();
        }
        return sc.nextDouble();
    }

    public String readString() {
        while (!sc.hasNextLine()) {
            System.out.println("The input must be a string.");
            sc.next();
        }
        return sc.nextLine();
    }
}
