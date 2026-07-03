#pragma once

#include <string>

#include "tradecore/common/Enums.hpp"
#include "tradecore/types/Types.hpp"

namespace tradecore
{

class Order
{
public:
    Order(
        OrderId orderId,
        ClientId clientId,
        std::string symbol,
        Side side,
        Price price,
        Quantity quantity,
        Timestamp timestamp,
        OrderType orderType = OrderType::Limit
    );

    [[nodiscard]] OrderId orderId() const noexcept;
    [[nodiscard]] ClientId clientId() const noexcept;
    [[nodiscard]] const std::string& symbol() const noexcept;
    [[nodiscard]] Side side() const noexcept;
    [[nodiscard]] Price price() const noexcept;
    [[nodiscard]] Quantity originalQuantity() const noexcept;
    [[nodiscard]] Quantity remainingQuantity() const noexcept;
    [[nodiscard]] Timestamp timestamp() const noexcept;
    [[nodiscard]] OrderStatus status() const noexcept;
    [[nodiscard]] OrderType orderType() const noexcept;

    void fill(Quantity quantity);

    [[nodiscard]] bool isFilled() const noexcept;

private:
    OrderId m_orderId;
    ClientId m_clientId;
    std::string m_symbol;
    Side m_side;
    Price m_price;
    Quantity m_originalQuantity;
    Quantity m_remainingQuantity;
    Timestamp m_timestamp;
    OrderStatus m_status;
    OrderType m_orderType;
};

} // namespace tradecore