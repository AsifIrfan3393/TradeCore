#include "tradecore/matching/MatchingEngine.hpp"

#include <utility>

namespace tradecore
{

void MatchingEngine::submitOrder(Order order)
{
    orderBook_.addOrder(std::move(order));
}

const OrderBook& MatchingEngine::orderBook() const noexcept
{
    return orderBook_;
}

} // namespace tradecore