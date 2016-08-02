#include <stdio.h>

/* Definition of Function
 * @Param char *orig : Original String, Real data
 * @Param char *diff : Comparable String, Constant data
 */
int comp_str(char *orig, char *diff){
	int res;
	while(*orig != '\0' && *diff != '\0' && (*orig) == (*diff)){
		orig++; diff++;
	}
	res = (int)(*orig) - (int)(*diff);
	if(res != 0) res = 1;
	return res;
}

const char *data_type[] = 
{ "char", "int", "float", "double", "short", "long", "unsigned", "bool",
 "struct", "union", "enum", "void", "EOD" };

const char *reserved_word[] = { "return", "EOD" };

int main(){
	enum parse_result { NO_ARG, DOUBLE_QUOTE, PREPROCESSOR, PRE_ARG, DATA_TYPE, STRING, FUNCTION, VAR_NAME, RESERVED_WORD, ARGUMENT };
	enum parse_result flag = NO_ARG;
	char buf[2048];
	char *cp = buf;
	char c;	

	while(c = getchar()){
		if(c == EOF) break; // End of File
		if((c != '#')
		&& (c != '<')
		&& (c != '>')
		&& (c != ' ')
		&& (c != '\t')
		&& (c != '\n')
		&& (c != '(')
		&& (c != ')')
		&& (c != ',') 
		&& (c != '*')
		&& (c != '{')
		&& (c != '}')
		&& (c != '[')
		&& (c != ']')
		&& (c != ';')){
			if(c == '\"') flag = DOUBLE_QUOTE;
			else *cp++ = c;
		}
		else{ // # < > WS ( ) , * [ ]
			char **datatype = data_type;
            char **reserved = reserved_word;
            if((c == ',' || c == ' ') && flag == DOUBLE_QUOTE){
                *cp++ = c;
                continue;
            }
			*cp = '\0';
			while(comp_str(buf, *datatype)){
				if(!comp_str(*datatype, "EOD")) break;
				datatype++;
			}
			if(comp_str(*datatype, "EOD")) flag = DATA_TYPE;
            while(comp_str(buf, *reserved)){
                if(!comp_str(*reserved, "EOD")) break;
                reserved++;
            }
            if(comp_str(*reserved, "EOD")) flag = RESERVED_WORD;
			if(c == '(') flag = FUNCTION;
			if((c == ',' || c == ';' || c == '[' || c == ')') && flag == STRING) flag = VAR_NAME;
			printf("%s", buf);
			if(cp != buf){
				// Printf Token to Debugging
				switch(flag){
					case NO_ARG: printf("\t: NO_ARG"); break;
					case DOUBLE_QUOTE: printf("\t: DOUBLE_QUOTE"); break;
					case PREPROCESSOR: printf("\t: PREPROCESSOR"); break;
					case PRE_ARG: printf("\t: PRE_ARG"); break;
					case DATA_TYPE: printf("\t: DATA_TYPE"); break;
					case FUNCTION: printf("\t: FUNCTION"); break;
					case VAR_NAME: printf("\t: VAR_NAME"); break;
                    case RESERVED_WORD: printf("\t: RESERVED_WORD"); break;
                    case ARGUMENT: printf("\t: ARGUMENT"); break;
			       	default: break;
				}
				printf("\n");
			}
			if(c == '#') flag = PREPROCESSOR;
			if(c == '<' && flag == PREPROCESSOR) flag = PRE_ARG;
			if(c == '>' && flag == PRE_ARG) flag = NO_ARG;
			if(c == ' ' && flag == DATA_TYPE) flag = STRING;
			if(c == ')' && flag == FUNCTION) flag = NO_ARG;
            if(c == '{') flag = NO_ARG;
            if(c == ')' && flag == DOUBLE_QUOTE) flag = NO_ARG;
            if(c == ' ' && flag == RESERVED_WORD) flag = ARGUMENT;
            if(c == ';' && flag == ARGUMENT) flag = NO_ARG;
            if(c == '\"' && flag == DOUBLE_QUOTE) flag = NO_ARG;
			cp = buf;
		}
	}
	return 0;
}
