#!/usr/bin/python

output_file = open("notes", "w")
data = open("ToneKeyboard.txt").read()
output_file.write(data.replace("NOTE_", ""))
output_file.close()