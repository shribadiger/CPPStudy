# codeing the functionality of the bytes and how that each bytes are going to work in the each object
# let check the functionality of each charector which are assigned to the variable and that is going to
data = 'my user data going to encode by encoding technique'
encodedData = data.encode('utf-8')
print(encodedData)
decodeData = encodedData.decode('utf-8')
if encodedData == decodeData:
    print('encoding and decoding data both are same')
