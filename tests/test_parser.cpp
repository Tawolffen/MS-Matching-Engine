#include <catch2/catch_test_macros.hpp>

#include "cli/parser.hpp"

TEST_CASE("scaffold: build de testes funcionando", "[parser]") {
    REQUIRE(1 + 1 == 2);
}

// TODO: TEST_CASE("limit buy vira NewOrderCommand com preco e qty corretos")
// TODO: TEST_CASE("market buy vira NewOrderCommand sem preco")
// TODO: TEST_CASE("peg bid buy vira NewOrderCommand com PegReference::Bid")
// TODO: TEST_CASE("cancel order <id> vira CancelCommand")
// TODO: TEST_CASE("entrada invalida vira ParseError")
