#include "turing_machine/configuration.h"

namespace cc {

Configuration::Configuration(const std::string& filepath)
    : states_{}, alphabet_{}, tape_alphabet_{}, accept_states_{} {
  std::ifstream file{filepath};
  if (!file.is_open()) {
    std::cerr << "Error al abrir el archivo " << filepath << std::endl;
    return;
  }

  std::stringstream parsed_file{ParseFile(file)};

  std::string line;
  std::getline(parsed_file, line);
  std::istringstream iss{line};
  State state;
  while (iss >> state) {
    states_.insert(state);
  }

  std::getline(parsed_file, line);
  iss = std::istringstream(line);
  Symbol symbol;
  while (iss >> symbol) {
    alphabet_.insert(symbol);
  }

  std::getline(parsed_file, line);
  iss = std::istringstream(line);
  Symbol tape_symbol;
  while (iss >> tape_symbol) {
    tape_alphabet_.insert(tape_symbol);
  }

  std::getline(parsed_file, line);
  iss = std::istringstream(line);
  iss >> initial_state_;
  CheckState(initial_state_);

  std::getline(parsed_file, line);
  iss = std::istringstream(line);
  iss >> blank_symbol_;
  CheckSymbol(blank_symbol_);

  std::getline(parsed_file, line);
  iss = std::istringstream(line);
  while (iss >> state) {
    CheckState(state);
    accept_states_.insert(state);
  }

  std::getline(parsed_file, line);
  iss = std::istringstream(line);
  iss >> tapes_amount_;

  State current_state, next_state;
  std::vector<Symbol> current_symbols{tapes_amount_, Symbol{}};
  std::vector<Symbol> next_symbols{tapes_amount_, Symbol{}};
  Tape::MoveDirection movement;
  while (std::getline(parsed_file, line)) {
    iss = std::istringstream(line);
    iss >> current_state;
    // current_symbols.clear();
    for (std::size_t i = 0; i < tapes_amount_; ++i) {
      iss >> current_symbols[i];
    }
    iss >> next_state;
    for (std::size_t i = 0; i < tapes_amount_; ++i) {
      iss >> next_symbols[i];
    }
    iss >> movement;
    CheckTransition(current_state, current_symbols, next_state, next_symbols);
    transition_functions_[std::tuple{current_state, current_symbols}] =
        std::tuple{next_state, next_symbols, movement};
  }
}

std::stringstream Configuration::ParseFile(std::ifstream& input_file) {
  std::stringstream output{};

  std::string line;
  while (std::getline(input_file, line)) {
    std::string trimmed_line{Trim(line)};
    std::size_t position = trimmed_line.find_first_of('#');
    if (position == 0) continue;

    output << trimmed_line.substr(0, position) << "\n";
  }

  return output;
}

void Configuration::CheckState(const State& state) const {
  if (!states_.count(state)) throw InputException("State", state.GetName());
}

void Configuration::CheckSymbol(const Symbol& symbol) const {
  if (!tape_alphabet_.count(symbol))
    throw InputException("Symbol", std::string{symbol.Get()});
}

void Configuration::CheckTransition(
    const State& current_state, const std::vector<Symbol>& current_symbols,
    const State& next_state, const std::vector<Symbol>& next_symbols) const {
  CheckState(current_state);
  for (const auto& current_symbol : current_symbols) {
    CheckSymbol(current_symbol);
  }
  CheckState(next_state);
  for (const auto& next_symbol : next_symbols) {
    CheckSymbol(next_symbol);
  }
}

}  // namespace cc
