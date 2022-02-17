#!/bin/zsh
testcase_filename=("" "rt" ".rt" "qwe" "qwe.rt" "qwe.rt.qwe" "qwe.rt.qwe.rt")


for testcase in ${testcase_filename}
do
	echo "> ./miniRT ${testcase}"
	./miniRT ${testcase}
done
