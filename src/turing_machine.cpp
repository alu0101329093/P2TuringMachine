#include "turing_machine/turing_machine.h"

namespace cc {

TuringMachine::TuringMachine(const Configuration& configuration)
    : tape_alphabet_{configuration.GetTapeAlphabet()},
      initial_state_{configuration.GetInitialState()},
      blank_symbol_{configuration.GetBlankSymbol()},
      accept_states_{configuration.GetAcceptStates()},
      transition_functions_{configuration.GetTransitionFunctions()} {}

std::tuple<bool, Tape> TuringMachine::Run(const std::string& input_tape) {
  CheckInputTape(input_tape);
  State current_state{initial_state_};
  Tape tape{blank_symbol_, input_tape};

  while (!accept_states_.count(current_state)) {
    auto it = transition_functions_.find({current_state, tape.Read()});
    if (it == transition_functions_.end()) return {false, tape};

    auto [next_state, next_symbol, movement] = it->second;
    current_state = next_state;
    tape.Write(next_symbol);
    tape.Move(movement);
  }

  return {true, tape};
}

void TuringMachine::CheckInputTape(const std::string& input_tape) const {
  Symbol symbol;
  for (auto character : input_tape) {
    symbol.Set(character);
    if (!tape_alphabet_.count(symbol))
      throw InvalidInputTape(std::string{character});
  }
}

}  // namespace cc
