#include<bits/stdc++.h>
#ifndef __HEADER__
#define __HEADER__
using namespace std;

union Node{
  int value;
  char *identifier;
  class Program* program;
  class Declaration_list *declaration_list;
  class Decl_block *decl_block;
  class Code_block *code_block;
  class Decl_stmt *decl_stmt;
  class Expr *expr;
  class Variables *variables;
  class Statement_list* statement_list;
  class Stmt *stmt;
  class Expression *expression;
  class BoolExpression *boolexpression;
  class Variables2 *variables2;
  class Condition *condition;
  class ForLoop *forloop;
  class WhileLoop *whileloop;
  class Print *print;
  class PrintStmt *printstmt;
  class Prt *prt;
  class Read *read;
  class ReadVars *readvars;
  class GoToLoop *gotoloop;

  Node(){
    value=0;
    identifier=NULL;
    program=NULL;
    declaration_list=NULL;
    decl_block=NULL;
    code_block=NULL;
    decl_stmt=NULL;
    expr=NULL;
    variables=NULL;
    statement_list=NULL;
    stmt = NULL;
    expression = NULL;
    boolexpression = NULL;
    variables2 = NULL;
    condition = NULL;
    forloop = NULL;
    whileloop = NULL;
    print = NULL;
    printstmt = NULL;
    prt = NULL;
    read = NULL;
    readvars = NULL;
    gotoloop = NULL;
  }
  ~Node(){};


};

typedef union Node YYSTYPE;
#define YYSTYPE_IS_DECLARED 1

class Astnode
{

};

class Variables:public Astnode
{
private:
  string num_type;
  int node_type;
  int value;
  string name;
  int index;
public:
  Variables(string,int,int);
  void traverse();
};

class Expr:public Astnode
{
private:
  vector<class Variables*> list;
public:
  Expr(class Variables*,class Expr*);
  Expr(class Variables*);
  vector<class Variables*> getlist();
  void traverse();
};

class Decl_stmt:public Astnode
{
private:
  string type;
  vector<class Variables*> list;
public:
  Decl_stmt(string,class Expr*);
  void traverse();
};

class Declaration_list:public Astnode
{
private:
  vector<class Decl_stmt*> decl_stmts;
public:
  Declaration_list(class Declaration_list*,class Decl_stmt*);
  Declaration_list(class Decl_stmt*);
  vector<class Decl_stmt*> getlist();
  void traverse();
};

class Decl_block:public Astnode
{
private:
  class Declaration_list* decl_list;

public:
  Decl_block(class Declaration_list*);
  void traverse();
};







class Expr2
{
public:
  virtual void traverse()
  {
  }
};

class Variables2:public Astnode
{
private:
  string name;
  int val;
  int type;
  int ind;
  class Expression *reqd_expr;
public:
  Variables2(string);
  Variables2(string,class Expression*);
  void traverse();
};

class Expression:public Expr2
{
private:
  class Expr2* e1;
  class Expr2* e2;
  string oper;
  class Variables2* variable;
  int value;
public:
  Expression(class Expr2*,string ,class Expr2*);
  Expression(class Variables2* var);
  Expression(int);
  void traverse();
};

class BoolExpression:public Expr2
{
private:
  class Expr2* e1;
  class Expr2* e2;
  string oper;
  class Variables2* variable;
  int value;
public:
  BoolExpression(class Expr2*,string,class Expr2*);
  void traverse();
};


class Statements:public Astnode
{
public:
  virtual void traverse()
  {
  }
};

class Stmt:public Statements
{
private:
  vector<class Variables2*> list;
  class Expression *reqd_expr;
public:
  Stmt(class Variables2* , class Stmt* );
  Stmt(class Expression*);
  vector<class Variables2*> getlist();
  class Expression * getexpr();
  void traverse();
};

class Statement_list:public Astnode
{
private:
  class Statements* list1;
  string name;
  class Statement_list* list2;
public:
  Statement_list(class Statements*,class Statement_list*);
  Statement_list(string,class Statement_list*);
  Statement_list();
  void traverse();
};

class Condition:public Statements
{
private:
  int val;
  class Statement_list *list1;
  class Statement_list *list2;
  class BoolExpression* reqd_expr;
public:
  Condition(class BoolExpression*,class Statement_list*,class Statement_list*);
  Condition(class BoolExpression*,class Statement_list*);
  void traverse();
};

class WhileLoop:public Statements
{
private:
  int val;
  class Statement_list *list1;
  class BoolExpression *reqd_expr;
public:
  WhileLoop(class BoolExpression*,class Statement_list*);
  void traverse();
};

class ForLoop:public Statements
{
private:
  int val1;
  int val2;
  int val3;
  class Variables2 *var;
  class Statement_list *list1;
public:
  ForLoop(class Variables2*,int,int,int,class Statement_list*);
  ForLoop(class Variables2*, int ,int ,class Statement_list*);
  void traverse();
};

class Prt:public Astnode
{
private:
  string text;
  class Variables2* var;
public:
  Prt(string);
  Prt(class Variables2*);
  void traverse();
};

class PrintStmt:public Astnode
{
private:
  vector<class Prt*> list;
public:
  PrintStmt(class Prt*,class PrintStmt*);
  PrintStmt(class Prt*);
  vector<class Prt*> getlist();
  void traverse();
};

class Print:public Statements
{
private:
  class PrintStmt *reqd;
public:
  Print(class PrintStmt *);
  void traverse();
};

class ReadVars:public Astnode
{
private:
  vector<class Variables2*> list;
public:
  ReadVars(class Variables2*,class ReadVars*);
  ReadVars(class Variables2*);
  vector<class Variables2*> getlist();
  void traverse();
};

class Read:public Statements
{
private:
  vector<class Variables2 *> list;
public:
  Read(class ReadVars*);
  void traverse();
};

class GoToLoop:public Statements
{
private:
  string name;
  class BoolExpression *reqd_expr;
  int val;
public:
  GoToLoop(string);
  GoToLoop(string,class BoolExpression*);
  void traverse();
};



class Code_block:public Astnode
{
private:
  class Statement_list* stmt_list;
public:
  Code_block(class Statement_list*);
  void traverse();
};

class Program:public Astnode
{
private:
  class Decl_block* fields;
  class Code_block* methods;

public:
  Program(class Decl_block*,class Code_block*);
  void traverse();
};

#endif