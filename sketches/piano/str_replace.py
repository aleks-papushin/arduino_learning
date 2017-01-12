#!/usr/bin/python

with open('tones.txt') as oldfile, open('tones_wtht_sharps.txt', 'w') as newfile:
    for line in oldfile:
        newfile.write(line.replace('NOTE_', ''))
