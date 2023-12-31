#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm> 
#include "lex.h"


void commandLineArgs(const std::string& flag, bool& Vflag, bool& ncFlag, bool& scFlag, bool& idFlag, int& counter) //DETERMINING ARGUMENTS
{
    if (std::string(flag).compare("-v") == 0)
    {
        Vflag = true;
    }
    else if (std::string(flag).compare("-nconst") == 0)
    {
        ncFlag = true;
    }
    else if (std::string(flag).compare("-sconst") == 0)
    {
        scFlag = true;
    }
    else  if (std::string(flag).compare("-ident") == 0)
    {
        idFlag = true;
    }
    else if (std::string(flag).compare("-hello") == 0)
    {
        std::cerr << "UNRECOGNIZED FLAG" << " {" << flag << "}" << std::endl;
        exit(1);
    }
    else
    {
        counter++;
    }
}

int main(int argc, char* argv[])
{
    ifstream file;
    int linenum = 0; int tokCount = 0; int fileNum = 0;
    bool vFlag = false; bool sconstFlag = false; bool nconstFlag = false; bool identFlag = false; 
    
    std::vector<std::string> IDENTIFIERS; std::vector<std::string> NUMBERS; std::vector<std::string> STRINGS;

    for (int i = 1; i < argc; i++)
    {
        commandLineArgs(std::string(argv[i]), vFlag, nconstFlag, sconstFlag, identFlag, fileNum);
    }
    
    if (fileNum == 1)
    {
        file.open(std::string(argv[1]));
        if (file.is_open())
        {
            if (file.peek() == EOF)
            {
                std::cout << "Lines: 0" << std::endl;
                std::cout << "Empty File." << std::endl;
                exit(0);
            }
        }
        else if (file.fail())
        {
            std::cerr << "CANNOT OPEN THE FILE " << std::string(argv[1]) << std::endl;
            exit(1);
        }
    }
    if (fileNum < 1)
    {
        std::cerr << "NO SPECIFIED INPUT FILE." << endl;
        exit(1);
    }
    else if (fileNum > 1)
    {
        std::cerr << "ONLY ONE FILE NAME IS ALLOWED." << std::endl;
        exit(1);
    }

    LexItem token;
    while ((token = getNextToken(file, linenum)) != DONE)
    {
        tokCount++;
        if (token == ERR)
        {
            std::cout << "Error in line " << (token.GetLinenum() + 1) << " (" << token.GetLexeme() << ')' << std::endl;
            exit(1);
        }
        if (vFlag)
        {
            std::cout << token << std::endl;
        }
        if ((token == IDENT || token == NIDENT || token == SIDENT) && std::find(IDENTIFIERS.begin(), IDENTIFIERS.end(), token.GetLexeme()) == IDENTIFIERS.end())
        {
            IDENTIFIERS.push_back(token.GetLexeme());
        }
        if ((token == ICONST || token == RCONST) && std::find(NUMBERS.begin(), NUMBERS.end(), token.GetLexeme()) == NUMBERS.end())
        {
            bool isSorted = false;
            std::string str = token.GetLexeme();
            for (auto iter = NUMBERS.begin(); iter != NUMBERS.end(); iter++)
            {
                if (stod(str) < stod(*iter))
                {
                    int i = 0;
                    while (str[i] == '0') 
                    { 
                        i++;
                    }
                    if (str[i] != '.')
                    {
                        str.erase(0, i); 
                    }
                    else
                    {
                        str.erase(0, i - 1);
                    }
                    NUMBERS.insert(iter, 1, str);
                    isSorted = true;
                    break; 
                }
            }
            if (!isSorted)
            {
                NUMBERS.push_back(str);
            }
        }
        if (token == SCONST && std::find(STRINGS.begin(), STRINGS.end(), token.GetLexeme()) == STRINGS.end())
        {
            STRINGS.push_back(token.GetLexeme());
        }
    }
    if (token != ERR)
    {
        std::cout << "\n" << "Lines: " << linenum << std::endl;
        std::cout << "Total Tokens: " << tokCount << std::endl;
        std::cout << "Identifiers: " << IDENTIFIERS.size() << std::endl;
        std::cout << "Numbers: " << NUMBERS.size() << std::endl;
        std::cout << "Strings: " << STRINGS.size() << std::endl;
    }
    if (identFlag)
    {
        std::sort(IDENTIFIERS.begin(), IDENTIFIERS.end());
        std::cout << "IDENTIFIERS:" << std::endl;
        for (auto iter = IDENTIFIERS.begin(); iter != IDENTIFIERS.end(); iter++)
        {
            if (iter == IDENTIFIERS.begin())
            {
                std::cout << *iter;
                continue;
            }
            std::cout << ", " << *iter;
        }
        std::cout << std::endl;
    }
    if (nconstFlag)
    {
        //std::sort(NUMBERS.begin(), NUMBERS.end(), [](std::string const& A, std::string const& B) { return std::stof(A) < std::stof(B); });
        std::cout << "NUMBERS:" << std::endl;
        for (auto iter = NUMBERS.begin(); iter != NUMBERS.end(); iter++)
        {
            std::cout << *iter << std::endl;
        }
    }
    if (sconstFlag)
    {
        std::sort(STRINGS.begin(), STRINGS.end());
        std::cout << "STRINGS:" << std::endl;
        for (auto iter = STRINGS.begin(); iter != STRINGS.end(); iter++)
        {
            std::cout << '\'' << *iter << '\'' << std::endl;
        }
    }
    return 0;
}