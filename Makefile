all: day01 day01b

day01: day01.c
	gcc -o day01 day01.c

day01b: day01b.c common.c
	gcc -o day01b common.c day01b.c