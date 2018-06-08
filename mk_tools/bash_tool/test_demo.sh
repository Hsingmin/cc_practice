#!/bin/bash
X=3
Y=4
empty_string=""
if [ $X -lt $Y ]	# is $X less than $Y ?
then
	echo "$X=${X}, which is smaller than $Y=${Y}"
fi

if [ -n "$empty_string" ]; then
	echo "empty string is non_empty"
fi

if [ -e "${HOME}/.fvwmrc" ]; then
	echo "you have a .fvwmrc file"
	if [ -L "${HOME}/.fvwmrc" ]; then
		echo "it's a symbolic  link"
	elif [ -f "${HOME}/.fvwmrc" ]; then
		echo "it's a regular file"
	fi
else
	echo "you have no .fvwmrc file"
fi


# loop demo
color1="red"
color2="light blue"
color3="dark green"
for X in "$color1" "$color2" "$color3"
do
	echo $X
done

for X in *.sh
do
	grep -L '<UL>' "$X"
done

# while loop
X=0
while [ $X -le 20 ]
do
	echo $X
	X=$((X+1))
done

files="$(ls)"
web_files=`ls public_html`
echo "$files"
echo "$web_files"
X=`expr 3 \* 2 + 4`
echo "$X"









