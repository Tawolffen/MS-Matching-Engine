#pragma once

#include <cstdint>
#include <string>

namespace engine {

// Preço representado como inteiro escalado (4 casas decimais) para evitar
// problemas de comparação/ordenação com ponto flutuante dentro do book.
// Ver DECISIONS.md para a justificativa completa.
using Price = std::int64_t;

constexpr Price kPriceScale = 10000;  // 1.0000 -> 10000

// Converte uma string de entrada (ex: "10.5") para a representação interna.
Price parsePrice(const std::string& text);

// Converte de volta para exibição (ex: 100000 -> "10.5", sem zeros à direita
// desnecessários, respeitando o formato usado nos exemplos do enunciado).
std::string formatPrice(Price price);

}  // namespace engine
