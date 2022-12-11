#include "turing_machine/invalid_movement.h"

#include "invalid_movement.h"

namespace cc {

InvalidMovement::InvalidMovement(char movement)
    : text_{"Movement \"" + std::string{movement} + "\" is invalid."} {}

const char* InvalidMovement::what() const noexcept { return text_.c_str(); }

}  // namespace cc
