#!/bin/sh

MYPATH=$PWD

if [ "clean" == "$1" ]; then 
	CLEAN='clean'
fi
cd src;
make $CLEAN; 
cd $MYPATH;
cd test;
make $CLEAN;

