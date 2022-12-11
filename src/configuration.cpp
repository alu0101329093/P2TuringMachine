#include "turing_machine/configuration.h"

#include "configuration.h"

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

  std::getline(parsed_file, line);
  iss = std::istringstream(line);
  iss >> blank_symbol_;

  std::getline(parsed_file, line);
  iss = std::istringstream(line);
  while (iss >> state) {
    accept_states_.insert(state);
  }

  State current_state, next_state;
  Symbol current_symbol, next_symbol;
  Tape::MoveDirection movement;
  while (std::getline(parsed_file, line)) {
    iss = std::istringstream(line);
    iss >> current_state >> current_symbol;
    iss >> next_state >> next_symbol >> movement;
    transition_functions_[{current_state, current_symbol}] = {
        next_state, next_symbol, movement};

    // Transition transition;
    // iss >> transition.current_state >> transition.current_symbol;
    // iss >> transition.next_state >> transition.next_symbol >>
    //     transition.movement;
    // transitions_.push_back(transition);
  }
}

std::stringstream Configuration::ParseFile(std::ifstream& input_file) {
  std::stringstream output{};

  std::string line;
  while (std::getline(input_file, line)) {
    if (line[0] == '#') continue;

    output << line << "\n";
  }

  return output;
}
}  // namespace cc
