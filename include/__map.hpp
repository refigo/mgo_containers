#ifndef __MGO_MAP_HPP_
#define __MGO_MAP_HPP_

#include "__functional_base.hpp"
#include "pair.hpp"
#include "iterator.hpp"

// #include "__rb_tree.hpp"
#include "rb_tree.hpp"

#include <memory>

#include <algorithm> // TODO: remove

namespace ft
{

template <class _Key, class _Tp, class _Compare = ft::less<_Key>,
          class _Allocator = std::allocator<ft::pair<const _Key, _Tp> > >
class map
{
public:
    typedef _Key                                     	key_type;
    typedef _Tp                                      	mapped_type;
    typedef ft::pair<const key_type, mapped_type>		value_type;
    typedef _Compare                                 	key_compare;

    class value_compare
        : public ft::binary_function<value_type, value_type, bool>
    {
        friend class map;
    protected:
        key_compare comp;

        value_compare(key_compare c) : comp(c) {}
    public:
        bool operator()(const value_type& __x, const value_type& __y) const
            {return comp(__x.first, __y.first);}
    };

private:
    typedef ft::pair<key_type, mapped_type>									__value_type;
    typedef value_compare													__vc;
    typedef _Allocator														__allocator_type;
    typedef ft::rb_tree<key_type, value_type, 
						key_type, __vc, __allocator_type>					__base;
    __base __tree_;

public:
    typedef _Allocator                               	allocator_type;
	typedef typename __base::pointer					pointer;
	typedef typename __base::const_pointer 				const_pointer;
	typedef typename __base::reference					reference;
	typedef typename __base::const_reference			const_reference;
	typedef typename __base::iterator					iterator;
	typedef typename __base::const_iterator				const_iterator;
	typedef typename __base::reverse_iterator			reverse_iterator;
	typedef typename __base::const_reverse_iterator		const_reverse_iterator;
	typedef typename __base::size_type					size_type;
	typedef typename __base::difference_type			difference_type;

public:
// (Constructor)
    // empty (1)
    explicit map(const key_compare& __comp = key_compare(), 
                    const allocator_type& __a = allocator_type())
        : __tree_(__vc(__comp), __a) {}

// Modifiers:
    // insert
        // single element (1)
    // pair<iterator, bool>
    //     insert(const value_type& __v) {return __tree_.insert_unique(__v);}
    
        // with hint (2)
        // range (3)

// Operations:
    // find
    // iterator find(const key_type& __k)             {return __tree_.find(__k);}
    // const_iterator find(const key_type& __k) const {return __tree_.find(__k);}

};

} // namespace ft

#endif /* __MGO_MAP_HPP_ */