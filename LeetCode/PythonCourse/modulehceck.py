
from urllib.request import urlopen

story = urlopen('http://sixty-north.com/c/t.txt')
story_words = []
print(story)

story.close()
