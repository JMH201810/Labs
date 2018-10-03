# Favorite Places:
# Make a dictionary called favorite_places.
# Think of three names to use as keys in the dictionary, and store one to
# three favorite places for each person.

# Loop through the dictionary, and print each person's name and their
# favorite places.

favorite_places = {'Alice':['Benton Harbor', 'Alice Springs', 'Utah'],
                   'Brenda':['Ann Arbor', 'Detroit', 'Eau Claire'],
                   'Charles':['under the  couch', 'VBISD', 'Michigan']}

for person,placeList in favorite_places.items():
    print("\n",person,"'s favorite places are:", sep='')
    for place in placeList:
        print(place)
