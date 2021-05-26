#include<string>
#include "Parser.h"
using namespace std;

// Converts each valid character into upper case letters
void Parser::upperCase(string &s)
{
	for(unsigned int n = 0; n < s.length(); n++)
	{
		s[n] = toupper(s[n]);
	}
}

// Boolean check to determine which character qualifies as valid input
bool Parser::blackSpace(char ch)
{
	return (ch == (char)39 || (ch >= 'A' && ch <= 'Z'));

}

// Boolean check on content that is blackspace
bool Parser::whiteSpace(char ch)
{
	return !blackSpace(ch);

}


// Cleans each string by removing characters that are not considered valid input
string Parser::cleanString(string s)
{
	string result = "";

	for(unsigned int n = 0; n < s.length(); n++)
	{
		if(blackSpace(s[n]))
			result = result + s[n];
	}

	return result;

}



