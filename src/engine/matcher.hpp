#pragma once

#include <cstdint>
#include <vector>

#include "domain/order.hpp"
#include "domain/trade.hpp"
#include "engine/order_book.hpp"

namespace engine {

// Orquestra a lógica de negócio: recebe comandos vindos do parser (new
// order, cancel, amend), decide o que cruza contra o book e o que sobra
// como ordem passiva, e devolve os trades resultantes para a CLI imprimir.
class Matcher {
public:
    // Processa uma nova ordem (limit, market ou peg). Retorna os trades
    // gerados, na ordem em que ocorreram. Ordens limit que não cruzam
    // totalmente (ou não cruzam nada) entram no book como passivas.
    std::vector<Trade> submit(const Order& order);

    // Requisito adicional 3.
    bool cancel(OrderId id);

    // Requisito adicional 4. Se newPrice mudar, a ordem perde prioridade
    // (vai para o fim da fila na nova faixa de preço).
    bool amend(OrderId id, std::optional<Price> newPrice, std::optional<Quantity> newQuantity);

    const OrderBook& book() const { return book_; }

private:
    OrderBook book_;
    OrderId nextOrderId_ = 1;

    // TODO: acompanhar todas as ordens Peg ativas para poder reavaliar seu
    // preço sempre que o melhor bid/offer do book mudar (ver requisito 5).
};

}  // namespace engine
