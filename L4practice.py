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
    count = 0
    for num in s:
        count += 1
    return(count)

def my_count(s, char):
    '''
    (string, string) -> (int)

    Return the amount of times a character appears in a string.
    '''
    count = 0
    for i in range(my_length(s)):
        if char == s[i]:
            count +=1
    print(count)
    return count

def my_find(s, char):
    '''
    (string, string) -> (int)

    Return the index of the first occurence of a character in a string
    If character is not in s, returns -1.
    '''
    for i in range(my_length(s)):
        if char == s[i]:
            return i
    return -1

def my_lstrip(s, char):
    '''
    (string, string) -> (string)

    Return the string with the character removed from the front of the string
    Will occur for if multiples of the same character are in the front.
    '''
    for char in s:
        my_find(s, char)
        if char != s[0]:
            s = s[:i] + s[i + 1:]
            return s
        while char == s[0]:
            s = s[1:]
if __name__=="__main__":
    print(my_lstrip("ssstringsss", "s"))

def my_rstrip(s, char):
    '''
    (string, string) -> (string)

    Return the string with the character removed from the back of the string
    Will occur for if multiples of the same character are in the back.
    '''


def my_strip(s, char):
    '''
    (string, string) -> (string)

    Return the string with both the front and back end of the string stripped
    the entered character. Will occur for multiples of the same character in
    the front and back end.
    '''


def my_lower(s):
    '''
    (string) -> (string)

    Return string with all upper letters converted into lower ones.
    '''

            
def my_upper(s):
    '''
    (string) -> (string)

    Return string with all lower letters converted into upper ones.
    '''


def my_replace(s, char1, char2):
    '''
    (string, string, string) -> (string)

    Return string with char1 removed, and replaced with char2 for all
    occurences of char1.
    '''


def my_startswith(s1, s2):
    '''
    (string, string) -> (string)

    Check if s2 or both s1 and s2 are empty, and return true.
    Check if s2 is in s1, and return true.
    If s2 is not in s1, return false.
    '''

