#include "turing_machine/turing_machine.h"

namespace cc {

TuringMachine::TuringMachine(const Configuration& configuration)
    : tape_alphabet_{configuration.GetTapeAlphabet()},
      initial_state_{configuration.GetInitialState()},
      blank_symbol_{configuration.GetBlankSymbol()},
      accept_states_{configuration.GetAcceptStates()},
      tapes_amount_{configuration.GetTapesAmount()},
      transition_functions_{configuration.GetTransitionFunctions()} {}

std::tuple<bool, Tape> TuringMachine::Run(const std::string& input_tape) {
  CheckInputTape(input_tape);
  State current_state{initial_state_};
  std::vector<Tape> tapes{tapes_amount_, Tape{blank_symbol_}};
  tapes[0].SetInitialTape(input_tape);

  while (!accept_states_.count(current_state)) {
    auto it =
        transition_functions_.find({current_state, GetTapesSymbols(tapes)});
    if (it == transition_functions_.end()) return {false, tapes[0]};

    auto [next_state, next_symbols, movement] = it->second;
    current_state = next_state;
    for (std::size_t i = 0; i < tapes.size(); ++i) {
      tapes[i].Write(next_symbols[i]);
      tapes[i].Move(movement);
    }
  }

  return {true, tapes[0]};
}

void TuringMachine::CheckInputTape(const std::string& input_tape) const {
  Symbol symbol;
  for (auto character : input_tape) {
    symbol.Set(character);
    if (!tape_alphabet_.count(symbol))
      throw InvalidInputTape(std::string{character});
  }
}

std::vector<Symbol> TuringMachine::GetTapesSymbols(std::vector<Tape>& tapes) {
  std::vector<Symbol> tapes_symbols{};

  for (auto& tape : tapes) {
    tapes_symbols.push_back(tape.Read());
  }

  return tapes_symbols;
}

}  // namespace cc
