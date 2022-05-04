from re import sub
from deck import Deck
from renderer import Renderer
from pot_handler import PotHandler
from wallet import Wallet

if __name__ == "__main__":
    deck = Deck()
    renderer = Renderer()

    player_wallet = Wallet(200)
    pot_handler = PotHandler()

    print("----------- VIDEO POKER -----------")
    deck.shuffle()

    round = 1
    while not player_wallet.isBroke():
        print(f"===> Round {round}")
        print(f"Current budget: {player_wallet.budget}\n")

        pot = pot_handler.read_gamble(player_wallet.budget)
        player_wallet.pay(pot)

        hand = deck.deal(5)
        for i in range(2):
            print("\n", end="")
            renderer.print_hand(hand)

            substitution_requests = input("\nWhich cards do you want to substitute? (Enter for none)\n")
            deck.replace_cards(hand, substitution_requests)

        print("\nYour hand:")
        renderer.print_hand(hand)

        reward = pot_handler.reward_hand(hand)
        player_wallet.receive(reward)

        if reward > 0: print(f"You've earned {reward} bucks!\n")
        else: print("You've earned nothing :(\n")

        round += 1
    
    print("You're broke! The house always wins ;)")
    print("Bye!")
