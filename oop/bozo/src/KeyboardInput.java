import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Scanner;

public class KeyboardInput {

    private static Scanner sc;
    private static BufferedReader bufferedReader;

    public KeyboardInput(InputStream inputSource) {
        sc = new Scanner(inputSource);
        InputStreamReader inputStreamReader = new InputStreamReader(inputSource);
        bufferedReader = new BufferedReader(inputStreamReader);
    }

    public Integer readInteger() {
        Boolean readSucceeded = false;

        Integer input = null;
        while (!readSucceeded) {
            try {
                String rawInput = bufferedReader.readLine();
                input = Integer.parseInt(rawInput);
                readSucceeded = true;
            } catch (Exception e) {
                System.out.println("The input must be an integer.");
            }
        }

        return input;
    }

    public String readString() {
        Boolean readSucceeded = false;

        String input = null;
        while (!readSucceeded) {
            try {
                input = bufferedReader.readLine();
                readSucceeded = true;
            } catch (IOException e) {
                System.out.println("The input must be a string.");
            }
        }

        return input;
    }
}
