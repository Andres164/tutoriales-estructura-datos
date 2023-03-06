#pragma once

namespace algoritmosAcomodoTest
{
    enum class AlgoritmosDeAcomodo = { InsertionSort, SelectionSort, MergeSort, QuickSort };
    bool test_AlgoritmoAcomodo(AlgoritmosDeAcomodo algoritmoAcomodo, int longiutdSetDeDatos);
    void llenarSetDatosConValoresRandom(int arreglo[], int longitud);
    bool estaElArregloAcomodadoMenorAMayor(int arreglo[], int longitud);
    void acomodarArregloCon(int arreglo[], int longitud, AlgoritmosDeAcomodo algoritmo);
}

