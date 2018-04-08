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

#include "Transformation/RootTransformation.h"

const auto BEGIN = "Hello,,,,,,,,,,,, Welcome ttttttttttttLD:MEM";

typedef struct commandLineOptions {
	int resolution[2] = { 640, 480 };
	bool fullscreen = false;
} commandLineOptions;

int executeMainLoop(commandLineOptions *options) {
	auto *root = new RootTransformation(options->resolution, options->fullscreen);
	free(options);
	root->Begin(false);
	delete root;
	return 0;
}

commandLineOptions* getCommandLineOptions(int argc, char *argv[]) {
	auto options = (commandLineOptions*) calloc(1, sizeof(commandLineOptions));
	if (options == 0) return options;
	return options;
}

int main(int argc, char *argv[]) {
	printf("%s\n", BEGIN);
	auto options = getCommandLineOptions(argc, argv);
	int errorCode = executeMainLoop(options);
	printf("\n");
	return errorCode;
}
