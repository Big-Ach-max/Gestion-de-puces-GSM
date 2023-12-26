# include <iostream>
# include <cstdio>
# include <chrono>
# include <thread>
# include <string>
# include <vector>
# include <algorithm>
# include <fstream>
# include "Chip.hpp"

using namespace std;

/***************************************************************************************************************/

Chip::Chip () // 
{
	Num = 0;
	Network = "";
	FName = "";
	Balance = 0;
	Bonus = 0;
	NumberEnv = 0;
	NumberRec = 0;
}

/***************************************************************************************************************/

Chip::Chip (int n, std::string r, std::string np, int s, int b, int env, int rec) // Constructeur avec paramétres
{
    Num = n;
	Network = r;
	FName = np;
	Balance = s;
	Bonus = b;
	NumberEnv = env;
	NumberRec = rec;
}

/***************************************************************************************************************/
 
Chip::~Chip () // 
{
    
}

/***************************************************************************************************************/
 
void Chip::Input1 () // 
{
	int number;
	std::cout << "\n\n\t\t Number : +227";
	while (true)
		{
			if (std::cin >> number && number > 0)
			{
				break;
			}
			else
			{
				// La donnée saisie n'était pas un entier ou était négative
				std::cout << "\n\n\t\t Invalid number. Please try again" << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "\n\n\t\t Number : +227";
			}
		}
	number = Orange_control (number);
	Num = number;
	Network = "Zamani_Telecom";
	std::cout << "\n\n\t\t First Name and Last Name : ";
	cin.ignore();
	getline(std::cin , FName);
	std::cout << "\n\n\t\t Balance : ";
	while (true)
		{
			if (std::cin >> Balance && Balance > 0)
			{
				break;
			}
			else
			{
				// La donnée saisie n'était pas un entier ou était négative
				std::cout << "\n\n\t\t Invalid number. Please try again" << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "\n\n\t\t Balance :";
			}
		}

	Chip chip1(Num, Network, FName, Balance);

    chip.push_back(chip1);

	Save_file();
	Update_file();

    getchar();
}

/***************************************************************************************************************/

void Chip::Display () const // 
{
	std::cout << "\n\t\t**************************************" << std::endl;
	std::cout << "\n\t\t Number : +227" << Num << std::endl;
	std::cout << "\t\t Network : " << Network << std::endl;
	std::cout << "\t\t FName : " << FName << std::endl;
	std::cout << "\t\t Balance : " << Balance << "SAHEL" << std::endl;
	std::cout << "\t\t Bonus : " << Bonus << "%" << std::endl;
	std::cout << "\t\t NumberEnv : " << NumberEnv << std::endl;
	std::cout << "\t\t NumberRec : " << NumberRec << std::endl;
	std::cout << "\n\t\t**************************************" << std::endl;
}

/***************************************************************************************************************/

void Chip::Modify ()
{
	int number {}, n {};

	std::cout << "\n\n\t\t Please enter the chip number to modify : +227";
	while (true)
	{
		if (std::cin >> number && number > 0)
		{
			break;
		}
		else
		{
			// La donnée saisie n'était pas un entier ou était négative
			std::cout << "\n\n\t\t Invalid number. Please try again" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\n\n\t\t Number : +227";
		}
	}

	// Trie le vector par numero ;
            		
    std::sort(chip.begin(), chip.end(), [] (const Chip& a, const Chip& b){
        return a.Num < b.Num;
            });
         
    // Supression des doublons
            		
    chip.erase(std::unique(chip.begin(), chip.end(), [](const Chip& a, const Chip& b){
        return a.Num == b.Num;
            }), chip.end());
			
	std::cout << "\n\n\t\t\033[1m\033[34m Chip before modification \033[0m\033[0m" << std::endl;
	n = Display_account (number);

	for (auto it = chip.begin(); it < chip.end(); ++it)
	{
		if (it->Num == number)
		{
			std::cout << "\n\n\t\t FName : ";
			cin.ignore();
			getline(cin, it->FName);
			std::cout << "\n\n\t\t Balance : "; 
			std::cin >> it->Balance;
			std::cout << "\n\n\t\t\t\033[1m\033[7m\033[34m Chip Modified \033[0m\033[0m\033[0m" << std::endl;
			Update_file ();
			break;
		}
	}

	system("cls");
	if (n == 0)
	{
		std::cout << "\n\n\t\t\033[1m\033[34m Chip after modification \033[0m\033[0m" << std::endl;
		Display_account (number);
	}
}

