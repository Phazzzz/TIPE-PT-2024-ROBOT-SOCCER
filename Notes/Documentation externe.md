

#### Ressource général 

[3D find it , le trouve tout de la 3D](https://www.3dfindit.com/fr/)

[Référence language Arduino](https://www.arduino.cc/reference/en/)

[Github Arduino](https://github.com/arduino/docs-content)https://fr.overleaf.com/learn/latex/List_of_Greek_letters_and_math_symbols

[Référence Latex](https://fr.overleaf.com/learn/latex/List_of_Greek_letters_and_math_symbols)
#### Cours 


##### [Excellent Tuto asservissemennt vitesse](http://www.ferdinandpiette.com/blog/2012/04/asservissement-en-vitesse-dun-moteur-avec-arduino/)


[Cours complet conception robot holonome](https://www.studica.co/resources-4)

[Explication déplacement Holomnique Facile](https://www.servomagazine.com/magazine/article/a-look-at-holonomic-locomotion)

[Fonctionnement Encodeur](https://www.generationrobots.com/blog/fr/encodeurs-robotique-mobile/#:~:text=Un encodeur est un dispositif,chacune des roues du robot.) 

[Dynamics of a four-wheeled mobile robot with Mecanum wheels](https://onlinelibrary.wiley.com/doi/full/10.1002/zamm.201900173)


#### Exemple autre projet

[Projet Robot Soccer](https://robot-soccer-kit.github.io/hardware-robots#motors-and-wheels)
[Modèle 3D Robot Soccer](https://cad.onshape.com/documents/c5fe05581d14c59bfb08f79e/w/a8cb82e3a358c0b06e1cbf91/e/f45372d8263c18466905bd9b)


##### Site commerce : 

- [RobotShop](https://www.servomagazine.com/magazine/article/a-look-at-holonomic-locomotion)



#### Design electronique

Protheus Visual Designer for Arduino

[https://www.multipower.fr/boutique/visual-designer/](https://www.multipower.fr/boutique/visual-designer/)

https://www.multipower.fr/software/cao_proteus/proteus-visual-designer/

[https://www.theengineeringprojects.com/2021/03/arduino-mega-2560-library-for-proteus-v2-0.html](https://www.theengineeringprojects.com/2021/03/arduino-mega-2560-library-for-proteus-v2-0.html)


### [TUTO SIGMA ASSERVISSEMENT POSTION/VITESSE](https://blog.3sigma.fr/arduino/tutoriel-arduino-asservissement-en-vitesse-dun-moteur-a-courant-continu/)
#### Librairie Arduino digitalWrite fast :

- "Vous aurez peut-être remarqué l’utilisation de la fonction **digitalReadFast2()** pour lire le niveau des entrées codeur, au lieu de la fonction standard **digitalRead()**. Cette fonction, issues de la librairie **digitalWriteFast** (téléchargeable à l’adresse [http://www.3sigma.fr/telechargements/digitalWriteFast.zip](http://www.3sigma.fr/telechargements/digitalWriteFast.zip)) permet d’améliorer la rapidité de lecture et d’écriture des entrées digitales pour minimiser le temps passé dans la routine d’interruption (et donc rendre la main plus vite à la boucle de calcul principal). Pour utiliser cette bibliothèque dans votre code, vous devez faire deux choses simples"

For a 16 MHz Uno digitalWrite() is speed up from 5.8 µs to 125 ns, able to generate a 4 MHz signal instead of 86 kHz. [SOURCE CHIFFRE](https://github.com/ArminJo/digitalWriteFast)
#### Utilisation de delay() :

Pour que cela fonctionne correctement, ce code doit être exécuté à la cadence fixe de 0.01 s. L’utilisation de la fonction **delay()** pour faire ça est une **mauvaise** méthode. En effet, vous pourriez penser écrire le code suivant :

|                                                    |                                                                                                                                                                          |
| -------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| 1<br><br>2<br><br>3<br><br>4<br><br>5<br><br>6<br> | `void` `loop() {`<br><br>  `// Traitements divers`<br><br>  `// Lecture d'entrées + calculs par exemple`<br><br>  `// Attente de 10 ms`<br><br>  `delay(10);`<br><br>`}` |

Le problème est que les « traitements divers » vont prendre un certain temps, inconnu (T) et potentiellement variable (dans le cas où ils incluent des instructions conditionnelles). Par conséquent, la boucle sera exécutée toutes les T+0.01 s et non pas toutes les 0.01 s, et la mesure de la vitesse de rotation sera fausse.

La bonne méthode consiste à utiliser un timer du microcontrôleur pour générer une interruption toutes les 0.01 s. Vous pouvez utiliser pour cela la bibliothèque FlexiTimer2 (téléchargeable ici: [http://www.3sigma.fr/telechargements/FlexiTimer2.zip](http://www.3sigma.fr/telechargements/FlexiTimer2.zip)). Après l’avoir décompressée, il faut la placer dans le sous-répertoire « librairies » de l’installation de l’environnement de développement Arduino et ajouter au début du programme la ligne :


Enfin, il faut ajouter les deux lignes suivantes dans la fonction **startup()** :

|   |   |
|---|---|
|1<br><br>2|`FlexiTimer2::set(10, 1/1000., isrt);` `// résolution timer = 1 ms`<br><br>`FlexiTimer2::start();`|

La première ligne crée une interruption qui se produit toutes les 10 ms (avec une résolution de 1 ms), ce qui exécute alors la fonction **isrt()** (contenant le code permettant de calculer la vitesse de rotation et de réaliser l’asservissement de vitesse). La seconde ligne démarre ce timer.

------

[attachInterrupt function reference](https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/)
### Interrupt Numbers

Normally you should use `digitalPinToInterrupt(pin)`, rather than place an interrupt number directly into your sketch. The specific pins with interrupts and their mapping to interrupt number varies for each type of board. Direct use of interrupt numbers may seem simple, but it can cause compatibility trouble when your sketch runs on a different board.

However, older sketches often have direct interrupt numbers. Often number 0 (for digital pin 2) or number 1 (for digital pin 3) were used. The table below shows the available interrupt pins on various boards.

Note that in the table below, the interrupt numbers refer to the number to be passed to `attachInterrupt()`. For historical reasons, this numbering does not always correspond directly to the interrupt numbering on the ATmega chip (e.g. int.0 corresponds to INT4 on the ATmega2560 chip).


| BOARD    | INT.0 | INT.1 | INT.2 | INT.3 | INT.4 | INT.5 |
| -------- | ----- | ----- | ----- | ----- | ----- | ----- |
| Mega2560 | 2     | 3     | 21    | 20    | 19    | 18    |
|          |       |       |       |       |       |       |

For Uno WiFi Rev2, Due, Zero, MKR Family and 101 boards the **interrupt number = pin number**.

----------------

## Fonction map()

Re-maps a number from one range to another. That is, a value of **fromLow** would get mapped to **toLow**, a value of **fromHigh** to **toHigh**, values in-between to values in-between, etc.

Does not constrain values to within the range, because out-of-range values are sometimes intended and useful. The `constrain()` function may be used either before or after this function, if limits to the ranges are desired.

**Note that the "lower bounds" of either range may be larger or smaller than the "upper bounds" so the `map()` function may be used to reverse a range of numbers, for example**

### `y = map(x, 1, 50, 50, 1);`


-------


### Broches analogiques Arduino Mega 2560 Rev3

Mega 2560 dispose de 16 entrées analogiques, chacune pouvant fournir une mesure d’une résolution de 10 bits (càd sur 1024 niveaux soit de 0 à 1023) à l’aide de la très utile fonction analogRead() du langage Arduino. Par défaut, ces broches mesurent entre le 0V (valeur 0) et le 5V (valeur 1023), mais il est possible de modifier la référence supérieure de la plage de mesure en utilisant la broche AREF et l’instruction analogReference() du langage Arduino.



---------------------------


https://www.comptoir-du-cable.com/content/7-calcul-section-cable-electrique#tableau_cinq

![[Longueur maxi en câble cuivre alimentation monophasé 230V.png]]