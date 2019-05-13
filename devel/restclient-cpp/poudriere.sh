#!/bin/sh
poudriere testport -j amd64 $1 -o devel/restclient-cpp
