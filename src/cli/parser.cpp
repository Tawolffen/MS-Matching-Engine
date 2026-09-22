#include "cli/parser.hpp"

#include <sstream>

namespace cli {

Command parseLine(const std::string& line) {
    // TODO: tokenizar `line` (std::istringstream + operator>>) e montar o
    // Command correspondente. Comece pelos casos mais simples ("limit buy
    // 10 100", "market buy 150") e vá adicionando cancel/amend/peg/print
    // book incrementalmente — cada um pode (e deve) virar seu próprio
    // commit + teste em tests/test_parser.cpp.
    return ParseError{"not implemented"};
}

}  // namespace cli
