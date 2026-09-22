#include "engine/matcher.hpp"

namespace engine {

std::vector<Trade> Matcher::submit(const Order& order) {
    // TODO:
    // 1. Se for Market: cruzar contra o melhor preço do lado oposto até
    //    esgotar a quantidade ou o book (ordem nunca fica passiva).
    // 2. Se for Limit: cruzar enquanto o preço permitir (ver DECISIONS.md
    //    para a decisão sobre "preencher vs. ignorar" quando cruzaria);
    //    o restante (se houver) vira ordem passiva no book.
    // 3. Se for Peg: resolver o preço de referência (bestBid/bestOffer)
    //    no momento da inserção e tratar como uma Limit nesse preço; manter
    //    registrada a necessidade de realinhamento futuro (requisito 5).
    return {};
}

bool Matcher::cancel(OrderId id) {
    // TODO: delegar para book_.removeOrder(id) (e remover de qualquer
    // registro auxiliar de ordens Peg, se aplicável).
    return false;
}

bool Matcher::amend(OrderId id, std::optional<Price> newPrice, std::optional<Quantity> newQuantity) {
    // TODO: se o preço mudar, a ordem deve perder a prioridade FIFO (ou
    // seja, na prática: remover do book e reinserir como se fosse nova,
    // preservando o mesmo OrderId).
    return false;
}

}  // namespace engine
