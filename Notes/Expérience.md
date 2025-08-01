

#### Expérience 1 : Précision de déplacement du robot

Réaliser plusieurs motif cyclique de différentes complexité, ainsi en mesurant l'écart entre le point de départ et d'arrivé on peut définir une précision 

- Un carré, avance, tourne, avance, etc.
- un triangle équilatérale, selon les axes des moteurs 
- un cercle 
- le robot translate en décrivant un cercle tout en tournant sur lui même.

-----



#### Expérience 1 : V2 de secours : Précision déplacement selon l'axe de 1 moteur 

- Calcul de consigne à partir de la partir théorique 
- Donner ces vitesses en consigne durant un temps définie 
- Mesurer la distance parcourut par le robot 
- Comparaison avec la distance théorique parcourut par le robot 

###### Bonus : Vérifier la vitesse obtenue par les encodeurs à fin de validé leurs fonctionnement

Hypothèse : 
- Le robot va parfaitement droit 
- On néglige la baisse de tension de la batterie


###### Résultats expérience :

|             | bit      | bit      |          |       |          |     |
| ----------- | -------- | -------- | -------- | ----- | -------- | --- |
| N°          | Moteur 1 | Moteur 2 | Distance | Temps | Statut   |     |
| 1           | 240      | 100      | 130cm    | 5s    | Invalide |     |
| 2           | 240      | 110      | 145cm    | 4.8s  | Invalide |     |
| 3           | 250      | 110      | 148cm    | 5s    | Valide   |     |
| 4           | 250      | 110      | 148cm    | 5s    | Valide   |     |
| 5 (chambre) | 250      | 110      | 110cm    | 3s    | Valide   |     |

Mesure encodeur moteur 1 : 11.55 rad/s
Revêtement : parquet synthétique 

###### Calcul exp.  :
V : Vitesse du robot 

Pour les expérience 3 et 4 :
$$
V = \frac{148}{5} * 10 = 296 mm/s
$$
Pour l'expérience 5 :
$$
V = \frac{110}{5} * 10 = 367 mm/s
$$
D'après l'étude cinématique :

- Pour les expérience 3 et 4 :
 $$
\begin{split} 
\omega = \frac{\sqrt{3}}{29\times2}\times V  \\ \\
A.N : \omega =   \frac{\sqrt{3}}{29\times2}\times 296 = 8.84 rad/s
\end{split}
$$
- Pour l'expérience 5 :
$$
\begin{split} 
A.N : \omega =   \frac{\sqrt{3}}{29\times2}\times 366 = 11 rad/s
\end{split}
$$


##### Validation Vidéo :

- Moteur 1 :
	- Début : 5,41s
	- Fin : 5,84s 
	- Durée : 0,43s
	- $\omega1 = \frac{2\pi}{0.43} = 14,61$ rad/secondes

	- Début : 7,07s
	- Fin : 7,50s 
	- Durée : 0,43s
	- $\omega1 = \frac{2\pi}{0.43} = 14,61$ rad/secondes


- Moteur 3 :
	- Début : 7,19s
	- Fin : 7,62s 
	- Durée : 0,43s
	- $\omega1 = \frac{2\pi}{0.43} = 14,61$ rad/secondes 



----------------------------------------------------



#### Expérience 2 : Mesure : évolution de la vitesse maximale / consigne

Tracé : 
- Ordonnée : Vitesse maximale 
- Abscysse : consigne en % (consigne/255*100)
- Pas de la consigne : 25 bits

Comparer 2 test : 
- Test 1 : avec 1 moteur sollicité
- Test 2 : avec 2 moteurs sollicités


----


#### Expérience 3 : Encodeurs

- ###### 1 Moteur en fonctionnement :
	- Mesure : 
		- Début : 2.31
		- Fin : 2.58
	- $\rightarrow \omega = \frac{2\pi}{0.27} = 23.27$ rad / seconde

- Valeur mesuré par l'encodeur : 23 rad/s
- Conclusion : Validé

- ###### 2 Moteur en fonctionnement :
	- Mesure : 
		- Début : 3.26
		- Fin : 3.55
	- $\rightarrow \omega = \frac{2\pi}{0.29} = 21.66$ rad / seconde

	- Valeur mesuré par l'encodeur : 11.55 rad/s
	- Conclusion : Incohérent 
		- Hypothèse : Trop d'interruption donc le comptage des ticks est faussé








---


#### Mots clés

[[Documentation externe]]
[[Fiches Techniques]]
[[Note de code]]
[[Note de suivie]]
[[Fiches Techniques]]
