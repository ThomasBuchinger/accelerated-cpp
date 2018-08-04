#ifndef GUARD_vec_h
#define GURAD_vec_h

#include <cstddef>
#include <memory>
#include <algorithm>
#include <iostream>

template <class T> class Vec {

  public:
      // typedefs
      typedef T*       iterator;
      typedef const T* const_iterator;
      typedef size_t   size_type;
      typedef T        value_type;

      // Constructors & desctructor
      Vec()                                         { create(); }
      explicit Vec(size_type n, const T& val = T()) { create(n, val); }
      Vec(const Vec& vec)                           { create(vec.begin(), vec.end()); }  

      ~Vec() { uncreate(); }

      //Operators
      Vec& operator=(const Vec&);

      // Iterator functions
      T& operator[](size_type i)              { return data[i]; }
      const T& operator[](size_type i) const  { return data[i]; }
      iterator begin()                        { return data; }
      const_iterator begin() const            { return data; }
      iterator end()                          { return avail; }
      const_iterator end() const              { return avail; }

      // Member functions
      size_type size() const                  { return avail - data; }
      void clear()                            { uncreate(); }
      void push_back(const T& val)            { append_element(val);}
      void erase(size_type n)                 { remove_element(data+n); }
      void erase(iterator it)                 { remove_element(it); }
    

  private:
      iterator data;
      iterator avail;
      iterator limit;

      std::allocator<T> alloc;

      void create();
      void create(size_type, const T&);
      void create(const_iterator, const_iterator);

      void uncreate();
      
      void grow();
      void shrink();
      void resize(size_type new_size);
      void append_element(const T&);
      void remove_element(iterator);

};

template <class T> 
Vec<T>& Vec<T>::operator=(const Vec<T>& right_side) {
    if ( &right_side != this ) {
       // free the array in the left-hand-side
       uncreate();

       create(right_side.begin(), right_side.end());
    }
    return *this;
}

template <class T> void Vec<T>::create() {
    data = avail = limit = 0;
}
template <class T> void Vec<T>::create(size_type n, const T& val) {
    data = alloc.allocate(n);
    avail = limit = data + n;
    std::uninitialized_fill(data, limit, val);
}
template <class T> void Vec<T>::create(const_iterator b, const_iterator e) {
    data = alloc.allocate(e - b);
    avail = limit = std::uninitialized_copy(b, e, data);
}

template <class T> void Vec<T>::uncreate() {
    if(data) {
        iterator it = avail;
        while(it != data) {
            alloc.destroy(--it);
        }
        alloc.deallocate(data, limit - data);
    }
    data = avail = limit = 0;
}

template <class T> void Vec<T>::grow() {
    if (avail != limit) {
        return;
    }
    size_type new_size = 2 * std::max(limit - data, ptrdiff_t(1));
    resize(new_size);
}
template <class T> void Vec<T>::shrink() {
    if ((limit - data) / 2 < size()) { 
        return;
    } else { 
        resize(size());
    }
}
template <class T> void Vec<T>::resize(Vec<T>::size_type new_size) {
    std::cerr << "Resize Vec to " << new_size << std::endl;

    iterator new_data  = alloc.allocate(new_size);
    iterator new_avail = std::uninitialized_copy(data, avail, new_data);
    uncreate();

    data  = new_data;
    avail = new_avail;
    limit = data + new_size;
}

template <class T> void Vec<T>::append_element(const T& val) {
    grow();
    alloc.construct(avail++, val);
}
template <class T> void Vec<T>::remove_element(Vec<T>::iterator it) {
    iterator element =  it;
    if (data == 0) {
       return;
    }
    if (it == limit){ 
        uncreate();
        return; 
    }
    avail = std::uninitialized_copy(++it, avail, element);    
    shrink();
}



#endif
