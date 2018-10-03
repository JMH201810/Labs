# Changing Guest List: You just heard that one of your guests can't make the
# dinner, so you need to send out a new set of invitations. You'll have to think of
# someone else to invite.
# i. Make a copy of your program from Exercise c. Add a print statement at
# the end of your program stating the name of the guest who can't make it.
# ii. Modify your list, replacing the name of the guest who can't make it with
# the name of the new person you are inviting.
# iii. Print a second set of invitation messages, one for each person who is still
# in your list.

people = ['Albert Einstein', 'Babaganoush', 'Casey Jones', 'Donald Duck']
for person in people:
    print("Dear ", person, ",\nPlease join us for dinner.\n", sep = '')

# add a print statement giving the name of the person who cannot make it.
print("This person cannot make it:",people[1],"\n")

# replace the name of the person who cannot make it.
people[1] = "Zeto the Magnificent"

# a second set of invitations for the current people.
for person in people:
    print("Dear ", person, ",\nPlease join us for dinner.\n", sep = '')


