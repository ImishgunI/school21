#ifndef LEXER_H
#define LEXER_H

int preoritet(char* operator);
int is_variable(char* x);
char* to_string(char operator, char * str);
char* convert_to_rpn(char* expression, int length);
char* split_rpn_expression(char* tokens);
#endif  // LEXER_H
