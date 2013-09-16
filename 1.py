import re
import os

def print_ver_no(filename):
	#filename="iv"
	with open("./"+filename+"/"+filename+".c","r") as f:
		a=f.read()
		f.closed
	get_all_ver_nos=re.findall("v.\..\...",a)
	print get_all_ver_nos
	max_version_no=get_all_ver_nos[0];
	for index in range(1,len(get_all_ver_nos)):
		if get_all_ver_nos[index]>max_version_no:
			max_version_no=get_all_ver_nos[index]

	print max_version_no
	
	

print_ver_no("iv")
