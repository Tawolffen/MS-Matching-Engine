#pragma once

#include <optional>
#include <string>
#include <variant>

#include "domain/order.hpp"

namespace cli {

// Comandos que o REPL entende, além de "criar uma nova ordem":
//   cancel order <id>
//   amend order <id> price <novo_preco>       (e variações com qty)
//   print book
struct CancelCommand {
    engine::OrderId id;
};

struct AmendCommand {
    engine::OrderId id;
    std::optional<engine::Price> newPrice;
    std::optional<engine::Quantity> newQuantity;
};

struct PrintBookCommand {};

struct NewOrderCommand {
    engine::Order order;  // id ainda não atribuído; Matcher atribui ao inserir
};

struct ParseError {
    std::string message;
};

using Command = std::variant<NewOrderCommand, CancelCommand, AmendCommand, PrintBookCommand, ParseError>;

// Transforma uma linha de texto do usuário em um Command.
// Exemplos aceitos (ver enunciado):
//   "limit buy 10 100"     -> preço 10, qty 100
//   "market buy 150"       -> sem preço
//   "peg bid buy 150"      -> peg to bid
//   "cancel order 3"
//   "print book"
Command parseLine(const std::string& line);

}  // namespace cli