/***************************************************************************************************************/

void Chip::Delete ()
{
	int number {};

	std::cout << "\n\n\t\t Please enter the chip number to delete : +227";
	while (true)
	{
		if (std::cin >> number && number > 0)
		{
			break;
		}
		else
		{
			// La donnée saisie n'était pas un entier ou était négative
			std::cout << "\n\n\t\t Invalid number. Please try again" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\n\n\t\t Number : +227";
		}
	}

	// Trie le vector par numero ;
            		
    std::sort(chip.begin(), chip.end(), [] (const Chip& a, const Chip& b){
        return a.Num < b.Num;
            });
         
    // Supression des doublons
            		
    chip.erase(std::unique(chip.begin(), chip.end(), [](const Chip& a, const Chip& b){
        return a.Num == b.Num;
            }), chip.end());

	std::cout << "\n\n\t\t\033[1m\033[31m Chip before deletion \033[0m\033[0m" << std::endl;
	Display_account (number);

	for (auto it = chip.begin(); it < chip.end(); ++it)
	{
		if (it->Num == number)
		{
			Trash.push_back(*it);
			it = chip.erase(it);
			std::cout << "\n\n\t\t\t\033[1m\033[7m\033[31m Chip Moved to Trash \033[0m\033[0m\033[0m" << std::endl;
			Update_file ();
			break;
		}
	}
	Save_Trash_File ();
	Update_Trash_file ();
}

/***************************************************************************************************************/

void Chip::Reload (int n) // 
{
	int amount {}, n1 {};
	
	std::cout << "\n\n\t\t Please enter the amount : ";

	while (true)
	{
		if (std::cin >> amount && amount > 0)
		{
			break;
		}
		else
		{
			// La donnée saisie n'était pas un entier ou était négative
			std::cout << "\n\n\t\t Invalid number. Please try again" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\n\n\t\t Amount : ";
		}
	}

	n1 = Display_account (n);

	for (auto it = chip.begin(); it < chip.end(); ++it)
	{
		if (it->Num == n)
		{
			it->Balance += amount;

			if (amount >= 500)
			{
				it->Bonus += 100;
			} 

			std::cout << "\n\n\t\t\t\033[1m\033[7m\033[36m Recharge completed \033[0m\033[0m\033[0m" << std::endl;
			Update_file ();
			break;
		}
	}

	system("cls");
	if (n1 == 0)
	{
		std::cout << "\n\n\t\t\033[1m\033[36m Account after recharge \033[0m\033[0m" << std::endl;
		Display_account (n);
	}
}

/***************************************************************************************************************/

int Chip::GetBalance () const // 
{
	int number {};

	std::cout << "\n\n\t\t Please enter the chip number : +227";
	while (true)
	{
		if (std::cin >> number && number > 0)
		{
			break;
		}
		else
		{
			// La donnée saisie n'était pas un entier ou était négative
			std::cout << "\n\n\t\t Invalid number. Please try again" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\n\n\t\t Number : +227";
		}
	}

	Display_account (number);

	for (auto it = chip.begin(); it < chip.end(); ++it)
	{
		if (it->Num == number)
		{
			return it->Balance;
		}
	}
return 0;
}

/***************************************************************************************************************/

