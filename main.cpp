int palier = 1; // Cette variable permet de compter le nombre de fois, où l'on va diminuer l'expi une fois qu'on sera passé dans l'état inslufation 
int expi = 1;   // Cette variable est la valeur qu'on renvoie au moniteur, elle depend de la valeur pprox et de l'état dans lequel on est
bool inslufation = false; // Cette variable considère, si nous sommes dans l'état inslufation

while (DEMO == true) {

  int defaultDelay = 50;        // On met un delay à 50 ms pour pas faire trop chauffer l'arduino, histoire qu'il se repose entre chaque tour de boucle.
  
  if (inslufation == false) { // Tant que nous ne sommes pas dans l'inslufation, la courbe expi et pprox se suivent avec un coeff de 20
    expi = pprox * 20;
  } else { // Nous sommes dans l'état inslufation
    palier += 1;         // On augmente le palier de 1
    expi -= 120;         // On decremente l'expi par palier de 120
    defaultDelay = 1000; // On initie le delay à 1000ms pour que l'expi redescende par palier d'une seconde + On ecrase la valeur du début de boucle
  }

  if (palier >= 5) { // l'expi est suffisement redescendu, on revient dans l'état, où l'expi et le pprox se suivent
    palier = 1;
    inslufation = false;
  }

  if ((pprox > 21) && (inslufation == false)) { // Nous déclenchons la simulation avec un delai de une seconde
    defaultDelay = 1000;  // On ecrase la valeur du début de boucle, et on laisse un plateau avant de réagit
    expi = 600;
  }

  envoyerlExpi(600);    // Appel à la fonction qui envoie l'expi (où qui va mettre à jour l'expi)
  delay(defaultDelay);  // On fait la pause prévu, avant un autre tour de boucle
}
