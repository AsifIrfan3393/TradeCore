#pragma once

#include <list>

#include "tradecore/model/Order.hpp"

namespace tradecore
{

class PriceLevel
{
public:
    void addOrder(Order order);

    void removeFront();

    Order& front();
    const Order& front() const;

    bool empty() const noexcept;

    std::size_t size() const noexcept;

    Quantity totalQuantity() const noexcept;

private:
    std::list<Order> orders_;

    Quantity totalQuantity_{0};
};

}