int Chip::Display_account (int number) const // 
{
	for (auto it = chip.begin(); it < chip.end(); ++it)
	{
		if (it->Num == number)
		{
			std::cout << "\n\t\t**************************************" << std::endl;
			std::cout << "\n\t\t Number : +227" << it->Num << std::endl;
			std::cout << "\t\t Network : " << it->Network << std::endl;
			std::cout << "\t\t FName : " << it->FName << std::endl;
			std::cout << "\t\t Balance : " << it->Balance << "SAHEL" << std::endl;
			std::cout << "\t\t Bonus : " << it->Bonus << "%" << std::endl;
			std::cout << "\t\t NumberEnv : " << it->NumberEnv << std::endl;
			std::cout << "\t\t NumberRec : " << it->NumberRec << std::endl;
			std::cout << "\n\t\t**************************************" << std::endl;
			return 0;
		}
	}
return printf("\n\n\t\t\033[1m\033[31m The number +227%d does not exist\033[0m\033[0m ", number);
}

/***************************************************************************************************************/

void Chip::Save_file () const
{
	std::string file0 ("File.txt"); 
	ofstream file(file0.c_str(), ios::app);
	if(file)
	{
		for (const Chip &chip : chip)
			file << chip.Num << " " << chip.Network << " " << chip.FName << " " << chip.Balance << " " << chip.Bonus << " " << chip.NumberEnv << " " << chip.NumberRec << std::endl;
	}
	else
		std::cout << "\n\n\t\t Error " << std::endl;
}

/***************************************************************************************************************/

void Chip::Update_file () const
{
	std::string file0 ("File.txt"); 
	ofstream file(file0.c_str());
	if(file)
	{
		for (const Chip &chip : chip)
			file << chip.Num << " " << chip.Network << " " << chip.FName << " " << chip.Balance << " " << chip.Bonus << " " << chip.NumberEnv << " " << chip.NumberRec << std::endl;
	}
	else
		std::cout << "\n\n\t\t Error " << std::endl;
}

/***************************************************************************************************************/

void Chip::Read_file ()
{
	chip.clear();
	std::string file0 ("File.txt");
	ifstream file(file0.c_str());
	if(file)
	{
		int number, balance, bonus, env, rec; std::string network, fname, lname;
		while (file >> number >> network >> fname >> lname >> balance >> bonus >> env >> rec)
		{
			Num = number;
			Network = network;
			FName = fname + " " + lname;
			Balance = balance;
			Bonus = bonus;
			NumberEnv = env;
			NumberRec = rec;
			Chip chip1(Num, Network, FName, Balance, Bonus, NumberEnv, NumberRec);
			chip.push_back(chip1);
		}
	}
	else
		std::cout << "\n\n\t\t Error " << std::endl;
}

/***************************************************************************************************************/
 
void Chip::Input2 () // 
{
	int number;
	std::cout << "\n\n\t\t Number : +227";
	while (true)
		{
			if (std::cin >> number && number > 0)
			{
				break;
			}
			else
			{
				// La donnée saisie n'était pas un entier ou était négative
				std::cout << "\n\n\t\t Invalid number. Please try again" << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "\n\n\t\t Number : +227";
			}
		}
	number = Niger_Telecom_control (number);
	Num = number;
	Network = "Niger_Telecom";
	std::cout << "\n\n\t\t First Name and Last Name : ";
	cin.ignore();
	getline(std::cin , FName);
	std::cout << "\n\n\t\t Balance : ";
	while (true)
		{
			if (std::cin >> Balance && Balance > 0)
			{
				break;
			}
			else
			{
				// La donnée saisie n'était pas un entier ou était négative
				std::cout << "\n\n\t\t Invalid number. Please try again" << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "\n\n\t\t Balance :";
			}
		}

	Chip chip1(Num, Network, FName, Balance);

    chip.push_back(chip1);

	Save_file();
	Update_file();

    getchar();
}

/***************************************************************************************************************/
 
