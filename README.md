# Grupa5
Nedžla Sitnić, Belma Dedić, Mus'ab Kozlić

 Tema naše grupe je Rubikova kocka - igrica. 
 Svaka strana kocke je predstavljena 2D nizom. Svaku od stranica korisnik vidi kao tabelu sastavljenu od kolona i redova. Da bi korisnik osjetio slast igranja, potrebno da okreće kolone prema gore ili dole, a redove lijevo ili desno, sve dok ne sklopi čitavu kocku, tj. dok svaka strana ne bude ispunjena tabelom odgoavarajućeg broja (npr. stranica na kojoj broj 6 ispunjava sve njene kolone i redove). 

 Prilikom pokretanje programa, korisniku se ispisuje meni sa ponuđenim mogućnostima (let's play, load game, save game, score board, instructions, arcade, arcade board, credits i exit). 
 Prilikom odabira Let's play, korisniku se ispisuje šema kocke gdje mu se prikazuje položaj kocke, tj. može tačno vidjeti gdje je koja stranica kocke. Ispod toga je Rubikova kocka sa izmiješanim brojevima od 1 do 6. Od korisnika se traži da unese prvo stranicu na kojoj želi izvršiti pokret. Nakon toga, odabire da li želi okrenuti kolonu ili red. Ukoliko odabere kolonu, potrebno je da odabere da li će je okrenuti gore ili dole. Ukoliko odabere red, onda je potrebno da odabere da li će ga okrenuti lijevo ili desno. Korisnik ima neograničen broj pokreta. Ukoliko složi čitavu kocku, na ekranu će mu se ispisati pehar kao znak pobjede. Tražit će se od korisnika da unese svoje ime koje će se spremiti u score board zajedno sa utrošenim vremenom za rješavanje kocke.
 U slučaju da korisnika pomete nešto od obaveza, nudi mu se mogućnost da spremi sve što je uradio opcijom Save game i unosom željenog imena datoteke u koju će se spremiti. Kada završi s obavezama, može se ponovo vratiti i nastaviti se zabavljati, a ujedno i razvijati svoje sposobnosti brzog razmišljanja i logike. Da bi nastavio započetu igru, potrebno je samo da odabere opciju Load game i unese naziv datoteke u koju je spremio. Pri samom odabiru opcije Load game, korisniku se ispisuje lista svih spremljenih datoteka kako bi lakše pronašao svoju, što je veoma korisno u slučaju da zaboravi ime iste. 
Pri odabiru opcije Score Board, korisnik će moći vidjeti sva imena korisnika sa njihovim ukupnim vremenom rješavanja kocke rangiranih prema vremenu, idući od korisnika sa najmanjim utrošenim vremenom do korisnika sa najviše utrošenog vremena za rješavanje.
 Ukoliko korisnik igra igricu po prvi put i nije siguran na koji način treba da je igra, tu je opcija Instructions. Ona će korisniku detaljno objasniti šta i kako treba da radi, ispisujući mu na ekran upute igranja.
 Međutim, pripremili smo nešto i za one malo uspješnije igrače. Tu je Arcade mode u kojem je igrač ograničen, za razliku od prethodnog mode-a. Korisnik ima samo 20 pokreta za slaganje. Za svaki uspješno složen red ili kolonu odabrane stranice za pokret igrač dobija 10 bodova. Ukoliko završi 20 pokreta a ne složi ništa, završava igru sa 0 bodova. Osim toga, korisnik ne može dva puta zaredom pomjeriti istu stranu. Također, prvo pomjera kolonu, zatim red i tako redom. Dakle, igrač ne može pomjeriti dva puta za redom istu stranicu, kao ni dva puta kolonu ili red. U Arcade Board-u su rangirana sva imena igrača sa njihovim osvojenim bodovima počevši od igrača sa najviše ostavrenih bodova prema igraču sa najmanjim brojem ostvarenih bodova. Igrači čiji je broj bodova jednak nuli se ne smješta u arcade board.
 Ukoliko korisnik želi da sazna ko je zaslužan za igricu, potrebno je samo da odabere opciju Credits u glavnom meniju. Na ekranu će mu se ispisati imena i prezimena osoba koje su učestvovale u kreiranju igrice. Osim toga, tu će moći vidjeti tačno koja je osoba bila zadužena za koji dio u izradi. Ukoliko ima nekih pitanja, kritika ili pohvala, tu su naši mailovi pomoću kojih nas uvijek može kontaktirati.
 Ukoliko, pak, korisnik ne želi više igrati ili je završio za igricu, te želi izaći potrebno je da odabere opciju Exit.

Obavezni elementi projekta:
1. Barem 3 klase. 
   Radi bolje preglednosti i lakšeg pronalaženja bug-ova smo projekat rasporedili na 11 klasa.
2. Enumeracija
   Enumeraciju smo iskoristili za smjer okretanja kolona i redova (NONE = 0, RIGHT, LEFT, UP, DOWN) u klasi Pokret. Prilikom pokretanja, u konstruktoru se smjer postavlja na NONE. Prilikom igranja, igrač odabire smjer unosom broja, a nakon toga u ispisu se uneseni smjer ne ispisuje brojem, nego riječima: RIGHT, LEFT, UP ili DOWN.
3. Pametni pokazivač
   Pametne pokazivače smo upotrijebili za rangiranje, odnosno sortiranje po vremenu u Score Board-u, kao i sortiranje po bodovima u Arcade Board-u.
4. Iznimke
   Iskoristili smo ih u klasi SaveLoad kada kod upisa tražene datoteke korisnik unese nepostojeću datoteku i u Source-u prilikom odabira opcije u meniju. Također smo ih koristili i u klasi Pokret u arcade mode-u čime smo spriječili unos dvije iste stranice zaredom.
5. Virtualna funkcija
   Virtuelne funkcije smo iskoristili u klasi Pokret, kod pravljenja odvojenog načina igranja, tj. arcade mode-a, koji je zasnovan na orginalnom, standardnom načinu.
6. Preopterećeni operatori
   Koristili smo ih u klasi ScoreBoard za unos i ispis imena igrača.
7. Nasljeđivanje
   Nasljeđivanje smo koristili u score board-ima za rangiranje igrača u ScoreBoardIspis klasi, ali također i za rangiranje za arcade mode u klasi ScoreBoardArcade. Osim toga, iskoristili smo ga još i u klasi Pokret za pomjeranje kolona i redova u arcade mode.
8. Rad sa datotekama
   Datoteke smo koristili u više navrata. Možda najznačajniji dio gdje smo ih koristili je u klasi SaveLoad, gdje smo u posebne datoteke spremali nezavršene igre, tj. u datoteku se spremaju pokreti, strane kocke i vrijeme igranja igrača. Zatim u jedno datoteku se spremaju sve postojeće datoteke kako bi ispisali listu postojećih datoteka korisniku prilikom odabira opcije Load. Također smo ih koristili za opcije Instructions i Credits, kao i za spremanje score boarda za oba moda.
9. Meni
   Glavni meni se ispisuje korisniku prilikom samog pokretanja programa, gdje se od njega traži da unese željenu opciju. Prilikom igranja, korisniku se ispisuju i meniji za odabir pomjeranja kolone ili reda, kako u običnom, tako i u arcade mode-u.

 Time smo uspješno završili projekat. Pažljivo smo vodili računa o svim mogućnostima prilikom pomjeranja kolona i redova, kao i uništavanju mogućnosti nemoguće kocke. Na kraju smo zaključili da se svaki put, na kraju, trud isplati. Uspjeli smo nadmašiti naša očekivanja. Nadamo se da smo uspjeli zadovoljiti i Vaša očekivanja. 
Želimo Vam mnogo sreće prilikom igranja i rješavanja ove naše Rubikove kocke!