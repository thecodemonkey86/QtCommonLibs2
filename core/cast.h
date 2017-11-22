#ifndef CAST_H
#define CAST_H

#include <memory>
using namespace std;

namespace QtCommon2 {

	template<class D,class B>unique_ptr<D>cast(unique_ptr<B>&ptr){
		B* b = ptr.release();
		D* d = dynamic_cast<D*>(b);
		if (d == nullptr) {
			return nullptr;
		} else {
			return unique_ptr<D>(d);
		}

	}
}
#endif // CAST_H
