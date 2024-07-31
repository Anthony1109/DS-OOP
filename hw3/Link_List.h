#include <iostream>
#include <list>

template <class T>
class Link_List
{
public:
    // default constructor
    Link_List();
    // copy constructor
    Link_List(Link_List &);

    // get size of list
    std::size_t getSize() const;

    // inserts `value` at the beginning of list. always returns true.
    bool insert_node(T value);
    // inserts `value` before `index`. always returns true.
    bool insert_node(std::size_t index, T value);

    // removes element at the beginning of list. returns true if delete
    // successfully, otherwise returns false.
    bool delete_node();
    // removes element at `index`. returns true if delete successfully,
    // otherwise returns false.
    bool delete_node(std::size_t index);

    // checks whther the contents of two lists are equal.
    // that is, they have the same number of elements and each element
    // at the same position is equal
    bool operator==(const Link_List &) const;
    // get element at position
    const T &operator[](std::size_t) const;

    // Reads a list from an input stream. The first element represents the size of the list `N`,
    // followed by `N` elements.
    // Example input: 3 1 2 3
    // This represents a list of elements {1, 2, 3}
    template <class U>
    friend std::istream &operator>>(std::istream &, Link_List<U> &);

    // Outputs the list to an output stream. Each element in the list is output
    // separated by a single space character.
    // Example:
    // If the list contains {1, 2, 3}
    // cout << list; will print "1 2 3" to the console.
    template <class U>
    friend std::ostream &operator<<(std::ostream &, const Link_List<U> &);

// declare your own functions/variables
private:
    std::list<T> list_;
};

// implement Link_List's methods

template <class T>
Link_List<T>::Link_List(){}

template <class T>
Link_List<T>::Link_List(Link_List &other): list_(other.list_){}

template <class T>
bool Link_List<T>::insert_node(T value)
{
    list_.push_front(value);
    return true;
}

template <class T>
bool Link_List<T>::insert_node(std::size_t index, T value)
{
    if (index >= list_.size())
    {
        return false;
    }
    auto it = list_.begin();
    advance(it, index);
    list_.insert(it, value);
    return true;
}

template <class T>
bool Link_List<T>::delete_node()
{
    if (list_.empty())
    {
        return false;
    }
    list_.pop_front();
    return true;
}

template <class T>
bool Link_List<T>::delete_node(std::size_t index)
{
    if (index >= list_.size())
    {
        return false;
    }
    auto it = list_.begin();
    advance(it, index);
    list_.erase(it);
    return true;
}

template <class T>
size_t Link_List<T>::getSize() const
{
    return list_.size();
}

template <class T>
bool Link_List<T>::operator==(const Link_List &other) const
{
    return list_ == other.list_;
}

template <class T>
const T &Link_List<T>::operator[](std::size_t index) const
{
    auto it = list_.begin();
    advance(it, index);
    return *it;
}

template <class U>
std::istream &operator>>(std::istream &in, Link_List<U> &list)
{
    size_t size;
    in >> size;
    for (size_t i = 0; i < size; i++)
    {
        U value;
        in >> value;
        list.list_.push_back(value);
    }
    return in;
}

template <class U>
std::ostream &operator<<(std::ostream &out, const Link_List<U> &list)
{
    for (auto it = list.list_.begin(); it != list.list_.end(); it++)
    {
        out << *it << " ";
    }
    return out;
}