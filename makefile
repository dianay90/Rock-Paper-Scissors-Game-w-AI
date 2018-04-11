default: inputValidation.cpp Tool.cpp RPSGame.cpp Scissors.cpp Rock.cpp Paper.cpp groupProjMain.cpp InputVal.cpp
	g++ -std=c++0x inputValidation.cpp Tool.cpp RPSGame.cpp Scissors.cpp Rock.cpp Paper.cpp InputVal.cpp groupProjMain.cpp  -o p

clean: 
	rm p
	

