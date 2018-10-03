# Slices: Make a copy of one of the programs you wrote in this assignment, 

# from program e
people = ['Albert Einstein', 'Babaganoush', 'Casey Jones', 'Donald Duck']
for person in people:
    print("Dear ", person, ",\nPlease join us for dinner.\n", sep = '')

# add a print statement giving the name of the person who cannot make it.
print("This person cannot make it:",people[1],"\n")

# replace the name of the person who cannot make it.
people[1] = "Zeto the Magnificent"

# a second set of invitations for the current people.
print ("\nRevised Invitations:")
for person in people:
    print("Dear ", person, ",\nPlease join us for dinner.\n", sep = '')

# a statement informing people that a bigger table is found.
for person in people:
    print("Dear ", person, ",\nA bigger table has been found.\n", sep = '')

# insert new guest at beginning of list
people.insert(0, 'First Person')

# insert new guest in the middle of the list
people.insert(int(1+len(people)/2), 'Middle Person')

# insert new guest at the end of the list
people.insert(len(people), 'Last Person')

# New invitation
print ("\nNew Invitations:")
for person in people:
    print("Dear ", person, ",\nPlease join us for dinner.\n", sep = '')




# add several lines to the end of the program that do the following:


# i. Print the message, The first three items in the list are:. Then use a slice to
# print the first three items from that program's list.
print("The first three items in the list are:")
print(people[0:3])


# ii. Print the message, Three items from the middle of the list are:. Use a slice
# to print three items from the middle of the list.
print("Three items from the middle of the list are:")
m = int(1+len(people)/2)-1   # middle index
print(people[m-1:m+2])

# iii. Print the message, The last three items in the list are:. Use a slice to print
# the last three items in the list.
print("The last three items in the list are:")
print(people[-3:len(people)])
        

