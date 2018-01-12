#ifndef CAST_H
#define CAST_H

#include <memory>
using namespace std;

namespace QtCommon2 {

template<class D,class B>unique_ptr<D>static_cast_unique_ptr(unique_ptr<B>&ptr){
    return unique_ptr<D>(static_cast<D*>(ptr.release()));
}

template<class D,class B>unique_ptr<D>cast(unique_ptr<B>&ptr){
    B* b = ptr.get();
    D* d = dynamic_cast<D*>(b);
    if (d == nullptr) {
        ptr.reset();
        return nullptr;
    } else {
        ptr.release();
        return unique_ptr<D>(d);
    }

}

}
#endif // CAST_H
