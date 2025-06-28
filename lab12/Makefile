part1: 
	g++ part1.cpp library.cpp library.h -o part1
part2: 
	g++ part2.cpp library.cpp library.h -o part2
part3: 
	g++ part3.cpp library.cpp library.h -o part3
part4: 
	g++ part4.cpp library.cpp library.h -o part4

############# DON'T TOUCH BELOW ################
run%: part%
	@valgrind ./part$* 2> out; python3 val.py