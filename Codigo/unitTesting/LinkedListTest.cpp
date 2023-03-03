#include <iostream>
#include <exception>
#include "LinkedListTest.h"

const vector<int> LinkedListTest::setDeDatos = { -20, 10, -1586, -2,147,483,648, 12, 10, -20, 789, 2,147,483,647, 0, 81, 39, -69 };


bool LinkedListTest::test_push_back()
{
    bool testExitoso = true;
    LinkedList<int> testList = LinkedList<int>();
    unsigned int elementosInsertados = listaPushBackVector(testList, LinkedListTest::setDeDatos);
    std::cout << "Elementos insertados... " << elementosInsertados << "/" << LinkedListTest::setDeDatos.size() << std::endl;
    testExitoso = contienenLosMismosElementos(testList, LinkedListTest::setDeDatos);
    std::cout << "El linked list contiene los elementos insertados? " << (testExitoso ? "SI" : "NO") << std::endl;
    testExitoso = elementosInsertados != LinkedListTest::setDeDatos.size() ? false : testExitoso;
    std::cout << "test_push_back... " << ( testExitoso ? "EXITOSO" : "FALLIDO" ) << std::endl;
    std::cout << "---------------------------  ---------------------------\n\n";
    return testExitoso;
}

bool LinkedListTest::test_push_front()
{
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
    std::cout << "test_push_front... " << ( testExitoso ? "EXITOSO" : "FALLIDO" ) << std::endl;
        std::cout << "---------------------------  ---------------------------\n\n";

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
    std::cout << "test_pop_back... " << ( testExitoso ? "EXITOSO" : "FALLIDO" ) << std::endl;
    std::cout << "---------------------------  ---------------------------\n\n";

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
    testExitoso = ( !LinkedListTest::contienenLosMismosElementos(testList, mitadSetDeDatos) ? false : testExitoso ) ;
    std::cout << "test_pop_front... " << ( testExitoso ? "EXITOSO" : "FALLIDO" ) << std::endl;
    std::cout << "---------------------------  ---------------------------\n\n";
    return testExitoso;
}

bool LinkedListTest::test_InsertarElemento()
{
    bool testExitoso = true;
    LinkedList<int> testList = LinkedList<int>();
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
    bool seEncuentraValorAlInicio = 0, seEncuentraValorAlMedio = 0, seEncontraronTodosLosElementos = 0;
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
    testExitoso = !seEncuentraValorAlInicio || !seEncuentraValorAlMedio || !seEncontraronTodosLosElementos ? false : testExitoso;
    std::cout << "test_InsertarElemento... " << ( testExitoso ? "EXITOSO" : "FALLIDO" ) << std::endl;
    if(!testExitoso)
    {
        std::cout << "Se encontro el valor insertado al inicio del LinkedList... " << ( seEncuentraValorAlInicio ? "SI" : "NO" ) << std::endl;
        std::cout << "Se encontro el valor insertado al medio del LinkedList... " << ( seEncuentraValorAlMedio ? "SI" : "NO" ) << std::endl;
        std::cout << "Todos los elementos insertados estan en orden... " << ( seEncontraronTodosLosElementos ? "SI" : "NO" ) << std::endl;
    }
    return testExitoso;
}

