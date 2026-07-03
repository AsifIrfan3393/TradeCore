#include "tradecore/model/Order.hpp"

#include <stdexcept>
#include <utility>

namespace tradecore
{

Order::Order(
    OrderId orderId,
    ClientId clientId,
    std::string symbol,
    Side side,
    Price price,
    Quantity quantity,
    Timestamp timestamp,
    OrderType orderType)
    : m_orderId(orderId),
      m_clientId(clientId),
      m_symbol(std::move(symbol)),
      m_side(side),
      m_price(price),
      m_originalQuantity(quantity),
      m_remainingQuantity(quantity),
      m_timestamp(timestamp),
      m_status(OrderStatus::New),
      m_orderType(orderType)
{
    if (price <= 0)
    {
        throw std::invalid_argument("Price must be positive.");
    }

    if (quantity == 0)
    {
        throw std::invalid_argument("Quantity must be positive.");
    }

    if (m_symbol.empty())
    {
        throw std::invalid_argument("Symbol cannot be empty.");
    }
}
OrderId Order::orderId() const noexcept
{
    return m_orderId;
}

ClientId Order::clientId() const noexcept
{
    return m_clientId;
}

const std::string& Order::symbol() const noexcept
{
    return m_symbol;
}

Side Order::side() const noexcept
{
    return m_side;
}

Price Order::price() const noexcept
{
    return m_price;
}

Quantity Order::originalQuantity() const noexcept
{
    return m_originalQuantity;
}

Quantity Order::remainingQuantity() const noexcept
{
    return m_remainingQuantity;
}

Timestamp Order::timestamp() const noexcept
{
    return m_timestamp;
}

OrderStatus Order::status() const noexcept
{
    return m_status;
}

OrderType Order::orderType() const noexcept
{
    return m_orderType;
}

void Order::fill(Quantity quantity)
{
    if (quantity == 0)
    {
        throw std::invalid_argument("Fill quantity must be positive.");
    }

    if (quantity > m_remainingQuantity)
    {
        throw std::invalid_argument("Fill quantity exceeds remaining quantity.");
    }

    m_remainingQuantity -= quantity;

    if (m_remainingQuantity == 0)
    {
        m_status = OrderStatus::Filled;
    }
    else
    {
        m_status = OrderStatus::PartiallyFilled;
    }
}

bool Order::isFilled() const noexcept
{
    return m_status == OrderStatus::Filled;
}

}// namespace tradecore