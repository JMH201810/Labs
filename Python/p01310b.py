## b.	Person: Use a dictionary to store information about a person you know.
##      Store their first name, last name, age, and the city in which they live.
##      You should have keys such as first_name, last_name, age, and city.
##      Print each piece of information stored in your dictionary.

person = {'first_name':'Bob', 'last_name':'Bird', 'age':26, 'city':'Lawton'}

# two different ways of doing it:
# 1. just print the raw dictionary
print (person)

# 2. use a key,value pair to iterate over the dictionary items.
for key,value in person.items():
    print (key, ": ", value, sep='')
