#ifndef TABLACERRADO_CPP
#define TABLACERRADO_CPP

#include "Iterable.h"
#include "Puntero.h"
#include "Tupla.h"
#include "HashCerrado.h"
#include "FuncionHash.h"

template <class C, class V>
HashCerrado<C, V>::HashCerrado(nat cantidadElementos, Puntero<FuncionHash<C>> fHash, const Comparador<C>& comp) {

}

template <class C, class V>
void HashCerrado<C, V>::Agregar(const C& c, const V& v) {

}

template <class C, class V>
void HashCerrado<C, V>::Borrar(const C& c) {

}

template <class C, class V>
void HashCerrado<C, V>::BorrarTodos() {

}

template <class C, class V>
bool HashCerrado<C, V>::EstaVacia() const {
	return false;
}

template <class C, class V>
bool HashCerrado<C, V>::EstaLlena() const {
	return false;
}

template <class C, class V>
bool HashCerrado<C, V>::EstaDefinida(const C& c) const {
	return false;
}

template <class C, class V>
const V& HashCerrado<C, V>::Obtener(const C& c) const {
	return NULL;
}

template <class C, class V>
nat HashCerrado<C, V>::Largo() const {
	return -1;
}

template <class C, class V>
Puntero<Tabla<C, V>> HashCerrado<C, V>::Clonar() const {
	return NULL;
}

template <class C, class V>
Iterador<Tabla<C, V>> HashCerrado<C, V>::ObtenerIterador() const {
	return NULL;
}

#endif