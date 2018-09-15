#ifndef TABLAABIERTO_CPP
#define TABLAABIERTO_CPP

#include "HashAbierto.h"


template <class C, class V>
HashAbierto<C, V>::HashAbierto(nat cantidadElementos, pFuncionHash fHash, const Comparador<C>& comp) {
	cantElementos = 0;
	factorDeCarga = 0,7;
	cubetas = primerPrimo(cantidadElementos) / factorDeCarga;
	hash = aHash(cubetas);
	funcionHash = fHash;
	this->comp = comp;
}

template <class C, class V>
void HashAbierto<C, V>::Agregar(const C& c, const V& v) {
	if (EstaLlena()) {
		Agrandar();
	}
	
	nat pos = funcionHash(c);
	
}

template <class C, class V>
void HashAbierto<C, V>::Borrar(const C& c) {
	nat pos = funcionHash(c);
	BorrarAux(c, hash[pos]);
}

template <class C, class V>
void HashAbierto<C, V>::BorrarAux(const C& c, pAHash& h) {
	if (comp.SonIguales(h->dato1, c)) {
		h = h->sig;
	}
	return BorrarAux(c, hash[pos]->sig);
}

template <class C, class V>
void HashAbierto<C, V>::BorrarTodos() {

}

template <class C, class V>
bool HashAbierto<C, V>::EstaVacia() const {
	return cantElementos == 0 ;
}

template <class C, class V>
bool HashAbierto<C, V>::EstaLlena() const {
	return (factorDeCarga < cantElementos / cubetas);
}

template <class C, class V>
bool HashAbierto<C, V>::EstaDefinida(const C& c) const {
	nat pos = funcionHash(c);
	return EstaDefinidaAux(c, hash[pos]);
}

template <class C, class V>
bool HashAbierto<C, V>::EstaDefinidaAux(const C& c, const pAHash& h) const {
	if (h) {
		if (comp.SonIguales(h->dato1, c)) {
			return true;
		}
		return EstaDefinidaAux(c, hash[pos]->sig);
	}
	else {
		return false;
	}
}

template <class C, class V>
const V& HashAbierto<C, V>::Obtener(const C& c) const {
	nat pos = funcionHash(c);
	return EstaDefinidaAux(c, hash[pos]);
}

template <class C, class V>
const V& HashAbierto<C, V>::ObtenerAux(const C& c, const pAHash& h) const {
	if (comp.SonIguales(h->dato1, c)) {
		Array<V> ret = h->dato2;
		return ret;
	}
	return ObtenerAux(c, hash[pos]->sig);
}

template <class C, class V>
nat HashAbierto<C, V>::Largo() const {
	return cantElementos;
}

template <class C, class V>
Puntero<Tabla<C, V>> HashAbierto<C, V>::Clonar() const {
	return NULL;
}

template <class C, class V>
Iterador<Tabla<C, V>> HashAbierto<C, V>::ObtenerIterador() const {
	return NULL;
}

template <class C, class V>
nat HashAbierto<C, V>::PrimerPrimo(nat n) {
	if (esPrimo(n)) {
		return n;
	}
	return (primerPrimo(n + 1));
}

template <class C, class V>
bool HashAbierto<C, V>::EsPrimo(nat n) {
	nat contador = n-1;
	nat cantDivs = 0;
	while (contador > 1) {
		if ((n % contador) == 0) {
			return false;
		}
		contador--;
	}
	return true;
}

#endif