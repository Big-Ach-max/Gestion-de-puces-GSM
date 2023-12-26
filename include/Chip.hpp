#ifndef Chip_HPP_INCLUDED
#define Chip_HPP_INCLUDED

# include <string>
# include <vector>

class Chip
{
    private :
        int Num {}, Balance {}, Bonus {};
        std::string Network {};
        std::string FName {};
        int NumberEnv {}, NumberRec {};
        std::vector <Chip> chip {};
        std::vector<Chip> Trash {};
        std::vector<std::pair<std::string, int>> messageHistory; // L'historique de message
        /*
            * Un vecteur (tableau, conteneur dynamique) des paires ou chaque paire contient une chaine
            des caractères (message) et un entier (cout (par message))
        */
    public :
        Chip(); // Constructeur par d�faut
        Chip (int n, std::string r, std::string np, int s, int b = 100, int env = 0, int rec = 0); // Constructeur avec paramétres
        ~Chip(); // Destructeur
        void Main_menu (); // Menu principal
        void Input1 (); // Pour saisir les données au clavier
        void Input2 (); // Pour saisir les données au clavier
        void Input3 (); // Pour saisir les données au clavier
        void Input4 (); // Pour saisir les données au clavier
        void Display () const; // Pour afficher toutes les données d'une Chip
        int  Display_account (int number) const;
        void Modify ();
        void Delete ();
        void Reload (int n); // Pour recharger ou créditer la Chip
        void Send_SMS (Chip p, std::string msg); // Envoyer le msg (taille en octet) à la Chip indiquée en paramètre
        void Receive_SMS(Chip& p, std::string& msg);
        void Exchange (Chip p); // Afficher dans cette puce tous les échanges avec la puce en paramétre
        float Calculate_Recipe (); // Calculer la recette réalisée par cette puce à travers tous les messages envoyés
        int  GetBalance () const; // Renvoie la solde de la puce
        void Save_file () const; // Methode pour sauvegarder les données dans un fichier
        void Update_file () const; // Methode pour mettre à jour le fichier ()
        void Read_file (); // Methode pour dans le fichier
        
        // Methode pour Trash 
        void DisplayTrash() const;
        int  Display_Trash_account (int number) const;
        void Restoration_Trash (int number);
        void Trash_clear ();
        void Save_Trash_File () const;
        void Update_Trash_file () const;
        void Load_Trash_File ();

};

    void Control ();
    void Read_file ();
    void Password ();
    void Save_file ();
    void Time ();
    int Number_control (float number);
    int Orange_control (int number1);
    int Niger_Telecom_control (int number1);
    int Airtel_control (int number1);
    int Moov_control (int number1);
    void About ();
    void welcom ();

#endif // Chip_HPP_INCLUDED
