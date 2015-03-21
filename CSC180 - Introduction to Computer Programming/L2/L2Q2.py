def pennies():
    ''' pennies() returns the remainder of pennies from an amount of change
    (as a floating point) by multiplying the change by 100, to convert dollars
    and cents into cents and then calculating the remainder
    of the cents divided by 5
    '''
    change = float(input("Please enter amount of change: "))
    remainder = change*100%5
    return remainder

pennies()
