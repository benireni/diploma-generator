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
            3: [1, 4, 4, 1, 4],
            2: [2, 3, 2, 6, 3],
            5: [6, 5, 5, 1, 4],
            7: [6, 2, 6, 6, 6]
        }
        self.positions = [1, 2, 3, 4, 5, 6]

    @classmethod
    def tearDown(self): self.scoreboard = None

    def testScoreboardInitialization(self): self.assertEqual(0, self.scoreboard.getScore())

    def testInvalidPositionSubmittingHandling(self):
        with self.assertRaises(IndexError): self.scoreboard.add(0, [1, 1, 1, 1, 1])
        with self.assertRaises(IndexError): self.scoreboard.add(11, [1, 1, 1, 1, 1])

    def testOccupiedPositionSubmittingHandling(self):
        with self.assertRaises(ValueError):
            self.scoreboard.add(1, [1, 1, 1, 1, 1])
            self.scoreboard.add(1, [1, 1, 1, 1, 1])

    def testPositionOccupationHandling(self):
        baseValues = [range(1, 6), range(2, 7)]

        currentScore = 0
        for positionIndex in range(0, 6):
            offset = positionIndex // 5
            self.scoreboard.add(self.positions[positionIndex], baseValues[offset])
            self.assertEqual(baseValues[offset][positionIndex - offset], self.scoreboard.getScore() - currentScore)
            currentScore = self.scoreboard.getScore()

    def testTakenPositionReservations(self):
        self.populateMockGame(self.scoreboard)
        occupiedPositions = list(self.mockedGame.keys())

        for position in range(1, 10):
            if position in occupiedPositions: self.assertTrue(self.scoreboard.getTaken(position - 1))
            else: self.assertFalse(self.scoreboard.getTaken(position - 1))

    def testFullHouseCounting(self):
        self.assertTrue(Placar.checkFull([1, 1, 2, 2, 2]))
        self.assertFalse(Placar.checkFull([6, 6, 5, 5, 4]))

    def testSequenceCounting(self):
        self.assertTrue(Placar.checkSeqMaior([2, 3, 4, 5, 6]))
        self.assertFalse(Placar.checkSeqMaior([1, 2, 3, 4, 6]))

    def testFourOfAKindCounting(self):
        self.assertTrue(Placar.checkQuadra([2, 3, 3, 3, 3]))
        self.assertFalse(Placar.checkQuadra([2, 3, 3, 3, 4]))

    def testFiveOfAKindCounting(self):
        self.assertTrue(Placar.checkQuina([1, 1, 1, 1, 1]))
        self.assertFalse(Placar.checkQuina([1, 1, 6, 1, 1]))

    def populateMockGame(self, placar):
        for position, game in self.mockedGame.items(): placar.add(position, game)
