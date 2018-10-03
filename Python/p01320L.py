# l.	Sandwiches:
# Write a function that accepts a list of items a person wants on a sandwich.

# The function should have one parameter that collects as many items as the
# function call provides, and it should print a summary of the sandwich that
# is being ordered.

# Call the function three times, using a different number
# of arguments each time.


def toppings(*thing):
    print ()
    for t in thing:
        print('-', t)

toppings('butter', 'air', 'salt')

toppings('worms', 'sand', 'rocks', 'tahini')

toppings('wallets', 'staplers')
