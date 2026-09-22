#include <catch2/catch_test_macros.hpp>

#include "engine/matcher.hpp"

TEST_CASE("scaffold: build de testes funcionando", "[matcher]") {
    engine::Matcher matcher;
    REQUIRE(matcher.book().bestBid() == std::nullopt);
}

// TODO: reproduzir o exemplo completo do enunciado:
//   limit buy 10 100
//   limit sell 20 100
//   limit sell 20 200
//   market buy 150   -> Trade price 20 qty 150
//   market buy 200   -> Trade price 20 qty 150 (e sobra 50 sem preencher, ou
//                        outro comportamento definido no DECISIONS.md)
//   market sell 200  -> Trade price 10 qty 100
// TODO: TEST_CASE("limit order que cruzaria: comportamento decidido em DECISIONS.md")
// TODO: TEST_CASE("market order sem liquidez suficiente no book")
