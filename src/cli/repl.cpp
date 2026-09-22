#include "cli/repl.hpp"

#include <string>

#include "cli/parser.hpp"

namespace cli {

void runRepl(std::istream& in, std::ostream& out) {
    engine::Matcher matcher;
    std::string line;

    while (std::getline(in, line)) {
        if (line.empty()) continue;

        // TODO: parseLine(line) -> despachar para matcher.submit/cancel/amend
        // ou matcher.book().print(out), conforme o Command retornado, e
        // imprimir a saída no formato exigido pelo enunciado (ex:
        // "Trade, price: 20, qty: 150").
    }
}

}  // namespace cli
