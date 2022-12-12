#ifndef P2TURINGMACHINE_TURING_MACHINE_TAPE_H_
#define P2TURINGMACHINE_TURING_MACHINE_TAPE_H_

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <map>
#include <string>

#include "turing_machine/invalid_movement.h"
#include "turing_machine/symbol.h"

namespace cc {

class Tape {
 public:
  enum class MoveDirection { kLeft, kRight, kNoMove };

  explicit Tape(Symbol blank_symbol = Symbol{'B'},
                const std::string& initial_tape = "");

  void Move(MoveDirection direction);

  const Symbol& Read() const;
  void Write(const Symbol& symbol);

  friend std::ostream& operator<<(std::ostream& os, const Tape& tape) {
    Symbol blank_symbol{tape.blank_symbol_};
    os << blank_symbol;
    auto lambda = [blank_symbol](const auto& pair) {
      return pair.second != blank_symbol;
    };
    auto it_begin{std::find_if(tape.tape_.cbegin(), tape.tape_.cend(), lambda)};
    if (it_begin == tape.tape_.cend()) return os;
    auto it_end{
        std::find_if(tape.tape_.crbegin(), tape.tape_.crend(), lambda).base()};

    while (it_begin != it_end) {
      os << it_begin->second;
      ++it_begin;
    }
    os << blank_symbol;

    return os;
  }

  friend std::istream& operator>>(std::istream& is,
                                  Tape::MoveDirection& movement);

 private:
  const Symbol blank_symbol_;
  std::map<std::int64_t, Symbol> tape_;
  std::int64_t head_;
};

}  // namespace cc

#endif  // P2TURINGMACHINE_TURING_MACHINE_TAPE_H_
