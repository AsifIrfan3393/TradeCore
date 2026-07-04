#pragma once

#include <list>

#include "tradecore/common/Enums.hpp"
#include "tradecore/model/Order.hpp"
#include "tradecore/types/Types.hpp"

namespace tradecore
{

struct OrderLocation
{
    Side side;

    Price price;

    std::list<Order>::iterator iterator;
};

} // namespace tradecore