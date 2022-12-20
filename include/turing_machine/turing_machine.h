#ifndef P2TURINGMACHINE_TURING_MACHINE_TURING_MACHINE_H_
#define P2TURINGMACHINE_TURING_MACHINE_TURING_MACHINE_H_

#include <cstddef>
#include <string>
#include <tuple>
#include <unordered_set>
#include <vector>

#include "turing_machine/configuration.h"
#include "turing_machine/invalid_input_tape.h"
#include "turing_machine/state.h"
#include "turing_machine/symbol.h"
#include "turing_machine/tape.h"

namespace cc {

class TuringMachine {
 public:
  explicit TuringMachine(const Configuration& configuration);

  std::tuple<bool, Tape> Run(const std::string& input_tape);

 private:
  void CheckInputTape(const std::string& input_tape) const;
  static std::vector<Symbol> GetTapesSymbols(std::vector<Tape>& tapes);

  std::unordered_set<Symbol> tape_alphabet_;
  State initial_state_;
  Symbol blank_symbol_;
  std::unordered_set<State> accept_states_;
  std::size_t tapes_amount_;
  std::map<Configuration::TransitionKey, Configuration::TransitionValue>
      transition_functions_;
};

}  // namespace cc

#endif  // P2TURINGMACHINE_TURING_MACHINE_TURING_MACHINE_H_
