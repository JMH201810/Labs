# Favorite Numbers:
# Use a dictionary to store people's favorite numbers.
# Think of five names, and use them as keys in your dictionary.
# Think of a favorite number for each person, and store each as a value
# in your dictionary.
# Print each person's name and their favorite number.

favnums = {'Albert':2, 'Brenda':8, 'Charles': 88, 'Dorothy':0, 'Edward':1}

for key,value in favnums.items():
    print(key,"'s favorite number is: ", value, sep="")

