#include <iostream>
#include <exception>
#include "LinkedListTest.h"
#include "../algoritmosEstructurasDatos/manejoEstructuraDatos.h"

const vector<int> LinkedListTest::setDeDatos = { -20, 10, -1586, -2,147,483,648, 12, 10, -20, 789, 2,147,483,647, 0, 81, 39, -69 };


bool LinkedListTest::test_push_back()
{
    std::cout << "--------------------------- test_push_back ---------------------------\n\n";
    bool testExitoso = true;
    LinkedList<int> testList = LinkedList<int>();
    unsigned int elementosInsertados = listaPushBackVector(testList, LinkedListTest::setDeDatos);
    std::cout << "Elementos insertados... " << elementosInsertados << "/" << LinkedListTest::setDeDatos.size() << std::endl;
    testExitoso = contienenLosMismosElementos(testList, LinkedListTest::setDeDatos);
    std::cout << "El linked list contiene los elementos insertados? " << (testExitoso ? "SI" : "NO") << std::endl;
    testExitoso = elementosInsertados != LinkedListTest::setDeDatos.size() ? false : testExitoso;
    std::cout << "test_push_back... " << ( testExitoso ? "Exitoso" : "Fallido" ) << std::endl;
    return testExitoso;
}

bool LinkedListTest::test_push_front()
{
    std::cout << "--------------------------- test_push_front ---------------------------\n\n";
    LinkedList<int> testList = LinkedList<int>();
    unsigned int elementosInsertados = listaPushFrontVector(testList, LinkedListTest::setDeDatos);
    std::cout << "Elementos insertados... " << elementosInsertados << "/" << LinkedListTest::setDeDatos.size() << std::endl;
    bool contienenLosMismosElementos = true;
    try
    {
        for(unsigned int i = 0; i < LinkedListTest::setDeDatos.size(); i++)
            contienenLosMismosElementos = ( LinkedListTest::setDeDatos[LinkedListTest::setDeDatos.size()-1 -i] != testList.elementoEnIndex(i) ? false : contienenLosMismosElementos );
    }
    catch(const exception& ex)
    {
        std::cout << "Ocurrio una excepcion al intentar comparar los elementos de las estructuras de datos: " << ex.what() << std::endl;
        contienenLosMismosElementos = false;
    }
    bool testExitoso = contienenLosMismosElementos;
    std::cout << "El linked list contiene los elementos insertados? " << (testExitoso ? "SI" : "NO") << std::endl;
    testExitoso = elementosInsertados != LinkedListTest::setDeDatos.size() ? false : testExitoso;
    std::cout << "test_push_front... " << ( testExitoso ? "Exitoso" : "Fallido" ) << std::endl;
    return testExitoso;
}

bool LinkedListTest::test_pop_back()
{
    bool testExitoso = true;

    LinkedList<int> testList = LinkedList<int>();
    LinkedListTest::listaPushBackVector(testList, LinkedListTest::setDeDatos);

    std::vector<int> mitadSetDeDatos = std::vector<int>(LinkedListTest::setDeDatos.size()/2);
    std::vector<int>::const_iterator itMitadSetDeDatos = LinkedListTest::setDeDatos.begin() +LinkedListTest::setDeDatos.size()/2;
    std::copy(LinkedListTest::setDeDatos.begin(), itMitadSetDeDatos, mitadSetDeDatos.begin());

    unsigned int elementosEliminados = 0;
    try
    {
        for(; elementosEliminados < mitadSetDeDatos.size(); elementosEliminados++)
            testList.pop_back();
    }
    catch(const exception& ex)
    {
        std::cout << "Ocurrio una excepcion al intentar hacer pop_back: " << ex.what() << std::endl;
        testExitoso = false;
    }
    std::cout << "Elementos eliminados... " << elementosEliminados << "/" << mitadSetDeDatos.size() << std::endl;

    testExitoso = ( !LinkedListTest::contienenLosMismosElementos(testList, mitadSetDeDatos) ? false : testExitoso ) ;
    std::cout << "test_pop_back... " << ( testExitoso ? "Exitoso" : "Fallido" ) << std::endl;
    return testExitoso;
}

bool LinkedListTest::test_pop_front()
{
    bool testExitoso = true;
    LinkedList<int> testList = LinkedList<int>();
    LinkedListTest::listaPushBackVector(testList, LinkedListTest::setDeDatos);
    std::vector<int> mitadSetDeDatos = std::vector<int>(LinkedListTest::setDeDatos.size()/2);
    std::vector<int>::const_iterator itMitadSetDeDatos = LinkedListTest::setDeDatos.begin() +LinkedListTest::setDeDatos.size()/2;
    std::copy(itMitadSetDeDatos, LinkedListTest::setDeDatos.end(), mitadSetDeDatos.begin());
    unsigned int elementosEliminados = 0;
    try
    {
        for(; elementosEliminados < mitadSetDeDatos.size(); elementosEliminados++)
            testList.pop_front();
    }
    catch(const exception& ex)
    {
        std::cout << "Ocurrio una excepcion al intentar hacer pop_front: " << ex.what() << std::endl;
        testExitoso = false;
    }
    std::cout << "Elementos eliminados... " << elementosEliminados << "/" << mitadSetDeDatos.size() << std::endl;
    manejoEstructuraDatos::imprimirLinkedList(testList);
    testExitoso = ( !LinkedListTest::contienenLosMismosElementos(testList, mitadSetDeDatos) ? false : testExitoso ) ;
    std::cout << "test_pop_front... " << ( testExitoso ? "Exitoso" : "Fallido" ) << std::endl;
    return testExitoso;
}

