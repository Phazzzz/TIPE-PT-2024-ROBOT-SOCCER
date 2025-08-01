

| Pin                 | Fonction                                                                                              | Couleur fil | Nom Pin     |     |
| ------------------- | ----------------------------------------------------------------------------------------------------- | :---------- | ----------- | --- |
|                     |                                                                                                       |             |             |     |
| Broche Interruption |                                                                                                       |             |             |     |
| 2                   | Encodeur 1A                                                                                           | Blanc<br>   | interrupt 0 |     |
| 3                   | Encodeur 1B                                                                                           | Jaune       | interrupt 1 |     |
|                     | les pins de enco 1 ont temporairement été branché sur les pins de enco 2 et enco 2 n'est plus branché |             |             |     |
| 18                  | Encodeur 2A                                                                                           | Blanc       | interrupt 5 |     |
| 19                  | Encodeur 2B                                                                                           | Jaune       | interrupt 4 |     |
|                     |                                                                                                       |             |             |     |
| 20                  | Encodeur 3A                                                                                           | Blanc       | interrupt 3 |     |
| 21                  | Encodeur 3B                                                                                           | Jaune       | interrupt 2 |     |
|                     |                                                                                                       |             |             |     |
|                     |                                                                                                       |             |             |     |
| PWM                 |                                                                                                       |             |             |     |
| 8                   | Vitesse moteur 1                                                                                      | Vert        | D3 (Solo)   |     |
| 10                  | Vitesse moteur 2                                                                                      | Blanc       | D3 (Duo)    |     |
| 12                  | Vitesse moteur 3                                                                                      | Jaune       | D1 (Duo)    |     |
|                     |                                                                                                       |             |             |     |
| Digital             |                                                                                                       |             |             |     |
| 50                  | Sens moteur 1                                                                                         | Jaune       | D2 (Solo)   |     |
| 51                  | Sens moteur 2                                                                                         | Vert        | D2 (Duo)    |     |
| 52                  | Sens moteur 3                                                                                         | Orange      | D0 (Duo)    |     |


## Formules 

- vitesse au sol : v = $\omega \times 2 \pi \times Rayon$


## Valeurs expérimentales
#### Masses : 

Chassis bas + chassis haut = 248g
Supports moteurs : 3 x 50g = 150g
entretoises : 6 x 12g = 72g


#### Expérience moteur :

|                    |                       |                                                                           |                                                         |                                      |
| ------------------ | --------------------- | ------------------------------------------------------------------------- | ------------------------------------------------------- | ------------------------------------ |
|                    |                       |                                                                           |                                                         |                                      |
| Moteur :           | Temps Caractéristique | Mesure                                                                    | Vitesse au sol                                          | K                                    |
| Moteur 1           | T1 =                  |                                                                           |                                                         |                                      |
| Moteur 2           | T2 =                  |                                                                           |                                                         |                                      |
| Moteur 3           | T3 = 0.055s           | 164ms pour aller à 191 tr/min, consigne : 255 bits ($\leftrightarrow$ 5V) | $v3 = \frac{191 \times 2 \pi \times 29}{60} = 580 mm/s$ | $K = \frac{580}{255} = 2.27 mm/tick$ |
|                    |                       |                                                                           |                                                         |                                      |
| Résistance interne |                       |                                                                           |                                                         |                                      |
| Moteur de secours  | R = 1.8 ohm           |                                                                           |                                                         |                                      |

##### Cas :
- 2 moteurs à la même vitesse dans le même sens : RAS
- 2 moteurs à deux vitesses 
### Expérience Drivers
#### Table logique driver moteur et bit de seuil 


| MOTEUR 1                                     | Sens     | PWM     |
| -------------------------------------------- | -------- | ------- |
| Rotation Horaire vitesse maximale            | LOW      | 255     |
| Rotation Horaire vitesse minimale            | LOW      | 38      |
|                                              |          |         |
| Rotation anti-Horaire vitesse maximale       | HIGH     | 0       |
| Rotation anti-Horaire vitesse ***minimale*** | HIGH     | 245     |
|                                              |          |         |
|                                              | **Sens** | **PWM** |
| MOTEUR 2                                     | LOW      |         |
| Rotation Horaire vitesse maximale            | LOW      |         |
| Rotation Horaire vitesse minimale            |          |         |
|                                              | HIGH     |         |
| Rotation anti-Horaire vitesse maximale       | HIGH     |         |
| Rotation anti-Horaire vitesse ***minimale*** |          |         |
|                                              |          |         |
| MOTEUR 3                                     | **Sens** | **PWM** |
| Rotation Horaire vitesse maximale            | LOW      | 255     |
| Rotation Horaire vitesse minimale            | LOW      | 60      |
|                                              |          |         |
| Rotation anti-Horaire vitesse maximale       | HIGH     | 0       |
| Rotation anti-Horaire vitesse ***minimale*** | HIGH     | 236     |

----------------------

### Valeurs calculés :

- (Fiche technique ) Vmax moteur = 295 tr/min
- Vitesse max du moteur à 5V : Vmax théorique = $\frac{5}{6} \times \frac{295 \times 2 \pi \times 29}{60} = 746 mm/s$
- Rendement : r = $\frac{V,max,mot,3}{Vmax,théorique} = \frac{580}{746} = 0.77$ (Nota bene : calcul réalisé avec la vitesse max expérimentale du moteur 3)

#### Encodeurs :

- Chgmt d'états : 544 tick/tr (fiche technique)

- Résolution = $\frac{2\pi}{544} = 0.01$  rad/tick
- Précision = $Périmètre*Résolution = 29*0.01 = 0.029 \approx 0.03$ **mm/tick 

- ***Vitesse au angulaire*** : $v = \frac{d}{t} = \frac{2\pi\times ticks \times 1000}{dt}$ rad/seconde
- ***Vitesse au sol*** : $v = \frac{d}{t} = \frac{2\pi\times ticks \times 1000}{dt}$ rad/seconde




-----


### Equations :


	Angle : a = arctan(dy/dx)

	A : dx

	BD : dx*cos(a) + dy*sin(a)

	BG : dx*cos(2*a) + dy*sin(2*a)


