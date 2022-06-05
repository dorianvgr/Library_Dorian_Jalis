# Library_Dorian_Jalis


Voici notre projet de gestion de livres.

Pour compiler le projet, il faut écrire gcc Main.c Display.c Registration.c Login.c Check_and_Verifications.c Modifications.c Sort.c Security.c Time.c -o BBprojet dans le terminal.
Pour l'exécuter, écrire ./BBprojet dans le terminal.
Une fois le programme lancé, suivre les indications : taper 1, 2 ou 3 quand vous arrivez à des interfaces qui explicitent clairement ce que vous pouvez faire et écrire le titre exact d'un livre quand vous souhaitez l'emprunter ou le rendre.


Lors de la création d'un compte, si l'utilisateur est un professeur, il lui sera demandé d'entrer un mot de passe administrateur parmi tous les mots de passe administrateurs contenus dans le fichier.txt "Password_prof.txt" pour prouver qu'il est un professeur.

Lorsque vous créez un compte, votre identifiant ne doit pas être déjà pris. Ensuite votre mot de passe doit faire 8 caractères minimum, contenir une minuscule, un majuscule et un chiffre. Enfin votre identifiant et votre mot de passe ne doivent pas contenir d'espaces.

Lors de la connexion, si l'utilisateur se trompe d'identifiant trois fois de suite, un interface apparait pour lui suggérer soit de 1.continuer à se connecter soit 2.créer un compte.


Une fois connecté, il a la possibilité d'emprunter des livres. Dans ce cas la, il peut faire une recherche par titre, auteur ou catégorie. Le programme va alors chercher tous les livres qui commencent par ce qu'a écrit l'utilsateur en fonction de s'il a choisi de rechercher par titre, auteur ou catégorie. Il va ensuite les afficher par odre alphabétique.
