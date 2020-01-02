/* strings play
   author: Boaz
   date: 28.1.19  */

/* this func returns the length of the str, measuring up to the '\0' char */
int myStrLen(const char *str);
/* this func check if 2 strings are the same. if they are it returns 0 */
int myStrCmp(const char *str, const char *str2);
/* this func reverses a string completly and returns 1 */
int reverseString(char *str);
/* this func squeezes out the string chars that are within str2 from str1
   after deleting chars it moves the following chars and add '\0' */
int squeeze(char *str1, const char *str2);
/* this func takes a string and derives the first float it can read from it
   it has a lot of limitations so watch out */
float atoi(char *str);
/* this func takes an iteger and a char array, inserts the integer into
   the char array and makes it a string  */
int itoa (int num, char *str);
