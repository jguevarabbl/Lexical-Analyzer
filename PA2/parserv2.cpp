/* Implementation of Recursive-Descent Parser
 * parser.cpp
*/

#include "parser.h"

map<string, bool> defVar;
map<string, Token> SymTable;

namespace Parser {
	bool pushed_back = false;
	LexItem	pushed_token;

	static LexItem GetNextToken(istream& in, int& line) {
		if (pushed_back) {
			pushed_back = false;
			return pushed_token;
		}
		return getNextToken(in, line);
	}

	static void PushBackToken(LexItem& t) {
		if (pushed_back) {
			abort();
		}
		pushed_back = true;
		pushed_token = t;
	}

}

static int error_count = 0;

int ErrCount()
{
	return error_count;
}

void ParseError(int line, string msg)
{
	++error_count;
	cout << error_count << ". Line # " << line << ": " << msg << endl;
}

bool Prog(istream& in, int& line)
{
	bool status = StmtList(in, line);
	if (!status)
	{
		ParseError(line, "Missing Program");
		return false;
	}
	std::cout << "(DONE)" << std::endl;
	return true;
}
bool StmtList(istream& in, int& line)
{
	bool status = Stmt(in, line);
	if (!status)
	{
		ParseError(line, "Missing Statement"); // will likely be changed
		return false;
	}

	LexItem token = Parser::GetNextToken(in, line);
	if (token.GetToken() != SEMICOL)
	{
		ParseError(line, "Missing SemiColon");
		return false;
	}

	token = Parser::GetNextToken(in, line);
	if (token.GetToken() == RBRACES)
	{
		Parser::PushBackToken(token);
		return true;
	}
	if (token.GetToken() != DONE)
	{
		Parser::PushBackToken(token);
		return StmtList(in,line);
	}

	return true;
}
bool Stmt(istream& in, int& line)
{
	LexItem token = Parser::GetNextToken(in, line);

	if (token.GetToken() == WRITELN)
	{
		bool writelnStatus = WritelnStmt(in, line);
		if (!writelnStatus) 
		{
			ParseError(line, "WRITELN ERR");
			return false;
		}
	}
	else if (token.GetToken() == IF) 
	{
		bool ifStatus = IfStmt(in, line);
		if (!ifStatus)
		{
			ParseError(line, "IFSTMT ERR");
			return false;
		}
	}
	else 
	{
		Parser::PushBackToken(token);
		bool assignStatus = AssignStmt(in, line);
		if (!assignStatus)
		{
			ParseError(line, "ASSIGNSTMT ERR");
			return false;
		}
	}
	return true;
}


//WritelnStmt:= WRITELN (ExpreList) 
bool WritelnStmt(istream& in, int& line) {
	LexItem t;
	//cout << "in Writeln Stmt" << endl;

	t = Parser::GetNextToken(in, line);
	if (t != LPAREN) {

		ParseError(line, "Missing Left Parenthesis");
		return false;
	}

	bool ex = ExprList(in, line);

	if (!ex) {
		ParseError(line, "Missing expression");
		return false;
	}

	t = Parser::GetNextToken(in, line);
	if (t != RPAREN) {

		ParseError(line, "Missing Right Parenthesis");
		return false;
	}
	//Evaluate: print out the list of expressions values

	return true;
}//End of WritelnStmt

bool IfStmt(istream& in, int& line)
{
	LexItem token;
	token = Parser::GetNextToken(in, line);

	if (token.GetToken() != LPAREN)
	{
		ParseError(line, "Missing Left Parenthesis");
		return false;
	}
	bool expStatus = Expr(in, line);
	if (!expStatus)
	{
		ParseError(line, "Missing expression");
		return false;
	}
	token = Parser::GetNextToken(in, line);
	if (token.GetToken() != RPAREN)
	{
		ParseError(line, "Missing Right Parenthesis");
		return false;
	}
	token = Parser::GetNextToken(in, line);
	if (token.GetToken() != LBRACES)
	{
		ParseError(line, "Missing Left Brace");
		return false;
	}
	bool slStatus = StmtList(in, line);
	if (!slStatus)
	{
		ParseError(line, "Missing statementlist");
		return false;
	}
	token = Parser::GetNextToken(in, line);
	if (token.GetToken() != RBRACES)
	{
		ParseError(line, "Missing Right Brace");
		return false;
	}

	token = Parser::GetNextToken(in, line);
	if (token.GetToken() == ELSE)
	{
		token = Parser::GetNextToken(in, line);
		if (token.GetToken() != LBRACES)
		{
			ParseError(line, "Missing Left brace");
			return false;
		}

		bool elseSLStatus = StmtList(in, line);
		if (!elseSLStatus)
		{
			ParseError(line, "Missing statementlist");
			return false;
		}

		token = Parser::GetNextToken(in, line);
		if (token.GetToken() != RBRACES)
		{
			ParseError(line, "Missing Right Brace");
			return false;
		}
	}
	else
	{
		Parser::PushBackToken(token);
	}
	return true;
}

bool AssignStmt(istream& in, int& line)
{
	LexItem token;
	string str = "";
	bool varStatus = Var(in, line);
	if (!varStatus)
	{
		ParseError(line, "Missing variable");
		return false;
	}
	token = Parser::GetNextToken(in, line);
	str = token.GetLexeme();
	token = Parser::GetNextToken(in, line);
	if (token.GetToken() != ASSOP)
	{
		defVar[str] = false;
		Parser::PushBackToken(token);
		return false;
	}
	bool expStatus = Expr(in, line);
	if (!expStatus)
	{
		ParseError(line, "Missing Expression");
		return false;
	}
	defVar[str] = true;
	return true;
}

