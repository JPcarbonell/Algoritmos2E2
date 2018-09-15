#ifndef TABLAABIERTO_H
#define TABLAABIERTO_H

#include "Iterable.h"
#include "Puntero.h"
#include "Tupla.h"
#include "Tabla.h"
#include "FuncionHash.h"
#include "Array.h"

template <class U,class T>
class NodoHash {
	typedef Puntero<NodoHash<U,T>> pNodoHash;
public:
	U dato1;
	T dato2;
	nat cant;
	pNodoHash sig;

	NodoHash(const U &e1,const T &e2, pNodoHash s, nat c) : dato1(e1), dato2(e2), sig(s), cant(c) {};

	NodoHash<U,T> &operator=(const NodoHash<U,T> &n) {
		if (this != &n) { dato1 = n.dato1; dato2 = n.dato2; sig = n.sig; cant = n.cant; };
		return *this;
	};

	virtual ~NodoHash() {};
};

template <class C, class V>
class HashAbierto : public Tabla<C,V>
{
public:
	typedef unsigned int nat;
	typedef Puntero<NodoHash<C, Array<V>>> pAHash;
	typedef Array<Puntero<NodoHash<C, Array<V>>>> aHash;
	typedef Puntero<FuncionHash<C>> pFuncionHash;

	HashAbierto(nat cantidadElementos, pFuncionHash fHash, const Comparador<C>& comp);

	//PRE: T(c) no está definida y la tabla no está llena
	//POS: Define T(c) = v
	void Agregar(const C& c, const V& v);

	//PRE: T(c) está definida
	//POS: Borra la asociación ligada a 'c'
	void Borrar(const C& c);

	//PRE: - 
	//POS: Borra todas las asociaciones
	void BorrarTodos();

	/* PREDICADOS */

	//PRE: - 
	//POS: Retorna true si está vacía, false sino.
	bool EstaVacia() const;

	//PRE: - 
	//POS: Retorna true si está llena, false sino.
	bool EstaLlena() const;

	//PRE: - 
	//POS: Retorna true si T(c) está definida, es decir, si la clave c está definida. False sino.
	bool EstaDefinida(const C& c) const;

	/* SELECTORAS */

	//PRE: T(c) está definida
	//POS: Retorna 'v', tal que T(c) = v
	const V& Obtener(const C& c) const;

	//PRE: -
	//POS: Retorna el largo de la tabla
	nat Largo() const;

	//PRE: -
	//POS: Devuelve un clon de la tabla, no comparten memoria
	Puntero<Tabla<C, V>> Clonar() const;

	// Retorna un nuevo iterador sobre la estructura
	// Postcondición: El iterador se encuentra reiniciado
	Iterador<Tabla<C, V>> ObtenerIterador() const;

private:
	//Funciones auxiliares
	nat PrimerPrimo(nat n);
	bool EsPrimo(nat n);
	bool EstaDefinidaAux(const C& c, const pAHash& h) const;
	void BorrarAux(const C& c, pAHash& h);
	const V& ObtenerAux(const C& c, const pAHash& h) const;

	//Atributos
	nat cubetas;
	nat cantElementos;
	float factorDeCarga;
	aHash hash;
	pFuncionHash funcionHash;
	Comparador<C>& comp;
};


#include "HashAbierto.cpp"

#endif