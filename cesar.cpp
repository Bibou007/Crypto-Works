#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Prototype e la fonction de Cryptage

string crypter(string, int);

// Prototype de la fonction pour décrypter

string decrypter(string, int);

int main()
{
    char letter;
    int key=0;
    string cipher="",line;
    string text="";
    // Nom du fichier 
    string filename="plaintext.txt"; 

    cout << "Veuillez insérer la clé:" << endl;
    cin >> letter;

    // Calcul du Décalage obtenu
if(isupper(letter)){
 key = letter - 'A';
} else if(islower(letter)){
     key = letter - 'a';
}
   
    // Ouverture du fichier 

    ifstream in(filename.c_str(),ios::in);

    // Vérifier si le fichier est ouvert et renvoyer un message d'erreure sinon

    if(!in.is_open()){
        cout<<"ERREUR: Ouverture impossible"<<filename <<endl;
        return 0;
    }
    // Lecture du texte dans le fichier
    // On procèdera ligne par ligne

    while (!in.eof()){
        getline(in, line,'\n');

        if(in){
            text=text + line +"\n";
        }
    }
    in.close();

    // Chiffrer à présent un texte en appelant la fonction de cryptage de césar

    cipher= crypter(text, key);

    // Affichage du résultat obtenu après avoir chiffré le texte

    cout<<"Plain Text:";
    cout<<text<<endl;
    cout<<"Cipher Text:";
    cout<<cipher<<endl;


    return 0;
}

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

            // SI le x est plus grand que la norme (90) faire un modulo 26 pour le ramerner à la normale

            x = x % 26;

            // Convertir ensuite le numéro trouver en chaine de caratere
            c = (char)(x + 'a');
        }
        cipher.insert(cipher.end(), 1, c);
    }
    // cout << cipher << endl;
    return cipher;
}

string decrypter(string text, int key)
{
    string plain = "";

    for (unsigned i = 0; i < text.length(); i++)
    {

        char c = text[i];

        if (isupper(c))
        {

            // Appliquer l'algorithme de César en inversant pour pouvoir décrypter
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

            // Utilisons l'algorithme de cryptage de César

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

    cout << plain << endl;
    return plain;
}