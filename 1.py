import re
filename="iv"
f=open(filename+".c","r")
a=f.read()
get_all_ver_nos=re.findall("v.\..\...",a)
print get_all_ver_nos
max_version_no=get_all_ver_nos[0];
for index in range(1,len(get_all_ver_nos)):
	if get_all_ver_nos[index]>max_version_no:
		max_version_no=get_all_ver_nos[index]

print max_version_no
	
