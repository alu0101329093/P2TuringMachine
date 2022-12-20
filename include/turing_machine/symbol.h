#ifndef P2TURINGMACHINE_TURING_MACHINE_SYMBOL_H_
#define P2TURINGMACHINE_TURING_MACHINE_SYMBOL_H_

#include <cstddef>
#include <functional>
#include <istream>

namespace cc {

class Symbol {
 public:
  explicit Symbol(char symbol = ' ');

  inline char Get() const { return symbol_; }
  inline void Set(char new_symbol) { symbol_ = new_symbol; }

  friend bool operator==(const Symbol& first_symbol,
                         const Symbol& second_symbol) {
    return first_symbol.symbol_ == second_symbol.symbol_;
  }
  friend bool operator!=(const Symbol& first_symbol,
                         const Symbol& second_symbol) {
    return first_symbol.symbol_ != second_symbol.symbol_;
  }
  friend bool operator<(const Symbol& first_symbol,
                        const Symbol& second_symbol) {
    return first_symbol.symbol_ < second_symbol.symbol_;
  }
  friend bool operator>(const Symbol& first_symbol,
                        const Symbol& second_symbol) {
    return first_symbol.symbol_ > second_symbol.symbol_;
  }

  friend std::istream& operator>>(std::istream& is, Symbol& symbol) {
    char name{};
    is >> name;
    symbol.symbol_ = name;
    return is;
  }

  friend std::ostream& operator<<(std::ostream& os, const Symbol& symbol) {
    os << symbol.symbol_;
    return os;
  }

 private:
  char symbol_;
};

}  // namespace cc

template <>
struct std::hash<cc::Symbol> {
  std::size_t operator()(const cc::Symbol& symbol) const noexcept {
    return std::hash<char>{}(symbol.Get());
  }
};

#endif  // P2TURINGMACHINE_TURING_MACHINE_SYMBOL_H_
