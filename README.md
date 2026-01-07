Projet INDP1 - Longest Substring Without Repeating Characters
 Informations du projet


Problème choisi : Longest Substring Without Repeating Characters
Référence LeetCode : LeetCode 3 - Medium
Équipe : Allani Nour / Azzabou Chayma / Hamdi Sarra / Laouini Rawand
Date : 7 Janvier 2026
Langage : C
Cours : INDP1 - Programmation en C

 Cas réel d'utilisation
Cette solution modélise plusieurs scénarios réels :

Analyse de logs serveur : Identifier la plus longue période sans événements répétés dans des logs système.
Validation de flux de données : Détecter des séquences uniques dans des streams en temps réel.
Sécurité informatique : Analyser les patterns dans les mots de passe pour éviter les répétitions.
Bio-informatique : Rechercher des séquences d'ADN sans répétitions de nucléotides.
Analyse de texte : Étudier la diversité lexicale dans des documents.

 Approche et algorithme
1. Solution brute-force (O(n²))
Comme demandé par le professeur, nous avons d'abord envisagé une solution naïve :
for i from 0 to n-1:
    pour j from i to n-1:
        si caractère déjà vu → break
        sinon → incrémenter longueur
2. Solution optimisée (O(n)) - Fenêtre glissante
Nous avons implémenté l'approche fenêtre glissante avec tableau de hachage.
Algorithme :
int lengthOfLongestSubstring(const char *s) {
    int last_index[256]; // Tableau pour stocker les derniers indices
    for (int i = 0; i < 256; i++) {
        last_index[i] = -1; // Initialisation à -1
    }
   
    int max_len = 0, start = 0;
    int n = strlen(s);
   
    for (int end = 0; end < n; end++) {
        unsigned char c = (unsigned char)s[end];
       
        // Si le caractère est déjà dans la fenêtre actuelle
        if (last_index[c] >= start) {
            start = last_index[c] + 1; // Déplacer le début de la fenêtre
        }
       
        last_index[c] = end; // Mettre à jour le dernier index
       
        // Calculer la longueur actuelle
        int current_len = end - start + 1;
        if (current_len > max_len) {
            max_len = current_len; // Mettre à jour le maximum
        }
    }
   
    return max_len;
}
Explication :

Tableau last_index[256] : Stocke le dernier index de chaque caractère ASCII.
Deux pointeurs : start (début de la fenêtre) et end (fin de la fenêtre).
Ajustement dynamique : Quand un caractère répété est détecté, start est déplacé.
Parcours unique : Chaque caractère est visité exactement une fois.

3. Structures de données choisies

Tableau statique de 256 entiers (pour couvrir ASCII étendu).
Complexité spatiale constante (O(1)) indépendante de la taille d'entrée.
Pas d'allocations dynamiques pour garantir la performance.

 Analyse de complexité

Temps : O(n) – Parcourt la chaîne une seule fois, chaque caractère est traité en O(1).
Espace : O(1) – Utilise un tableau fixe de 256 entiers (taille constante).
Comparaisons : O(n) – Chaque caractère est comparé une fois.

Détail :

n = longueur de la chaîne d'entrée.
Opérations par caractère : 1 accès tableau + 1 comparaison + 1 affectation.
Total opérations : ~3n → O(n).

 Compilation et exécution
Prérequis

Windows (MinGW) : Vérifiez avec gcc --version.
Linux : Installez avec sudo apt install gcc.
macOS : Installez avec brew install gcc.

Compilation

Méthode 1 : Avec le script batch (Windows) – Exécutez build.bat.
Méthode 2 : Manuellement – gcc -Wall -Wextra -std=c99 -O2 -o program.exe src/longest_substring.c tests/test_longest_substring.c.

Exécution

Exécuter le programme : ./program.exe.
Exécuter avec un exemple spécifique : echo "abcabcbb" | ./program.exe.

Tests unitaires
Le projet inclut 30+ tests organisés en 3 catégories :

✅ Tests de base (15 cas).
✅ Tests des cas limites (10 cas).
✅ Tests de performance (5 cas).

Pour exécuter tous les tests :

Via le script : build.bat.
Manuellement : gcc -o tests.exe src/longest_substring.c tests/test_longest_substring.c puis ./tests.exe.

📁 Structure du projet
longest-substring/
├── .github/workflows/         # Intégration continue
│   └── ci.yml                 # GitHub Actions configuration
├── data/                      # Données de test
│   ├── input.txt              # 15 cas de test
│   ├── expected_output.txt    # Résultats attendus
│   └── test_cases.json        # Cas de test structurés (JSON)
├── src/                       # Code source
│   ├── longest_substring.h    # Header file (interface)
│   └── longest_substring.c    # Implémentation O(n)
├── tests/                     # Tests unitaires
│   └── test_longest_substring.c # 30+ tests complets
├── .gitignore                 # Fichiers à ignorer (exécutables, etc.)
├── build.bat                  # Script de compilation Windows
└── README.md                  # Documentation (ce fichier)
 Travail d'équipe

Processus de développement :

C'est un projet de deux semaines.
Semaine 1 : Recherche de l'algorithme optimal, étude des solutions existantes.
Semaine 2 : Implémentation en C avec validation progressive, création de tests exhaustifs, correction des bugs, configuration CI/CD, documentation, optimisation finale.
Nous avons poussé les commits sur GitHub principalement les deux derniers jours avant la deadline.

 Intégration Continue (GitHub Actions)
Notre pipeline CI/CD assure la qualité du code à chaque modification :

✅ Checkout du code source.
✅ Compilation automatique avec GCC.
✅ Exécution de tous les tests unitaires.
✅ Notification en cas de succès/échec.

Statut : CI
 Validation et résultats
Tests critiques passés :

✅ "abcabcbb" → 3 (cas standard LeetCode).
✅ "bbbbb" → 1 (tous caractères identiques).
✅ "pwwkew" → 3 (répétition interne).
✅ "dvdf" → 3 (cas complexe nécessitant ajustement).
✅ "" → 0 (chaîne vide).
✅ "abcdefghijklmnopqrstuvwxyz" → 26 (alphabet complet).


 Références
Académiques :

LeetCode Problem 3 - Official.
Sliding Window Pattern - LeetCode Discuss.
The C Programming Language (K&R) - Chapter 3.

Techniques :

GitHub Actions Documentation.
GCC Compiler Options.
Unit Testing in C - Best Practices.

✅ Conformité aux exigences

Code source en C : ✅ Implémentation complète avec header/source.
Tests unitaires : ✅ 30+ tests couvrant normaux + limites.
GitHub Actions : ✅ Pipeline CI/CD fonctionnel.
README complet : ✅ Documentation détaillée.
Solution optimisée : ✅ O(n) temps, O(1) espace.
Travail d'équipe : ✅ 4 membres, rôles définis.
Cas réel d'utilisation : ✅ 5 scénarios.

 Licence
Ce projet est un travail académique réalisé dans le cadre du cours INDP1 - Programmation en C.
Le code est fourni à des fins éducatives et peut être utilisé librement pour l'apprentissage.
🔍 Vérification finale

Code compile sans erreurs.
Tous les tests passent.
GitHub Actions vert.
Documentation complète.
Structure de projet propre.




