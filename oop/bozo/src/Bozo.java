import java.util.List;

public class Bozo {

    public static void main(String[] args) {
        Score score = new Score();
        DiceRoller diceRoller = new DiceRoller(5);

        KeyboardInput keyboardInput = new KeyboardInput(System.in);

        System.out.println("--------------- BOZÓ, THE GAME ---------------\n");
        for (int round = 1; round <= 10; round++) {
            System.out.printf("\n======> ROUND %d", round);

            System.out.println("\n------ CURRENT SCORE ------");
            System.out.println(score);

            List<Integer> currentRoll = diceRoller.roll();

            System.out.println(diceRoller);
            for (int reroll = 1; reroll <= 3; reroll++) {
                System.out.printf("[%d/3] Provide the dice numbers that will be rerolled separated by spaces\n", reroll);
                System.out.println(
                    reroll == 1
                        ? "(if you do not want to make any rerolls, enter 'x')"
                        : "(if you do not want to make any more rerolls, just press enter)"
                );

                String rerollRequest = keyboardInput.readString();
                if (rerollRequest.isEmpty() || rerollRequest.equals("x")) break;

                currentRoll = diceRoller.roll(rerollRequest);
                System.out.println(diceRoller);
            }

            Boolean placementSucceeded = false;
            while (!placementSucceeded) {
                System.out.println(score);
                System.out.println("Where do you want to place your roll?");
                Integer slotIndex = keyboardInput.readInteger();

                try {
                   score.add(slotIndex, currentRoll);
                   placementSucceeded = true;
                } catch (IndexOutOfBoundsException e) {
                    System.out.println(e.getMessage());
                    System.out.println("Please, provide a valid one.\n");
                }
            }

        }

        System.out.println("--------- FINAL SCORE ---------");
        System.out.println(score);
        System.out.printf("\nTOTAL POINTS: %d\n", score.getPoints());
    }
}