bool LinkedListTest::test_InsertarElemento()
{
    bool testExitoso = true;
    LinkedList<int> testList = LinkedList<int>(LinkedListTest::setDeDatos.size());
    LinkedListTest::listaPushBackVector(testList, LinkedListTest::setDeDatos);
    int valorInsertadoAlInicio = 560, valorInsertadoAlMedio = 702;
    try
    {
        testList.insertarElemento(0, valorInsertadoAlInicio);
        testList.insertarElemento(testList.Longitud()/2, valorInsertadoAlMedio);
    }
    catch(const exception& ex)
    {
        std::cout << "Ocurrio una excepcion al intentar insertar los elementos en el LinkedList: " << ex.what() << std::endl;
        testExitoso = false;
    }
    std::vector<int> setDatosModificado = std::vector<int>(LinkedListTest::setDeDatos.size());
    try
    {
        std::copy(LinkedListTest::setDeDatos.begin(), LinkedListTest::setDeDatos.end(), setDatosModificado.begin());
        setDatosModificado.insert(setDatosModificado.begin(), valorInsertadoAlInicio);
        std::vector<int>::const_iterator itAlMedio = setDatosModificado.begin()+setDatosModificado.size()/2;
        setDatosModificado.insert(itAlMedio, valorInsertadoAlMedio);

    }
    catch(const exception& ex)
    {
        std::cout << "Ocurrio una excepcion al intentar crear el nuevo set de datos con los nuevos elementos: " << ex.what() << std::endl;
        testExitoso = false;
    }
    bool seEncuentraValorAlInicio, seEncuentraValorAlMedio, seEncontraronTodosLosElementos;
    try
    {
        seEncuentraValorAlInicio = testList.elementoEnIndex(0) == valorInsertadoAlInicio;
        seEncuentraValorAlMedio = testList.elementoEnIndex(testList.Longitud()/2) == valorInsertadoAlMedio;
    }
    catch(const exception& ex)
    {
        std::cout << "Ocurrio una excepcion al intentar verificar que los elementos fueron insertados: " <<  ex.what() << std::endl;
        testExitoso = false;
    }
    try
    {
        seEncontraronTodosLosElementos = LinkedListTest::contienenLosMismosElementos(testList, setDatosModificado);
    }
    catch(const exception& ex)
    {
        std::cout << "Ocurrio una excepcion al intentar verificar todos los elementos que deben estar en la lista existan: " <<  ex.what() << std::endl;
        testExitoso = false;
    }

    std::cout << "Elemento en el Medio: " << setDatosModificado[setDatosModificado.size()/2] << std::endl;
    return testExitoso;
}

bool LinkedListTest::test_EliminarElemento()
{
    bool testExitoso = true;

    return testExitoso;
}

bool LinkedListTest::test_EliminarEnIndex()
{
    bool testExitoso = true;

    return testExitoso;
}

bool LinkedListTest::test_elementoEnIndex()
{
    bool testExitoso = true;

    return testExitoso;
}

bool LinkedListTest::test_EstaVacia()
{
    bool testExitoso = true;

    return testExitoso;
}

bool LinkedListTest::test_Vaciar()
{
    bool testExitoso = true;

    return testExitoso;
}

bool LinkedListTest::test_Longitud()
{
    bool testExitoso = true;

    return testExitoso;
}


// PRIVATE
int LinkedListTest::listaPushBackVector(LinkedList<int>& list, const vector<int>& vector)
{
    unsigned int i = 0;
    try
    {
        for(; i < vector.size(); i++)
            list.push_back(vector[i]);
    }
    catch(const exception& ex)
    {
        std::cout << "Ocurrio una excepcion al intentar insertar los elementos al linked lsit: " << ex.what() << std::endl;
    }
    return i;
}

int LinkedListTest::listaPushFrontVector(LinkedList<int>& list, const vector<int>& vector)
{
    unsigned int i = 0;
    try
    {
        for(; i < vector.size(); i++)
            list.push_front(vector[i]);
    }
    catch(const exception& ex)
    {
        std::cout << "Ocurrio una excepcion al intentar insertar los elementos al linked lsit: " << ex.what() << std::endl;
    }
    return i;
}

bool LinkedListTest::contienenLosMismosElementos(LinkedList<int>& list, const vector<int>& vector)
{
    bool contienenLosMismosElementos = true;
    try
    {
        for(unsigned int i = 0; i < vector.size(); i++)
            contienenLosMismosElementos = ( vector[i] != list.elementoEnIndex(i) ? false : contienenLosMismosElementos );
    }
    catch(const exception& ex)
    {
        std::cout << "Ocurrio una excepcion al intentar comparar los elementos de las estructuras de datos: " << ex.what() << std::endl;
        return false;
    }
    return contienenLosMismosElementos;
}


