# h.	People: Make a copy of the program you wrote for part (b).
# Make two new dictionaries representing different people,
# and store all three dictionaries in a list called people.
# Loop through your list of people.
# As you loop through the list, print everything you know about each person.



## b.	Person: Use a dictionary to store information about a person you know.
##      Store their first name, last name, age, and the city in which they live.
##      You should have keys such as first_name, last_name, age, and city.
##      Print each piece of information stored in your dictionary.

person = {'first_name':'Bob', 'last_name':'Bird', 'age':26, 'city':'Lawton'}

# two different ways of doing it:
# 1. just print the raw dictionary
#print (person)

# 2. use a key,value pair to iterate over the dictionary items.
#for key,value in person.items():
#    print (key, ": ", value, sep='')

person2 = {'first_name':'Alice', 'last_name':'InWonderLand', 'age':11, 'city':'Lawrence'}
person3 = {'first_name':'George', 'last_name':'Haddad', 'age':84, 'city':'Ann Arbor'}


people = [person, person2, person3]

for p in people:
    print ("\n")
    for key,value in p.items():
        print (key, ": ", value, sep='')
   
