# include <iostream>
# include <typeinfo>
# include <cstdio>
# include <chrono>
# include <thread>
# include <string>
# include <cstdlib>
# include <iomanip>// Nécessaire pour formater l'affichage de temps
# include <ctime>
# include <fstream>
# include "Chip.hpp"

using namespace std;

    int mon_code0 = 0;

/*************************************************************************************************************************/

void Control()
{
    Read_file ();
    Password ();
    Save_file ();
    system("cls");
}

/*************************************************************************************************************************/

void Password ()
{
	int i{3};
	bool code, check{true};
	int mon_code1;

    if (mon_code0 == 0)
    {
        std::cout <<"\n\n\t\t Entrer the new code :";
	    std::cin >> mon_code0;
	    system("cls");
    }

    while(check)
    {
        std::cout <<"\n\n\t\t Confirm the code :";
        std::cin >> mon_code1;

        if (mon_code0 == mon_code1)
        {
            check = false;
        }
        else
        {
            std::cout <<"\n\n\t\t the code must match first code entered \a." <<std::endl;
            --i;
        }

        if(i == 0)
        {
            std::cout << "\n\n\t\t Too many incorrect attempts. \n please wait 30 seconds before trying again." <<std::endl;
            for(int seconds = 30; seconds > 0; --seconds)
            {
                std::cout << "\n\t\t " << " " << seconds << " \r ";
                std::this_thread::sleep_for(std::chrono::seconds(1));
                system("cls");
            }
            std::cout << "\n\n\t\t Wait is over, you can try again ." <<std::endl;
            i = 3;
        }
    }

}

/*************************************************************************************************************/

void Save_file ()
{
    mon_code0 *= 19988;
    string const TEXT("Password.txt");
    ofstream TXT(TEXT.c_str());
    if(TXT)
        TXT << mon_code0;
}

/*************************************************************************************************************************/

void Read_file ()
{
    int number {};

    string const TEXT("Password.txt");
    ifstream TXT(TEXT);
    if(TXT)
    {
        TXT >> number;
        number /= (int)19988;
        mon_code0 = number;
    }
}

/*************************************************************************************************************************/

void Time ()
{
    std::cout << endl;
    std::time_t currentTime = std::time(nullptr);

    // Struct tm pour stocker les composants de temps (heure, minute, etc.)
    std::tm *localTime = std::localtime(&currentTime);

    // Affichage du temps au format "hh:mm:ss"
    // Affichage de la date au format "jj-mm-aaaa"
    std::cout << "\t -----------------\t\t\t       ----------------- " <<std::endl;
    std::cout << "\t|\033[1m\033[34m Date :" << std::put_time(localTime, "%d-%m-%Y")<<"\033[0m\033[0m|";
    std::cout << "\t\t\t      |\033[34m\033[1m Temps :" << std::put_time(localTime, "%T") <<"\033[0m\033[0m |" << std::endl;
    std::cout << "\t -----------------\t\t\t       ----------------- " << std::endl;
}

/*************************************************************************************************************************/

int Number_control (float number)
{
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
			std::cout << "\n\n\t\t Number :";
		}
	}

    number = (int)number;

    return number;
}

/*************************************************************************************************************************/

int Orange_control (int number1)
{
    string number = std::to_string(number1);
    bool F;
    do{
        F=false;

    // VÃ©rifier si la longueur est egale à  8
    if (number.length() == 8) {
        // Extraire les deux premiers chiffres
        string B = number.substr(0, 2);

        // Convertir les deux premiers chiffres en entier
        int C = stoi(B);

        // Verifier si les deux premiers chiffres sont dans les intervalles 
        if ((C >= 70 && C <= 72) ||
            (C >= 80 && C <= 82) ||
            (C >= 90 && C <= 92))
        {
    		number1 = std::stoi(number);
    		return number1;
        } 
	else 
	{
            std::cout << "\n\n\t\t The number isn\'t Zamani Telecom number." << std::endl;
    }
    } 
    else
    {
        std::cout << "\n\n\t\t PLease you must enter eight(8) digits." << std::endl;
    }
    std::cout << "\n\n\t\t Number : +227";
    std::cin >> number;
}while(!F);
 
return 0;
}

/*************************************************************************************************************************/

