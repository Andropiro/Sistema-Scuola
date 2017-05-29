#include <iostream>
#include "stdlib.h"
#include "stdlib.h"
#include <User.h>
#include <string.h>

using namespace std;

bool login = 0; //Flag per capire se un utente è connesso o meno

void confronta_username(char* name){ //Funzione che confronta l'username immesso dall'utente con quello registrato
    while ( strcmp(name, utente.Username) !=0 ){
        cout << " L'username inserito non corrisponde a quello registrato. "
        cout << " Inserire l'username (Massimo 50 caratteri) : ";
        cin >> name;
    }
    return 1;
}

void confronta_password(char* pass){ //Funzione che confronta la password immessa dall'utente con quella registrata
    while ( strcmp(pass, utente.Password) !=0 ){
        cout << " La password inserita non corrisponde a quella registrata. "
        cout << " Inserire la password (Massimo 50 caratteri) : ";
        cin >> pass;
    }
    return 1;
}

void User::login(){ //Metodo per il login
    char name[50]; //Dove finirà l'username
    char pass[50]; //Dove finirà la password

    cout << " Inserire l'username (Massimo 50 caratteri) : "; cin >> name;
    cout << " Inserire la password (Massimo 50 caratteri) : "; cin >> pass;

    confronta_username(name); //Richiamo delle funzioni di controllo
    confronta_password(pass);

    utente = new User(name, pass); //Si crea un oggetto dell'utente commesso
    cout << " Autenticazione riuscita. Benvenuto/a : " << utente.Username;
    login = 1; //Si setta il flag
}

void User::logout(){ //Metodo per il logout
    cout << " Utente disconnesso. ";
    login = 0; //Si setta il flag a 0
}

void User::cambiaPassword(){ //Metodo per cambiare password
    cout << "Inserire la nuova password desiderata (Massimo 50 caratteri) : "; cin >> Password;
}

void main(){
    int opzione = 0; //Indice per il menù dello Switch
    User utente; //Si crea un utente

    cout << "Scegliere l'opzione desiderata digitando il numero alla sinistra di tale operazione: ";
    cout << " 1: Login ";
    cout << " 2: Logout ( possibile solo se si è effettuato il login ) ";
    cout << " 3: Cambio della password ( possibile solo se si è effettuato il login ) ";
    cout << " 4: Uscita. ";

    while ( opzione != 4 ){ //Finché non si esce, il menù continua
        switch(opzione){
            case (1):
            utente.login(); //Si connette l'utente
            break;

        case (2):
            if ( login == 1 ){ utente.logout(); } //Si controlla che sia connesso per disconnetterlo
            cout << "E' necessario effettuare il login prima di eseguire il logout. ";
            cout << "---------------------------------------------------------------";
            break;

        case (3):
            if ( login == 1 ){ utente.cambiaPassword();} //Si controlla che sia connesso per cambiare la relativa password
            cout << "E' necessario effettuare il login prima di cambiare la password. ";
            cout << "-----------------------------------------------------------------";
            break;

        case (4):
            cout << "Arrivederci. ";
            return 1;
        }
    }
}
