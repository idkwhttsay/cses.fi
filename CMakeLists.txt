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
        dynamic-programming/increasing-subsequence.cpp
        range-queries/static-range-sum-queries.cpp
        range-queries/static-range-minimum-queries.cpp
        range-queries/dynamic-range-sum-queries.cpp
        range-queries/dynamic-range-minimum-queries.cpp
        range-queries/range-xor-queries.cpp
        range-queries/range-update-queries.cpp
        range-queries/forest-queries.cpp
        range-queries/hotel-queries.cpp
        range-queries/list-removals.cpp
        range-queries/salary-queries.cpp
        range-queries/prefix-sum-queries.cpp
        range-queries/subarray-sum-queries.cpp
        range-queries/distinct-values-queries.cpp
        sorting-and-searching/distinct-numbers.cpp
        sorting-and-searching/apartments.cpp
        sorting-and-searching/ferris-wheel.cpp
        sorting-and-searching/concert-tickets.cpp
        sorting-and-searching/restaraunt-customers.cpp
        sorting-and-searching/movie-festival.cpp
        sorting-and-searching/sum-of-two-values.cpp
        sorting-and-searching/max-subarray-sum.cpp
        sorting-and-searching/stick-lengths.cpp
        sorting-and-searching/missing-coin-sum.cpp
        sorting-and-searching/collecting-numbers.cpp
        sorting-and-searching/collecting-numbers-2.cpp
        sorting-and-searching/playlist.cpp
        sorting-and-searching/towers.cpp
        sorting-and-searching/josephus-problem-1.cpp
        sorting-and-searching/factory-machines.cpp
        sorting-and-searching/subarray-sums-1.cpp
        sorting-and-searching/subarray-sums-2.cpp
        mathematics/exponentiation.cpp
        mathematics/exponentiation-2.cpp
        mathematics/counting-divisors.cpp
        mathematics/binominal-coefficents.cpp
        mathematics/creating-strings-2.cpp
        mathematics/distributing-apples.cpp
        mathematics/christmas-party.cpp
        mathematics/bracket-sequences-1.cpp
        mathematics/fibonacci-numbers.cpp
        mathematics/graph-paths-1.cpp
        mathematics/graph-paths-2.cpp
        sorting-and-searching/subarray-divisibility.cpp
        advanced-techniques/meet-in-the-middle.cpp)
