#ifndef CAST_H
#define CAST_H

#include <memory>

namespace QtCommon2 {

template<class D,class B>std::unique_ptr<D>static_cast_unique_ptr(std::unique_ptr<B> ptr){
    return std::unique_ptr<D>(static_cast<D*>(ptr.release()));
}

template<class D,class B>std::unique_ptr<D>cast(std::unique_ptr<B> ptr){
    B* b = ptr.get();
    D* d = dynamic_cast<D*>(b);
    if (d == nullptr) {
        ptr.reset();
        return nullptr;
    } else {
        ptr.release();
        return std::unique_ptr<D>(d);
    }

}

}
#endif // CAST_H
