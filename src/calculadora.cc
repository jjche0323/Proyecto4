#include <algorithm>
#include "../include/tokenizer.hh"
//#include "calculadora.hh"
#include "../include/calculadora.hh"
//#include <postfijo.hh>
#include "../include/postfijo.hh"
//#include <shunting_yard.hh>
#include "../include/shunting_yard.hh"
//#include <tokenizer.hh>


bool ask_user(std::istream& in, std::ostream& out)
{
    std::string expresion;
    out << "Ingrese una expresi\¢n o escriba \"salir\": ";
    getline(in, expresion);

    // Convertir expresion a minúsculas
    std::transform(expresion.begin(), expresion.end(), expresion.begin(), ::tolower);

    if (expresion == "exit") {
        out << "Saliendo..." << std::endl;
        return false;
    }

    Calculadora calculadora(expresion);
    if (calculadora.IsValid()) {
        out << "El resultado es: " << calculadora.Resultado() << std::endl;
    } else {
        out << "Error: " << calculadora.Error() << std::endl;
    }
    return true;
}

Calculadora::Calculadora(std::string expresion)
        : expresion(expresion)
        , error("")
        , resultado(0)
{
    Evaluar();
}

double Calculadora::Resultado() const
{
    return resultado;
}

std::string Calculadora::Error() const
{
    return error;
}

bool Calculadora::IsValid() const
{
    return error == "";
}

void Calculadora::Evaluar()
{
    try {
        // Primero se tokeniza la expresion
        Tokenizer tokenizer(expresion);

        // Luego se convierte a postfijo
        ShuntingYard shuntingYard(tokenizer);
        auto cola = shuntingYard.ConvertirAPostfijo();

        // Evaluamos la expresión en postfijo
        Postfijo postfijo(cola);

        // Y finalmente obtenemos el resultado
        resultado = postfijo.Resultado();
    } catch (std::exception& e) {
        //El error es que se asigna el valor error incorrectamente
        //error = e.what();
        error = "Error al evaluar la expresión";
        return;
    }
}
