filename = input("Filename > ")
filesize = input("Filesize (bytes) > ")
filesize = int(filesize)
s = input("string: (if left blank none will be included)")

size = filesize - len(s) if s != "" else filesize
with open(filename, 'wb') as f:
	f.write(s.encode())
	f.write('\x00'.encode()*size)
	f.close()