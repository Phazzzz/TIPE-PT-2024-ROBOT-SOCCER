


Expérience : Précision de déplacement du robot 

### Déroulé : **Temps totale : (15min)**

-          Présentation du contexte **(1min)**

-          Description du robot (Diagramme de définitions, schéma électrique, etc) **(3min)**

-          Cinématique du robot omnidirectionnel **(4min)**

-          Présentation du code informatique **(3min)**

-          Compte rendu de l’expérience **(3min)**

-          Conclusion **(1min)**

##### Bonus :

-          Conception des supports moteurs

-          Calcul d’asservissement ? (PID)





### Présentation du contexte 

- Présentation (rapide) Robocup 
- Diagramme des cas d'utilisations
	- Se déplacer sur le terrain
		- Ne pas sortir des limites du terrain
		- Déplacer la balle
	- Intercepter la balle 
	- Tromper l'adversaire
	- Tirer la balle 
	- Faire une passe à son coéquipier
- - Problématique 
	- Comment tirer un pénalty capable de tromper le gardien avec un robot soccer ?
-  Identification des besoins
	- Agilité 
	- rapidité
- Cahier des charges



### Présentation du robot 

- Choix de constructions
	- Déplacement Holomnique 
	- Robot à trois roues 
- Architecture générale 
	- Diagramme d'exigence
	- Diagramme de bloc interne



### Cinématique du robot omnidirectionnel

- Les objectifs de l'études
- Paramétrage 
- Etude de la translation sur x0


### Expérience 


- Déplacement du robot selon l'axe d'un moteur  
- Consigne à envoyer au moteur issue de la partie théorique 
- Expérience 1 : mesure de vitesse robot
	- Protocole
		- Faire avancer le robot sur 148cm (limite de la longueur du cable entre l'Arduino et l'ordi) et mesurer le temps que met le robot à parcourir la distance 
	- Hypothèses et incertitude
	- Résultat
- Expérience 2 : mesure rotation des roues 
	- Protocole
	- Résultat

### Présentation du code informatique 
##### Qu'est ce qu'il fait  ?
-    Initialisation 
	- Définition des constantes 
- Pilotage des moteurs 
- Encodeurs 


### Résultat d'expérience 


### Les petites expériences 

- Note de code#Table logique driver moteur|Table de consigne des drivers moteurs
- Note de code#Valeurs expérimentales#Valeurs calculés|Constantes fonction de transfère moteurs
- Note de code#Encodeurs|Constantes fonction de transfère encodeurs
- Note de code#Valeurs calculés|Comparaison vitesse max théorique et vitesse max mesurée
	- Vérification du cahier des charges 


### Les problèmes 

- Sous dimensionnement de la chaine de puissance :
	- Cables électriques
		- voir Diagramme
	- Driver
		- Comparaison du courant entre l'ancien et le nouveau :
	- Abaisseur de tension
		- Courant
	- Batterie 
		- Calcul de puissance :
			- Consommation moteur : $P = tension \times courant = 6 \times 15 = 90Watt$
			- Batterie : 24,4Wh -> $24,4\times3600 = 87840 Watt/s$

- Moteur qui ne fonctionne pas 
	- Difficile à tourner 
		- Couple statique très élevé sans raison 
- 


Consigne
T_(1 tour)
ω

### Temps additionnel 

- Détail des calcul de la partie théorique 

- Problèmes rencontrés 
	- Transmission électrique 
	- moteur

- Explication Omniwheels
	- Avantage 
		- Manoeuvrabilité 
	- Inconvénient 
		- Manque d'adhérence 
		- Vibration 
			- Améliorer en mettant plus de petit rouleaux et plus de ranger  
		- Besoin d'un couple plus important qu'un système classique
			- Exemple : tourner une poigné mais en y mettant de l'angle 
	- Omni à 3 roues
		- + Stable (3 points = 1 plan)
		- + simple à réaliser (mais un peu plus dure à coder)
	- Omni à 4 roues :
		- Mécanisme plus complexe (mais un peu plus simple à coder)
			- 4 moteurs à gérer
			- Problème de planéité 
			- Encombrement
		- Amélioration de l'adherence 
		- Amélioration du couple 
			- + de moteur = + de puissance
			- Permet d'utiliser plus de moteur pour un même mouvement 


- Modélisation des supports de drivers et les supports moteurs
## Attendus pédagogique

##### Objectif principaux :

- maintenir un questionnement scientifique sur toute la durée de son projet 

-  mettre en relief les choix qu’il aura dû faire au cours de son étude, la cohérence, ainsi que la densité du travail réalisé

