# k.	Unchanged Magicians:
# Make a copy of your program from part (j).

# Call the function make_great() with a copy of the list of magicians' names.
# Because the original list will be unchanged, return the new list and store
# it in a separate list.

# Call show_magicians() with each list to show that you have one list of
# the original names and one list with the Great added to each magician's name.

def show_magicians(listOfMagicians):
    for x in listOfMagicians:
        print(x)

def make_great(listOfMagicians):
    for i in range(len(listOfMagicians)):
        p = 'The Great ' + listOfMagicians[i]
        listOfMagicians[i] = p

group = ['Mr. Bennett', 'Houdini', 'Penn Jillette']
newgroup = group[:]
make_great(newgroup)
show_magicians(newgroup)
show_magicians(group)
