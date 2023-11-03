#include <iostream>
#include <fstream>
#include <map>
#include <regex>
#include "lex.h"

std::map<std::string, Token>keyWordList = //for id_or_kw METHOD
{
    {"if",IF},
    {"writeln",WRITELN},
    {"else",ELSE},
    {"IF", IF},
    {"WRITELN", WRITELN},
    {"ELSE",ELSE}
};

LexItem id_or_kw(const string& lexeme, int linenum)
{
    Token tokType = IDENT;
    if (tokType)
    {
        if (lexeme[0] == '$')
        {
            tokType = NIDENT;
            return LexItem(tokType, lexeme, linenum);
        }
        if (lexeme[0] == '@')
        {
            tokType = SIDENT;
            return LexItem(tokType, lexeme, linenum);
        }
        else
        {
            const auto& tokIter = keyWordList.find(lexeme);
            if (tokIter != keyWordList.end())
            {
                tokType = tokIter->second;
            }
        }
    }
    return LexItem(tokType, lexeme, linenum);
}

ostream& operator<<(ostream& out, const LexItem& tok) //must figure out how to use in main
{
    Token tokType = tok.GetToken();
    switch (tokType)
    {
    case WRITELN:
    {
        out << "WRITELN";
        break;
    }
    case IF:
    {
        out << "IF";
        break;
    }
    case ELSE:
    {
        out << "ELSE";
        break;
    }
    case IDENT:
    {
        out << "IDENT" << '(' << tok.GetLexeme() << ')';
        break;
    }
    case NIDENT:
    {
        out << "NIDENT" << '(' << tok.GetLexeme() << ')';
        break;
    }
    case SIDENT:
    {
        out << "SIDENT" << '(' << tok.GetLexeme() << ')';
        break;
    }
    case ICONST:
    {
        out << "ICONST" << '(' << tok.GetLexeme() << ')';
        break;
    }
    case RCONST:
    {
        out << "RCONST" << '(' << tok.GetLexeme() << ')';
        break;
    }
    case SCONST:
    {
        out << "SCONST" << '(' << tok.GetLexeme() << ')';
        break;
    }
    case PLUS:
    {
        out << "PLUS";
        break;
    }
    case MINUS:
    {
        out << "MINUS";
        break;
    }
    case MULT:
    {
        out << "MULT";
        break;
    }
    case DIV:
    {
        out << "DIV";
        break;
    }
    case EXPONENT:
    {
        out << "EXPONENT";
        break;
    }
    case ASSOP:
    {
        out << "ASSOP";
        break;
    }
    case LPAREN:
    {
        out << "LPAREN";
        break;
    }
    case RPAREN:
    {
        out << "RPAREN";
        break;
    }
    case LBRACES:
    {
        out << "LBRACES";
        break;
    }
    case RBRACES:
    {
        out << "RBRACES";
        break;
    }
    case NEQ:
    {
        out << "NEQ";
        break;
    }
    case NGTHAN:
    {
        out << "NGTHAN";
        break;
    }
    case NLTHAN:
    {
        out << "NLTHAN";
        break;
    }
    case CAT:
    {
        out << "CAT";
        break;
    }
    case SREPEAT:
    {
        out << "SREPEAT";
        break;
    }
    case SEQ:
    {
        out << "SEQ";
        break;
    }
    case SLTHAN:
    {
        out << "SLTHAN";
        break;
    }
    case SGTHAN:
    {
        out << "SGTHAN";
        break;
    }
    case COMMA:
    {
        out << "COMMA";
        break;
    }
    case SEMICOL:
    {
        out << "SEMICOL";
        break;
    }
    default:
        break;
    }
    return out;
}

