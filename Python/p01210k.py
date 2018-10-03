# Summing a Million: Make a list of the numbers from one to one million, and
# then use min() and max() to make sure your list actually starts at one and ends at
# one million. Also, use the sum() function to see how quickly Python can add a
# million numbers.

numbers = range(1,1000001)

low = min(numbers)
print("first number in list:", low)
high = max(numbers)
print("last number in list:", high)
total = sum(numbers)
print("sum of values 1 to 10^6:", total)

