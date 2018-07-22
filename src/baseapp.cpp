#include "sqlite3.h"
#include <iostream>
#include <string>
#include "functions.h"
using namespace std;

int main(int argc, char* argv[])
{
    sqlite3 *db;
    cout<<("Podaj nazwe tworzonej bazy\n");
    string nameBase;
    while(!(cin>>nameBase))
    {
        cout<<(stderr, "Blad. Podaj nazwe ponownie\n");
        cin.clear();
        while(cin.get() != '\n') continue;
    }
    int correctlyOpen = sqlite3_open(nameBase.c_str(), &db);
    if(correctlyOpen)
    {
        cout<<(stderr,"Blad otwarcia bazy: ");
        cout<<sqlite3_errmsg(db);
        cin.clear();
        while(cin.get() != '\n') continue;
        cin.get();
        return 0;
    }
    else
    {
        cout<<("Baza otwarta prawidlowo\n");
    }
    string prepareTable = "CREATE TABLE LUDZIE(" \
			"ID         INT     PRIMARY KEY NOT NULL," \
			"NAZWISKO   TEXT    NOT NULL," \
			"IMIE       TEXT    NOT NULL," \
			"WIEK       INT     DEFAULT 0);";
    correctlyOpen = sqlite3_exec(db,prepareTable.c_str(), 0, 0, 0);
    if(correctlyOpen)
    {
        cout<<"Blad tworzenia tabeli: "<<sqlite3_errmsg(db)<<endl;
    }
    else
    {
        cout<<"Tabela LUDZIE stworzona poprawnie\n";
    }
    int lastID = 0;
    int choose;
    while(true)
    {
    	cout<<"\nWybierz\n";
    	    cout<<"1: Wprowadz dane\n";
    	    cout<<"2: Skasuj ostatni rekord\n";
    	    cout<<"3: Wyswietl tabele\n";
    	    cout<<"4: Zamknij baze i zakoncz program\n";
    	   while(!(cin>>choose))
    	   {
    		   cin.clear();
    		   while(cin.get() != '\n') continue;
    	   }
    	    switch(choose)
    	    {
    	    case 1:
    	    	pushData(db, lastID);
    	    	break;
    	    case 2:
    	    	popBack(db, lastID);
    	    	break;
    	    case 3:
    	    	showTable(db);
    	    	break;
    	    case 4:
    	    	closeBase(db);
    	    default:
    	    	break;
    	    }
    }

}
