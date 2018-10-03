# h.	User Albums:
# Make a copy of your program from part (g) and modify it by writing a while
# loop that allows users to enter an album's artist and title.

# Once you have that information, call make_album() with the user's input
# and print the dictionary that's created. Be sure to include a quit value
# in the while loop.



def make_album(artist_name, album_title, nTracks=''):
    if nTracks:
        d = {'artist_name':artist_name,
             'album_title':album_title,
             'nTracks':nTracks}
    else:
        d = {'artist_name':artist_name,
             'album_title':album_title}
    return d


albumList = []

while True:
    print("\nEnter artist name (q to quit): ",end='')
    artist = input()
    if artist == "q":
        break
    print("Enter album title: ",end='')
    album = input()
    print("Enter album title (-1 to omit): ",end='')
    n = int(input())

    if n != -1:
        # include number of tracks
        d1 = make_album(artist,album,n)
    else:
        #omit number of tracks
        d1 = make_album(artist,album)
        
    albumList.append(d1)


for d in albumList:
    for key,value in d.items():
        if key == 'artist_name':
            print("\nName:",value)
        elif key == 'album_title':
            print("Album:",value)
        elif key == 'nTracks':
            print("# Tracks:",value)

