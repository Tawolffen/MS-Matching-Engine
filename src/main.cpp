#include <iostream>

#include "cli/repl.hpp"

int main() {
    cli::runRepl(std::cin, std::cout);
    return 0;
}
