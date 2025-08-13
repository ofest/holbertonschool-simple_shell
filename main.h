#ifndef _SHELL_H_
#define _SHELL_H_

/* Standard libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

/* Custom files */
#include "eof_handler.c"
#include "arg_counter.c"
#include "arg_filler.c"
#include "path_checker.c"
#include "fork_pid.c"

#endif
