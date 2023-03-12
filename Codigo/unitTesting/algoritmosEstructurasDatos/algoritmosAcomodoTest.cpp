#include <iostream>
#include <exception>
#include <time.h>
#include "algoritmosEstructurasDatos/algoritmosAcomodoTest.h"

namespace algoritmosAcomodoTest
{
    bool test_AlgoritmoAcomodo(AlgoritmosDeAcomodo algoritmoAcomodo, int longiutdSetDeDatos)
    {

    }

    bool srandEstaInicializado = false;

    void inicializarSrand()
    {
        if( !algoritmosAcomodoTest::srandEstaInicializado )
        {
            srand(time(NULL));
            srandEstaInicializado = true;
        }
    }

    void llenarSetDatosConValoresRandom(int arreglo[], int longitud)
    {
        try
        {
            algoritmosAcomodoTest::inicializarSrand();
            for(int i = 0; i < longitud; i++)
                arreglo[i] = rand() % 2000;
        }
        catch(const std::exception& ex)
        {
            std::cout << "Ocurrio una excepcion al intentar llenar el set de datos" << ex.what() << std::endl;
        }
    }

    bool estaElArregloAcomodadoMenorAMayor(int arreglo[], int longitud)
    {
        try
        {
            for( int i = 1; i < longitud; i++)
                if(arreglo[i -1] > arreglo[i])
                    return false;
        }
        catch(const std::exception& ex)
        {
            std::cout << "currio una excepcion al intentar verificar que el arreglo estubiera acomodado: " << ex.what() << std::endl;
            return false;
        }
        return true;
    }

    void acomodarArregloCon(int arreglo[], int longitud, AlgoritmosDeAcomodo algoritmo)
    {

    }
}
