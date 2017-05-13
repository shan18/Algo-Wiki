""" Implementing a trie with make, insert, search, and find_prefix methods.

Note:
You may assume that all inputs consist of lowercase letters a-z.
"""


_end = '_end_'
trie = dict()


# Inserts a list of words in trie at once
def make_trie(words):
    for word in words:
        current_dict = trie
        for letter in word:
            current_dict = current_dict.setdefault(letter, {})
        current_dict[_end] = _end


# Inserts strings into trie one by one
def insert(word):
    current_dict = trie
    for letter in word:
        if letter in current_dict:
            current_dict = current_dict[letter]
        else:
            current_dict = current_dict.setdefault(letter, {})
    current_dict[_end] = _end


# Searches for a given string in trie
def search(word):
    current_dict = trie
    for letter in word:
        if letter in current_dict:
            current_dict = current_dict[letter]
        else:
            return False
    if _end in current_dict:
        return True
    else:
        return False


# Searches for a prefix of a word in trie
def find_prefix(prefix):
    current_dict = trie
    for letter in prefix:
        try:
            current_dict = current_dict[letter]
        except KeyError:
            return False
    return True
