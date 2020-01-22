#include <iostream>
#include <vector>
#include <cstring>
#include "LogReader.h"
#include "Request.h"

using namespace std;

const int TOP = 10;

int main(int argc, char* argv[]){
    string logFile;
    string graphFile;
    bool optionE = false;
    bool graph = false;
    bool optionT = false;
    int time = -1;
    int i = 1;
    if(argc <= 1)
    {
        cerr << "Usage blablabla argc" << endl;
        //TODO
        return 1;
    }
    while(i < argc-1)
    {
        if(strcmp(argv[i], "-g") == 0 && !graph)
        {
            graph = true;
            ++i;
            graphFile = argv[i];
        }
        else if(strcmp(argv[i], "-e") == 0 and !optionE)
        {
            optionE = true;
        }
        else if(strcmp(argv[i], "-t") == 0 && !optionT)
        {
            optionT = true;
            ++i;
            time = atoi(argv[i])%24;
        }
        else
        {
            cerr << "Usage blablabla while" << endl;
            //TODO
            return 1;
        }
        ++i;
    }
    logFile = string(argv[i]);
    std::vector<Request> tab;
    LogReader::ReadFile(logFile, tab);
    Catalog c;
    if(graph)
    {
        c.FillGraphEdges(tab, optionE, time);
        GraphGenerator::GenerateGraph(c, graphFile);
    }
    else
    {
        c.FillHitsPerTarget(tab, optionE, time);
        c.ConvertMapToMultimap();
        RankingDisplayer::DisplayTopHits(c, TOP);
    }

    return 0;
}
