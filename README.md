Schedule - Linux

sintaxa : ./schedule dd/mm/yyyy (data curenta)

La rulare se vor afisa obiectivele pentru ziua curenta:

	ASTAZI
- <OBJ1>
- <OBJ2>
- <...>

In cazul in care nu sunt obiective se afiseaza :

	ASTAZI
    NIMIC PROGRAMAT

De asemenea, tot la rulare vor fi sterse si obiectivele
din zilele ce au trecut. Introducerea datei gresite la 
rulare poate duce la pierderea unor informatii relevante.

Programul asteapta input pana la primirea comenzii EXIT.

Comenzi input:

	ADD dd/mm/yyyy "obiectiv / nume activitate" 
	- sirul de caractere trebuie pus intre ghilimele
	si data trebuie sa respecte formatul. Lungimea 
	sirului trebuie sa fie de maxim 256 de caractere
	- adauga evenimente/ obiective in ziua specificata

	CLEAR dd/mm/yyyy - sterge toate evenimentele din
	ziua specificata

	CLOSE - afiseaza obiectivele din urmatoarele 7 
	zile

	COMMON -M <mm> - afiseaza obiectivele ce se repeta
	in luna <mm> si zilele acestora

	COMMON -D <dd>-<dd>  -afiseaza obiectivele ce se
	repeta in intervalul de zile (trebuie sa apartina
	aceleiasi luni) si zilele lor

	COUNT dd/mm/yyyy - numara obiectivele din data
	specificata

	DEL dd/mm/yyyy <N> - sterge al <N> obiectiv din
	ziua specificata

        EXIT  -  inchide programul

	FULL CLEAR - sterge toate obiectivele din toate datele

	MONTH <mm> - afiseaza zilele ce au activitati din
	luna <mm>

	MOVE dd/mm/yyyy DD/MM/YYYY - muta toate obiectivele de pe data
	dd/mm/yyyy pe data DD/MM/YYYY

	MOVE_ONLY <N> dd/mm/yyyy DD/MM/YYYY - muta doar al <N>
	obiectiv de pe data dd/mm/yyyy pe data DD/MM/YYYY

	PATH /home/<user>/.../.../<directorul executabilului>
	-este necesar la prima rulare a programului sau cand 
	executabilul este mutat. Mutarea executabilului poate
	duce la pierderea informatiilor precedente.

	SHOW dd/mm/yyyy - afiseaza obiectivele din 
	ziua specificata
	

Participanti : David Andrei-Gabriel : ADD CLEAR CLOSE COMMON EXIT MONTH
	       Ionel Sebastian : SHOW PATH MOVE FULL CLEAR DEL + (main)
	       
Concepte acoperite : -alocare dinamica 
		     -pointeri
		     -operatii pe biti
		     -optimizarea codului
	     
	     
