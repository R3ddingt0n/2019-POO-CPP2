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
        cerr << "Usage : " << argv[0] << " [options] <filename>" << endl
             << "[options] can be a combination of :" << endl
             << "\t-g <filename.dot> : This option creates a graph of the different request targets from the log file." << endl
             << "\t-e : This option excludes every target that has a .png, .jpg, .jpeg, .gif, .ico, .css, .js extension." << endl
             << "\t-t <hour> : This option excludes every request that was not done between <hour>:00 and <hour+1>:00. <hour> has to be an integer." << endl;
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
        cout << "Dot-file <" << graphFile << "> generated." << endl;
        c.FillGraphEdges(tab, optionE, time);
        GraphGenerator::GenerateGraph(c, graphFile);
    }
    if(optionT)
    {
        cout << "Warning : only hits between " << (time < 10 ? "0" : "") << time << ":00:00 and " << (time+1 < 10 ? "0" : "") << time+1 << ":00:00 have been taken into account." << endl;
    }
    if(optionE)
    {
        cout << "Warning : only hits on non-JS, non-CSS, non-image documents have been taken into account." << endl;
    }
    c.FillHitsPerTarget(tab, optionE, time);
    c.ConvertMapToMultimap();
    RankingDisplayer::DisplayTopHits(c, TOP);

    return 0;
}
