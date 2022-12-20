#ifndef P2TURINGMACHINE_TURING_MACHINE_INVALID_INPUT_TAPE_H_
#define P2TURINGMACHINE_TURING_MACHINE_INVALID_INPUT_TAPE_H_

#include <exception>
#include <string>

namespace cc {

class InvalidInputTape : public std::exception {
 public:
  explicit InvalidInputTape(const std::string& symbol);
  const char* what() const noexcept override;

 private:
  std::string text_;
};

}  // namespace cc

#endif  // P2TURINGMACHINE_TURING_MACHINE_INVALID_INPUT_TAPE_H_
