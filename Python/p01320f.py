# f.	City Names:
# Write a function called city_country() that takes in the name of a city and
# its country. The function should return a string formatted like this:

# Santiago, Chile

# Call your function with at least three city-country pairs, and print the
# value that's returned. 

def city_country(city, country):
    retval = city + ", " + country
    return retval


    
place = city_country("Santiago", "Chile")
print (place)

place = city_country("Chicago", "United States")
print (place)

place = city_country("Berlin", "Germany")
print (place)
