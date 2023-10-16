""" Function is to check whether two strings are anagram of each other or not. """

def isAnagram(a, b):
    """ Check 2 strings are anagram or not """

    if sorted(a) == sorted(b):
        return True
    else:
        return False
