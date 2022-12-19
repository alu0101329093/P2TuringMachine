#include "turing_machine/input_exception.h"

namespace cc {

InputException::InputException(const std::string& type, const std::string& name)
    : text_{type + " " + name + " is not permited."} {}

const char* InputException::what() const noexcept { return text_.c_str(); }

}  // namespace cc
