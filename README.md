Eduard Petcu - 314CC

====================

AutomaticallyFill:
	Am citit cheia si textul iar apoi am verificat
	daca acestea sunt valide. In cazul in care ambele
	siruri contin doar litere, am aplicat functia de multiplicare.
	Functia de multiplicare a cheii multiplica cheia pana cand
	lungimea acesteia devine mai mare sau egala cu lungimea textului.
	Pentru a avea totusi o cheie de aceeasi lungime cu textul, am pus
	caracterul '\0' in cheie la pozitia la care s-ar fi terminat textul.
	Functia de modificare text preia atat cheia multiplicata, cat si
	textul, si aplica fiecarui caracter din text functia de transformare
	(conform cerintei).
	Programul a fost implementat in decurs de 2 ore, iar rezolvarea
	erorilor de memorie a durat 2 ore.

====================

CifrulVigenere:
	Datele de intrare au fost citite in functia *readstr care returneaza
	textul formularului (care este de asemenea citit de la tastatura).
	Am parcurs vectorul de campuri, iar pentru fiecare camp am verificat
	daca acesta este primul cuvant in text (caz in care l-am inlocuit cu
	valoarea inserata). Am cautat in continuare in mesaj aparitia campului
	si in cazul in care acesta este gasit, se verifica daca campul
	respectiv este un cuvant propriu zis
	(si nu face parte dintr-un alt cuvant) folosind functia check_word
	care verifica daca caracterul dinaintea
	campului si caracterul imediat de dupa camp sunt delimitatori.
	In cazul in care sirul gasit nu este inclus intr-un alt cuvant,
	se aplica functiile strdel si strins prin care
	este sters campul initial si este inserata valoarea corespunzatoare.
	Se reia apoi cautarea acestui camp in text pana cand acesta 
	nu mai poate fi gasit.
	Programul a fost implementat in decurs de 3 ore, iar rezolvarea
	erorilor de memorie a durat 12 ore.

====================

PasswordGenerator:
	Am citit seed-ul si numarul de caractere si am generat sirul
	folosind functia generare_paola. Am generat apoi cate un numar
	de la 0 la 2 folosind functia rand() si seedul initial si am 
	aplicat codificarea 0, 1 sau 2. La codificarea 0, a fost necesar
	sa tratez cazul in care frecventa unui caracter este format dintr-un
	numar de mai mult de o cifra caz pentru care am luat sir de caractere
	auxiliar in care am retinut fiecare cifra a frecventei caracterului.
	Programul a fost implementat in decurs de 4 ore iar 
	rezolvarea erorilor de memorie a durat 10 ore. 
	
