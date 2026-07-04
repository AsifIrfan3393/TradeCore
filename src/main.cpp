#include <iostream>

#include "tradecore/model/Order.hpp"
#include "tradecore/model/PriceLevel.hpp"
#include "tradecore/model/OrderBook.hpp"
#include "tradecore/matching/MatchingEngine.hpp"

using namespace tradecore;

int main()
{
    std::cout << "========== Order Test ==========\n\n";

    Order order(
        1,
        100,
        "AAPL",
        Side::Buy,
        15000,
        100,
        1
    );

    std::cout << "Original Quantity : " << order.originalQuantity() << '\n';
    std::cout << "Remaining Quantity: " << order.remainingQuantity() << '\n';

    order.fill(40);

    std::cout << "\nAfter filling 40 shares\n";
    std::cout << "Remaining Quantity: " << order.remainingQuantity() << '\n';

    order.fill(60);

    std::cout << "\nAfter filling remaining shares\n";
    std::cout << "Remaining Quantity: " << order.remainingQuantity() << '\n';

    std::cout << "Filled: "
              << std::boolalpha
              << order.isFilled()
              << "\n\n";


    std::cout << "========== PriceLevel Test ==========\n\n";

    Order order1(
        1,
        100,
        "AAPL",
        Side::Buy,
        15000,
        100,
        1
    );

    Order order2(
        2,
        101,
        "AAPL",
        Side::Buy,
        15000,
        200,
        2
    );

    PriceLevel level;

    level.addOrder(std::move(order1));
    level.addOrder(std::move(order2));

    std::cout << "Size           : " << level.size() << '\n';
    std::cout << "Total Quantity : " << level.totalQuantity() << '\n';
    std::cout << "Front Order ID : " << level.front().orderId() << '\n';

    level.removeFront();

    std::cout << "\nAfter removing front order\n";
    std::cout << "Size           : " << level.size() << '\n';
    std::cout << "Total Quantity : " << level.totalQuantity() << '\n';
    std::cout << "Front Order ID : " << level.front().orderId() << '\n';

OrderBook book;

book.addOrder(Order(
    1,
    100,
    "AAPL",
    Side::Buy,
    15000,
    100,
    1));

book.addOrder(Order(
    2,
    101,
    "AAPL",
    Side::Buy,
    15100,
    50,
    2));

book.addOrder(Order(
    3,
    102,
    "AAPL",
    Side::Sell,
    15200,
    200,
    3));

std::cout << "Best Bid: "
          << book.bestBid().front().price()
          << '\n';

std::cout << "Best Ask: "
          << book.bestAsk().front().price()
          << '\n';

std::cout << "\n========== Matching Engine ==========\n\n";

MatchingEngine engine;

engine.submitOrder(Order(
    1,
    100,
    "AAPL",
    Side::Buy,
    15000,
    100,
    1));

engine.submitOrder(Order(
    2,
    101,
    "AAPL",
    Side::Sell,
    15100,
    200,
    2));

std::cout << "Best Bid : "
          << engine.orderBook().bestBid().front().price()
          << '\n';

std::cout << "Best Ask : "
          << engine.orderBook().bestAsk().front().price()
          << '\n';

    return 0;
}