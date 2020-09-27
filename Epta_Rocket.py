# Code that reads a CSV file containing the information about the trajectory of a rocket
# Joao Barboza Rodrigues
# Computer Engineering student at Federal University of Uberlandia

import codecs
import csv
import matplotlib.pyplot as plt
import numpy as np

import codecs
import csv
import matplotlib.pyplot as plt
import numpy as np

f = open("foguete.txt",encoding='utf-8')
contents = f.read()
newcontents = contents.replace(',','.').replace(';',',')
f.close

file = open("output.csv",'w',newline='', encoding='utf-8')
file.write(newcontents)
file.close

data_dict = {}
reader = csv.reader(open("output.csv"))
for row in reader:
    data_dict[row[8]] = {"time":[row[8]] , "East":[row[4]] , "North":[row[5]] , "Altitude Mar":[row[6]] , "Altitude":[row[7]] , "Verticle Speed":[row[11]], "Distance Travelled":[row[12]], "Ground speed":[row[13]], "Accelleration":[row[14]]}

list_data = [*data_dict.values()] 

x_data = []
y_data = []
z_data = []
verticle_speed = []

for i in range(266):
    x_data.append(float(list_data[i]['North'][0]))
    y_data.append(float(list_data[i]['East'][0]))
    z_data.append(float(list_data[i]['Altitude'][0]))
    verticle_speed.append(float(list_data[i]["Verticle Speed"][0]))
    
    
ax = plt.axes(projection='3d')
ax.set_title('Trajetória foguete');
ax.scatter(x_data, y_data, z_data, c=x_data, cmap='viridis', linewidth=0.5);

fig= plt.figure(figsize=(6,3))
axes= fig.add_axes([0.1,0.1,0.8,0.8])
axes.set_title('Eixo x e z ( Visão de lado )');
axes.plot(x_data,z_data)
fig1= plt.figure(figsize=(6,3))
axes1= fig1.add_axes([0.1,0.1,0.8,0.8])
axes1.set_title('Eixo y e z ( Visão de lado )');
axes1.plot(y_data,z_data)
fig2= plt.figure(figsize=(6,3))
axes2= fig2.add_axes([0.1,0.1,0.8,0.8])
axes2.set_title('Eixo x e y ( Visão de cima )');
axes2.plot(x_data,y_data)


plt.show()
