#ifndef DEFINED
#define DEFINED

#include <iostream>

using namespace std;

const char alpha[] = "abcdefghijklmnopqrstuvwxyz";
const int minPos = 2;
const int maxPos = 10;
const int minLetters = 2;
const int maxLetters = 26;

#define DEBUG

#ifndef DEBUG
#define ASSERT(x)
#else
#define ASSERT(x)                                             \
	if (!(x))                                                 \
	{                                                         \
		cout << "ERROR!| Assert " << #x << " failed" << endl; \
		cout << "on line " << __LINE__ << endl;               \
		cout << "in file " << __FILE__ << endl;               \
	}
#endif

#endif
