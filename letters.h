/* Header for letters.c

   James Stanley 2010 */

#ifndef LETTERS_H_INC
#define LETTERS_H_INC

#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <stdio.h>

#ifndef BUFLEN
#define BUFLEN 8192
#endif

typedef struct TrieNode {
  struct TrieNode *child[26];
  char end_word;
} TrieNode;

extern TrieNode *dictionary;

void load_dictionary(const char *path, int maxlen);
void solve_letters(const char *letters, void (*callback)(const char *word));
int word_in_dictionary(const char *word);
int can_make_word(const char *word, const char *letters);

#ifndef CNTDN
/* the following is only if we're not part of the cntdn program */
void die(const char *fmt, ...);
#endif

#endif