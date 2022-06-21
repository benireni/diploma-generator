import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class DiceRoller {

    private final List<Dice> dices = new ArrayList<>();

    public DiceRoller(int diceQuantity) {
        for (int i = 0; i < diceQuantity; i++) {
            this.dices.add(new Dice());
            try { Thread.sleep(5); }
            catch (InterruptedException e) { continue; }
        }
    }

    public List<Integer> roll() {
        return this.dices.stream()
                .map(Dice::roll)
                .collect(Collectors.toList());
    }

    public List<Integer> roll(List<Boolean> targets) {
        return this.dices.stream()
                .map(dice -> targets.get(this.dices.indexOf(dice))
                    ? dice.roll() : dice.getLastValue()
                ).collect(Collectors.toList());
    }

    public List<Integer> roll(String targets) {
        if (targets.isEmpty() || targets.isBlank()) return this.dices.stream()
                .map(Dice::getLastValue)
                .collect(Collectors.toList());

        List<Integer> targetIndexes = Stream.of(targets
                .replaceAll("[^0-9]+", " ")
                .trim().split(" ")).distinct()
                .map(Integer::parseInt)
                .collect(Collectors.toList());

        if (targetIndexes.stream().anyMatch(target -> target > 4 || target < 0)) {
            System.out.println("At least one of your target dices is out of bounds!\nRolling the valid ones (if any).\n");
            targetIndexes = targetIndexes.stream().filter(target -> target <= 4 && target >= 0 ).collect(Collectors.toList());
        }

        for (Integer target:targetIndexes) this.dices.get(target - 1).roll();
        return this.dices.stream().map(Dice::getLastValue).collect(Collectors.toList());
    }

    @Override
    public String toString() {
        if (this.dices.stream().anyMatch(dice -> dice.getLastValue() == null)) {
            System.out.println("You will need to roll the dices before seeing the result.");
            return "";
        }

        List<String> dices = this.dices.stream()
                .map(Dice::toString)
                .collect(Collectors.toList());

        StringBuilder dicesRepresentation = new StringBuilder();
        for(int i = 1; i <= this.dices.size(); i++)
            dicesRepresentation.append(String.format(" %d        ", i));
        dicesRepresentation.append("\n");

        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < this.dices.size(); j++) {
                dicesRepresentation.append(dices.get(j), i * 8, (i * 8) + 7);
                dicesRepresentation.append("   ");
            }
            dicesRepresentation.append("\n");
        }

        return dicesRepresentation.toString() + "\n";
    }
}
