

Pour installer la mini-moulinette et la norminette,
executer le script install.sh (chmod 666 install.sh pour le rendre executable)



#   Generalites et structure du repo    #

-   Un repertoire "Introduction" si jamais le sombre C tu n'as touche,
    Pour de bonnes habitudes, user de la norminette**
        
        1) Module 0, un langage type --> executer test.sh pour correction

        2) Module 1, les headers --> executer la cmd 'mini C08' dans le repertoire

        3) Module 2, makefile --> executer la cmd 'mini C09' dans le repertoire


-   Un repertoire "ressources" avec des ressources utilses

-   Sinon le repo est organise par modules (cpp00, cpp01, ..., cpp07)

-   Dans chaque module, tu trouveras :
        
        1) Le sujet en format PDF
        
        2) L'evalsheet correspondante (Conseil: Ne pas la consulter avant d'avoir fini tous les exercices)
        
        3) Un repertoire pour chaque exercice dans lequel tu trouveras :
            
            a) La place pour y creer des fichiers de l'exercices
            
            b) Les fichiers Colors.* (pour coder en couleur (waw!))
            
            c) Un repertoire test dans lequel tu trouveras
                
                aa) un script shell pour tester si ton code est correct (en construction)
                bb) un main qui devra compiler avec ton code


#   COMMENT TESTER VOS PROGRAMMES   #

1) Respecter les formats demander dans les sujets
Ca me permettra d'integrer des tests plus facilement

2) Pour le repertoire introduction executer :
    ./test.sh mon_fichier

3) Pour l'instant testez les vous meme



#   CONCERNANT LE STYLE  #

Si vous ecriver du code sexy (et utile), + de personnes vont vouloir vous aider...

Ne pas hesiter a consulter la rubrique "coding style" chez GNU

Citation de Richar Stallman :
   Le style est style, ah, oui oui


#   En termes pedagogiques, quelques conseil  #

    A)  Faites vos tests (mains)

    C)  Perseverer. Gerer les erreurs c'est 90% du temps qu'on passe a coder

    D)  Trouver vos lignes directrices x0x0



#   comment executer votre code     #

-   Choisir son compilateur (clang, gcc ou autre)

-   il doit y avoir un point d'entree dans un de vos fichiers (int  main())

-   Concevoir son makefile

-   make

-   ./mon_programme

-   Et si ca ne marche pas, trouvez la solution !


#   Quelques commandes Utiles
Il est semblable que ca soit dur de tester si vous bossez pas sur un terminal...
Donc voila les commandes de bases pour survivre :

    -   ls (permet de lister les fichiers et dossiers dans le repertoire courant)
    -   cd (permet de changer de repertoire || ex : cd Documents --> on va dans documents)
    -   cat (affiche le contenu d'un fichier)
    -   vim (un editeur de texte pour bosser sur vos fichiers)


Pour le reste, Au nom d'Odin ! Non d'une pipe! Reflechissez !


--------------------------------------------------------------------------

Pour ameliorer le repo, ne pas hesiter a faire des pull-requests

J'ajouterai conseils, sources et nouvelles methodes au fur et a mesure, mais l'essentiel est la !


Good luck
