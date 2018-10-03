# Cities:
# Make a dictionary called cities.

# Use the names of three cities as keys in your dictionary.
# Create a dictionary of information about each city and include the
# country that the city is in, its approximate population,
# and one fact about that city.

# The keys for each city's dictionary should be something like country,
# population, and fact.

# Print the name of each city and all of the information you have stored
# about it.

cities = {'Ann Arbor':{'country':'United States',
                       'population':120782,
                       'fact':'home of the University of Michigan'},
          'Istanbul':{'country':'Turkey',
                      'population':15.03e6,
                      'fact':'spans two continents'},
          'San Luis Potosi':{'country':'Mexico',
                             'population':2.718e6,
                             'fact':'location of three vision machines by HRC'}
          }

for city,city_info in cities.items():
    print("\nInformation about",city)
    for entry,value in city_info.items():
        if entry == 'population' and value >= 1e6:
            newValue = value * 1e-6
            print(entry,"=",newValue,"million")
        else:
            print(entry,"=",value)

                       
