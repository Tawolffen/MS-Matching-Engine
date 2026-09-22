#pragma once

#include <deque>
#include <map>
#include <optional>
#include <ostream>

#include "domain/order.hpp"
#include "domain/price.hpp"

namespace engine {

// Mantém as ordens passivas (resultantes de limit orders que não cruzaram)
// organizadas por preço e, dentro do mesmo preço, por ordem de chegada (FIFO).
//
// Bids (compra): melhor preço = maior preço -> ordenar em ordem decrescente.
// Asks (venda):  melhor preço = menor preço -> ordenar em ordem crescente.
class OrderBook {
public:
    // Insere uma ordem passiva no lado correto do book.
    void addOrder(const Order& order);

    // Remove uma ordem do book. Retorna false se o id não existir.
    bool removeOrder(OrderId id);

    // Retorna o melhor preço de compra (bid) atual, se houver alguma ordem de compra.
    std::optional<Price> bestBid() const;

    // Retorna o melhor preço de venda (offer/ask) atual, se houver alguma ordem de venda.
    std::optional<Price> bestOffer() const;

    // Imprime o livro no formato pedido pelo requisito adicional 1.
    void print(std::ostream& out) const;

private:
    // std::map<Price, std::deque<Order>> por lado. O deque preserva FIFO
    // dentro do mesmo nível de preço (push_back ao chegar, pop_front ao
    // preencher). std::map mantém os preços ordenados automaticamente,
    // então "melhor preço" é sempre begin() ou rbegin() dependendo do lado.
    std::map<Price, std::deque<Order>> bids_;   // ordenado crescente; melhor = rbegin()
    std::map<Price, std::deque<Order>> asks_;   // ordenado crescente; melhor = begin()

    // TODO (eficiência): sem um índice auxiliar, cancel/amend por OrderId
    // exigem varrer o nível de preço (ou o book inteiro, se o preço da ordem
    // não for conhecido de antemão) -> O(n). Para O(log n) de fato, considere
    // manter um std::unordered_map<OrderId, {Side, Price, iterator}> que
    // aponte direto para a posição da ordem dentro do deque correspondente.
    // Essa é uma decisão de troca (mais memória/complexidade de manutenção
    // vs. tempo de cancelamento) que vale registrar no DECISIONS.md.
};

}  // namespace engine
