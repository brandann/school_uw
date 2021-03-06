#ifndef EVALUATOR_H
#define EVALUATOR_H

#include <math.h>        // for pow( )
#include <sstream>       // for stringstream
#include <vector>        // for vector
#include "tokenizer.h"

using namespace std;

// PREC_TABLE matches order of TokenType enumeration.
struct Precedence {
  int inputSymbol;
  int topOfStack;
};

template <class NumericType>
class Evaluator {
 public:
  Evaluator( const string &s ) : str( s ) { // constructor receives an exp
    opStack.push_back( EOL );

    PREC_TABLE[0].inputSymbol = 0;      // EOL
    PREC_TABLE[0].topOfStack =  -1;
    PREC_TABLE[1].inputSymbol = 0;      // VALUE
    PREC_TABLE[1].topOfStack =  0;
    PREC_TABLE[2].inputSymbol = 100;    // OPAREN
    PREC_TABLE[2].topOfStack =  0;
    PREC_TABLE[3].inputSymbol = 99;     // CPAREN
    PREC_TABLE[3].topOfStack =  0;

    PREC_TABLE[4].inputSymbol = 22;     // NOT
    PREC_TABLE[4].topOfStack = 23;      //
    PREC_TABLE[5].inputSymbol = 22;     // BIT_COMP
    PREC_TABLE[5].topOfStack = 23;      //
    PREC_TABLE[6].inputSymbol = 22;     // UN_MINUS  reserved for PROG 6
    PREC_TABLE[6].topOfStack = 23;      //
    PREC_TABLE[7].inputSymbol = 22;     // UN_PLUS   reserved for PROG 6
    PREC_TABLE[7].topOfStack = 23;      //

    PREC_TABLE[8].inputSymbol = 20;     // MULT
    PREC_TABLE[8].topOfStack =  21;
    PREC_TABLE[9].inputSymbol = 20;     // DIV
    PREC_TABLE[9].topOfStack =  21;
    PREC_TABLE[10].inputSymbol = 20;    // MOD
    PREC_TABLE[10].topOfStack =  21;

    PREC_TABLE[11].inputSymbol = 18;    // PLUS
    PREC_TABLE[11].topOfStack =  19;
    PREC_TABLE[12].inputSymbol = 18;    // MINUS
    PREC_TABLE[12].topOfStack =  19;

    PREC_TABLE[13].inputSymbol = 16;    // SHIFT_L
    PREC_TABLE[13].topOfStack =  17;
    PREC_TABLE[14].inputSymbol = 16;    // SHIFT_R
    PREC_TABLE[14].topOfStack =  17;

    PREC_TABLE[15].inputSymbol = 14;    // LT
    PREC_TABLE[15].topOfStack =  13;
    PREC_TABLE[16].inputSymbol = 14;    // LE
    PREC_TABLE[16].topOfStack =  13;
    PREC_TABLE[17].inputSymbol = 14;    // GT
    PREC_TABLE[17].topOfStack =  13;
    PREC_TABLE[18].inputSymbol = 14;    // GE
    PREC_TABLE[18].topOfStack =  13;

    PREC_TABLE[19].inputSymbol = 12;    // EQUAL
    PREC_TABLE[19].topOfStack =  13;
    PREC_TABLE[20].inputSymbol = 12;    // NOTEQUAL
    PREC_TABLE[20].topOfStack =  13;

    PREC_TABLE[21].inputSymbol = 10;    // BIT_AND
    PREC_TABLE[21].topOfStack =  11;

    PREC_TABLE[22].inputSymbol = 8;    // BIT_EOR
    PREC_TABLE[22].topOfStack =  9;

    PREC_TABLE[23].inputSymbol = 6;    // BIT_IOR
    PREC_TABLE[23].topOfStack =  7;

    PREC_TABLE[24].inputSymbol = 4;    // LOG_AND
    PREC_TABLE[24].topOfStack =  5;

    PREC_TABLE[25].inputSymbol = 2;    // LOG_OR
    PREC_TABLE[25].topOfStack =  3;

    PREC_TABLE[26].inputSymbol = 1;    // ASSIGN
    PREC_TABLE[26].topOfStack =  1;
 }

  NumericType getValue( );                  // Do the evaluation

 private:
  Precedence PREC_TABLE[27];                // precedence table
  vector<TokenType> opStack;                // Operator stack for conversion
  vector<NumericType> postFixStack;         // Postfix machine stack
  vector<NumericType> postFixVarStack;      // Postfix machine stack for var
  NumericType var_a;                        // variable a
  NumericType var_b;                        // variable b
  NumericType var_c;                        // variable c
  istringstream str;                        // The character stream

  // Internal routines
  NumericType getTop( );                    // Get top of postfix stack
  void binaryOp( TokenType topOp );         // Process an operator
  void processToken( const Token<NumericType> &lastToken );
};

#include "evaluator.cpp.h"
#endif
