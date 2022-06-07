import serial
import time
import MySQLdb as mdb
from datetime import date
from datetime import datetime

arduino = serial.Serial("/dev/ttyACM0")
arduino.baudrate=9600

data = arduino.readline()
time.sleep(1)
data = arduino.readline()
val = data.split(b'\t') //since the data published is in 1 array with 't' as a space so it is easier to split

//5 sensor values on split
rain = val[0]
temp = val[1]
humi = val[2]
press = val[3]
light = val[4]

today = date.today() //today's date

now = datetime.now() //today's time

dt_string = now.strftime("%H:%M:%S") //to display time in the format of Hour:Min:Sec


con = mdb.connect ('localhost', 'admin', '12345', 'iot') //connect to db

with con:
	cursor = con.cursor()
	sql=" SELECT ID FROM sensor ORDER BY ID DESC LIMIT 1 "
	cursor.execute(sql)
	last_id=cursor.fetchone() //fetch last id from db
	for lastID in last_id:
		id = lastID+1  //increment id 
		#print(id)
	cursor.execute("""INSERT INTO sensor VALUES(%s,%s,%s,%s,%s,%s,%s,%s)""", (id,temp, humi, press, light, rain, today, now))
	con.commit()
	cursor.close()

