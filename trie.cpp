#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

// Alphabet size (# of symbols)

#define ALPHABET_SIZE (26)

// Converts key current character into index

// use only ‘a’ through ‘z’ and lower case

#define CHAR_TO_INDEX(c) ((int)c – (int)’a’)

char store[1000] ;

// trie node

typedef struct trie_node trie_node_t;

struct trie_node {

int value;

trie_node_t *children[ALPHABET_SIZE];

};

// trie ADT

typedef struct trie trie_t;

struct trie {

trie_node_t *root;

int count;

};

// Returns new trie node (initialized to NULLs)

trie_node_t *getNode(void) {

trie_node_t *pNode = NULL;

pNode = (trie_node_t *)malloc(sizeof(trie_node_t));

if( pNode ) {

int i;

pNode->value = 0;

for(i = 0; i < ALPHABET_SIZE; i++) {

pNode->children = NULL;

}

}

return pNode;

}

// Initializes trie (root is dummy node)

void initialize(trie_t *pTrie) {

pTrie->root = getNode();

pTrie->count = 0;

}

// If not present, inserts key into trie

// If the key is prefix of trie node, just marks leaf node

void insert(trie_t *pTrie, char key[]) {

int level;

int length = strlen(key);

int index;

trie_node_t *pCrawl;

pTrie->count++;

pCrawl = pTrie->root;

for( level = 0; level < length; level++ ) {

index = CHAR_TO_INDEX(key[level]);

if( !pCrawl->children[index] )

pCrawl->children[index] = getNode();

pCrawl = pCrawl->children[index];

}

// mark last node as leaf

pCrawl->value = pTrie->count;

}

void printTrieUtil (trie_node_t *pCrawl, char str[], int len) {

int i ;

for ( i = 0 ; i < ALPHABET_SIZE; i ++ ) {

if ( pCrawl->children ) { /* It has child means there should be a letter in the next depth */

if (pCrawl->children->value != 0 ) {/* found a valid entry */

str[len] = i+’a’ ;

str[len+1] = ” ;

printf ( ” %sn”, str ) ;

printTrieUtil (pCrawl->children,str, len+1); /* Iterate through this node to next depth */

}

else { /* It is the some inside letter of the word */

str[len] = i + ‘a’ ;

printTrieUtil (pCrawl->children,str, len+1);

}

}

}

}

void printSelectedWord (trie_t pTrie, char *str) {

trie_node_t *pCrawl ;

int index ;

if (*str == ”) {

printf ( “nGiven string is of zero length”) ;

return ;

}

memcpy (store,str,strlen(str));

for ( pCrawl=pTrie.root ; pCrawl && *str ; pCrawl ) {

printf ( “%cn”, *str ) ;

index = CHAR_TO_INDEX (*str) ;

if ( pCrawl->children[index] ) {

str ++ ;

pCrawl = pCrawl->children[index] ;

}

else {

printf ( “nThere is no word with this string.n”) ;

return ;

}

}

printf ( “nSelected strings are : n”) ;

printTrieUtil (pCrawl,store, strlen(store));

}

void printTrie (trie_t pTrie) {

trie_node_t *pCrawl = pTrie.root ;

printf ( “nThe whole trie contains :n”) ;

printTrieUtil (pCrawl, store, 0) ;

}

// Returns non zero, if key presents in trie

int search(trie_t *pTrie, char key[]){

int level;

int length = strlen(key);

int index;

trie_node_t *pCrawl;

pCrawl = pTrie->root;

for( level = 0; level < length; level++ ) {

index = CHAR_TO_INDEX(key[level]);

if( !pCrawl->children[index] ){

return 0;

}

pCrawl = pCrawl->children[index];

}

return (0 != pCrawl && pCrawl->value);

}

// Driver

int main()

{

// Input keys (use only ‘a’ through ‘z’ and lower case)

char keys[][8] = {“the”, “a”, “there”, “answer”, “any”, “by”, “bye”, “their”};

trie_t trie;

int i ;

char output[][32] = {“Not present in trie”, “Present in trie”};

initialize(&trie);

// Construct trie

for( i = 0; i < ARRAY_SIZE(keys); i++)

{

insert(&trie, keys);

}

// Search for different keys

printf("%s — %sn", “the”, output[search(&trie, “the”)] );

printf(“%s — %sn”, “these”, output[search(&trie, “these”)] );

printf(“%s — %sn”, “their”, output[search(&trie, “their”)] );

printf(“%s — %sn”, “thaw”, output[search(&trie, “thaw”)] );

printSelectedWord (trie, "a) ;

printTrie (trie) ;

return 0;

}