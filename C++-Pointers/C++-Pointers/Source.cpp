#include <iostream>
#include <stdlib.h>
#include <time.h>

int RandomizeNumber(int* ppRN, int maxNumber);
int RandomizePrize(int* pRP, int maxNumber);

int main() {
	std::cout << "\n\tWelcome To The SCP Guessing Game!\n" << std::endl;
	std::cout << "For those who know of SCP, this might be a bit easier since you should be familiar with the various SCPs, so put your knowledge to the test\nFor those who do not know of SCP, then this will serve as a great memory game as well\n" << std::endl;
	std::cout << "Your Job:\nYou'll be given the alternate name of these SCPs and you're to input the number associated with them\n" << std::endl;

	std::cout << "Do you want to start the game? Y/N - ";
	char understand = 'N';
	std::cin >> understand;
	understand = toupper(understand);
	do {
		if (understand != 'Y' && understand != 'N')
		{
			std::cout << "\nThis is a Y/N Question\nPlease Try Again\n" << std::endl;
			std::cout << "Do you want to start the game? Y/N - ";
			std::cin >> understand;
			understand = toupper(understand);
		}
	} while (understand != 'Y' && understand != 'N');
	std::cout << "\n";

	if (understand == 'N')
	{
		return 0;
	}

	int simulationNumber = 0;
	int correct = 0;
	int outOf = 0;

	int SCPnumbs[7]{
		173,
		682,
		106,
		978,
		1548,
		1983,
		597
	};

	std::string SCPdescs[7]{
		"The Sculpture",
		"The Hard-To-Destroy Reptile",
		"The Old Man - Aka - Radical Larry",
		"The Polaroid",
		"The Hateful Star",
		"The Farmhouse",
		"The Mother"
	};

	std::string Prizes[3]{
		"Cookie",
		"Cake",
		"Pie"
	};

	int randomPrizes = RandomizePrize(&randomPrizes, 3);
	std::string randomPrize = Prizes[randomPrizes];

	char startAgain = 'N';
	do {
		int randomNumber = RandomizeNumber(&randomNumber, 7);

		simulationNumber++;

		int SCPnumb = SCPnumbs[randomNumber];
		std::string SCPdesc = SCPdescs[randomNumber];

		std::cout << "Name: " << SCPdesc << std::endl;
		std::cout << "SCP-";
		int guess;
		std::cin >> guess;

		outOf++;

		if (guess == SCPnumb)
		{
			std::cout << "\nThat's Right! SCP-" << guess << " is " << SCPdesc << "\n" << std::endl;
			correct++;
		}
		else
		{
			std::cout << "\nNo, I'm Sorry. " << guess << " is not the assigned number of SCP-" << SCPnumb << ", " << SCPdesc << "\n" << std::endl;
		}

		std::cout << "Start Again? Y/N - ";
		std::cin >> startAgain;
		startAgain = toupper(startAgain);

		do {
			if (startAgain != 'Y' && startAgain != 'N')
			{
				std::cout << "\nThis is a Y/N Question\nPlease Try Again\n" << std::endl;
				std::cout << "Start Again? Y/N - ";

				std::cin >> startAgain;
				startAgain = toupper(startAgain);
			}
		} while (startAgain != 'Y' && startAgain != 'N');
		std::cout << "\n";
	} while (startAgain == 'Y');

	if (startAgain == 'N')
	{
		std::cout << "This is the end of the game\n" << std::endl;
		std::cout << "You ran " << simulationNumber << " Simulations" << std::endl;
		std::cout << "And got " << correct << "/" << outOf << " of the SCPs correct\n" << std::endl;
		std::cout << "Here's Your Prize: " << randomPrize << "\n" << std::endl;
	}

	system("pause");
	return 0;
}

int RandomizeNumber(int* ppRN, int maxNumber) {
	srand(time(0));
	int RandomNumb = rand() % maxNumber;
	return RandomNumb;
}

int RandomizePrize(int* pRP, int maxNumber) {
	srand(time(0));
	int RandomPrize = rand() % maxNumber;
	return RandomPrize;
}