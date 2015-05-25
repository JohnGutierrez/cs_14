// John Gutierrez
// SID: 861167274
// Date: 5/25/15

#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <set>
#include <unordered_set>
#include <ctime>
#include <cstdlib>
#include <utility>
using namespace std;

//self-balancing tree = set
//hash table = unordered set

void randomize(vector<string> &v)
{
    srand(0);
    for(unsigned i = 0; i < v.size(); i++)
    {
        int randIndex = rand() % v.size();
        swap(v.at(i), v.at(randIndex));
    }
}


int main(int argc, char* argv[])
{
    if(argc != 3)
    {
        cout << "Usage: ./a.out <file1> <file2>" << endl;
    }
    ifstream fin  (argv[1]);
    ofstream fout (argv[2]);
    
    if(!fin.is_open() || !fout.is_open())
    {
        cout << "Error opening files." << endl;
        exit(1);
    }
    
    vector<string> words;
    string word;
    while(fin >> word)
    {
        words.push_back(word);
    }
    
    int wordCount;
    std::chrono::duration<double> treeInsertTime, hashInsertTime, 
    treeQueryTime, hashQueryTime;
    
    set<string> my_set;
    unordered_set<string> my_unorderedSet;
    std::chrono::time_point<std::chrono::system_clock> start, end;
    
    for(int i = 1; i < 11; i++)
    {
        my_set.clear();
        my_unorderedSet.clear();
        randomize(words);
        wordCount = 5000 * i;
        
        //treeInsertTime
        start = std::chrono::system_clock::now();
        for(int i = 0; i < wordCount; i++)
        {
            my_set.insert(words.at(i));
        }
        end = std::chrono::system_clock::now();
        treeInsertTime = end - start;
        
        //hashInsertTime
        start = std::chrono::system_clock::now();
        for(int i = 0; i < wordCount; i++)
        {
            my_unorderedSet.insert(words.at(i));
        }
        end = std::chrono::system_clock::now();
        hashInsertTime = end - start;
        
        //treeQueryTime
        start = std::chrono::system_clock::now();
        for(int i = 0; i < wordCount; i++)
        {
            my_set.find(words.at(i));
        }
        end = std::chrono::system_clock::now();
        treeQueryTime = end - start;
        
        //hashQueryTime
        start = std::chrono::system_clock::now();
        for(int i = 0; i < wordCount; i++)
        {
            my_unorderedSet.find(words.at(i));
        }
        end = std::chrono::system_clock::now();
        hashQueryTime = end - start;
        
        fout << wordCount << " " << treeInsertTime.count() * 1000 << " " 
            << hashInsertTime.count() * 1000 << " " 
            << treeQueryTime.count() * 1000 << " " 
            << hashQueryTime.count() * 1000 << "\n";
    }
    return 0;
}