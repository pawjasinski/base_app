#include "functions.h"
using namespace std;

static int show(void *nothing, int argc, char **argv, char **colName)
{
	int i = 0;
	for( int i =0; i<argc; ++i)
	{
		cout.width(10);
		cout<<left<<colName[i]<<": "<< (argv[i] ? argv[i] : "NULL")<<endl;
	}
	cout<<endl;
	return 0;
}

void popBack(sqlite3 *db, int &i)
{
	string sql = "DELETE FROM LUDZIE where ID="+to_string(i)+";";
	int correctlyDel = sqlite3_exec(db, sql.c_str(), 0, 0, 0);
	if(correctlyDel)
	{
		cout<<"Blad: "<<sqlite3_errmsg(db)<<endl;
	}
	else
	{
		cout<<"Operacja wykonana poprawnie: "<<endl;
		--i;
	}
}

void showTable(sqlite3 *db)
{
	sqlite3_exec(db, "SELECT * from LUDZIE;", show, 0, 0);
}

void pushData(sqlite3 *db, int &i)
{
	unsigned int wiek, correctlyExec;
	string imie, nazwisko, sql;
    cout<<"Podaj imie nazwisko wiek:\n";
    while(!(cin>>imie>>nazwisko>>wiek))
    {
        cout<<(stderr,"Blad. Podaj ponownie imie nazwisko wiek" \
		        " (oddzielone bialym znakiem):\n");
        cin.clear();
        while(cin.get() != '\n') continue;
    }
    sql= (string)"INSERT INTO LUDZIE (ID,NAZWISKO,IMIE,WIEK) " \
            "VALUES ("+to_string(i+1)+", '"+nazwisko+"', '"+imie+"', "+to_string(wiek)+" );";
    correctlyExec = sqlite3_exec(db, sql.c_str(), 0, 0, 0 );;
    if(correctlyExec)
    {
        cout<<stderr, "Blad: ";
        cout<<sqlite3_errmsg(db)<<endl;
    }
    else
    {
    	cout<<"Dane wprowadzono prawidlowo: "<<endl;;
    	++i;
    }
}

void closeBase(sqlite3 *db)
{
    int correctlyClose = sqlite3_close(db);
    if(correctlyClose)
    {
        cout<<stderr, "Blad zamkniecia bazy\n";
    }
    else
    {
        cout<<"Baza zamknieta prawidlowo\n";
    }
    cin.clear();
    while(cin.get() != '\n') continue;
    cin.get();
    exit(EXIT_SUCCESS);
}
