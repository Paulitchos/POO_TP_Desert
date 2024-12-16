cmake_minimum_required(VERSION 3.29)
project(src)

set(CMAKE_CXX_STANDARD 20)

add_executable(src main.cpp
        Interface/Buffer.cpp
        Interface/Buffer.h
        Componentes/Mapa.cpp
        Componentes/Mapa.h
        Interface/Interface.cpp
        Interface/Interface.h
        Componentes/Simulador.cpp
        Componentes/Simulador.h
        Componentes/Montanha/Montanha.cpp
        Componentes/Montanha/Montanha.h
        Componentes/Cidade/Cidade.cpp
        Componentes/Cidade/Cidade.h
        Comandos/Comando.cpp
        Comandos/Comando.h
        Comandos/ComandoProx.cpp
        Comandos/ComandoProx.h
        Comandos/ComandoPrecos.cpp
        Comandos/ComandoPrecos.h
        Componentes/Item/Pandora.cpp
        Componentes/Item/Pandora.h
        Componentes/Item/Item.cpp
        Componentes/Item/Item.h
        Componentes/Caravanas/Caravana.cpp
        Componentes/Caravanas/Caravana.h
        Componentes/Caravanas/Barbaros.cpp
        Componentes/Caravanas/Barbaros.h
        Componentes/Caravanas/Militar.cpp
        Componentes/Caravanas/Militar.h
        Componentes/Caravanas/Comercio.cpp
        Componentes/Caravanas/Comercio.h
        Componentes/Caravanas/Secreta.cpp
        Componentes/Caravanas/Secreta.h
        Comandos/ComandoCompraC.cpp
        Comandos/ComandoCompraC.h
)
