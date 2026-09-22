#pragma once

namespace engine {

enum class Side {
    Buy,
    Sell
};

enum class OrderType {
    Limit,
    Market,
    Peg  // ordem "peg to bid" ou "peg to offer" — ver PegReference
};

// Só é relevante quando OrderType::Peg
enum class PegReference {
    None,
    Bid,    // acompanha o melhor preço de compra do book
    Offer   // acompanha o melhor preço de venda do book
};

}  // namespace engine
