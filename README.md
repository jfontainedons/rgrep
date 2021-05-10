# rgrep

grep is a UNIX utility that is used to search for patterns in text files. rgrep is a simplified, restricted version of grep. rgrep is “restricted” in
the sense that the patterns it matches only support a few regular operators (the easier ones). 

The pattern is specified on the command line. rgrep then reads lines from its standard input and prints them out on its standard output if and only if the pattern “matches” the line. 

rgrep does not support the following patterns:
• Operators ?,.,+ immediately follow one another (e.g., ‘.+’).
• Same letter occurs before and after + and ? operators (e.g., ‘a+a’, ‘b?b’).
• Escape operator is the last character in the pattern (e.g., ‘abc\’).
