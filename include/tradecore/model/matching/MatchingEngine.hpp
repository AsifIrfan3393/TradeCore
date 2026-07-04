#pragma once

#include "tradecore/model/Order.hpp"
#include "tradecore/model/OrderBook.hpp"

namespace tradecore
{

class MatchingEngine
{
public:
    void submitOrder(Order order);

    const OrderBook& orderBook() const noexcept;

private:
    OrderBook orderBook_;
};

} // namespace tradecore