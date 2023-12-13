// En realidad este archivo NO es parte del proyecto,
// se agregó como ejemplo para las pruebas unitarias

#ifndef ITREE_HH
#define ITREE_HH

#include <cstddef>

template <typename TK, typename TV>
class ITree {
    virtual void Insert(TK clave, TV valor) = 0;
    virtual bool Contains(TK clave) = 0;
    virtual TV Get(TK clave) = 0;
    //virtual void PrintPreorder() = 0;
    //virtual void PrintInorder() = 0;
    //virtual void PostOrder() = 0;
    virtual size_t count() = 0;
    //virtual bool Remove(TK clave) = 0;
};
#endif