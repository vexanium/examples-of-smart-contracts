cmake_minimum_required(VERSION 3.5)
project(eosio_token_example VERSION 1.0.0)
find_package(eosio.cdt)


file(GLOB_RECURSE SOURCE_FILES "*.hpp" "*.cpp")

add_contract(basopooloflp  basopooloflp ${CMAKE_CURRENT_SOURCE_DIR}/src/basopooloflp.cpp)

target_include_directories(basopooloflp.wasm
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_compile_options(basopooloflp.wasm PUBLIC -R${CMAKE_CURRENT_SOURCE_DIR})










