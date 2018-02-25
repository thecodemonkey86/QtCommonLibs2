#ifndef ORDEREDSET_H
#define ORDEREDSET_H
#include <QSet>
namespace QtCommon2 {
template <class T>
class OrderedSet
{
protected:
    QVector<T> insertionOrder;
    QSet<T> items;
public:
    OrderedSet() {

    }

    bool append(const T &value) {
        if (!items.contains(value)) {
            items.insert(value);
            insertionOrder.append(value);
            return true;
        }
        return false;
    }

    inline bool insert(const T &value) {
        return append(value);
    }

    bool contains(const T &value) {
        return items.contains(value);
    }

    QVector<T> toList() const {
        return insertionOrder;
    }

    bool isEmpty() const {
        return items.isEmpty();
    }

    int size() const {
        return insertionOrder.size();
    }

    inline typename QVector<T>::iterator begin() {
        return insertionOrder.begin();
    }
    inline typename QVector<T>::const_iterator begin() const {
        return insertionOrder.constBegin();
    }
    inline typename QVector<T>::iterator end() {
        return insertionOrder.end();
    }

    inline typename QVector<T>::const_iterator end() const {
         return insertionOrder.constEnd();
    }


};
}
#endif // ORDEREDSET_H
