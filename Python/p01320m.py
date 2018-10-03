# m.	Cars:
# Write a function that stores information about a car in a dictionary.

# The function should always receive a manufacturer and a model name.
# It should then accept an arbitrary number of keyword arguments.

# Call the function with the required information and two other name-value
# pairs, such as a color or an optional feature. Your function should work for
# a call like this one:

# car = make_car('subaru', 'outback', color='blue', tow_package=True)


# Print the dictionary that's returned to make sure all the information was
# stored correctly.  


def make_car(manufacturer, model, **features):
    d = {'manufacturer':manufacturer, 'model':model}
    for key,value in features.items():
        d.update({key:value})

    return d

car = make_car('Subaru', 'Outback', color='blue', tow_package=True)
car2 = make_car('Volkswagen', 'Beetle', wings=False, paddles='long')

print(car)
print(car2)
