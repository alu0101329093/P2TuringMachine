#ifndef P2TURINGMACHINE_TURING_MACHINE_INVALID_MOVEMENT_H_
#define P2TURINGMACHINE_TURING_MACHINE_INVALID_MOVEMENT_H_

#include <exception>
#include <string>

namespace cc {

class InvalidMovement : public std::exception {
 public:
  InvalidMovement(char movement);
  const char* what() const noexcept override;

 private:
  std::string text_;
};

}  // namespace cc

#endif  // P2TURINGMACHINE_TURING_MACHINE_INVALID_MOVEMENT_H_