- à clairement faire apparaître l’originalité de sa contribution par rapport à celles des autres membres de son groupe dans le cas d’un projet à plusieurs membres.



## Attendus de présentation

- **Il est fortement recommandé aux candidats de placer leur numéro d'inscription en première page, et de numéroter toutes les diapositives, afin de faciliter l’entretien avec les examinateurs.**

- format PDF2 
- ne doit pas dépasser 5 Mo.
- Il ne pourra pas contenir de vidéos, de fichiers audio, ni d'animations notamment du type Powerpoint
- Il n'y a pas de nombre limité de pages ni de mots
	- (Conseil) : au grand maximum 10 lignes par diapositive
- adjoindre autant que possible une iconographie adaptée (graphiques, schémas, photographies, images) venant en complément du texte et de l'exposé associé.
	- Toute illustration extraite d’une source externe devra être référencée, par exemple en bas de diapositive, en bonne et due forme afin qu’il n’y ait pas d’ambiguïté sur son origine.


Spécifique à chaque membre d'un éventuel groupe, le support de présentation doit être propre à chaque candidat et correspondre à son objectif individuel. Seul un petit nombre de diapositives peuvent introduire ou reprendre le projet du groupe.


Cette présentation doit être téléversée sur le site SCEI rubrique SCEI>Mon_Dossier>TIPE. L'absence de dépôt pourra conduire à l’attribution de la note zéro à l’épreuve. Dans tous les cas, le candidat devra vérifier la présentation téléversée afin de s’assurer qu’elle pourra être ouverte et utilisée lors de son passage en salle d’oral. Pour ce faire, il est conseillé de l’afficher à partir du serveur SCEI.

###### Programme informatique : 
Si le candidat a développé des programmes informatiques, il devra apporter en double exemplaire les listings correspondants sur support papier. Ces listings seront également inclus en documents annexes à la présentation (en aval de la conclusion) mais ne seront pas présentés formellement durant l’exposé du candidat. Ils pourront faire l'objet de questions spécifiques lors de la phase d’échange avec les examinateurs. Il est fortement recommandé d’afficher ces listings sur fond blanc pour être plus lisibles


##### Critères d'évaluation 

- Potentiel Scientifique :
	- Pertinence et justesse scientifiques
	- Appropriation et capacité à apprendre
	- Ouverture & Curiosité
- Démarche Scientifique :
	- Questionnement et Méthode 
	- Résolution de problème 
	- Communication - Présentation - Échange





##### Référence illustration

Match robocup junior : https://www.iceberg-robots.de/2019/08/27/robocup-german-open-2019/

Match robocup : https://www.robocup.org/leagues/19

robocup match humanoide : https://www.indramat-us.com/robocup/


robocup-junior1-1247468535 : https://de.mathworks.com/academia/student-competitions/robocup-junior.html

maxresdefault-935886106.jpg : https://www.youtube.com/watch?v=gZ-AAXpM4U4

Logo Robocup : https://robocuprussiaopen.ru/en/events/russiaopen/2019/

Schema déplacement robot omni : https://www.servomagazine.com/magazine/article/get-rolling-with-omni-directional-wheels

Comparaison des roues omni : https://www.omnitrack.com/product-category/wheels-castors/omniwheels/

Robot omni 4 roue : https://www.aliexpress.com/item/MT200S-4WD-100mm-Omni-Wheels-Robot-Car-Chassis-Stainsteel-Frame-Big-Power-Motor-For-DIY-Toy/32841507269.html


Roue mecanum : https://www.artstation.com/marketplace/p/rPw2/3d-mecanum-wheel

L7806 : https://thaipick.com/product/lazada/2221014

Jumper Wire : https://udvabony.com/product/male-to-female-jumper-wire-single/

Breadboard : https://cukii.com/product/quality-solderless-breadboard-400-tie-point-pcb-breadboard-for-arduino-interconnect-any-components-with-20-29-awg-(0.3-0.8)-wire

Moteur : https://www.gotronic.fr/art-motoreducteur-34-1-encodeur-rs003-24295.htm

Batterie : https://rcsearch.info/-c11374

Abaisseur de tension : https://www.alibaba.com/product-detail/Factory-Tobsun-12v-24v-To-5v_1600627269932.html

Fil Tuofeng : https://www.carousell.sg/p/tuofeng-22-gauge-pvc-electrical-wire-30-meter-reel-2-pin-extension-cable-12v-24v-dc-cable-wire-for-single-led-strip-light-1098966592/

L9910 :https://gethacking.com/products/dc-stepper-motor-driver-board

ZK-5AD : http://aquaphoton.net/product/zk-5ad-5a-dual-dc-motor-drive-module/





