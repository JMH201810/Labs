# Pets:

# Make several dictionaries, where the name of each dictionary is
# the name of a pet. In each dictionary, include the kind of animal
# and the owner's name. Store these dictionaries in a list called pets.

# Next, loop through your list and as you do print everything you know
# about each pet.

Suzy = {'type':'cat', 'name':'Suzy', 'owner':'Patricia'}
Jinx = {'type':'cat', 'name':'Jinx', 'owner':'Sarah'}
Fruit = {'type':'cat', 'name':'Fruit', 'owner':'Collin'}
Simon = {'type':'cat', 'name':'Simon', 'owner':'MaryAnn'}
Prudence = {'type':'cat', 'name':'Prudence', 'owner':'MaryAnn'}

pets = [Suzy, Jinx, Fruit, Simon, Prudence]

for p in pets:
    print("\nData about ", p['name'],":",sep='')
    for k,v in p.items():
        if k != 'name':
            print(k,": ",v,sep='')
