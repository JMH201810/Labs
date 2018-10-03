# More Guests: You just found a bigger dinner table, so now more space is
# available. Think of three more guests to invite to dinner.
# i. Make a copy of your program from Exercise d. Add a statement to the
# end of your program informing people that you found a bigger dinner
# table.
# ii. Use insert() to add one new guest to the beginning of your list.
# iii. Use insert() to add one new guest to the middle of your list.
# iv. Use insert() to add one new guest to the end of your list.
# v. Print a new set of invitation messages, one for each person on your list.

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

