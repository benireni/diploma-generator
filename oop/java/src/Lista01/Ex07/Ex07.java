package Lista01.Ex07;

import Lista01.KeyboardInput;

import java.util.ArrayList;
import java.util.Arrays;

public class Ex07 {

    private final KeyboardInput keyboardInput = new KeyboardInput(System.in);

    public ArrayList<Double> readDoubleStream() {
        ArrayList<Double> inputStream = new ArrayList<>(){};
        Double currentInput;
        while(!(currentInput = keyboardInput.readDouble()).equals(0.)) inputStream.add(currentInput);
        return inputStream;
    }

    public ArrayList<Double> getStreamExtremes(ArrayList<Double> doubleStream) {
        Double max = Double.MIN_VALUE;
        Double min = Double.MAX_VALUE;
        for (Double record : doubleStream) {
            if (record > max) max = record;
            if (record < min) min = record;
        }

        return new ArrayList<>(Arrays.asList(min, max)){};
    }

    public static void main(String[] args) {
        Ex07 doubleStreamAnalyst = new Ex07();

        System.out.println("Provide your doubles separated by line breaks (enter 0 to halt): ");
        ArrayList<Double> input = doubleStreamAnalyst.readDoubleStream();

        ArrayList<Double> inputExtremes = doubleStreamAnalyst.getStreamExtremes(input);
        System.out.printf("Stream min: %.2f, max: %.2f", inputExtremes.get(0), inputExtremes.get(1));
    }
}
