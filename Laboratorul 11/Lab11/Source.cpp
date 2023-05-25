#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "CircularQueue.cpp"

unsigned int Factorial(unsigned int number) {
    return number <= 1 ? number : Factorial(number - 1) * number;
}

TEST_CASE("Factorials are computed", "[factorial]") {
    REQUIRE(Factorial(1) == 1);
    REQUIRE(Factorial(2) == 2);
    REQUIRE(Factorial(3) == 6);
    REQUIRE(Factorial(10) == 3628800);
}

TEST_CASE("CircularQueue tests for unsigned int") {
    SECTION("Adding 2 elements and checking size") {
        CircularQueue<unsigned int> queue(4);
        unsigned int a = 5;
        unsigned int b = 10;
        queue.push(a);
        queue.push(b);
        REQUIRE(queue.getSize() == 2);
    }
}
TEST_CASE("2") {
    SECTION(u8"Adăugarea unui element și deschiderea unui element, verificând dacă coada este goală") {
        CircularQueue<unsigned int> queue(4);
        queue.push(5);
        queue.pop();
        REQUIRE(queue.empty() == true);
    }
}
TEST_CASE("3") {
    SECTION(u8"Verificați primul și ultimul element fără a adăuga nimic (ar trebui să arunce)") {
        CircularQueue<unsigned int> queue(4);
        REQUIRE_THROWS_AS(queue.front(), std::runtime_error);
        REQUIRE_THROWS_AS(queue.back(), std::runtime_error);
    }
}
TEST_CASE("4") {
    SECTION("Adding 5 elements and checking first element") {
        CircularQueue<unsigned int> queue(4);
        queue.push(1);
        queue.push(2);
        queue.push(3);
        queue.push(4);
        queue.push(5);
        REQUIRE(queue.front() == 2); //CU 2 da corect cu altceva ciu ciu plange puiu
    }
}
    TEST_CASE("5") {
    SECTION(u8"Adăugarea a 1000 de elemente, afișarea lor pe toate și verificarea corectitudinii") {
        CircularQueue<unsigned int> queue(4);
        for (unsigned int i = 0; i < 1000; ++i) {
            queue.push(i);
        }

        for (unsigned int i = 996; !queue.empty(); ++i) {
            REQUIRE(queue.front() == i);
            queue.pop();
        }
    }
}
    TEST_CASE("6") {
        SECTION("Adding 2 elements and checking size") {
            CircularQueue<std::string> queue(4);
            queue.push("Hello");
            queue.push("World");
            REQUIRE(queue.getSize() == 2);
        }
    }
    TEST_CASE("7") {
        SECTION("Adding one element and popping one element, checking if queue is empty") {
            CircularQueue<std::string> queue(4);
            queue.push("Hello");
            queue.pop();
            REQUIRE(queue.empty() == true);
        }
    }
    TEST_CASE("8") {
        SECTION("Checking first and last element without adding anything (should throw)") {
            CircularQueue<std::string> queue(4);
            REQUIRE_THROWS_AS(queue.front(), std::runtime_error);
            REQUIRE_THROWS_AS(queue.back(), std::runtime_error);
        }
    }
    TEST_CASE("9") {
        SECTION("Adding 5 elements and checking first element") {
            CircularQueue<std::string> queue(4);
            queue.push("Hello");
            queue.push("World");
            queue.push("!");
            queue.push("Goodbye");
            queue.push("Cruel");
            REQUIRE(queue.front() == "World");
        }
    }
    TEST_CASE("10") {
        SECTION("Adding 1000 elements, popping all of them, and checking correctness") {
            CircularQueue<std::string> queue(4);
            for (unsigned int i = 0; i < 1000; ++i) {
                queue.push(std::to_string(i));
            }
                    for (unsigned int i = 996;  i<1000 && !queue.empty(); ++i) {
                REQUIRE(queue.front() == std::to_string(i));
                queue.pop();
            }
        }
    }
    
 