LexItem getNextToken(istream& in, int& linenum)
{
    enum TokState { START, INID, INSTRING, ININT, OPERATORS, PUNCT, PARENS, BRACES, INREAL, COMMENT }; //token STATES
    TokState lexState = START; //beginning of search
    string lexeme = ""; char ch;
    while (in.get(ch))
    {
        switch (lexState)
        {
        case START:
        {
            if (isspace(ch))
            {
                if (ch == '\n') // counting lines
                {
                    linenum++;
                }
                break;
            } // Whitespaces skipped

            lexeme = ch;

            if (isalpha(ch) != 0 || ch == '$' || ch == '@' || ch == '_')
            {
                lexState = INID; //Identifiers
            }
            else if (isdigit(ch) != 0)
            {
                lexState = ININT; //ICONST  OR RCONST
            }
            else if (ch == '&')
            {
                return LexItem(ERR, lexeme, linenum);
            }
            else if (ch == '\'')
            {
                lexState = INSTRING; //SCONST
            }
            //Signs and concatentations
            else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '<' || ch == '>' || ch == '=' || ch == '.')
            {
                in.putback(ch);
                lexState = OPERATORS;
            }
            else if (ch == ';' || ch == ',')
            {
                in.putback(ch);
                lexState = PUNCT;
            }
            else if (ch == '(' || ch == ')')
            {
                in.putback(ch);
                lexState = PARENS;
            }
            else if (ch == '{' || ch == '}')
            {
                in.putback(ch);
                lexState = BRACES;
            }
            else if (ch == '#')
            {
                lexState = COMMENT; //comment
            }
            else
            {
                return LexItem(ERR, lexeme += ch, linenum);
            }
            break;
        }
        case INID: // case sensitive
        {
            if (std::regex_match(lexeme + ch, regex("[_a-zA-Z]+[_a-zA-Z0-9]+")))
            {
                lexeme += ch;
            }
            else if (std::regex_match(lexeme + ch, regex("^\\@[_a-zA-Z][_a-zA-Z0-9]*")))
            {
                lexeme += ch;
            }
            else if (std::regex_match(lexeme + ch, regex("^\\$[_a-zA-Z][_a-zA-Z0-9]*")))
            {
                lexeme+=ch;
            }
            else
            {
                in.putback(ch);
                return id_or_kw(lexeme, linenum);
            }
            break;
        }
        case INSTRING:
        {
            if (ch == '\n')
            {
                return LexItem(ERR, lexeme , linenum); //cannot go to new line
            }
            else if (ch == '\'')
            {
                return LexItem(SCONST, lexeme.substr(1, lexeme.size()), linenum);
            }
            else
            {
                lexeme += ch;
            }
            break;
        }
        case ININT:
        {
            if (std::regex_match(lexeme + ch, std::regex("[0-9]+")))
            {
                lexeme += ch;
            }
            else if (ch == '.') //if decimal found, may be RCONST
            {
                lexeme += ch;
                lexState = INREAL;
            }
            else
            {
                in.putback(ch);
                return LexItem(ICONST, lexeme, linenum);
            }
            break;
        }
        case INREAL:
        {
            if (ch == '.')
            {
                return LexItem(ERR, lexeme+=ch, linenum);
            }
            else if (std::regex_match(lexeme + ch, std::regex("[0-9]+\\.[0-9]*")))
            {
                lexeme += ch;
            }
            else
            {
                in.putback(ch);
                return LexItem(RCONST, lexeme, linenum);
            }
            break;
        }
        case OPERATORS:
        {
            if (ch == '+')
            {
                return LexItem(PLUS, lexeme += ch, linenum);
            }
            else if (ch == '-')
            {

                if (char(in.peek()) == 'E' || char(in.peek()) == 'e') //String EQ
                {
                    in.get(ch);
                    if (char(in.peek()) == 'Q' || in.peek() == 'q')
                    {
                        lexeme += ch;
                        in.get(ch);
                        lexeme += ch;
                        return LexItem(SEQ, lexeme, linenum);
                    }
                }
                else if (char(in.peek()) == 'G' || char(in.peek()) == 'g') // String greater
                {
                    in.get(ch);
                    if (char(in.peek()) == 'T' || in.peek() == 't')
                    {
                        lexeme += ch;
                        in.get(ch);
                        lexeme += ch;
                        return LexItem(SGTHAN, lexeme, linenum);
                    }
                }
                else if (char(in.peek()) == 'L' || char(in.peek()) == 'l') //String less
                {
                    in.get(ch);
                    if (char(in.peek()) == 'T' || in.peek() == 't')
                    {
                        lexeme += ch;
                        in.get(ch);
                        lexeme += ch;
                        return LexItem(SLTHAN, lexeme, linenum);
                    }
                }
                else
                {
                    return LexItem(MINUS, lexeme+=ch, linenum);
                }
            }
   
            else if (ch == '*')
            {
                if (char(in.peek()) == '*')
                {
                    in.get(ch);
                    return LexItem(SREPEAT, lexeme += ch, linenum);
                }
                return LexItem(MULT, lexeme += ch, linenum);
            }
            else if (ch == '/')
            {
                return LexItem(DIV, lexeme += ch, linenum);
            }
            else if (ch == '^')
            {
                return LexItem(EXPONENT, lexeme += ch, linenum);
            }
            else if (ch == '<')
            {
                return LexItem(NLTHAN, lexeme += ch, linenum);
            }
            else if (ch == '>')
            {
                return LexItem(NGTHAN, lexeme += ch, linenum);
            }
            else if (ch == '=')
            {
                if (in.peek() == '=')
                {
                    in.get(ch);
                    return LexItem(NEQ, lexeme += ch, linenum);
                }
                else
                {
                    return LexItem(ASSOP, lexeme += ch, linenum);
                }
            }
            else if (ch == '.')
            {
                return LexItem(CAT, lexeme += ch, linenum);
            }
            break;
        }
        case PARENS:
        {
            if (ch == '(')
            {
                return LexItem(LPAREN, lexeme += ch, linenum);
            }
            else if (ch == ')')
            {
                return LexItem(RPAREN, lexeme += ch, linenum);
            }
            break;
        }
        case BRACES:
        {
            if (ch == '{')
            {
                return LexItem(LBRACES, lexeme += ch, linenum);
            }
            else if (ch == '}')
            {
                return LexItem(RBRACES, lexeme += ch, linenum);
            }
            break;
        }
        case PUNCT:
        {
            if (ch == ';')
            {
                return LexItem(SEMICOL, lexeme += ch, linenum);
            }
            else if (ch == ',')
            {
                return LexItem(COMMA, lexeme += ch, linenum);
            }
            break;
        }
        case COMMENT:
        {
            if (ch == '\n')
            {
                linenum++;
                lexState = START; //Comments ignored
            }
            break;
        }
        default:
            break;
        }
    }
    if (in.peek() == EOF)
    {
        return LexItem(DONE, "", linenum);
    }
    else
    {
        return LexItem(ERR, lexeme, linenum);
    }
}