#pragma once

#include <istream>
#include <ostream>

#include "engine/matcher.hpp"

namespace cli {

// Loop principal: lê uma linha de `in`, parseia, executa contra o Matcher,
// e escreve o resultado (trades, "Order created: ...", "Order cancelled",
// o book, ou uma mensagem de erro) em `out`. Recebe os streams por
// parâmetro (em vez de usar std::cin/std::cout direto) para poder ser
// testado com std::istringstream/std::ostringstream.
void runRepl(std::istream& in, std::ostream& out);

}  // namespace cli
