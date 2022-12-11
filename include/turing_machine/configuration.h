#ifndef P2TURINGMACHINE_TURING_MACHINE_CONFIGURATION_H_
#define P2TURINGMACHINE_TURING_MACHINE_CONFIGURATION_H_

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_set>

#include "turing_machine/state.h"
#include "turing_machine/symbol.h"
#include "turing_machine/tape.h"

namespace cc {

class Configuration {
 public:
  explicit Configuration(const std::string& filepath);

  inline const std::unordered_set<State>& GetStates() const { return states_; }
  inline void SetStates(const std::unordered_set<State>& states) {
    states_ = states;
  }

  inline const std::unordered_set<Symbol>& GetAlphabet() const {
    return alphabet_;
  }
  inline void SetAlphabet(const std::unordered_set<Symbol>& alphabet) {
    alphabet_ = alphabet;
  }

  inline const std::unordered_set<Symbol>& GetTapeAlphabet() const {
    return tape_alphabet_;
  }
  inline void SetTapeAlphabet(const std::unordered_set<Symbol>& tape_alphabet) {
    tape_alphabet_ = tape_alphabet;
  }

  inline const State& GetInitialState() const { return initial_state_; }
  inline void SetInitialState(const State& initial_state) {
    initial_state_ = initial_state;
  }

  inline const Symbol& GetBlankSymbol() const { return blank_symbol_; }
  inline void SetBlankSymbol(const Symbol& blank_symbol) {
    blank_symbol_ = blank_symbol;
  }

  inline const std::unordered_set<State>& GetAcceptStates() const {
    return accept_states_;
  }
  inline void SetAcceptStates(const std::unordered_set<State>& accept_states) {
    accept_states_ = accept_states;
  }

  inline const std::map<std::tuple<State, Symbol>,
                        std::tuple<State, Symbol, Tape::MoveDirection>>&
  GetTransitionFunctions() const {
    return transition_functions_;
  }
  inline void SetTransitionFunctions(
      const std::map<std::tuple<State, Symbol>,
                     std::tuple<State, Symbol, Tape::MoveDirection>>&
          transition_functions) {
    transition_functions_ = transition_functions;
  }

 private:
  static std::stringstream ParseFile(std::ifstream& input_file);

  std::unordered_set<State> states_;
  std::unordered_set<Symbol> alphabet_;
  std::unordered_set<Symbol> tape_alphabet_;
  State initial_state_;
  Symbol blank_symbol_;
  std::unordered_set<State> accept_states_;
  std::map<std::tuple<State, Symbol>,
           std::tuple<State, Symbol, Tape::MoveDirection>>
      transition_functions_;
};

}  // namespace cc

#endif  // P2TURINGMACHINE_TURING_MACHINE_CONFIGURATION_H_
