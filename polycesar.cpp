#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

// Prototype e la fonction de Cryptage

string crypter(string, int);

// Prototype de la fonction pour décrypter

string decrypter(string, int);

int main()
{
    string letter;
    // Déclarons un vecteur qui est un tableau dynamique à remplir au fur et à mesure pour récuperer tous les décalages calcule
    vector<int> key_table;
// La variable i pour 
    int i = 0;
    // key, une variable de type int permettant de calculer e décalage entre un caractère et la première lettre de l'alphabet
    int key = 0;
    // cipher est le texte chiffré
    string cipher = "", line;
    // final_cipher est le texte finale chiffré
    string final_cipher = "";
    // text est le text lut dans le fichier
    string text = "";
    // Nom du fichier
    string filename = "plaintext.txt";

    cout << "Veuillez insérer la clé:" << endl;
    cin >> letter;

    // Ouverture du fichier

    ifstream in(filename.c_str(), ios::in);

    // Vérifier si le fichier est ouvert et renvoyer un message d'erreure sinon

    if (!in.is_open())
    {
        cout << "ERREUR: Ouverture impossible" << filename << endl;
        return 0;
    }
    // Lecture du texte dans le fichier
    // On procèdera ligne par ligne

    while (!in.eof())
    {
        getline(in, line, '\n');

        if (in)
        {
            text = text + line + "\n";
        }
    }
    in.close();

    // Calcul du Décalage obtenu

    for (int i = 0; i < letter.length(); i++)
    {

        if (isupper(letter[i]))
        {
            key = letter[i] - 'A';
            // Insertion de la valeur issue de la différence entre le caractère et la première lettre de l'alphabet dans le vecteur key_table grace à la methode insert
            key_table.insert(key_table.end(), 1, key);
        }
        else if (islower(letter[i]))
        {
            key = letter[i] - 'a';

            key_table.push_back(key);
        }
    }

    while (final_cipher.length() < text.length())
    {
        cipher = crypter(text, key_table[i % key_table.size()]);

        final_cipher.insert(final_cipher.end(), 1, cipher[i]);

        i++;
    }

    // Chiffrer à présent un texte en appelant la fonction de cryptage de césar

    // Affichage du résultat obtenu après avoir chiffré le texte

    cout << "Le Message du fichier est:";
    cout << text << endl;
    cout << "Le Message chiffré est:";
    cout << final_cipher << endl;

    return 0;
}
// Implémentons la fonction pour crypter un message
string crypter(string text, int key)
{

    string cipher = "";

    for (unsigned i = 0; i < text.length(); i++)
    {

        char c = text[i];
        if (isupper(c))
        {
            // Appliquer l'algorithme de césar
            int x = c - 'A' + key;
            // Faire un modulo pour le ramener si valeur superieure
            x = x % 26;

            // Convertir en chaine de caractere
            c = (char)(x + 'A');
        }
        else if (islower(c))
        {
            // Appliquer l'algorithme de cesar
            int x = c - 'a' + key;

            // Si le x est plus grand que la norme (90) faire un modulo 26 pour le ramerner à la normale

            x = x % 26;

            // Convertir ensuite le numéro trouver en chaine de caratere
            c = (char)(x + 'a');
        }
        cipher.insert(cipher.end(), 1, c);
    }
    // cout << cipher << endl;
    return cipher;
}
// Implémentons la fonction pour décrypter un message
string decrypter(string text, int key)
{
    string plain = "";

    for (unsigned i = 0; i < text.length(); i++)
    {

        char c = text[i];

        if (isupper(c))
        {

            // Appliquer l'algorithme de César en inverse pour pouvoir décrypter
            int x = c - 'A' - key;

            // Ramener à un nomber positive si inferieur à 0

            if (x < 0)
            {
                x += 26;
            }

            // Convertir maintenant le numéro obtenu en charactère

            c = (char)(x + 'A');
        }
        else if (islower(c))
        {

            // Utilisons l'algorithme de cryptage de César mais en inverse

            int x = c - 'a' - key;

            // Ramener à une valeur positive si inférieure à 0

            if (x < 0)
            {
                x += 26;
            }

            // Convertir le numéro obtenu en chaine de caratère

            c = (char)(x + 'a');
        }

        plain.insert(plain.end(), 1, c);
    }

    return plain;
}