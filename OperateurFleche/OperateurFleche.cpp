#include <iostream>

// Implementer destructeur pour allouer dynamiquement de la mémoire et éviter des erreur et des fuites


// Classes.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>


class Personnage
{
public:

    // constructeur de copie par defaut sinon
    Personnage(Personnage& P) // constructeur de copie personnaliser
    {
        m_pdv = P.m_pdv;
        m_vitessedep = P.m_vitessedep;
        m_level = P.m_level;
        m_x = P.m_x;
        m_y = P.m_y;

    }

    Personnage() //constructeur par defaut
    {
        std::cout << "constructeur" << std::endl;
    }

    Personnage(unsigned int PDV, unsigned int VITESSE, unsigned int LEVEL, unsigned int X, unsigned int Y) : m_pdv(PDV), m_vitessedep(VITESSE), m_level(LEVEL), m_x(X), m_y(Y) // constructeur personalisé
    {
        std::cout << "constructeur" << std::endl;
    }
    ~Personnage()
    {
        std::cout << "destructeur" << std::endl;
    }

    unsigned int m_pdv, m_vitessedep, m_level;
    unsigned int m_x, m_y;



    void seDeplacer(unsigned int x, unsigned int y)
    {
        m_x += x;
        m_y += y;
    }

    void incrementlvl(unsigned int x, unsigned int y)
    {
        m_level++;
    }


};

class AbstractPerso
{
private: 
    Personnage* m_perso;
public:
    AbstractPerso(Personnage* perso) : m_perso(perso){}
    Personnage* operator -> () { return m_perso; }
};


int main()
{
    Personnage joueur1 (100, 10, 1, 12, 14 ); // pas d'argument, constructeur par default 

    Personnage* ptr = &joueur1;
    std::cout << "PDV : " << (*ptr).m_pdv << std::endl;
    std::cout << "PDV : " << ptr->m_pdv << std::endl;
    // *ptr. Error . spécifique a des variables alors que -> spécifique au pointeur
    // on peut utiliser ()


    AbstractPerso aPerso(ptr);
    // sans surcharge opérateur :
    // aPerso-> Error variable local aPerso n'est pas un pointeur 
    // aPerso. Error accede seulement variable public et pointeur Personnage* est en privé

    // avec surcharge opérateur :
    std::cout << "lvl : " << aPerso-> m_level<< std::endl;
    

    return 0;
}