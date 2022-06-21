import unittest
from Placar import Placar


class PlacarTest(unittest.TestCase):

    scoreboard = None

    @classmethod
    def setUp(self):
        self.scoreboard = Placar()
        self.combinations = [
            "Ones",
            "Twos",
            "Threes",
            "Fours",
            "Fives",
            "Sixes",
            "Full",
            "Sequence",
            "Four of a kind",
            "General"
        ]
        self.mockedGame = {
            3: [1, 3, 3, 1, 3],
            2: [2, 3, 2, 6, 3],
            5: [6, 5, 5, 1, 2],
            7: [1, 2, 1, 1, 1]
        }
        self.positions = [1, 2, 3, 4, 5, 6]

    @classmethod
    def tearDown(self): self.scoreboard = None

    def scoreboardShouldCountZeroPointsWhenStarted(self): self.assertEqual(0, self.scoreboard.getScore())

    def scoreboardShouldRaiseIndexErrorWhenReceivingInvalidPosition(self):
        with self.assertRaises(IndexError): self.scoreboard.add(0, [1, 1, 1, 1, 1])
        with self.assertRaises(IndexError): self.scoreboard.add(11, [1, 1, 1, 1, 1])

    def scoreboardShouldRaiseValueErrorWhenReceivingOccupiedPosition(self):
        with self.assertRaises(ValueError):
            self.scoreboard.add(1, [1, 1, 1, 1, 1])
            self.scoreboard.add(1, [1, 1, 1, 1, 1])

    def branchTestScoreboardCombinationReceiving(self):
        values = [[1, 2, 3, 4, 5], [2, 3, 4, 5, 6]]
        score = 0

        for i in range(6):
            shift = i // 5
            self.scoreboard.add(self.positions[i], values[shift])
            self.assertEqual(values[shift][i - shift], self.scoreboard.getScore() - score)
            score = self.scoreboard.getScore()

        self.scoreboard.add(7, [1, 1, 2, 2, 2])
        self.assertEqual(36, self.scoreboard.getScore())
        self.scoreboard.add(8, [1, 2, 3, 4, 5])
        self.assertEqual(56, self.scoreboard.getScore())
        self.scoreboard.add(9, [1, 1, 1, 1, 2])
        self.assertEqual(86, self.scoreboard.getScore())
        self.scoreboard.add(10, [1, 1, 1, 1, 1])
        self.assertEqual(126, self.scoreboard.getScore())

    def branchTestScoreboardNameRetrieval(self):
        for i, combination in enumerate(self.combinations): self.assertIn(combination, self.scoreboard.getName(i))

    def scoreboardShouldManageOccupiedPositions(self):
        self.populateMockGame(self.scoreboard)
        occupied = list(self.mockedGame.keys())

        for value in range(1, 10):
            if value in occupied: self.assertEqual(True, self.scoreboard.getTaken(value - 1))
            else: self.assertEqual(False, self.scoreboard.getTaken(value - 1))

    def scoreboardShouldCountCombinationPointsProperly(self):
        self.assertEqual(2, Placar.conta(1, [1, 2, 3, 4, 5, 6, 1, 2]))
        self.assertEqual(2, Placar.conta(2, [1, 2, 3, 4, 5, 6, 1, 2]))
        self.assertEqual(4, Placar.conta(3, [1, 2, 3, 4, 3, 3, 3, 2]))
        self.assertEqual(2, Placar.conta(4, [1, 2, 4, 4, 5, 6, 1, 2]))
        self.assertEqual(1, Placar.conta(5, [1, 2, 3, 4, 5, 6, 1, 2]))
        self.assertEqual(3, Placar.conta(6, [1, 2, 3, 4, 5, 6, 6, 6]))

    def scoreboardShouldIdentifyFullHouseCombinationProperly(self):

        self.assertEqual(True, Placar.checkFull([3, 3, 3, 4, 4]))
        self.assertEqual(True, Placar.checkFull([3, 4, 3, 4, 3]))

        mockedInvalidGames = [
            [1, 2, 2, 3, 3],
            [1, 1, 2, 3, 3],
            [1, 1, 1, 2, 3],
            [1, 1, 2, 2, 3],
            [1, 1, 2, 3, 3],
            [1, 2, 3, 3, 3]
        ]

        for invalidGame in mockedInvalidGames: self.assertEqual(False, Placar.checkFull(invalidGame))

    def scoreboardShouldIdentifySequenceCombinationProperly(self):
        self.assertEqual(True, Placar.checkSeqMaior([1, 2, 3, 4, 5]))
        self.assertEqual(True, Placar.checkSeqMaior([6, 4, 5, 3, 2]))

        mockedInvalidGames = [
            [1, 1, 1, 1, 1],
            [1, 2, 2, 2, 2],
            [1, 2, 3, 3, 3],
            [1, 2, 3, 4, 4],
            [2, 2, 2, 2, 2],
            [2, 3, 3, 3, 3],
            [2, 3, 4, 4, 4],
            [2, 3, 4, 5, 5]
        ]

        for invalidGame in mockedInvalidGames: self.assertEqual(False, Placar.checkSeqMaior(invalidGame))

    def scoreboardShouldIdentifyFourOfAKindCombinationProperly(self):
        self.assertEqual(True, Placar.checkQuadra([1, 1, 1, 1, 5]))
        self.assertEqual(True, Placar.checkQuadra([6, 1, 6, 6, 6]))

        mockedInvalidGames = [
            [1, 2, 2, 2, 3],
            [1, 1, 2, 2, 2],
            [1, 1, 1, 2, 3],
            [1, 2, 3, 3, 3],
            [1, 2, 2, 3, 3],
        ]

        for invalidGame in mockedInvalidGames: self.assertEqual(False, Placar.checkQuadra(invalidGame))

    def scoreboardShouldIdentifyFiveOfAKindCombinationProperly(self):
        self.assertEqual(True, Placar.checkQuina([1, 1, 1, 1, 1]))
        self.assertEqual(True, Placar.checkQuina([6, 6, 6, 6, 6]))

        mockedInvalidGames = [
            [1, 2, 2, 2, 2],
            [1, 1, 2, 2, 2],
            [1, 1, 1, 2, 2],
            [1, 1, 1, 1, 2]
        ]

        for invalidGame in mockedInvalidGames: self.assertEqual(False, Placar.checkQuina(invalidGame))

    def populateMockGame(self, placar):
        for position, game in self.mockedGame.items(): placar.add(position, game)

    def shouldRetrieveScoreboardCurentValueProperly(self):
        self.populateMockGame(self.scoreboard)
        self.assertEqual(15, self.scoreboard.getScore(6))
        self.assertEqual(41, self.scoreboard.getScore())

    def shouldRetrieveStringRepresentationProperly(self):
        self.populateMockGame(self.scoreboard)
        expectedOutput = (
            " 5     |    15    |  (4) \n"
            "-------|----------|-------\n"
            "(2)    |   (8)    |  (5) \n"
            "-------|----------|-------\n"
            " 9     |   (9)    |   12 \n"
            "-------|----------|-------\n"
            "       |   (10)   |\n"
            "       +----------+\n"
        )
        self.assertEqual(expectedOutput, self.scoreboard.__str__())

        self.scoreboard.add(10, [2, 2, 2, 2, 2])
        expectedOutput = (
            " 5     |    15    |  (4) \n"
            "-------|----------|-------\n"
            "(2)    |   (8)    |  (5) \n"
            "-------|----------|-------\n"
            " 9     |   (9)    |   12 \n"
            "-------|----------|-------\n"
            "       |    40    |\n"
            "       +----------+\n"
        )
        self.assertEqual(expectedOutput, self.scoreboard.__str__())
        
unittest.main()