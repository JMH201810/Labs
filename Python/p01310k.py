# Favorite Numbers:
# Make a copy of your program from exercise (c),
# then modify it so that each person can have more than one favorite number.
# Then print each person's name along with their favorite numbers.

favnums = {'Albert':[2,4,6],
           'Brenda':[8,16,24],
           'Charles':[88,176,264],
           'Dorothy':[-1,0,1],
           'Edward':[1,2,3]}

for key,value in favnums.items():
    print('\n',key,"'s favorite numbers are: ", sep='')
    for n in value:
        print(n)
        
