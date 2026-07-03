#include "tradecore/model/PriceLevel.hpp"

#include <stdexcept>
#include <utility>

namespace tradecore
{

void PriceLevel::addOrder(Order order)
{
    totalQuantity_ += order.remainingQuantity();

    orders_.push_back(std::move(order));
}

void PriceLevel::removeFront()
{
    if (orders_.empty())
    {
        throw std::runtime_error("PriceLevel is empty");
    }

    totalQuantity_ -= orders_.front().remainingQuantity();

    orders_.pop_front();
}

Order& PriceLevel::front()
{
    if (orders_.empty())
    {
        throw std::runtime_error("PriceLevel is empty");
    }

    return orders_.front();
}

const Order& PriceLevel::front() const
{
    if (orders_.empty())
    {
        throw std::runtime_error("PriceLevel is empty");
    }

    return orders_.front();
}

bool PriceLevel::empty() const noexcept
{
    return orders_.empty();
}

std::size_t PriceLevel::size() const noexcept
{
    return orders_.size();
}

Quantity PriceLevel::totalQuantity() const noexcept
{
    return totalQuantity_;
}

}