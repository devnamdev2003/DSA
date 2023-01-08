def function():
    length = 10000
    width = 1
    height = 1
    mass = 1
    bulky = False
    heavy = False
    if(mass >= 100):
        heavy = True

    if(length >= 10000 or width >= 10000 or height >= 10000 or mass >= 10000 or (length*width*height) >= 1000000000):
        bulky = True

    if(bulky == True and heavy == True):
        return'Both'

    if(bulky == False and heavy == False):
        return 'Neither'

    if(bulky == True):
        return 'Bulky'

    if(heavy == True):
        return 'Heavy'


print(function())
