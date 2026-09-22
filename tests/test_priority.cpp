#include <catch2/catch_test_macros.hpp>

#include "engine/matcher.hpp"

TEST_CASE("scaffold: build de testes funcionando", "[priority]") {
    REQUIRE(1 + 1 == 2);
}

// TODO: TEST_CASE("duas ordens sell no mesmo preco: a que chegou primeiro eh preenchida primeiro")
// TODO: TEST_CASE("amend que muda o preco perde a prioridade FIFO (vai para o fim da fila)")
// TODO: TEST_CASE("amend que so muda a quantidade mantem a prioridade FIFO")
