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
        "graph algorithms/flight-routes-check.cpp")
