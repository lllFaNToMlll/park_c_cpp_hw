#!/bin/bash

tr -dc "A-Za-z 0-9" < /dev/urandom | fold -w100|head -n 10000000 > verybigfile.txt
tr -dc "A-Za-z 0-9" < /dev/urandom | fold -w100|head -n 1000000 > bigfile.txt
