# create a function that calculates the greatest common
# denominator of two integers

def gcd(a, b):
        ''' int(a), int(b) -> int(remainder)

        Finds the larger value between integers a and b, then takes the larger
        value and makes it the dividend. Then takes the smaller value to equal
        divisor. The dividend is then divided by the divisor through integer
        division, and if the remainder is not zero, the new dividend becomes the
        old divisor and the new divisor becomes the old remainder as the process
        repeats until the remainder is zero, and the last divisor, which is the
        greatest common denominator, is returned.
        '''
        dividend = max(a, b)
        if a > b:
                divisor = b
        else:
        	divisor = a
        while dividend % divisor != 0:
        	remainder = dividend % divisor
        	dividend,divisor = divisor,remainder
        return divisor
