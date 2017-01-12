#!/usr/bin/python

with open('tones.txt') as oldfile, open('tones_wtht_sharps_array.txt', 'w') as newfile:
    newfile.write('int tones = {')
    for line in oldfile:        
        if not 'S' in line:            
            newfile.write(line.replace('#define NOTE_', '')[:2])
            newfile.write(', ')
    newfile.write('}')
