part1: part1.cpp
	g++ -o part1 part1.cpp easycurses.cpp Pos.cpp board.cpp -l ncurses
	
part2: 
	g++ -o part2 part2.cpp easycurses.cpp Pos.cpp board.cpp -l ncurses
part3: 
	g++ -o part3 part3.cpp easycurses.cpp Pos.cpp board.cpp -l ncurses
part4: 
	g++ -opart4 part4.cpp easycurses.cpp Pos.cpp board.cpp -l ncurses
part5: 
	g++ -opart5 part5.cpp easycurses.cpp Pos.cpp board.cpp -l ncurses
part6: 

################## DON'T TOUCH BELOW ##################
run1: part1
	@./part1
run_%: %
	@test -f $* && echo "$*: Code compiled successfully" 
