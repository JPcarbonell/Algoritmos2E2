#ifndef TABLACERRADO_H
#define TABLACERRADO_H

#include "Iterable.h"
#include "Puntero.h"
#include "Tupla.h"
#include "Tabla.h"
#include "FuncionHash.h"

typedef unsigned int nat;

template <class C, class V>
class HashCerrado : public Tabla<C, V>
{
public:

	HashCerrado(nat cantidadElementos, Puntero<FuncionHash<C>> fHash, const Comparador<C>& comp);

	//PRE: T(c) no est� definida y la tabla no est� llena
	//POS: Define T(c) = v
	void Agregar(const C& c, const V& v);

	//PRE: T(c) est� definida
	//POS: Borra la asociaci�n ligada a 'c'
	void Borrar(const C& c);

	//PRE: - 
	//POS: Borra todas las asociaciones
	void BorrarTodos();

	/* PREDICADOS */

	//PRE: - 
	//POS: Retorna true si est� vac�a, false sino.
	bool EstaVacia() const;

	//PRE: - 
	//POS: Retorna true si est� llena, false sino.
	bool EstaLlena() const;

	//PRE: - 
	//POS: Retorna true si T(c) est� definida, es decir, si la clave c est� definida. False sino.
	bool EstaDefinida(const C& c) const;

	/* SELECTORAS */

	//PRE: T(c) est� definida
	//POS: Retorna 'v', tal que T(c) = v
	const V& Obtener(const C& c) const;

	//PRE: -
	//POS: Retorna el largo de la tabla
	nat Largo() const;

	//PRE: -
	//POS: Devuelve un clon de la tabla, no comparten memoria
	Puntero<Tabla<C, V>> Clonar() const;

	// Retorna un nuevo iterador sobre la estructura
	// Postcondici�n: El iterador se encuentra reiniciado
	Iterador<Tabla<C, V>> ObtenerIterador() const;
};


#include "HashCerrado.cpp"

#endif