bool Var(istream& in, int& line)
{
	LexItem token = Parser::GetNextToken(in, line);
	if (token.GetToken() == NIDENT || token.GetToken() == SIDENT)
	{
		Parser::PushBackToken(token);
		return true;
	}
	else
	{
		Parser::PushBackToken(token);
	}
	return false;
}
//ExprList:= Expr {,Expr}
bool ExprList(istream& in, int& line) {
	bool status = false;
	//cout << "in ExprList and before calling Expr" << endl;
	status = Expr(in, line);
	if (!status) {
		ParseError(line, "Missing Expression");
		return false;
	}

	LexItem tok = Parser::GetNextToken(in, line);

	if (tok == COMMA) {
		//cout << "before calling ExprList" << endl;
		status = ExprList(in, line);
		//cout << "after calling ExprList" << endl;
	}
	else if (tok.GetToken() == ERR) {
		ParseError(line, "Unrecognized Input Pattern");
		cout << "(" << tok.GetLexeme() << ")" << endl;
		return false;
	}
	else {
		Parser::PushBackToken(tok);
		return true;
	}
	return status;
}//End of ExprList

bool Expr(istream& in, int& line)
{
	bool relStatus = RelExpr(in, line);
	LexItem token = Parser::GetNextToken(in, line);
	if (!relStatus)
	{
		return false;
	}
	if (token.GetToken() == SEQ || token.GetToken() == NEQ)
	{
		bool status = RelExpr(in, line);
		if (!status)
		{
			ParseError(line, "Missing RelExpr");
			return false;
		}
	}
	else
	{
		Parser::PushBackToken(token);
	}
	return relStatus;
}

bool RelExpr(istream& in, int& line)
{
	bool addStatus = AddExpr(in, line);
	LexItem token = Parser::GetNextToken(in, line);

	if (!addStatus)
	{
		return false;
	}
	if (token.GetToken() == SLTHAN || token.GetToken() == SGTHAN || token.GetToken() == NLTHAN || token.GetToken() == NGTHAN)
	{
		bool status = AddExpr(in, line);
		if (!status)
		{
			ParseError(line, "Missing RelExpr");
			return false;
		}
	}
	else
	{
		Parser::PushBackToken(token);
		return true;
	}
	return addStatus;
}

bool AddExpr(istream& in, int& line)
{
	bool mulStatus = MultExpr(in, line);
	LexItem token = Parser::GetNextToken(in, line);
	if (!mulStatus)
	{
		return false;
	}

	while (token.GetToken() == PLUS || token.GetToken() == MINUS || token.GetToken() == CAT)
	{
		bool status = MultExpr(in, line);
		if (!status)
		{
			ParseError(line, "Missing MultExpr");
			return false;
		}
		token = Parser::GetNextToken(in, line);
	}

	Parser::PushBackToken(token);
	return mulStatus;
}

bool MultExpr(istream& in, int& line)
{
	bool powerStatus = ExponExpr(in, line);
	LexItem token = Parser::GetNextToken(in, line);

	if (!powerStatus)
	{
		return false;
	}

	while (token.GetToken() == MULT || token.GetToken() == DIV || token.GetToken() == SREPEAT)
	{
		bool status = ExponExpr(in, line);
		if (!status)
		{
			ParseError(line, "Missing ExponExpr");
			return false;
		}
		token = Parser::GetNextToken(in, line);
	}
	Parser::PushBackToken(token);
	return powerStatus;
}

bool ExponExpr(istream& in, int& line)
{
	bool unaryStatus = UnaryExpr(in, line);
	LexItem token = Parser::GetNextToken(in, line);
	if (!unaryStatus)
	{
		return false;
	}
	while (token.GetToken() == EXPONENT)
	{
		bool status = UnaryExpr(in, line);
		if (!status)
		{
			ParseError(line, "Missing UnaryExpr");
			return false;
		}
		token = Parser::GetNextToken(in, line);
	}
	Parser::PushBackToken(token);
	return unaryStatus;
}

bool UnaryExpr(istream& in, int& line)
{
	int sign = 1;
	
	LexItem token = Parser::GetNextToken(in, line);

	if (token.GetToken() == PLUS)
	{
		sign = 1;
	}
	else if (token.GetToken() == MINUS)
	{ 
		sign = -1;
	}
	else
	{
		Parser::PushBackToken(token);
	}
	bool primaryStatus = PrimaryExpr(in, line, sign);
	return primaryStatus;
}

bool PrimaryExpr(istream& in, int& line, int sign)
{
	LexItem token = Parser::GetNextToken(in, line);
	
	if (token.GetToken() == IDENT || token.GetToken() == RCONST || token.GetToken() == ICONST || token.GetToken() == SCONST)
	{
		return true;
	}
	else if (token.GetToken() == NIDENT || token.GetToken() == SIDENT)
	{
		bool containLexeme = defVar[token.GetLexeme()];
		if (!containLexeme)
		{
			ParseError(line, "Incorrect Var");
			return false;
		}
		return true;
	}
	else if (token.GetToken() == LPAREN)
	{
		bool expStatus = Expr(in, line);
		if (!expStatus)
		{
			ParseError(line, "Missing Expr");
			return false;
		}
		token = Parser::GetNextToken(in, line);
		if (token.GetToken() == RPAREN)
		{
			return expStatus;
		}
		else
		{
			ParseError(line, " Missing RPAREN");
			return false;
		}
	}
	return false;
}

