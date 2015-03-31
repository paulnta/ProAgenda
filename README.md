# 1	Général #
Tout doit être écrit en anglais. (éventuellement pas les commentaires).
# 2	Fichiers #
## 2.1	Fichiers Header (.h) ##
Chaque fichier .h contient un #define pour empêcher les inclusions multiples.

```
#!c++

#ifndef FILENAME_H_
#define FILENAME_H_
…
#endif // FILENAME_H_
```

# 3	Nommage #
## 3.1	Règle général de nommage ##
Les noms de fonctions, de variables de fichiers devraient être descriptifs : éviter les abréviations.

## 3.2	Noms des fichiers ##
Les noms des fichiers ne sont composés que de minuscules. Les mots peuvent être séprarés par des « _ ».  (my_useful_class.cpp – my_useful_class.h)

## 3.3	Noms des variables ##
### 3.3.1	Nom des variables communes ###
Les variables commencent par une minuscule et chaque nouveau mot commence par une majuscule.

```
#!c++

string tableName;
```


### 3.3.2	Noms des variables de classes ###
Même chose que les variables communes ;

```
#!c++

class TableInfo {
private :
	string tableName ;
} ;
```


## 3.4	Noms des constantes ##
Tous est en majuscule et les mots sont séparés par un « _ ».
```
#!c++

const int DAYS_IN_WEEK = 7 ;
```

## 3.5	Noms des fonctions et méthodes ##
### 3.5.1	Noms des fonctions/méthodes régulières ###
Les fonctions commence par une minuscule et chaque nouveau mot commence par une majuscule.
```
#!c++

void addTableEntry() ;
```

### 3.5.2	Noms des accessors/mutators (getters/setters) ###
Les getters/setters commencent par get/set suivi de la même convention que pour les fonctions normales (le 1er mot commençant par une majuscule!).
```
#!c++

int getNumEntries() ;
void setNumEntries(int newValue) ;
```

## 3.6	Noms des enumérations ##
Le nom de l'énumérations commence par une majuscule et ses champs se nomment comme les constantes.
```
#!c++

enum AlternateUrlTableErrors {
	OK = 0,
	OUT_OF_MEMORY = 1,
} ;
```

## 3.7	Noms des classes ##
Les classes ont la même convention que les variables normales. Elles sont juste une majuscule au début.
```
#!c++

class TableInfo {
} ;
```

# 4	Commentaires #
## 4.1	Entête de fichiers ##
Chaque fichier doit avoir un commentaire en haut contenant :
* le nom de l'autre (des auteurs)
* la date de création
* une description de son contenu.

En général, un fichier .h décrira les classes qui sont déclarées dans le fichier avec un aperçu de ce qu'elles sont et comment elles sont utilisées.
Un fichier .cpp devrait contenir plus d'informations sur les détails de mise en œuvre ou des discussions sur des algorithmes difficiles. 

Essayer de ne pas dupliquer les commentaires entre le .h et le .cpp .
Les commentaires doubles peuvent diverger.

Entête fichiers:
```
#!c++

/*****************************************************************************************
* HEIG-VD // heig-vd.ch
* Haute Ecole d'Ingenerie et de Gestion du Canton de Vaud
* School of Business and Engineering in Canton de Vaud
******************************************************************************************
*
* File                 : header.php
* Author               : prenom nom (NOMP)
* Email                : prenom.nom@heig-vd.ch
* Date                 : 31 Mars 2015
*
* Project              : Project
*
******************************************************************************************
* Description : What does the code.
******************************************************************************************
* Information : 
******************************************************************************************
* Modifications :
* Ver     	Date          Engineer     Comments
*  1.0.0     24.10.13      NOMP         Original version
*  1.0.1 	 24.10.14      NOMP		    Modify existing code
*  1.1.0	 16.12.14	   NOMP	        Add feature
*  2.0.0     13.01.15	   NOMP			Optimize code
*****************************************************************************************/
```

Entête fonctions:
```
#!c++

/*****************************************************************************************
* Description fonction
* @param	xx description param
* @return	description return
*****************************************************************************************/

```

## 4.2	Commentaires de fonctions ##
### 4.2.1	Déclaration de la fonction (.h en général) ###
Chaque déclaration de fonction devrait avoir des commentaires qui décrivent ce que fait fonction et comment l'utiliser.

Types de choses à mentionner dans les commentaires à la déclaration de la fonction:

* Description de ce que fait la fonction et comment l'utiliser.
* Description des entrées/sorties. (param. entrés et retour).
* Si la fonction alloue de la mémoire que l'appelant doit libérer.

### 4.2.2	Définition de la fonction (implémentation) ###
Eventuellement si la fonction fait quelque chose de délicat, il faudrait un commentaire explicatif. (ne pas répéter les commentaires du .h).

## 4.3	Commentaires des classes ##
Chaque définition de classe doit avoir un commentaire qui décrit cette classe et comment elle doit être utilisée.

# 5	Autres #
## 5.1	Accolades ##
Je pense qu'on va utiliser les accolades avec cette convention (accolades « du haut » juste après le nom et non par après un retour à la ligne)..
```
#!c++

Class A {
   ...
} ;

if(a == 1) {
} else if (a == 2) {
} else {
}
```

## 5.2	Tabulation ou espace ? ##
On utilise soit des espaces soit des indentations, pas les deux.
Je pense qu'il est mieux d'utiliser 3 espaces comme indentation.
Configurer l'IDE pour qu'il utilise 3 espace comme tabulation.

## 5.3	N'utiliser que des unsigned int ##
Comme c'est René je pense qu'il faut utiliser les unsigned quand c'est nécessaire ;)

# 6	Source #
https://google-styleguide.googlecode.com/svn/trunk/cppguide.html
http://geosoft.no/development/cppstyle.html