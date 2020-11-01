#ifndef ORDEREDSET_H
#define ORDEREDSET_H
#include <QList>
#include <QSet>
namespace QtCommon2 {
template <class T>
class OrderedSet
{
protected:
    QList<T> insertionOrder;
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

    QList<T> toList() const {
        return insertionOrder;
    }

    bool isEmpty() const {
        return items.isEmpty();
    }

    int size() const {
        return insertionOrder.size();
    }

    inline typename QList<T>::iterator begin() {
        return insertionOrder.begin();
    }
    inline typename QList<T>::const_iterator begin() const {
        return insertionOrder.constBegin();
    }
    inline typename QList<T>::iterator end() {
        return insertionOrder.end();
    }

    inline typename QList<T>::const_iterator end() const {
         return insertionOrder.constEnd();
    }


};
}
#endif // ORDEREDSET_H
