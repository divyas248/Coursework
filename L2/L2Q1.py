a = float(input("Please enter the real component of the complex number: "))
b = float(input("Please enter the imaginary component of the complex number: "))

def mag_complex(a,b):
    ''' float(a), float(b) -> float(c)
    Calculates and returns the magnitude of c from the square root of the
    real and imaginary components a and b entered by the user.
    '''
    mag_value = (a**2 + b**2)**(1/2)
    return mag_value

mag_complex(a,b)
