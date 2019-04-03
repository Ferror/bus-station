# bus-station
The Bus Station project in C. Done for Polsl end of semester purpose


Napisz program, który przygotuje listy pasażerów autobusu. Pasażerowie mogą rezerwować bilety
na różne trasy w różnych biurach i przez internet. Wszystkie rezerwacje są zapisywane w centralnym
rejestrze. Centralny rejestr ma następującą postać:
  
| kod trasy | punkt startowy | data startu rrrr-mm | nr miejsca | nazwisko pasażera |
| --------- | -------------- | ------------------- | ---------- | ----------------- |
| 15551 | Katowice | 2011-12-13 | 33 | Jaworek |
| 15551 | Katowice | 2011-12-13 | 02 | Kowalski |
| 15551 | Katowice | 2011-12-13 | 12 | Szybki |
| 15551 | Katowice | 2011-12-13 | 43 | Biały |
| 15651 | Warszawa | 2012-02-03 | 02 | Hastings |
| 15651 | Warszawa | 2012-02-03 | 23 | Poirot |
| 15651 | Warszawa | 2012-02-03 | 11 | Holmes |
| 15651 | Warszawa | 2012-02-03 | 43 | Lemon |


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
