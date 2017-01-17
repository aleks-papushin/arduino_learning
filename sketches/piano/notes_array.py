#!/usr/bin/python

with open('tones.h') as oldfile, open('tones_wtht_sharps_array.txt', 'w') as newfile:
    newfile.write('int tones = {')
    for line in oldfile:        
        if not 'S' in line:            
            newfile.write(line.replace('#define', '')[:8])
            newfile.write(', ')
    newfile.write('}')
