ECHO=@echo
RM=@rm
COMP=g++
EDL=g++
RMFLAGS=-f
CPPFLAGS=-ansi -pedantic -Wall -Werror -std=c++11
CPPFLAGSDEBUG= -g -DMAP
EDLFLAGS=
INT=Trajet.h TrajetSimple.h TrajetComplexe.h Catalogue.h
REAL=$(INT:.h=.cpp) main.cpp
OBJ=$(REAL:.cpp=.o)
EXE=main
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