void About ()
{
    std::string About = "\n\n\t\t About \n"
    "\n\t\t We wouldn\'t begin this program without thankig the good lord for giving us the opportunity\n"
   "\t\t to see the great day.\n"

    "\n\t\t This program is based on chip management, allowing you to add, modify, delete, display all \n"
    "\t\t chips, and many other features to discover. We invite you to explore it step by step and we\n"
    "\t\t hope that this program will meet your expectations.\n"

    "\n\t\t Through this program, we take the opportunity to express our gratitude to our leader, friend \n"
    "\t\t and teacher Mr Moubarak, for guiding us, providing advice , and supporting us troughout. we \n"
    "\t\t cannot thank him enough, and a special thanks to our dear teacher MOUBARAK... \n"

    "\n\t\t Written by : \n"
    "\n\t\t\t RABE SAIDOU ADAMOU \n"
    "\n\t\t\t ASSOUMANA MAHAMADOU ISSA \n"
    "\n\t\t\t SALISSOU MAHAMANE ABOUBACAR \n"
    "\n\t\t\t MAMANE IDE IDE \n"
    "\n\t\t\t SAADOU HABOU MOUSAL AL ARI \n"
    "\n\t\t\t MOUSTAPHA MAHAMAN MAIKASSOUA IMRANA \n";
    
    for (char Character : About)
    {
    	std::cout << Character << std::flush;
    	std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    
    std::cout << std::endl;
}

/*************************************************************************************************************************/

void welcom ()
{
    system("cls");
    
    std::string welcomeArt = "___          ___    ____        _           ____        _______      _     _      ____ \n"

                             "\\  \\        /  /   | ___|      | |         |  __|      |  ___  |    |  \\_/  |    | ___|\n"
                             " \\  \\  __  /  /    | |_        | |         | |         | |   | |    | |\\_/| |    | |_  \n"
                             "  \\  \\/  \\/  /     | |__       | |__       | |__       | |___| |    | |   | |    | |__ \n"
                             "   \\___/\\___/      |____|      |____|      |____|      |_______|    |_|   |_|    |____|\n";

    // Afficher chaque caractère un à un avec une pause
    for (char character : welcomeArt) 
    {
        std::cout << character << std::flush;
        // Pause pour un effet progressif
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    std::cout << std::endl;
}

/*************************************************************************************************************************/

int Niger_Telecom_control (int number1)
{
    string number = std::to_string(number1);
    bool F;
    do{
        F=false;

    // VÃ©rifier si la longueur est egale à  8
    if (number.length() == 8) {
        // Extraire les deux premiers chiffres
        string B = number.substr(0, 2);

        // Convertir les deux premiers chiffres en entier
        int C = stoi(B);

        // Verifier si les deux premiers chiffres sont dans les intervalles 
        if ((C == 83 || C == 93))
        {
    		number1 = std::stoi(number);
    		return number1;
        } 
	else 
	{
            std::cout << "\n\n\t\t The number isn\'t Niger Telecom number." << std::endl;
    }
    } 
    else
    {
        std::cout << "\n\n\t\t PLease you must enter eight(8) digits." << std::endl;
    }
    std::cout << "\n\n\t\t Number : +227";
    std::cin >> number;
}while(!F);
 
return 0;
}

/*************************************************************************************************************************/

int Airtel_control (int number1)
{
    string number = std::to_string(number1);
    bool F;
    do{
        F=false;

    // VÃ©rifier si la longueur est egale à  8
    if (number.length() == 8) {
        // Extraire les deux premiers chiffres
        string B = number.substr(0, 2);

        // Convertir les deux premiers chiffres en entier
        int C = stoi(B);

        // Verifier si les deux premiers chiffres sont dans les intervalles 
        if ((C >= 76 && C <= 79) ||
            (C >= 86 && C <= 89) ||
            (C >= 96 && C <= 99))
        {
    		number1 = std::stoi(number);
    		return number1;
        } 
	else 
	{
            std::cout << "\n\n\t\t The number isn\'t Airtel number." << std::endl;
    }
    } 
    else
    {
        std::cout << "\n\n\t\t PLease you must enter eight(8) digits." << std::endl;
    }
    std::cout << "\n\n\t\t Number : +227";
    std::cin >> number;
}while(!F);
 
return 0;
}

/*************************************************************************************************************************/

int Moov_control (int number1)
{
    string number = std::to_string(number1);
    bool F;
    do{
        F=false;

    // VÃ©rifier si la longueur est egale à  8
    if (number.length() == 8) {
        // Extraire les deux premiers chiffres
        string B = number.substr(0, 2);

        // Convertir les deux premiers chiffres en entier
        int C = stoi(B);

        // Verifier si les deux premiers chiffres sont dans les intervalles 
        if ((C >= 74 && C <= 75) ||
            (C >= 84 && C <= 85) ||
            (C >= 94 && C <= 95))
        {
    		number1 = std::stoi(number);
    		return number1;
        } 
	else 
	{
            std::cout << "\n\n\t\t The number isn\'t Moov number." << std::endl;
    }
    } 
    else
    {
        std::cout << "\n\n\t\t PLease you must enter eight(8) digits." << std::endl;
    }
    std::cout << "\n\n\t\t Number : +227";
    std::cin >> number;
}while(!F);
 
return 0;
}