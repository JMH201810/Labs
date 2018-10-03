
# Seeing the World: Think of at least five places in the world you'd like to visit.

# i. Store the locations in a list. Make sure the list is not in alphabetical order.
places = ['Zanzibar', 'Peru', 'Aden', 'Brazil', 'Calcutta']

# ii. Print your list in its original order. Don't worry about printing the list
#     neatly, just print it as a raw Python list.
print("Raw list:")
print(places,'\n')

# iii. Use sorted() to print your list in alphabetical order without modifying the
#      actual list.
print("Sorted list:")
print(sorted(places), '\n')

# iv. Show that your list is still in its original order by printing it.
print("Raw list:")
print(places,'\n')

# v. Use sorted() to print your list in reverse alphabetical order without
#    changing the order of the original list.
print("Reverse sorted list:")
print(sorted(places, reverse = True), '\n')

# vi. Show that your list is still in its original order by printing it again.
print("Raw list:")
print(places,'\n')

# vii. Use reverse() to change the order of your list. Print the list to show that its
#      order has changed.
places.reverse()
print("Reverse sorted list:")
print(places,'\n')

# viii. Use reverse() to change the order of your list again. Print the list to show
#       it's back to its original order.
places.reverse()
print("Back to forward sorted list:")
print(places,'\n')

# ix. Use sort() to change your list so it's stored in alphabetical order. Print the
#     list to show that its order has been changed.
places.sort()
print("Alphabetically sorted list:")
print(places,'\n')

# x. Use sort() to change your list so it's stored in reverse alphabetical order.
#    Print the list to show that its order has changed.
places.sort(reverse = True)
print("Reverse alphabetically sorted list:")
print(places,'\n')




