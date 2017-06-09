# geo-area
### Area measure tool

## Scope and content
Software requirements specification:
...

<1> Introduction
a. Program zostanie wykonany na zaliczenie przedmiotu. G³ównym celem bedzie liczenie powierzchni dowolnej figury.
<2> Applicable and reference documents
a. Plik README bedzie zawieraæ wymagania dotycz¹ce programu i bedzie jednoczeœnie dokumentacj¹ tego programu.
<3> Terms, definitions and abbreviated terms
a. Program powinien zostac oddany do sprawdzenia do 24.06.2017r
<4> Software overview
<4.1> Function and purpose
a. program bedzie liczyc powierzchniê dowolnie zadanej figury geometrycznej.
b. Program bedzie pobiera³ dane wejœciowe od uzytkownika z klawiatury.
<4.2> Environmental considerations
a. Program powinien dzia³aæ na platformie Linux lub Windows
b. Program bêdzie zaimplementowany w jêzyku C;
c. Do poprawnego dzia³ania wymagane jest zainstalowanie CMake 3.7.2 lub wy¿szy z kompilatorem wspieraj¹cym CMake.
d. Zainstalowana biblioteka: "math.h"
<5> Requirements
<5.1> General
a. Ka¿de wymaganie bedzie jednoznacznie okreœlone.
b. Wymagania mog¹ byæ scharakteryzowane, na przyk³ad istotne lub nie.
<5.2> Functional requirements
a. Program bedzie wylicza³ powierzchnie po podaniu wspó³rzednych minimum trzech wierzcho³ków
b. W przypadku nie podania odpowiedniej iloœci wierzcho³ków ( mniej ni¿ 3), uzytkownik otrzyma komunikat o b³êdzie.
c. Dane wejsciowe bed¹ wprowadzone z klawiatury wraz z plikiem wykonywalnym
d. Para wejsciowa wsó³rzednych wierzcho³ka bêdzie wygladac wg wzorca: "X0:Y0 ... Xn:Yn"
e. Liczby wprowadzone jako wspólrzedne wierzcho³ków moga byæ w postaci dziesiêtnej. Separatorem dla liczb jest znak kropki (".").
f. Po wprowadzeniu danych i zatwierdzeniu przyciskiem Enter na ekranie wyswietli sie komunikat: "Obliczona powierzchnia:" i wynik dzia³ania programu.
g. Wynik bêdzie wyswietlany w formie liczby zmiennoprzecinkowej z dok³adnoœcia do 6 miejsc po przecinku.
<5.3> Interface requirements
a. Wprowadzanie danych odbywa siê za pomoc¹ klawiatury.
b. Wynik dzia³ania bedzie wyswietlany na ekranie w formie tekstowej w tym samym oknie. 
c. Jezykiem komunikowania sie z u¿ytkowniem bêdzie jêzyk Polski
<5.4> Design requirements and implementation constraints
a. Program bedzie napisany w jêzyku C
b. Narzedziem do napisania programu bedzie Dev-C++ v. 5.11
c. Typem liczby zmiennoprzecinkowej bedzie "double"
<5.5> Security and privacy requirements
a. Program bedzie na otwartej licencji 
b. Program wykorzystuje funkcjonalnoœæ http://alienryderflex.com/polygon_area/
<5.6> Portability requirements
a. Program bêdzie mo¿na przenosic na dowoln¹ iloœc urz¹dzeñ spe³niaj¹cych wymagania œrodowiskowe.
b. Program dzia³a lokalnie, bez dostêpu do sieci.
<5.7> Software reliability requirements
a. Program bedzie dzia³a³ po prawid³owym wprowadzeniu wartoœci wierzcho³ków. 
b. Program bedzie informowa³ o braku lub niew³aœciwych wprowadzonych danych.
<5.8> Human factors related requirements
a. Program bedzie niewra¿liwy na b³edne dane wprowadzane z klawiatury.
b. Program bedzie informowa³ uzytkownika o niew³asciwym wprowadzaniu danych.
<5.9> Adaptation and installation requirements
a. Program bêdzie mo¿liwy do zainstalowania na ka¿dej platformie Linux lub Windows z pow³oka Bash
```

## Build
To build type:
```
cmake 
make
```

To build on Windows type:
```
cmake -G "MinGW Makefiles" ./CMakeLists.txt
```

To clean project directory type:
```
make clean
```

## Tests
To run tests type:
```
make test
```

## Run
To run tool type:
```
./geo-area X1:Y1 X2:Y2 X3:Y3 ... Xn:Yn
```
