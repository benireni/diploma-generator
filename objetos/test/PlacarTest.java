import org.junit.jupiter.api.*;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertThrows;

class PlacarTest {
    private Placar scoreboard;

    int[] positions = {1, 2, 3, 4, 5, 6};
    int[] mockedGame = {4, 5, 4, 3, 4};

    @BeforeEach
    void setup() {
        scoreboard = new Placar();
    }

    @AfterEach
    public void tearDown() {
        scoreboard = null;
    }

    @Test
    public void scoreboardShouldInitializeWithZero() {
        assertEquals(0, scoreboard.getScore());
    }

    @Test
    public void scoreboardShouldRaiseIndexErrorWhenReceivingInvalidPosition() {
        assertThrows(IllegalArgumentException.class, () -> scoreboard.add(11, mockedGame));
        assertThrows(IllegalArgumentException.class, () -> scoreboard.add(0, mockedGame));
    }

    @Test
    public void scoreboardShouldRaiseValueErrorWhenReceivingOccupiedPosition() {
        scoreboard.add(1, mockedGame);
        assertThrows(IllegalArgumentException.class, () -> scoreboard.add(1, mockedGame));
    }

    @Test
    public void scoreboardShouldManageOccupiedPositions() {
        int[][] baseValues = {{1, 2, 3, 4, 5}, {2, 3, 4, 5, 6}};
        int currentScore = 0;
        int offset = 0;
        for (int positionIndex = 0; positionIndex < 6; positionIndex++) {
            offset = positionIndex / 5;
            scoreboard.add(positions[positionIndex], baseValues[offset]);
            assertEquals(baseValues[offset][positionIndex - offset], scoreboard.getScore() - currentScore);
            currentScore = scoreboard.getScore();
        }
    }

    @Test
    public void scoreboardShouldIdentifyFullHouseCombinationProperly() {
        scoreboard.add(7, new int[]{1, 5, 1, 5, 5});
        assertEquals(15, scoreboard.getScore());

        this.setup();
        scoreboard.add(7, new int[] {1, 1, 2, 3, 4});
        assertEquals(0, scoreboard.getScore());
    }

    @Test
    public void scoreboardShouldIdentifySequenceCombinationProperly() {
        scoreboard.add(8, new int[]{6, 4, 3, 5, 2});
        assertEquals(20, scoreboard.getScore());

        this.setup();
        scoreboard.add(8, new int[] {1, 1, 1, 1, 1});
        assertEquals(0, scoreboard.getScore());

    }

    @Test
    public void scoreboardShouldIdentifyFourOfAKindCombinationProperly() {
        scoreboard.add(9, new int[]{4, 1, 4, 4, 4});
        assertEquals(30, scoreboard.getScore());

        this.setup();
        scoreboard.add(9, new int[] {1, 1, 2, 2, 2});
        assertEquals(0, scoreboard.getScore());
    }

    @Test
    public void scoreboardShouldIdentifyFiveOfAKindCombinationProperly() {
        scoreboard.add(10, new int[]{3, 3, 3, 3, 3});
        assertEquals(40, scoreboard.getScore());

        this.setup();
        scoreboard.add(10, new int[] {1, 2, 2, 2, 2});
        assertEquals(0, scoreboard.getScore());
    }

    @Test
    public void shouldRetrieveScoreboardCurrentValueProperly() {
        this.populateMockGame();
        assertEquals(31, scoreboard.getScore());
    }

    private void populateMockGame() {
        scoreboard.add(7, new int[]{1, 3, 3, 1, 3});
        scoreboard.add(3, new int[]{2, 3, 6, 2, 3});
        scoreboard.add(6, new int[]{6, 5, 5, 1, 2});
        scoreboard.add(1, new int[]{1, 2, 1, 1, 1});
    }

}