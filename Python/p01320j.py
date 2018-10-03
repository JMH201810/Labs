# j.	Great Magicians:
# Make a copy of your program from part (i).
# Write a function called make_great() that modifies the list of magicians
# by adding the phrase the Great to each magician's name.
# Call show_magicians() to see that the list has actually been modified.

def show_magicians(listOfMagicians):
    for x in listOfMagicians:
        print(x)

def make_great(listOfMagicians):
    for i in range(len(listOfMagicians)):
        p = 'The Great ' + listOfMagicians[i]
        listOfMagicians[i] = p

group = ['Mr. Bennett', 'Houdini', 'Penn Jillette']
make_great(group)
show_magicians(group)
