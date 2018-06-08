
#!/bin/bash

# start the comment
echo "Hello World!"
echo "hello, $USER. I wish to list some files of yours"
echo "listing files in the current directory, $PWD"
ls	# list all files

X=""
if [ -n $X ]; then
	echo "the variable X is not the empty string"
fi

Y=""
if [ -n "$Y" ]; then
	echo "the variable Y is not the empty string"
fi

#LS="ls"
#LS_FLAGS="-al"

#$LS $LS_FLAGS $HOME

VAR=ABC
echo "${VAR}abc"












