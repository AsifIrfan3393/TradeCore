#pragma once

namespace tradecore
{

enum class Side
{
    Buy,
    Sell
};

enum class OrderStatus
{
    New,
    PartiallyFilled,
    Filled,
    Cancelled
};

enum class OrderType
{
    Limit
};

} // namespace tradecore