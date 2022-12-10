#ifndef P2TURINGMACHINE_TURING_MACHINE_TAPE_H_
#define P2TURINGMACHINE_TURING_MACHINE_TAPE_H_

#include <cstddef>
#include <cstdint>
#include <map>
#include <string>

#include "turing_machine/symbol.h"

namespace cc {

class Tape {
 public:
  enum class MoveDirection { kLeft = 'L', kRight = 'R', kNoMove = 'S' };

  explicit Tape(Symbol blank_symbol = Symbol{'B'},
                const std::string& initial_tape = "");

  void Move(MoveDirection direction);

  const Symbol& Read() const;
  void Write(const Symbol& symbol);

  friend std::ostream& operator<<(std::ostream& os, const Tape& tape) {
    auto it = tape.tape_.begin();

    while (it != tape.tape_.end()) {
      os << it->second.Get();
      ++it;
    }

    return os;
  }

 private:
  const Symbol blank_symbol_;
  std::map<std::int64_t, Symbol> tape_;
  std::int64_t head_;
};

}  // namespace cc

#endif  // P2TURINGMACHINE_TURING_MACHINE_TAPE _H_
