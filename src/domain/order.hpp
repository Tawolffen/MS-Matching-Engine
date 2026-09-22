#pragma once

#include <cstdint>
#include <optional>
#include <string>

#include "domain/enums.hpp"
#include "domain/price.hpp"

namespace engine {

using OrderId = std::uint64_t;
using SequenceNumber = std::uint64_t;  // usado para desempate FIFO
using Quantity = std::int64_t;

struct Order {
    OrderId id;
    OrderType type;
    Side side;
    Quantity quantity;

    // Presente apenas quando type == Limit (ou Peg, após resolvido para um preço).
    std::optional<Price> price;

    // Presente apenas quando type == Peg.
    PegReference pegReference = PegReference::None;

    // Usado para manter prioridade FIFO dentro da mesma faixa de preço.
    SequenceNumber sequence;

    std::string label() const;  // ex: "buy 100 @ 10" — para logs/testes
};

}  // namespace engine
