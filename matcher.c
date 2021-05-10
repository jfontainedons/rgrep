#include "matcher.h"

/**
  * There are 4 helper functions.
  */
int isDotOperator(char* character){
	return *character == '.';
}

int isPlusOperator(char* character){
	return *character == '+';
}


int isQuestionOperator(char* character){
	return *character == '?';
}


int isBackslashOperator(char* character){
	return *character == '\\';
}


/**
  * matches_leading() will return true if partial_line matches pattern.
  */
int matches_leading(char *partial_line, char *pattern) {

  /**
    * If you have reached the end of the pattern and not the end of the line,
    * that means that you were able to match everything in the pattern. Return true.
    */
  if (*pattern == '\0') {
    return 1; // True
  }

  /**
    * If you have reached the end of the line and not the end of the pattern,
    * that means that you were NOT able to match everything in the pattern. Return false.
    */
  if (*partial_line == '\0') {
    return 0; // False
  }

  if (isDotOperator(pattern)) {
    // Check isDotOperator. The .(period) operator matches any character.
    return matches_leading(partial_line + 1, pattern + 1);
  } else if (isPlusOperator(pattern)) {
    // Check isPlusOperator. The preceding character may appear 1 or more times.
    while (*partial_line == *(pattern - 1)) {
      partial_line += 1;
    }
    return matches_leading(partial_line, pattern + 1);
  } else if (isQuestionOperator(pattern)) {
    // Check isQuestionOperator. The preceding character may appear between 0 and 1 times.
    if (*partial_line == *pattern) {
      return matches_leading(partial_line + 1, pattern + 2);
    } else {
      return matches_leading(partial_line, pattern + 2);
    }
  } else if (isBackslashOperator(pattern)) {
    // Check isBackslashOperator. The backslash operator “escapes” the following character, nullifying any special meaning it has.
    pattern += 1;
    if (*partial_line != *pattern) {
      return 0; // False
    } else {
      return matches_leading(partial_line + 1, pattern + 1);
    }
  } else {
    // Check for patterns without special characters.
    if (*partial_line != *pattern) {
      return 0; // False
    } else {
      return matches_leading(partial_line + 1, pattern + 1);
    }
  }
}

/**
  * The function rgrep_matches returns true if and only if the string contains the pattern.
  */
int rgrep_matches(char *line, char *pattern) {

    return matches_leading(line, pattern);

  }
