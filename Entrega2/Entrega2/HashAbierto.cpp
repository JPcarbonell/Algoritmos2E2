#ifndef TABLAABIERTO_CPP
#define TABLAABIERTO_CPP

#include "Iterable.h"
#include "Puntero.h"
#include "Tupla.h"
#include "HashAbierto.h"
#include "FuncionHash.h"

template <class C, class V>
HashAbierto<C, V>::HashAbierto(nat cantidadElementos, Puntero<FuncionHash<C>> fHash, const Comparador<C>& comp) {

}

template <class C, class V>
void HashAbierto<C, V>::Agregar(const C& c, const V& v) {

}

template <class C, class V>
void HashAbierto<C, V>::Borrar(const C& c) {

}

template <class C, class V>
void HashAbierto<C, V>::BorrarTodos() {

}

template <class C, class V>
bool HashAbierto<C, V>::EstaVacia() const {
	return false;
}

template <class C, class V>
bool HashAbierto<C, V>::EstaLlena() const {
	return false;
}

template <class C, class V>
bool HashAbierto<C, V>::EstaDefinida(const C& c) const {
	return false;
}

template <class C, class V>
const V& HashAbierto<C, V>::Obtener(const C& c) const {
	return NULL;
}

template <class C, class V>
nat HashAbierto<C, V>::Largo() const {
	return -1;
}

template <class C, class V>
Puntero<Tabla<C, V>> HashAbierto<C, V>::Clonar() const {
	return NULL;
}

template <class C, class V>
Iterador<Tabla<C, V>> HashAbierto<C, V>::ObtenerIterador() const {
	return NULL;
}

#endif