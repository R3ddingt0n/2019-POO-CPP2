ECHO=@echo
RM=@rm
COMP=g++
EDL=g++
RMFLAGS=-f
CPPFLAGS=-ansi -pedantic -Wall -Werror -std=c++11
CPPFLAGSDEBUG= -g #-DMAP
EDLFLAGS=
INT=Request.h Catalog.h LogReader.h RankingDisplayer.h GraphGenerator.h
REAL=$(INT:.h=.cpp) main.cpp
OBJ=$(REAL:.cpp=.o)
EXE=analog
LIBS=
CLEAN=clean
CORE=core

$(EXE): $(OBJ)
	$(ECHO) "Edition des liens de <$(EXE)>"
	$(EDL) $(EDLFLAGS) -o $@ $^ $(LIBS)

%.o: %.cpp
	$(ECHO) "Compilation de <$@>"
	$(COMP) $(CPPFLAGS) $(CPPFLAGSDEBUG) -c -o $@ $<

$(CLEAN):
	$(RM) $(RMFLAGS) $(EXE) $(OBJ) $(CORE)

.PHONY: $(CLEAN)
