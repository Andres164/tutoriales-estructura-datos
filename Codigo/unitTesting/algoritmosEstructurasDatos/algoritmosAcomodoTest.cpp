#include <iostream>
#include <exception>
#include <time.h>
#include "algoritmosEstructurasDatos/algoritmosAcomodoTest.h"
#include "../../algoritmosEstructurasDatos/manejoArreglos.h"
#include "../../algoritmosEstructurasDatos/algoritmosAcomodo.h"

namespace algoritmosAcomodoTest
{
    bool test_AlgoritmoAcomodo(AlgoritmosDeAcomodo algoritmoAcomodo, int longiutdSetDeDatos)
    {
        int numeroArreglosMalAcomodados = 0, numeroArreglosBienAcomodados  = 0;
        try
        {
            while( numeroArreglosMalAcomodados < 6 && numeroArreglosBienAcomodados < 100 )
            {
                int setDeDatos[longiutdSetDeDatos];
                algoritmosAcomodoTest::llenarSetDatosConValoresRandom(setDeDatos, longiutdSetDeDatos);
                acomodarArregloCon(setDeDatos, longiutdSetDeDatos, algoritmoAcomodo);
                if( estaElArregloAcomodadoMenorAMayor(setDeDatos, longiutdSetDeDatos) )
                    numeroArreglosBienAcomodados++;
                else
                {
                    std::cout << "El arreglo esta mal acomodado" << std::endl;
                    numeroArreglosMalAcomodados++;
                    manejoArreglos::imprimirArreglo(setDeDatos, longiutdSetDeDatos);
                }
                std::cout << "-- " << numeroArreglosBienAcomodados + numeroArreglosMalAcomodados << " --" << std::endl;
            }
        }
        catch(const std::exception& ex)
        {
            std::cout << "Ocurrio una excepcion al testear el algoritmo de acomodo: " << ex.what() << std::endl;
        }
        bool testExitoso = numeroArreglosMalAcomodados == 0 && numeroArreglosBienAcomodados >= 1;
        std::cout << "test_AlgoritmoAcomodo... " << ( testExitoso ? "EXITOSO" : "FALLIDO" ) << std::endl;
        std::cout << "Numero de arreglos bien acomodados... " << numeroArreglosBienAcomodados << std::endl;
        std::cout << "Numero de arreglos mal acomodados... " << numeroArreglosMalAcomodados << std::endl;
        return testExitoso;
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
                arreglo[i] = rand();
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
        try
        {
            switch(algoritmo)
            {
            case AlgoritmosDeAcomodo::SelectionSort:
                algoritmosAcomodo::selectionSort(arreglo, longitud);
                break;

            case AlgoritmosDeAcomodo::InsertionSort:
                algoritmosAcomodo::insertionSort(arreglo, longitud);
                break;

            case AlgoritmosDeAcomodo::BinaryInsertionSort:
                algoritmosAcomodo::binaryInsertionSort(arreglo, longitud);
                break;

            case AlgoritmosDeAcomodo::ShellSort:
                algoritmosAcomodo::shellSort(arreglo, longitud);
                break;

            case AlgoritmosDeAcomodo::MergeSort:
                algoritmosAcomodo::mergeSort(arreglo, longitud);
                break;

            case AlgoritmosDeAcomodo::QuickSort:
                algoritmosAcomodo::quickSort(arreglo, longitud);
                break;
            }
        }
        catch(const std::exception& ex)
        {
            std::cout << "Ocurrio una excepcion al intentar acomodar el arreglo: " << ex.what() << std::endl;
        }
    }
}
