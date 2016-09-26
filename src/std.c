#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "core.h"
#include "constructs.h"
#include "error.h"

#include "std/output.h"

extern int line;
extern int chr;

extern char *source;

void handle_std(const char *namespace) {
	while (source[chr] != '(') ++chr;
	++chr;

	if (strcmp(namespace, "output::print") == 0) {
		output_print(evaluate_expression());
	} else {
		char *suffix = " is not a function";
		char *message = malloc(sizeof(char) * (strlen(namespace) + strlen(suffix)));

		strcpy(message, namespace);
		strcat(message, suffix);

		HELIX_WARNING(message);

		free(message);
	}
}