# d.	Large Shirts:
# Make a copy of program from part (c).
# Modify the make_shirt() function so that shirts are large by default
# with a message that reads I love Python.

# Make a large shirt and a medium shirt with the default message,
# and a shirt of any size with a different message.

def make_shirt(size, message="I love Python"):
    print("\nShirt size:",size)
    print("Message:", message)

make_shirt("Large")

make_shirt("Medium")

make_shirt(12, 'Que tal?')
