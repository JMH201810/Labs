##Shrinking Guest List: You just found out that your new dinner table won't arrive
##in time for the dinner, and you have space for only two guests.
##i. Make a copy of your program from Exercise e. Add a new line that prints
##a message saying that you can invite only two people for dinner.
##ii. Use pop() to remove guests from your list one at a time until only two
##names remain in your list. Each time you pop a name from your list, print
##a message to that person letting them know you're sorry you can't invite
##them to dinner.
##iii. Print a message to each of the two people still on your list, letting them
##know they're still invited.
##iv. Use del to remove the last two names from your list, so you have an empty
##list. Print your list to make sure you actually have an empty list at the end
##of your program.

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

# step f.
# Message that have space for only two guests.
print ("\nSorry, there's only space for two (2) guests for dinner.\n")
while (len(people) > 2):
    x = people.pop()
    print ("Sorry ", x, ", no room for you at dinner.", sep = '')

print()
for person in people:
    print("Dear ", person, ",\nYou are still invited to dinner.\n", sep = '')

del people[:]

print("List of people:", people)

