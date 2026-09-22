#include "engine/order_book.hpp"

namespace engine {

void OrderBook::addOrder(const Order& order) {
    // TODO: inserir em bids_ ou asks_ conforme order.side, no deque da
    // faixa de preço correspondente (order.price deve estar presente aqui —
    // ordens Market nunca chegam a este ponto, e ordens Peg já devem ter
    // sido resolvidas para um preço concreto pelo Matcher antes de chamar
    // addOrder).
}

bool OrderBook::removeOrder(OrderId id) {
    // TODO: localizar e remover a ordem. Ver nota de eficiência no .hpp.
    return false;
}

std::optional<Price> OrderBook::bestBid() const {
    // TODO: bids_.empty() ? std::nullopt : bids_.rbegin()->first
    return std::nullopt;
}

std::optional<Price> OrderBook::bestOffer() const {
    // TODO: asks_.empty() ? std::nullopt : asks_.begin()->first
    return std::nullopt;
}

void OrderBook::print(std::ostream& out) const {
    // TODO: imprimir as duas colunas (compra/venda) lado a lado, dos
    // melhores preços para os piores, como no exemplo do enunciado.
}

}  // namespace engine
