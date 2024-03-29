#ifndef MGO_ALGORITHM_
#define MGO_ALGORITHM_

#include "iterator.hpp"

namespace ft {

// equal

template <class _T1, class _T2 = _T1>
struct __equal_to {
    bool operator()(const _T1& __x, const _T1& __y) const {return __x == __y;}
    bool operator()(const _T1& __x, const _T2& __y) const {return __x == __y;}
    bool operator()(const _T2& __x, const _T1& __y) const {return __x == __y;}
    bool operator()(const _T2& __x, const _T2& __y) const {return __x == __y;}
};

template <class _T1>
struct __equal_to<_T1, _T1> {
    bool operator()(const _T1& __x, const _T1& __y) const {return __x == __y;}
};

template <class _T1>
struct __equal_to<const _T1, _T1> {
    bool operator()(const _T1& __x, const _T1& __y) const {return __x == __y;}
};

template <class _T1>
struct __equal_to<_T1, const _T1> {
    bool operator()(const _T1& __x, const _T1& __y) const {return __x == __y;}
};

template <class _InputIterator1, class _InputIterator2, class _BinaryPredicate>
inline
bool
equal(_InputIterator1 __first1, _InputIterator1 __last1, _InputIterator2 __first2, 
      _BinaryPredicate __pred) {
    for (; __first1 != __last1; ++__first1, ++__first2)
        if (!__pred(*__first1, *__first2))
            return false;
    return true;
}

template <class _InputIterator1, class _InputIterator2>
inline
bool
equal(_InputIterator1 __first1, _InputIterator1 __last1, _InputIterator2 __first2) {
    typedef typename iterator_traits<_InputIterator1>::value_type __v1;
    typedef typename iterator_traits<_InputIterator2>::value_type __v2;
    return ft::equal(__first1, __last1, __first2, __equal_to<__v1, __v2>());
}

// lexicographical_compare

template <class _T1, class _T2 = _T1>
struct __less {
    bool operator()(const _T1& __x, const _T1& __y) const {return __x < __y;}
    bool operator()(const _T1& __x, const _T2& __y) const {return __x < __y;}
    bool operator()(const _T2& __x, const _T1& __y) const {return __x < __y;}
    bool operator()(const _T2& __x, const _T2& __y) const {return __x < __y;}
};

template <class _T1>
struct __less<_T1, _T1> {
    bool operator()(const _T1& __x, const _T1& __y) const {return __x < __y;}
};

template <class _T1>
struct __less<const _T1, _T1> {
    bool operator()(const _T1& __x, const _T1& __y) const {return __x < __y;}
};

template <class _T1>
struct __less<_T1, const _T1> {
    bool operator()(const _T1& __x, const _T1& __y) const {return __x < __y;}
};

template <class _Compare, class _InputIterator1, class _InputIterator2>
bool
__lexicographical_compare(_InputIterator1 __first1, _InputIterator1 __last1,
                          _InputIterator2 __first2, _InputIterator2 __last2, _Compare __comp) {
    for (; __first2 != __last2; ++__first1, ++__first2)
    {
        if (__first1 == __last1 || __comp(*__first1, *__first2))
            return true;
        if (__comp(*__first2, *__first1))
            return false;
    }
    return false;
}

template <class _InputIterator1, class _InputIterator2, class _Compare>
inline
bool
lexicographical_compare(_InputIterator1 __first1, _InputIterator1 __last1,
                        _InputIterator2 __first2, _InputIterator2 __last2, _Compare __comp) {
    typedef typename add_lvalue_reference<_Compare>::type _Comp_ref;
    return ft::__lexicographical_compare<_Comp_ref>(__first1, __last1, __first2, __last2, __comp);
}

template <class _InputIterator1, class _InputIterator2>
inline
bool
lexicographical_compare(_InputIterator1 __first1, _InputIterator1 __last1,
                        _InputIterator2 __first2, _InputIterator2 __last2) {
    return ft::lexicographical_compare(__first1, __last1, __first2, __last2,
                                       __less<typename iterator_traits<_InputIterator1>::value_type,
                                              typename iterator_traits<_InputIterator2>::value_type>());
}

} // namespace ft

#endif /* MGO_ALGORITHM_ */