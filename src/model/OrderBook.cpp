#include "tradecore/model/OrderBook.hpp"

#include <stdexcept>
#include <utility>

namespace tradecore
{

void OrderBook::addOrder(Order order)
{
    if (order.side() == Side::Buy)
    {
        buyBook_[order.price()].addOrder(std::move(order));
    }
    else
    {
        sellBook_[order.price()].addOrder(std::move(order));
    }
}

bool OrderBook::empty() const noexcept
{
    return buyBook_.empty() && sellBook_.empty();
}

const PriceLevel& OrderBook::bestBid() const
{
    if (buyBook_.empty())
    {
        throw std::runtime_error("Buy book is empty");
    }

    return buyBook_.begin()->second;
}

const PriceLevel& OrderBook::bestAsk() const
{
    if (sellBook_.empty())
    {
        throw std::runtime_error("Sell book is empty");
    }

    return sellBook_.begin()->second;
}

} // namespace tradecore