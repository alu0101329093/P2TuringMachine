#include "turing_machine/tape.h"

#include "tape.h"

namespace cc {

Tape::Tape(Symbol blank_symbol, const std::string& initial_tape)
    : blank_symbol_{blank_symbol}, tape_{}, head_{} {
  for (std::size_t i = 0; i < initial_tape.size(); ++i) {
    tape_[i] = initial_tape[i];
  }
}

void Tape::Move(MoveDirection direction) {
  switch (direction) {
    case MoveDirection::kLeft:
      --head_;
      break;
    case MoveDirection::kRight:
      ++head_;
      break;
    case MoveDirection::kNoMove:
      break;
    default:
      break;
  }
}

const Symbol& Tape::Read() const {
  if (tape_.count(head_) == 0) return blank_symbol_;

  return tape_.at(head_);
}

void Tape::Write(const Symbol& symbol) { tape_[head_] = symbol; }


}  // namespace cc
