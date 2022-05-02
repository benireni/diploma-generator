import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Score {

    public enum Slot {
        ONES(1), TWOS(2), THREES(3), FOURS(4), FIVES(5),
        SIXES(6), FULL(7), SEQUENCE(8), FOUR_EQUAL(9), FIVE_EQUAL(10);

        public int slotIndex;
        Slot(int index) {
            slotIndex = index;
        }
    }

    private final HashMap<Slot, Integer> scoreTable = new HashMap<>();

    public void add(Integer position, List<Integer> dices) {

        Slot targetSlot = Arrays.stream(Slot.values())
                .filter(slot -> slot.slotIndex == position)
                .findFirst()
                .orElse(null);

        if (position > 10 || position < 1 || this.scoreTable.containsKey(targetSlot)) {
            List<Integer> availableSlots = Stream.of(Slot.values())
                    .filter(slotType -> !this.scoreTable.containsKey(slotType))
                    .map(slot -> slot.slotIndex)
                    .collect(Collectors.toList());

            throw new IndexOutOfBoundsException("Invalid slot. The available ones are " + availableSlots);
        }

        if (position >= Slot.ONES.slotIndex && position <= Slot.SIXES.slotIndex) {

            Integer scoredValue = dices.stream()
                    .filter(diceValue -> diceValue == position)
                    .reduce((scoredPoints, diceValue) -> scoredPoints += diceValue)
                    .orElse(0);
            this.scoreTable.put(targetSlot, scoredValue);

        } else if (position == Slot.FULL.slotIndex) {
            List<Integer> distinctDices = dices.stream()
                    .distinct().collect(Collectors.toList());

            Integer pivotValueFreq = Collections.frequency(dices, dices.get(0));

            // If there are only two different values in dice set, if any of them have 2, 3 or 5 occurrences, it is necessarily a full
            if (distinctDices.size() == 2 && List.of(2, 3, 5).contains(pivotValueFreq))
                this.scoreTable.put(Slot.FULL, 15);
            else this.scoreTable.put(Slot.FULL, 0);

        } else if (position == Slot.SEQUENCE.slotIndex) {
            List<Integer> sortedValues = dices.stream().sorted().collect(Collectors.toList());

            Integer valueCursor = sortedValues.get(0);

            this.scoreTable.put(Slot.SEQUENCE, 20);
            for (Integer value : sortedValues) if (!Objects.equals(value, valueCursor++))
                this.scoreTable.put(Slot.SEQUENCE, 0);

        } else if (position == Slot.FOUR_EQUAL.slotIndex) {
            Integer pivotValueFreq = Collections.frequency(dices, dices.get(0));

            if (dices.stream().distinct().count() == 2 && List.of(1, 4).contains(pivotValueFreq))
                this.scoreTable.put(Slot.FOUR_EQUAL, 25);
            else this.scoreTable.put(Slot.FOUR_EQUAL, 0);

        } else if (position == Slot.FIVE_EQUAL.slotIndex) {
            if (dices.stream().distinct().count() == 1)
                this.scoreTable.put(Slot.FIVE_EQUAL, 30);
            else this.scoreTable.put(Slot.FIVE_EQUAL, 0);

        }
    }

    public Integer getPoints() {
        return scoreTable.values().stream()
                .reduce((points, slotValue) -> points += slotValue)
                .orElseThrow(InstantiationError::new);
    }

    @Override
    public String toString() {
        List<String> allocatedPoints = Stream.of(Slot.values())
                .map(slotType -> !this.scoreTable.containsKey(slotType)
                        ? "(" + slotType.slotIndex + ")"
                        : " " + this.scoreTable.get(slotType) + " "
                ).collect(Collectors.toList());

        StringBuilder formattedOutput = new StringBuilder();
        for(int i = 0; i < 3; i++) {
            formattedOutput.append(allocatedPoints.get(i)).append("    |   ").append(allocatedPoints.get(i+6))
                    .append("    |   ").append(allocatedPoints.get(i+3)).append("\n");
            formattedOutput.append("--------------------------\n");
        }
        formattedOutput.append("       |   ").append(allocatedPoints.get(9)).append("   |\n");
        formattedOutput.append("       +----------+");

        return "\n" + formattedOutput + "\n\n";
    }
}
