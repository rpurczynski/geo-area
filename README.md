# geo-area
### Area measure tool

## Scope and content
Software requirements specification:
...

<1> Introduction
a. Program zostanie wykonany na zaliczenie przedmiotu. G��wnym celem bedzie liczenie powierzchni dowolnej figury.
<2> Applicable and reference documents
a. Plik README bedzie zawiera� wymagania dotycz�ce programu i bedzie jednocze�nie dokumentacj� tego programu.
<3> Terms, definitions and abbreviated terms
a. Program powinien zostac oddany do sprawdzenia do 24.06.2017r
<4> Software overview
<4.1> Function and purpose
a. program bedzie liczyc powierzchni� dowolnie zadanej figury geometrycznej.
b. Program bedzie pobiera� dane wej�ciowe od uzytkownika z klawiatury.
<4.2> Environmental considerations
a. Program powinien dzia�a� na platformie Linux lub Windows
b. Program b�dzie zaimplementowany w j�zyku C;
c. Do poprawnego dzia�ania wymagane jest zainstalowanie CMake 3.7.2 lub wy�szy z kompilatorem wspieraj�cym CMake.
d. Zainstalowana biblioteka: "math.h"
<5> Requirements
<5.1> General
a. Ka�de wymaganie bedzie jednoznacznie okre�lone.
b. Wymagania mog� by� scharakteryzowane, na przyk�ad istotne lub nie.
<5.2> Functional requirements
a. Program bedzie wylicza� powierzchnie po podaniu wsp�rzednych minimum trzech wierzcho�k�w
b. W przypadku nie podania odpowiedniej ilo�ci wierzcho�k�w ( mniej ni� 3), uzytkownik otrzyma komunikat o b��dzie.
c. Dane wejsciowe bed� wprowadzone z klawiatury wraz z plikiem wykonywalnym
d. Para wejsciowa ws�rzednych wierzcho�ka b�dzie wygladac wg wzorca: "X0:Y0 ... Xn:Yn"
e. Liczby wprowadzone jako wsp�lrzedne wierzcho�k�w moga by� w postaci dziesi�tnej. Separatorem dla liczb jest znak kropki (".").
f. Po wprowadzeniu danych i zatwierdzeniu przyciskiem Enter na ekranie wyswietli sie komunikat: "Obliczona powierzchnia:" i wynik dzia�ania programu.
g. Wynik b�dzie wyswietlany w formie liczby zmiennoprzecinkowej z dok�adno�cia do 6 miejsc po przecinku.
<5.3> Interface requirements
a. Wprowadzanie danych odbywa si� za pomoc� klawiatury.
b. Wynik dzia�ania bedzie wyswietlany na ekranie w formie tekstowej w tym samym oknie. 
c. Jezykiem komunikowania sie z u�ytkowniem b�dzie j�zyk Polski
<5.4> Design requirements and implementation constraints
a. Program bedzie napisany w j�zyku C
b. Narzedziem do napisania programu bedzie Dev-C++ v. 5.11
c. Typem liczby zmiennoprzecinkowej bedzie "double"
<5.5> Security and privacy requirements
a. Program bedzie na otwartej licencji 
b. Program wykorzystuje funkcjonalno�� http://alienryderflex.com/polygon_area/
<5.6> Portability requirements
a. Program b�dzie mo�na przenosic na dowoln� ilo�c urz�dze� spe�niaj�cych wymagania �rodowiskowe.
b. Program dzia�a lokalnie, bez dost�pu do sieci.
<5.7> Software reliability requirements
a. Program bedzie dzia�a� po prawid�owym wprowadzeniu warto�ci wierzcho�k�w. 
b. Program bedzie informowa� o braku lub niew�a�ciwych wprowadzonych danych.
<5.8> Human factors related requirements
a. Program bedzie niewra�liwy na b�edne dane wprowadzane z klawiatury.
b. Program bedzie informowa� uzytkownika o niew�asciwym wprowadzaniu danych.
<5.9> Adaptation and installation requirements
a. Program b�dzie mo�liwy do zainstalowania na ka�dej platformie Linux lub Windows z pow�oka Bash
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
