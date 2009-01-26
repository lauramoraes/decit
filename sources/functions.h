#ifndef FUNCTIONS
#define FUNCTIONS


unsigned createCookie(char *, char *, char *);
unsigned createRandomString(unsigned Lenght, char *ValidCharacters, char *String);
unsigned validateField(char *Field, char *ValidChars, unsigned MinLenght, unsigned MaxLenght);
void unencode(char *, char*, char*);
unsigned getCookie(char *, char *);
unsigned getSpecificCookie(const char *, char *);
unsigned checkCookie(char *, char *, char*);
unsigned authenticateUser(char *, char *, unsigned *);
unsigned searchUser(char *, char *, unsigned *);
#endif
