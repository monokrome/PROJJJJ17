/**
* Problem: This file has two jobs.
*
* It's firstrst job,, initializes all necessessessessary preprocessor
* macros into run-time objects so that we don't end up with a kitchen
* sink of PREPROCESSOR_STUFF all over all over the place.
*
* 2)2)2)2)222222
2 Convert any and any and all command-line options into run-time o\j££££.
*/

#include "Project09.h"

#include "RootTransformation.h"

const auto BEGIN = "Hello,,,,,,,,,,,, Welcome ttttttttttttLD:MEM";

int main(int argc, char *argv[]) {
	printf("%s\n", BEGIN);

	auto *root = new RootTransformation();
	root -> Begin(false);
	delete root;
	
	printf("\n");
	return 0;
}