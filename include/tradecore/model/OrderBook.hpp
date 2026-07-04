#pragma once

#include <map>
#include <unordered_map>

#include "tradecore/model/Order.hpp"
#include "tradecore/model/PriceLevel.hpp"
#include "tradecore/model/OrderLocation.hpp"

namespace tradecore
{

class OrderBook
{
public:

    void addOrder(Order order);

    bool empty() const noexcept;
    bool cancelOrder(OrderId orderId);

    bool contains(OrderId orderId) const noexcept;

    const PriceLevel& bestBid() const;

    const PriceLevel& bestAsk() const;
    // Queries
[[nodiscard]] bool hasBuyOrders() const noexcept;
[[nodiscard]] bool hasSellOrders() const noexcept;

[[nodiscard]] Price bestBidPrice() const;
[[nodiscard]] Price bestAskPrice() const;

// Access price levels
PriceLevel& bestBidLevel();
PriceLevel& bestAskLevel();

const PriceLevel& bestBidLevel() const;
const PriceLevel& bestAskLevel() const;

private:

    using BuyBook =
        std::map<Price, PriceLevel, std::greater<Price>>;

    using SellBook =
        std::map<Price, PriceLevel>;

    std::unordered_map<OrderId, OrderLocation> orderIndex_;

    BuyBook buyBook_;

    SellBook sellBook_;
};

}