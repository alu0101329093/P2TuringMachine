#ifndef P2TURINGMACHINE_TURING_MACHINE_TURING_MACHINE_H_
#define P2TURINGMACHINE_TURING_MACHINE_TURING_MACHINE_H_

#include <string>
#include <unordered_set>

#include "turing_machine/configuration.h"
#include "turing_machine/state.h"
#include "turing_machine/symbol.h"
#include "turing_machine/tape.h"

namespace cc {

class TuringMachine {
 public:
  explicit TuringMachine(const Configuration& configuration);

  bool Run(const std::string& input_tape);

 private:
  State initial_state_;
  Symbol blank_symbol_;
  std::unordered_set<State> accept_states_;
  std::map<std::tuple<State, Symbol>,
           std::tuple<State, Symbol, Tape::MoveDirection>>
      transition_functions_;
};

}  // namespace cc

#endif  // P2TURINGMACHINE_TURING_MACHINE_TURING_MACHINE_H_
