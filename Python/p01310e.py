# Glossary 2:
# Now that you know how to loop through a dictionary,
# clean up the code from (d.) by replacing your series of
# print statements with a loop that runs through the dictionary's
# keys and values.

# When you're sure that your loop works,
# add five more Python terms to your glossary.

# When you run your program again, these new words and meanings should
# automatically be included in the output.


glossary = {'compile':'convert from user-readable to machine-readable code',
            'IDE':'acronym for integraged development environment',
            'float':'data type for floating point number in C++',
            'io':'shortened form of input-output',
            'memory leak':'code going out of scope on an object without releasing the memory of the object'}

for i,j in glossary.items():
    print (i,":\n",j,"\n",sep='')

