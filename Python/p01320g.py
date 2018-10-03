# g.	Album:
# Write a function called make_album() that builds a dictionary describing
# a music album. The function should take in an artist name and an album
# title, and it should return a dictionary containing these two pieces of
# information. Use the function to make three dictionaries representing
# different albums. Print each return value to show that the dictionaries
# are storing the album information correctly.

# Add an optional parameter to make_album() that allows you to store the
# number of tracks on an album. If the calling line includes a value for
# the number of tracks, add that value to the album's dictionary.
# Make at least one new function call that includes the number of tracks on
# an album.

def make_album(artist_name, album_title, nTracks=''):
    if nTracks:
        d = {'artist_name':artist_name,
             'album_title':album_title,
             'nTracks':nTracks}
    else:
        d = {'artist_name':artist_name,
             'album_title':album_title}
    return d


d1 = make_album('Bob','Album1')
d2 = make_album('Donald','Album2')
d3 = make_album('Gertrude','Album3')

print ('\n', d1, '\n', d2, '\n', d3)

d1 = make_album('Bob','Album1')
d2 = make_album('Donald','Album2')
d3 = make_album('Gertrude','Album3', 7)

print ('\n', d1, '\n', d2, '\n', d3)

