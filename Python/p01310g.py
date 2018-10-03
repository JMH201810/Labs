# Polling:
# Use the code in favorite_languages.py.



# •	Loop through the list of people who should take the poll.

#       If they have already taken the poll,
#       print a message thanking them for responding.

#       If they have not yet taken the poll,
#       print a message inviting them to take the poll.



favorite_languages = {
      'jen': ['python', 'ruby'],
      'sarah': ['c'],
      'edward': ['ruby', 'go'],
      'phil': ['python', 'haskell'],
      }

for name, languages in favorite_languages.items():
      print("\n" + name.title() + "'s favorite languages are:")
      for language in languages:
          print("\t" + language.title())

people = ['c','jen', 'sarah', 'edward', 'phil', 'connor', 'hailey', 'anthony', 'cody', 'valerie']

for p in people:
    if p in favorite_languages:
        print(p, "Thank you for taking the poll.")
    else:
        print(p, "Please take the poll.")


