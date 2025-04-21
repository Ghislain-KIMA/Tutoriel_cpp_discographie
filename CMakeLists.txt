cmake_minimum_required(VERSION 3.30)

project(discographie)

set(HEADERS
    disco/include/afficher.hpp
    disco/include/ajouter.hpp
    disco/include/charger.hpp
    disco/include/enregistrer.hpp
    disco/include/menu.hpp
    disco/include/noms.hpp
    disco/include/outils.hpp
    disco/include/quitter.hpp
)

set(SOURCES
    disco/src/afficher.cpp
    disco/src/ajouter.cpp
    disco/src/charger.cpp
    disco/src/enregistrer.cpp
    disco/src/menu.cpp
    disco/src/outils.cpp
    disco/src/quitter.cpp
    disco/src/disco.cpp
)

set(CMAKE_CXX_STANDARD 23)

include_directories(${CMAKE_SOURCE_DIR}/disco/include)
add_executable(disco ${SOURCES} ${HEADERS})
set_target_properties(disco PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/disco/bin)