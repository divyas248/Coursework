def asterisks(n,m):
        ''' int(n), int(m) -> string
        asterisks(n,m) returns a string of asterisks and spaces in between
        where integer n represents the number of asterisks and integer m
        represents the number of spaces in between each asterisk
        '''
        if n < 1 or m < 0: exit
        return ((n - 1) * ("*" + m * " ") + "*")
