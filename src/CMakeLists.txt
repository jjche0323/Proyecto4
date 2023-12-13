set(HEADER_LIST "${Calculadora_SOURCE_DIR}/include/*.hh")

# Agreguen acá todos los archivos .cc que necesiten para compilar
add_executable(Calculadora
    main.cc
    token.cc
    tokenizer.cc
    shunting_yard.cc
    postfijo.cc
    calculadora.cc
        ../include/BST.hh
        ../include/calculadora.hh
        ../include/fibonacci.hh
        ../include/ITree.hh
        ../include/postfijo.hh
        ../include/shunting_yard.hh
        ../include/token.hh
        ../include/tokenizer.hh
)

target_include_directories(Calculadora PUBLIC
        ${Calculadora_SOURCE_DIR}/include
)