bool LinkedListTest::test_EliminarElemento()
{
    bool testExitoso = true;
    LinkedList<int> testList = LinkedList<int>();
    LinkedListTest::listaPushBackVector(testList, LinkedListTest::setDeDatos);
    int primerValorEliminado = testList.elementoEnIndex(0),
        segundoValorEliminado;
    try
    {
        testList.eliminarElemento(primerValorEliminado);
        segundoValorEliminado = testList.elementoEnIndex(testList.Longitud()/2);
        testList.eliminarElemento(segundoValorEliminado);
    }
    catch(const exception& ex)
    {
        std::cout << "Ocurrio una excepcion al intentar eliminar los elementos del linked test: " <<  ex.what() << std::endl;
        testExitoso = false;
    }
    std::vector<int> setDatosModificado = std::vector<int>(LinkedListTest::setDeDatos.size());
    try
    {
        std::copy(LinkedListTest::setDeDatos.begin(), LinkedListTest::setDeDatos.end(), setDatosModificado.begin());
        setDatosModificado.erase(setDatosModificado.begin());
        std::vector<int>::const_iterator itAlMedio = setDatosModificado.begin() + setDatosModificado.size()/2;
        setDatosModificado.erase(itAlMedio);
    }
    catch(const exception& ex)
    {
        std::cout << "Ocurrio una excepcion al intentar crear y modificar el nuevo set de datos: " << ex.what() << std::endl;
        testExitoso = false;
    }
    bool seEliminoValorAlInicio = 0, seEliminoValorAlMedio = 0, seEncontraronTodosLosElementos = 0;
    try
    {
        seEliminoValorAlInicio = testList.elementoEnIndex(0) != primerValorEliminado;
        seEliminoValorAlMedio = testList.elementoEnIndex(testList.Longitud()/2) != segundoValorEliminado;
    }
    catch(const exception& ex)
    {
        std::cout << "Ocurrio una excepcion al intentar verificar que los elementos fueran eliminados: " <<  ex.what() << std::endl;
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
    testExitoso = ( !seEliminoValorAlInicio || !seEliminoValorAlMedio || !seEncontraronTodosLosElementos ? false : testExitoso );
    std::cout << "test_EliminarElemento... " << ( testExitoso ? "EXITOSO" : "FALLIDO" ) << std::endl;
    if(!testExitoso)
    {
        std::cout << "Se elimino el valor insertado al inicio del LinkedList... " << ( seEliminoValorAlInicio ? "SI" : "NO" ) << std::endl;
        std::cout << "Se elimino el valor insertado al medio del LinkedList... " << ( seEliminoValorAlMedio ? "SI" : "NO" ) << std::endl;
        std::cout << "Todos los elementos estan en orden... " << ( seEncontraronTodosLosElementos ? "SI" : "NO" ) << std::endl;
    }
    return testExitoso;
}

bool LinkedListTest::test_EliminarEnIndex()
{
    bool testExitoso = true;
    LinkedList<int> testList = LinkedList<int>();
    LinkedListTest::listaPushBackVector(testList, LinkedListTest::setDeDatos);
    int primerValorEliminado = LinkedListTest::setDeDatos[0],
        segundoValorEliminado = LinkedListTest::setDeDatos[LinkedListTest::setDeDatos.size()/2 +1];
    try
    {
        testList.eliminarElemento(primerValorEliminado);
        testList.eliminarElemento(segundoValorEliminado);
    }
    catch(const exception& ex)
    {
        std::cout << "Ocurrio una excepcion al intentar eliminar los elementos del linked test: " <<  ex.what() << std::endl;
        testExitoso = false;
    }
    std::vector<int> setDatosModificado = std::vector<int>(LinkedListTest::setDeDatos.size());
    try
    {
        std::copy(LinkedListTest::setDeDatos.begin(), LinkedListTest::setDeDatos.end(), setDatosModificado.begin());
        setDatosModificado.erase(setDatosModificado.begin());
        std::vector<int>::const_iterator itAlMedio = setDatosModificado.begin() + setDatosModificado.size()/2;
        setDatosModificado.erase(itAlMedio);
    }
    catch(const exception& ex)
    {
        std::cout << "Ocurrio una excepcion al intentar crear y modificar el nuevo set de datos: " << ex.what() << std::endl;
        testExitoso = false;
    }
    bool seEliminoValorAlInicio = 0, seEliminoValorAlMedio = 0, seEncontraronTodosLosElementos = 0;
    try
    {
        seEliminoValorAlInicio = testList.elementoEnIndex(0) != primerValorEliminado;
        seEliminoValorAlMedio = testList.elementoEnIndex(testList.Longitud()/2) != segundoValorEliminado;
    }
    catch(const exception& ex)
    {
        std::cout << "Ocurrio una excepcion al intentar verificar que los elementos fueran eliminados: " <<  ex.what() << std::endl;
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
    testExitoso = ( !seEliminoValorAlInicio || !seEliminoValorAlMedio || !seEncontraronTodosLosElementos ? false : testExitoso );
    std::cout << "test_EliminarElemento... " << ( testExitoso ? "EXITOSO" : "FALLIDO" ) << std::endl;
    if(!testExitoso)
    {
        std::cout << "Se elimino el valor insertado al inicio del LinkedList... " << ( seEliminoValorAlInicio ? "SI" : "NO" ) << std::endl;
        std::cout << "Se elimino el valor insertado al medio del LinkedList... " << ( seEliminoValorAlMedio ? "SI" : "NO" ) << std::endl;
        std::cout << "Todos los elementos estan en orden... " << ( seEncontraronTodosLosElementos ? "SI" : "NO" ) << std::endl;
    }
    return testExitoso;
}

bool LinkedListTest::test_elementoEnIndex()
{
    LinkedList<int> testList = LinkedList<int>();
    LinkedListTest::listaPushBackVector(testList, LinkedListTest::setDeDatos);
    bool testExitoso = LinkedListTest::contienenLosMismosElementos(testList, LinkedListTest::setDeDatos);
    std::cout << "test_elementoEnIndex... " << ( testExitoso ? "EXITOSO" : "FALLIDO" ) << std::endl;
    return testExitoso;
}

bool LinkedListTest::test_EstaVacia()
{
    bool testExitoso;
    LinkedList<int> testList = LinkedList<int>();
    try
    {
        testList.push_back(2);
        testList.push_back(4);
    }
    catch(const exception& ex)
    {
        std::cout << "Ocurrio una excepcion al intentar insertar los elementos al linked list: " << ex.what() << std::endl;
    }
    try
    {
        testExitoso = !testList.estaVacia();
    }
    catch(const exception& ex)
    {
        std::cout << "Ocurrio una excepcion al intentar ejecutar testList.estaVacia() : " << ex.what() << std::endl;
        testExitoso = false;
    }
    try
    {
        testList.eliminarEnIndex(0);
    }
    catch(const exception& ex)
    {
        std::cout << "Ocurrio una excepcion al intentar eliminar el primer elemento : " << ex.what() << std::endl;
    }
    try
    {
        testExitoso = testList.estaVacia() ? false : testExitoso;
        testList.eliminarEnIndex(0);
        testExitoso = !testList.estaVacia() ? false : testExitoso;
    }
    catch(const exception& ex)
    {
        std::cout << "Ocurrio una excepcion al intentar eliminar el primer elemento y verificar que testList este vacia: " << ex.what() << std::endl;
    }
    std::cout << "test_EstaVacia... " << ( testExitoso ? "EXITOSO" : "FALLIDO" ) << std::endl;
    return testExitoso;
}

bool LinkedListTest::test_Vaciar()
{
    bool testExitoso = true;
    LinkedList<int> testList = LinkedList<int>();
    LinkedListTest::listaPushBackVector(testList, LinkedListTest::setDeDatos);
    try
    {
        testList.vaciar();
    }
    catch(const exception& ex)
    {
        std::cout << "Ocurrio una excepcion al intentar vaciar la linked list: " <<  ex.what() << std::endl;
        testExitoso = false;
    }
    testExitoso = testList.Longitud() != 0 ? false : testExitoso;
    std::cout << "test_Vaciar... " << ( testExitoso ? "EXITOSO" : "FALLIDO ") << std::endl;
    if(!testExitoso)
        cout << "La del longitud del linked list es " << testList.Longitud() << " cuando deberia de ser 0" << std::endl;
    return testExitoso;
}

bool LinkedListTest::test_Longitud()
{
    bool testExitoso = true;
    LinkedList<int> testList = LinkedList<int>();
    LinkedListTest::listaPushBackVector(testList, LinkedListTest::setDeDatos);
    try
    {
        testExitoso = ( testList.Longitud() == LinkedListTest::setDeDatos.size() );
    }
    catch(const exception& ex)
    {
        std::cout << "Ocurrio una excepcion al intentar obtener la longitud del linked list: " <<  ex.what() << std::endl;
        testExitoso = false;
    }
    try
    {
        testList.eliminarEnIndex(0);
        testExitoso = ( testList.Longitud() != LinkedListTest::setDeDatos.size() -1 ? false : testExitoso );
        testList.eliminarEnIndex(testList.Longitud()/2);
        testExitoso = ( testList.Longitud() != LinkedListTest::setDeDatos.size() -2 ? false : testExitoso );
    }
    catch(const exception& ex)
    {
        std::cout << "Ocurrio una excepcion al intentar eliminar elementos y obtener la longitud del linked list: " <<  ex.what() << std::endl;
        testExitoso = false;
    }
    try
    {
        testList.vaciar();
        testExitoso = ( testList.Longitud() != 0 ? false : testExitoso );
    }
    catch(const exception& ex)
    {
        std::cout << "Ocurrio una excepcion al intentar vaciar y obtener la longitud del linked list: " <<  ex.what() << std::endl;
        testExitoso = false;
    }
    std::cout << "test_Longitud... " << ( testExitoso ? "EXITOSO" : "FALLIDO ") << std::endl;
    return testExitoso;
}

void LinkedListTest::test_TodosLosMetodos()
{
    test_push_back();
    test_push_front();
    test_pop_back();
    test_pop_front();
    test_InsertarElemento();
    test_EliminarElemento();
    test_EliminarEnIndex();
    test_elementoEnIndex();
    test_EstaVacia();
    test_Vaciar();
    test_Longitud();
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
        std::cout << "Ocurrio una excepcion al intentar insertar los elementos al linked list: " << ex.what() << std::endl;
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
void LinkedListTest::vectorPushBackList(const vector<int>& vector, LinkedList<int>& list)
{

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



