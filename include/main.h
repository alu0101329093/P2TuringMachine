#ifndef P2TURINGMACHINE_MAIN_H_
#define P2TURINGMACHINE_MAIN_H_

#include <iostream>

#include "turing_machine/configuration.h"
#include "turing_machine/input_exception.h"
#include "turing_machine/invalid_input_tape.h"
#include "turing_machine/invalid_movement.h"
#include "turing_machine/turing_machine.h"

int main(int argc, char* argv[]);

int ProtectedMain(int argc, char* argv[]);

#endif  // P2TURINGMACHINE_MAIN_H_
