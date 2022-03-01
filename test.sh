#!/bin/zsh
#testcase_filename=("" "rt" ".rt" "qwe" "qwe.rt" "qwe.rt.qwe" "qwe.rt.qwe.rt")
#
#
#for testcase in ${testcase_filename}
#do
#	echo "> ./miniRT ${testcase}"
#	./miniRT ${testcase}
#done
#
#clear
#error_case=(`ls scene/error.*`)
#echo error case
#read; clear
#for testcase in ${error_case}
#do
#	echo error case
#	echo "> cat ${testcase}; leaks -atExit -- ./miniRT ${testcase}"
#	cat ${testcase}; leaks -atExit -- ./miniRT ${testcase}
#	read; clear
#done
#
#clear
#basic_case=(`ls scene/basic.*`)
#echo basic case
#read; clear
#for testcase in ${basic_case}
#do
#	echo basic case
#	echo "> cat ${testcase}; leaks -atExit -- ./miniRT ${testcase}"
#	cat ${testcase}; leaks -atExit -- ./miniRT ${testcase}
#	read; clear
#done
#
#clear
#case=(`ls scene/translate.*`)
#case+="scene/rotate.cylinder.90.rt"
#echo translations and rotations
#read; clear
#for testcase in ${case}
#do
#	echo translations and rotations
#	echo "> cat ${testcase}; leaks -atExit -- ./miniRT ${testcase}"
#	cat ${testcase}; leaks -atExit -- ./miniRT ${testcase}
#	read; clear
#done
#
#
#case=(`ls scene/multiobject.*`)
#echo multiobject 
#read; clear
#for testcase in ${case}
#do
#	echo multiobject 
#	echo "> cat ${testcase}; leaks -atExit -- ./miniRT ${testcase}"
#	cat ${testcase}; leaks -atExit -- ./miniRT ${testcase}
#	read; clear
#done
#
#case=(`ls scene/camera.*`)
#echo camera 
#read; clear
#for testcase in ${case}
#do
#	echo camera 
#	echo "> cat ${testcase}; leaks -atExit -- ./miniRT ${testcase}"
#	cat ${testcase}; leaks -atExit -- ./miniRT ${testcase}
#	read; clear
#done
#
#
case=(`ls scene/brightness*`)
echo brightness 
read; clear
for testcase in ${case}
do
	echo brightness 
	echo "> cat ${testcase}; leaks -atExit -- ./miniRT ${testcase}"
	cat ${testcase}; leaks -atExit -- ./miniRT ${testcase}
	read; clear
done

case=(`ls scene/bonus.*`)
echo bonus 
read; clear
for testcase in ${case}
do
	echo bonus 
	echo "> cat ${testcase}; leaks -atExit -- ./miniRT_bonus ${testcase}"
	cat ${testcase}; leaks -atExit -- ./miniRT_bonus ${testcase}
	read; clear
done