void Chip::Input3 () // 
{
	int number;
	std::cout << "\n\n\t\t Number : +227";
	while (true)
		{
			if (std::cin >> number && number > 0)
			{
				break;
			}
			else
			{
				// La donnée saisie n'était pas un entier ou était négative
				std::cout << "\n\n\t\t Invalid number. Please try again" << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "\n\n\t\t Number : +227";
			}
		}
	number = Airtel_control (number);
	Num = number;
	Network = "Airtel";
	std::cout << "\n\n\t\t First Name and Last Name : ";
	cin.ignore();
	getline(std::cin , FName);
	std::cout << "\n\n\t\t Balance : ";
	while (true)
		{
			if (std::cin >> Balance && Balance > 0)
			{
				break;
			}
			else
			{
				// La donnée saisie n'était pas un entier ou était négative
				std::cout << "\n\n\t\t Invalid number. Please try again" << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "\n\n\t\t Balance :";
			}
		}

	Chip chip1(Num, Network, FName, Balance);

    chip.push_back(chip1);

	Save_file();
	Update_file();

    getchar();
}

/***************************************************************************************************************/
 
void Chip::Input4 () // 
{
	int number;
	std::cout << "\n\n\t\t Number : +227";
	while (true)
		{
			if (std::cin >> number && number > 0)
			{
				break;
			}
			else
			{
				// La donnée saisie n'était pas un entier ou était négative
				std::cout << "\n\n\t\t Invalid number. Please try again" << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "\n\n\t\t Number : +227";
			}
		}
	number = Moov_control (number);
	Num = number;
	Network = "Moov";
	std::cout << "\n\n\t\t First Name and Last Name : ";
	cin.ignore();
	getline(std::cin , FName);
	std::cout << "\n\n\t\t Balance : ";
	while (true)
		{
			if (std::cin >> Balance && Balance > 0)
			{
				break;
			}
			else
			{
				// La donnée saisie n'était pas un entier ou était négative
				std::cout << "\n\n\t\t Invalid number. Please try again" << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "\n\n\t\t Balance :";
			}
		}

	Chip chip1(Num, Network, FName, Balance);

    chip.push_back(chip1);

	Save_file();
	Update_file();

    getchar();
}

void Chip::Send_SMS(Chip p, std::string msg)
{
	int number, coutMessage = 15;
	std::cout << "\n\n\t\t Entrez votre numero :";
	while (true)
	{
		if (std::cin >> number && number > 0)
		{
			break;
		}
		else
		{
			// La donnée saisie n'était pas un entier ou était négative
			std::cout << "\n\n\t\t Invalid number. Please try again" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\n\n\t\t Numero :";
		}
	}
	for (auto it = chip.begin(); it < chip.end(); ++it)
	{
		if (it->Num == number)
		{
			std::cout << "Saisissez le message a envoyer :"; getline(std::cin, msg);
		}
	}
	
	messageHistory.push_back(std::make_pair("Sent: " + msg, coutMessage));
	p.Receive_SMS(*this, msg);
}

void Chip::Receive_SMS(Chip& p, std::string& msg)
{
	int coutMessage = 15;
	messageHistory.push_back(std::make_pair("Received: " + msg, coutMessage));
}

void Chip::Exchange (Chip p)
{
	int number;
	std::cout << "\n\n\t\t Entrez le numero dont vous voulez voir les echanges:";
	while (true)
	{
		if (std::cin >> number && number > 0)
		{
			break;
		}
		else
		{
			// La donnée saisie n'était pas un entier ou était négative
			std::cout << "\n\n\t\t Invalid number. Please try again" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\n\n\t\t Numero :";
		}
	}
	for (auto it = chip.begin(); it < chip.end(); ++it)
	{
		if (it->Num == number)
		{
		    std::cout << "Message history for " << Num << ":\n";
			for (const auto& message : messageHistory) 
			{
				std::cout << message.first << " (Cost: " << message.second << ")\n";
			}
			std::cout << "-------------------------\n";
		}

	}
}