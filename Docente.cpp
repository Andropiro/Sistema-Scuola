#include <cstdio>
#include <string.h>
#include <iostream>
#include <stdbool.h>

#define CIFRE_IBAN 27
#define CIFRE_CF 16
#define MAX_LUNGHEZZA_EMAIL 128
#define LUNGHEZZA_RISPOSTA 2
#define MAX_LUNGHEZZA_STRINGA 1024

//autore: Bensi Simone

using namespace std;

class Docente // : public Persona
{
	private:
		char iban[CIFRE_IBAN];
		char cf[CIFRE_CF];
		char email[MAX_LUNGHEZZA_EMAIL];
		int tempoIndeterminato;
		
	public:
		//costruttore senza parametri
		Docente()
		{
			strcpy(iban, "");
			strcpy(cf, "");
			strcpy(email, "");
			tempoIndeterminato = false;
		}
		
		//costruttore con parametri
		Docente(char codice_iban[], char codice_fiscale[], char Email[], bool TempoIndeterminato)
		{
			strcpy(iban, codice_iban);
			strcpy(cf, codice_fiscale);
			strcpy(email, Email);
			tempoIndeterminato = TempoIndeterminato;
		}
		
		//setter e getter
		void setIban(char codice_iban[])
		{
			strcpy(iban, codice_iban);
		}
		
		void getIban(char codice_iban[])
		{
			strcpy(codice_iban, iban);
		}
		
		void setCf(char codice_fiscale[])
		{
			strcpy(cf, codice_fiscale);
		}
		
		void getCf(char codice_fiscale[])
		{
			strcpy(codice_fiscale, cf);
		}
		
		void setEmail(char Email[])
		{
			strcpy(email, Email);
		}
		
		void getEmail(char Email[])
		{
			strcpy(Email, email);
		}
		
		void setTempoIndeterminato(bool TempoIndeterminato)
		{
			tempoIndeterminato = TempoIndeterminato;
		}
		
		bool getTempoIndeterminato()
		{
			return tempoIndeterminato;
		}
		
		//metodo che rende disponibile le caratteristiche del docente
		//sotto forma di stringa
		void toString(char stringa[])
		{
			//concatenazione caratteristiche docente
			strcat(stringa, "Codice iban:");
			strcat(stringa, iban);
			strcat(stringa, "\nCodice fiscale:");
			strcat(stringa, cf);
			strcat(stringa, "\nEmail:");
			strcat(stringa, email);
		
			if(tempoIndeterminato == true)
				strcat(stringa, "\nDocente a tempo indeterminato");
			else
				strcat(stringa, "\nDocente a tempo determinato");
				
			
		}
		
		//funzione che stampa la stringa passata per parametro
		void stampaStringa(char stringa[])
		{
			cout << stringa << endl;
		}
		
		/*
		
		void addMateria()
		{
		
		}
		
		void removeMateria()
		{
		
		}
		
		void getMaterie()
		{
		
		}
		
		*/
};

int main()
{
	//variabili temporanee per l'inserimento delle caratteristiche
	//dei docenti attraverso setter
	char codice_iban[CIFRE_IBAN];
	char codice_fiscale[CIFRE_CF];
	char email[MAX_LUNGHEZZA_EMAIL];
	bool tempoIndeterminato;
	
	//utilizzata per la scelta del tempo indeterminato
	char scelta[LUNGHEZZA_RISPOSTA];
	
	//inizializzazione stringa che verrà stampata
	char caratteristiche_docente[MAX_LUNGHEZZA_STRINGA] = "";

	Docente docente;
	
	//inserimento caratteristiche docente da tastiera
	cout << "Iban docente: ";
	cin >> codice_iban;
	docente.setIban(codice_iban);
	
	cout << endl << "Codice fiscale docente: ";
	cin >> codice_fiscale;
	docente.setCf(codice_fiscale);
	
	cout << endl << "Email docente: ";
	cin >> email;
	docente.setEmail(email);
		
	cout << endl << "Docente a tempo indeterminato (si/no): ";
	cin >> scelta;
	
	//se l'utente digita 'si' sceglie tempo indeterminato,
	//altrimenti sceglie tempo determinato
	if(strcmp(scelta, "si") == 0)
		tempoIndeterminato = true;
	else
		tempoIndeterminato = false;
	docente.setTempoIndeterminato(tempoIndeterminato);
	
	//richiamo metodo per l'elenco delle caratteristiche del docente
	docente.toString(caratteristiche_docente);
	
	//stampo caratteristiche docente
	docente.stampaStringa(caratteristiche_docente);

	
	return 0;
}
