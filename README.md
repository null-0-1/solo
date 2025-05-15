# solo 
solo is a light weight and simple version control system (vcs)
specifically made for solo devs to use on tracking versions of their mini/small projects 

# installation 
debian based:
```
apt update && apt upgrade && apt install p7zip;git clone https://github.com/nul-0-1/solo;cd solo;g++ solo.cxx -o solo;./solo -n test
```

# how to use 

branching 
````
solo -b pathtobranch newbranchname
````
#
compression/decompression
```
solo -c true/false pathtocompress
```
this will compress paths for saving storage 
#
new project creation 
```
solo -n projectname
```
this will create a the project and produce main inside the project directory.
