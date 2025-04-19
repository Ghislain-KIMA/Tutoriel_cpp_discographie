cmake_minimum_required(VERSION 3.30)

project(discographie)

set(HEADERS
    afficher.hpp
    ajouter.hpp
    charger.hpp
    enregistrer.hpp
    menu.hpp
    noms.hpp
    outils.hpp
    quitter.hpp
)

set(SOURCES
    afficher.cpp
    ajouter.cpp
    charger.cpp
    enregistrer.cpp
    menu.cpp
    outils.cpp
    quitter.cpp
    main.cpp
)

set(CMAKE_CXX_STANDARD 23)

add_executable(disco ${SOURCES} ${HEADERS})