#!/bin/sh

for arquivo in $(file * | grep ISO | cut -f 1 -d ":"); do
	echo Convertendo $arquivo
	cp $arquivo $arquivo.iso
	iconv -f ISO_8859-1 -t UTF-8 $arquivo.iso > $arquivo
done
