# bus-station
The Bus Station project in C. Done for Polsl end of semester purpose


Napisz program, który przygotuje listy pasażerów autobusu. Pasażerowie mogą rezerwować bilety
na różne trasy w różnych biurach i przez internet. Wszystkie rezerwacje są zapisywane w centralnym
rejestrze. Centralny rejestr ma następującą postać:
  
| kod trasy | punkt startowy | data startu rrrr-mm | nazwisko pasażera | nr miejsca |
| --------- | -------------- | ------------------- | ---------- | ----------------- |
| 15551 | Katowice | 2011-12-13 | Jaworek  | 33 |
| 15551 | Katowice | 2011-12-13 | Kowalski | 02 |
| 15551 | Katowice | 2011-12-13 | Szybki   | 12 |
| 15551 | Katowice | 2011-12-13 | Biały    | 43 |
| 15651 | Warszawa | 2012-02-03 | Hastings | 02 |
| 15651 | Warszawa | 2012-02-03 | Poirot   | 23 |
| 15651 | Warszawa | 2012-02-03 | Holmes   | 11 |
| 15651 | Warszawa | 2012-02-03 | Lemon    | 43 |


Na podstawie pliku z rezerwacjami należy stworzyć plik z listą pasażerów dla każdego przystanku.
Nazwą pliku jest Kod trasy. W pliku umieszczone są: kod trasy, i lista pasażerów posortowana według
numerów siedzeń:


* Symbol trasy: 15551
* Punkt startowy: Katowice
* Data: 2011-12-13
* 02 Kowalski
* 12 Szybki
* 33 Jaworek
* 43 Biały

Liczba rezerwacji: 4


Program uruchamiany jest z linii poleceń z wykorzystaniem następującego przełącznika:
-i plik wejściowy z rezerwacjami
