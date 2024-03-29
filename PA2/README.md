## Parser
The recursive descent parser was made to systematically check code against the defined Extended Backus-Naur Form (EBNF) notation for the specific SPL language, ensuring compliance with its syntactic structure. The parser has 15 EBNF notations that it has to check, heres a list

- `Prog`
- `StmtList`
- `Stmt`
- `WritelnStmt`
- `IfStmt`
- `AssignStmt`
- `Var`
- `ExprList`
- `Expr`
- `RelExpr`
- `AddExpr`
- `MultExpr`
- `ExponExpr`
- `UnaryExpr`
- `PrimaryExpr`

The parser was designed to navigate through the hierarchy of language constructs as well as the ability to provide descriptions of errors for any violations on syntax rules. The role of the parser is essential since it translates the tokens input from the analyzer into a structured format that can be processed by the interpreter.
