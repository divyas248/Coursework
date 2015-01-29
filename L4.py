# Micro-assignment 4
# Baby string module
# Please complete docstrings for all the functions.

# Global variables

LOWER = 'abcdefghijklmnopqrstuvwxyz'
UPPER = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'

# Function definitions

def my_length(s):
    '''
    (string) -> (int)

    Return the length of a string.
    '''
    length = 0
    for char in s:
        length += 1
    return length
    
def my_count(s, char):
    '''
    (string, string) -> (int)

    Return the amount of times a character appears in a string.
    '''
    count = 0
    if char not in s:
        return False
    
    while count < my_length(s):
        if s[count] == char:
            count += 1 
    return count
        
def my_find(s, char):
    '''
    (string, string) -> (int)

    Return the index of the first occurence of a character in a string
    If character is not in s, returns -1.
    '''
    index = 0
    while index < my_length(s):
        if s[index] != char:
            index += 1
        elif s[index] == char:
            return index
    return -1
            
def my_lstrip(s, char):
    '''
    (string, string) -> (string)

    Return the string with the character removed from the front of the string
    Will occur for if multiples of the same character are in the front.
    '''
    while s[0] == char:
        s = s[1:]
    return s

def my_rstrip(s, char):
    '''
    (string, string) -> (string)

    Return the string with the character removed from the back of the string
    Will occur for if multiples of the same character are in the back.
    '''
    while s[-1] == char:
        s = s[:-1]
    return s

def my_strip(s, char):
    '''
    (string, string) -> (string)

    Return the string with both the front and back end of the string stripped
    the entered character. Will occur for multiples of the same character in
    the front and back end.
    '''
    while s[0] or s[-1] == char:
        my_lstrip(s, char)
        my_rstrip(s, char)
    return s

def my_lower(s):
    '''
    (string) -> (string)

    Return string with all upper letters converted into lower ones.
    '''
    for i in range(my_length(s)):
        for n in range(my_length(UPPER)):
            if s[i] in UPPER[n]:
                s = s[:i] + LOWER[n] + s[i+1:]
    return s
            
def my_upper(s):
    '''
    (string) -> (string)

    Return string with all lower letters converted into upper ones.
    '''
    for i in range(my_length(s)):
        for n in range(my_length(LOWER)):
            if s[i] in LOWER[n]:
                s = s[:i] + UPPER[n] + s[i+1:]
    return s

def my_replace(s, char1, char2):
    '''
    (string, string, string) -> (string)

    Return string with char1 removed, and replaced with char2 for all
    occurences of char1.
    '''
    while my_find(s, char1) != -1:
        s = s[0 : my_find(s, char1)] + char2 + s[my_find(s, char1) + 1 :]
    else:
        return s

def my_startswith(s1, s2):
    '''
    (string, string) -> (string)

    Check if s2 or both s1 and s2 are empty, and return true.
    Check if s2 is in s1, and return true.
    If s2 is not in s1, return false.
    '''
    if s2 == '' or (s1 == '' and s2 == '') or (s2 == s1[0:my_length(s2)]):   
        return True
    else:
        return False
