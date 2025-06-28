hw: 
	g++ hw.cpp hw32.cpp hw32.h -o hw

############### DON'T TOUCH BELOW #######################
run: hw
	@valgrind ./hw 2> out; python3 val.py