// penneys-game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <numeric>

int main()
{
    while (true) {
        std::cout << "Example sequence input: HTTHT \n";
        std::cout << "Player 1 enter your sequence: ";

        std::string p1_choice, p2_choice;
        std::cin >> p1_choice;
        std::cout << "Player 2 enter your sequence: ";
        std::cin >> p2_choice;

        //std::cout << p2_choice << p1_choice;

        const int seq_count = 10000;
        const int flips = 10000;

        //std::default_random_engine generator;
        //std::bernoulli_distribution distribution(0.5);

        std::vector<std::string> simulations(seq_count);
        std::vector<int> p1_positions(seq_count), p2_positions(seq_count);
        std::vector<bool> p1_won(seq_count), p2_won(seq_count);


        for (auto i = 0; i < seq_count; i++) {
            simulations[i].reserve(flips);
            for (auto j = 0; j < flips; j++) {
                char flip = (rand() % 2) ? 'H' : 'T';
                simulations[i] += flip;
            }
            p1_positions[i] = simulations[i].find(p1_choice);
            p2_positions[i] = simulations[i].find(p2_choice);
            p1_won[i] = p1_positions[i] < p2_positions[i];
            p2_won[i] = p2_positions[i] < p1_positions[i];
        };
        std::cout << simulations[4] << "\n" << p1_positions[4] << "\n" << p2_positions[4] << "\n" << p1_won[4] << "\n" << p2_won[4];
        std::cout << "Player 1 wins with probability " << std::accumulate(p1_won.begin(), p1_won.end(), 0.0) / (float)seq_count << '\n';
        std::cout << "Player 2 wins with probability " << std::accumulate(p2_won.begin(), p2_won.end(), 0.0) / (float)seq_count << '\n';
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
