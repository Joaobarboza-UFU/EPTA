# Code that reads a CSV file containing the information about the trajectory of a rocket
# Joao Barboza Rodrigues
# Computer Engineering student at Federal University of Uberlandia

import codecs
import csv

f = open("foguete.txt",encoding='utf-8')
contents = f.read()
newcontents = contents.replace(',','.').replace(';',',')
f.close

file = open("output.csv",'w',newline='', encoding='utf-8')
file.write(finalcontents)
file.close

data_dict = {}
reader = csv.reader(open("output.csv"))
for row in reader:
    data_dict[row[8]] = {"time":[row[8]] , "East":[row[4]] , "North":[row[5]] , "Altitude Mar":[row[6]] , "Altitude":[row[7]] , "Verticle Speed":[row[11]], "Distance Travelled":[row[12]], "Ground speed":[row[13]], "Accelleartion":[row[14]]}

list_data = [*data_dict.values()] 
