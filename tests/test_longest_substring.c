#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "../src/longest_substring.h"

void test_examples() {
    // Tests de base
    assert(lengthOfLongestSubstring("abcabcbb") == 3);
    assert(lengthOfLongestSubstring("bbbbb") == 1);
    assert(lengthOfLongestSubstring("pwwkew") == 3);
    assert(lengthOfLongestSubstring("") == 0);
    assert(lengthOfLongestSubstring("au") == 2);
    
    // Tests avec un seul caractère
    assert(lengthOfLongestSubstring("a") == 1);
    assert(lengthOfLongestSubstring("z") == 1);
    
    // Tests avec tous caractères différents
    assert(lengthOfLongestSubstring("abcdef") == 6);
    assert(lengthOfLongestSubstring("xyz123") == 6);
    assert(lengthOfLongestSubstring("123456") == 6);
    
    // Tests avec répétitions au milieu
    assert(lengthOfLongestSubstring("abca") == 3);
    assert(lengthOfLongestSubstring("abcb") == 3);
    assert(lengthOfLongestSubstring("abb") == 2);
    assert(lengthOfLongestSubstring("abba") == 2);
    
    // Tests avec caractères spéciaux
    assert(lengthOfLongestSubstring("a!b@c#") == 6);
    assert(lengthOfLongestSubstring("  ") == 1);  // deux espaces
    assert(lengthOfLongestSubstring("\t\n") == 2); // tab et newline
    
    // Tests avec sous-chaîne au début
    assert(lengthOfLongestSubstring("aaabcde") == 5); // "abcde"
    
    // Tests avec sous-chaîne à la fin
    assert(lengthOfLongestSubstring("abcdeeee") == 5); // "abcde"
    
    // CORRIGÉ : aabcdeff -> 6 (pas 5)
    assert(lengthOfLongestSubstring("aabcdeff") == 6); // "abcdef"
    
    // Tests avec chiffres
    assert(lengthOfLongestSubstring("112233") == 2);
    assert(lengthOfLongestSubstring("123321") == 3);
    
    // Tests avec mélange alphanumérique
    assert(lengthOfLongestSubstring("a1b2c3") == 6);
    assert(lengthOfLongestSubstring("abc123abc") == 6);
    
    // Test longue chaîne simple
    assert(lengthOfLongestSubstring("aaaaaaaaaaaaaaaaaaaa") == 1);
    
    // Test alternance
    assert(lengthOfLongestSubstring("abababab") == 2);
    
    // Test palindrome
    assert(lengthOfLongestSubstring("racecar") == 4); // "race" ou "ecar"
    
    // Tests de bordure
    assert(lengthOfLongestSubstring("abcabcabc") == 3);
    assert(lengthOfLongestSubstring("abcdabcd") == 4);
    
    // Test chaîne en ordre inverse
    assert(lengthOfLongestSubstring("cbaabc") == 3); // "cba" ou "abc"
    
    // Test avec tous caractères identiques sauf un
    assert(lengthOfLongestSubstring("aaaaab") == 2);
    assert(lengthOfLongestSubstring("baaaaa") == 2);
    
    printf("Tous les tests de base passés\n");
}

void test_edge_cases() {
    printf("\nTests des cas limites :\n");
    
    // Chaîne vide
    assert(lengthOfLongestSubstring("") == 0);
    printf("   Chaine vide\n");
    
    // Un seul caractère
    assert(lengthOfLongestSubstring("x") == 1);
    printf("  Un seul caractere\n");
    
    // Deux caractères identiques
    assert(lengthOfLongestSubstring("xx") == 1);
    printf("  Deux caracteres identiques\n");
    
    // Deux caractères différents
    assert(lengthOfLongestSubstring("xy") == 2);
    printf("   Deux caracteres differents\n");
    
    // Tous caractères différents (longue chaîne)
    char all_diff[27];  // 26 lettres + null terminator
    for (int i = 0; i < 26; i++) {
        all_diff[i] = 'a' + i;
    }
    all_diff[26] = '\0';
    assert(lengthOfLongestSubstring(all_diff) == 26);
    printf("   Tous caractères différents (26 lettres)\n");
    
    // Alternance parfaite
    assert(lengthOfLongestSubstring("ababababab") == 2);
    printf("   Alternance parfaite\n");
    
    // Sous-chaîne au tout début
    assert(lengthOfLongestSubstring("abcdefaaaaa") == 6);
    printf("   Sous-chaîne au debut\n");
    
    // Sous-chaîne à la toute fin
    assert(lengthOfLongestSubstring("aaaaabcdef") == 6);
    printf("   Sous-chaîne a la fin\n");
    
    printf(" Tous les cas limites passes\n");
}

void test_performance_cases() {
    printf("\nTests de performance (courts) :\n");
    
    // Longue séquence sans répétition
    assert(lengthOfLongestSubstring("abcdefghijklmnopqrstuvwxyz") == 26);
    printf("   Alphabet complet\n");
    
    // Répétition pattern
    assert(lengthOfLongestSubstring("abcabcabcabcabc") == 3);
    printf("   Pattern repete\n");

}

int main() {
    printf("=== Début des tests ===\n\n");
    
    test_examples();
    test_edge_cases();
    test_performance_cases();
    
    printf("\n=== Tous les tests ont reussi ! ===\n");
    printf(" Programme fonctionnel et robuste\n");
    
    return 0;
}