#pragma once

#include <list>

#include "tradecore/model/Order.hpp"

namespace tradecore
{

class PriceLevel
{
public:
    using OrderIterator = std::list<Order>::iterator;

    OrderIterator addOrder(Order order);

    void removeFront();

    Order& front();
    const Order& front() const;

    bool empty() const noexcept;

    std::size_t size() const noexcept;

    Quantity totalQuantity() const noexcept;

    using OrderIterator = std::list<Order>::iterator;
    using ConstOrderIterator = std::list<Order>::const_iterator;

    OrderIterator begin() noexcept;
    OrderIterator end() noexcept;

   ConstOrderIterator begin() const noexcept;
   ConstOrderIterator end() const noexcept;

void erase(OrderIterator it);

private:
    std::list<Order> orders_;

    Quantity totalQuantity_{0};
};

}