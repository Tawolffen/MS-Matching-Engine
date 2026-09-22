#include <catch2/catch_test_macros.hpp>

#include "engine/matcher.hpp"

TEST_CASE("scaffold: build de testes funcionando", "[pegged]") {
    REQUIRE(1 + 1 == 2);
}

// TODO: reproduzir o exemplo completo do enunciado (requisito adicional 5):
//   book inicial: 200@10 / 100@9.99 (compra) e 100@10.5 (venda)
//   peg bid buy 150       -> nova ordem entra a 10 (= bestBid), abaixo da
//                             ordem 200@10 ja existente (perde prioridade
//                             por ter chegado depois no mesmo preco)
//   limit buy 10.1 300    -> bestBid muda para 10.1; a peg deve ser
//                             realinhada automaticamente para 10.1
// TODO: TEST_CASE("peg to offer acompanha o bestOffer da mesma forma")
// TODO: TEST_CASE("peg reavaliada apos um trade que muda o best bid/offer")
