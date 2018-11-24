# TRIE
File Based Trie data structure to perform insert, search and delete operations on secondary storage

## Quick run
gcc mainTrie.c -o mainTrie -lm;./mainTrie<inputCreate;
gcc mainTrie.c -o mainTrie -lm;./mainTrie<inputInsert;
gcc mainTrie.c -o mainTrie -lm;./mainTrie<inputSearch;

We have used file redirection to standard input.
By default the length is set to 5 in the input files. It can be changed as per the need by following the format provided below.

## Create

gcc mainTrie.c -o mainTrie -lm;./mainTrie<inputCreate

inputCreate: c <length_variable> <trie_file_name>
example:     c 5 len5

## Insert

gcc mainTrie.c -o mainTrie -lm;./mainTrie<inputInsert

inputSearch: i <length_variable> <trie_file_name> <word_file_name>
example:     i 5 len5 length5

## Search

gcc mainTrie.c -o mainTrie -lm;./mainTrie<inputSearch

inputSearch: s <length_variable> <trie_file_name> <word_file_name>
example:     s 5 len5 length5.1
