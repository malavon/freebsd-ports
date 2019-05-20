#!/bin/sh

BRANCHES=$( git branch | grep -v master | cut -c3-999)

OLD_IFS=$IFS
IFS=$'\n'

git fetch --all

git checkout master
git rebase upstream/main

for BRANCH in $BRANCHES
do
	echo Rebasing branch: $BRANCH
	git checkout $BRANCH
	git rebase upstream/main
done
IFS=$OLD_IFS

git checkout master

echo "Time to do a 'git push --all -f'?"
