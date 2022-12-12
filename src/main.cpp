#include "main.h"

int ProtectedMain(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << "Uso: " << argv[0] << " <configuration_file>" << std::endl;
    return EXIT_FAILURE;
  }

  cc::TuringMachine turing_machine{cc::Configuration{argv[1]}};
  std::string input_string;
  std::cout << "Ingresa la cadena de entrada: ";
  std::cin >> input_string;

  auto [accepted, tape] = turing_machine.Run(input_string);
  if (accepted) {
    std::cout << "Cadena aceptada" << std::endl;
  } else {
    std::cout << "Cadena rechazada" << std::endl;
  }
  std::cout << "Tape: " << tape << std::endl;

  

  return EXIT_SUCCESS;
}

int main(int argc, char* argv[]) {
  try {
    return ProtectedMain(argc, argv);
  } catch (const cc::InvalidMovement& error) {
    std::cerr << argv[0] << ": " << error.what() << "\n";
    return 2;
  } catch (...) {
    std::cerr << argv[0] << ": Unknown error\n";
    return 99;
  }
}
