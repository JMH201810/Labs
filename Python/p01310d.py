# Glossary: A Python dictionary can be used to model an actual dictionary.
# However, to avoid confusion, call it a glossary.
# •	Think of five programming words you've learned about in your studies,
#       so far. Use these words as the keys in your glossary, and store their
#       meanings as values.
# •	Print each word and its meaning as neatly formatted output.
#       You might print the word followed by a colon and then its meaning,
#       or print the word on one line and then print its meaning indented
#       on a second line. Use the newline character (\n) to insert a
#       blank line between each word-meaning pair in your output.

glossary = {'compile':'convert from user-readable to machine-readable code',
            'IDE':'acronym for integraged development environment',
            'float':'data type for floating point number in C++',
            'io':'shortened form of input-output',
            'memory leak':'code going out of scope on an object without releasing the memory of the object'}

print('compile',
      ":\n",
      glossary['compile'],
      "\n",sep='')

print('IDE',
      ":\n",
      glossary['IDE'],
      "\n",sep='')

print('float',
      ":\n",
      glossary['float'],
      "\n",sep='')

print('io',
      ":\n",
      glossary['io'],
      "\n",sep='')

print('memory leak',
      ":\n",
      glossary['memory leak'],
      "\n",sep='')


#for i,j in glossary.items():
#    print (i,":\n",j,"\n",sep='')
