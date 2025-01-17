cmake_minimum_required(VERSION 3.30)
project(cses_fi)

set(CMAKE_CXX_STANDARD 20)

add_executable(cses_fi "graph algorithms/counting-rooms.cpp"
        "graph algorithms/labyrinth.cpp"
        "graph algorithms/building-roads .cpp"
        "graph algorithms/message-route.cpp"
        "graph algorithms/building-teams.cpp"
        "graph algorithms/round-trip.cpp"
        "graph algorithms/monsters.cpp"
        "graph algorithms/shortest-routes-1.cpp"
        "graph algorithms/shortest-routes-2.cpp"
        "graph algorithms/high-score.cpp"
        "graph algorithms/flight-discount.cpp"
        "graph algorithms/cycle-finding.cpp"
        "graph algorithms/flight-routes.cpp"
        "graph algorithms/round-trip-2.cpp"
        "graph algorithms/course-schedule.cpp"
        "graph algorithms/longest-flight-route.cpp"
        "graph algorithms/game-routes.cpp"
        "graph algorithms/road-reparation.cpp"
        "graph algorithms/road-construction.cpp"
        "graph algorithms/flight-routes-check.cpp"
        introductory-problems/weird-algorithm.cpp
        introductory-problems/missing-number.cpp
        introductory-problems/repetitions.cpp
        introductory-problems/increasing-array.cpp
        introductory-problems/permutations.cpp
        introductory-problems/number-spiral.cpp
        introductory-problems/two-knights.cpp
        introductory-problems/two-sets.cpp
        introductory-problems/bit-strings.cpp
        introductory-problems/trailing-zeros.cpp
        introductory-problems/coin-piles.cpp
        introductory-problems/palindrome-reorder.cpp
        introductory-problems/gray-code.cpp
        introductory-problems/creating-strings.cpp
        introductory-problems/apple-division.cpp
        introductory-problems/chessboard-and-queens.cpp
        introductory-problems/tower-of-hanoi.cpp
        dynamic-programming/dice-combinations.cpp
        dynamic-programming/minimizing-coins.cpp
        dynamic-programming/coin-combinations-1.cpp
        dynamic-programming/coin-combinations-2.cpp
        dynamic-programming/removing-digits.cpp
        dynamic-programming/grid-path.cpp
        dynamic-programming/book-shop.cpp
        dynamic-programming/array-description.cpp
        dynamic-programming/counting-towers.cpp
        dynamic-programming/edit-distance.cpp
        dynamic-programming/rectangle-cutting.cpp
        dynamic-programming/money-sums.cpp
        dynamic-programming/removal-game.cpp
        dynamic-programming/two-sets-2.cpp
        dynamic-programming/increasing-subsequence.cpp)
