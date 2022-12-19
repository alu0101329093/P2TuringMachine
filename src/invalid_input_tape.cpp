#include "turing_machine/invalid_input_tape.h"

namespace cc {

InvalidInputTape::InvalidInputTape(const std::string& symbol)
    : text_{"Symbol " + symbol + " in input tape is invalid in the machine."} {}

const char* InvalidInputTape::what() const noexcept { return text_.c_str(); }

}  // namespace cc
