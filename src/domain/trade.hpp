#pragma once

#include "domain/order.hpp"
#include "domain/price.hpp"

namespace engine {

struct Trade {
    Price price;
    Quantity quantity;
};

}  // namespace engine
