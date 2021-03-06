/*
 * weak.hpp
 *
 *  Created on: May 18, 2013
 *      Author: lenx
 */

#ifndef PROTON_WEAK_HPP_
#define PROTON_WEAK_HPP_

#include <proton/base.hpp>
#include <proton/ref.hpp>

namespace proton{

template<typename refT>
class weak_ {
public:
	typedef typename refT::refc_t refc_t;
	typedef typename refT::obj_t obj_t;
	typedef typename refT::alloc_t alloc_t;

private:

	refc_t* _w;
	obj_t* _p;

	refT lock()const
	{
		if(_w && _w->count()){
			// [FIXME] TOCTTOU might happen here in multi-threading
			return refT(alloc_inner, _w, _p);
		}
		else
			return none;
	}

public:

	weak_(const refT& r):_w(r._rp), _p(r._p)
	{
		if(_w)
			_w->weak_enter();
	}

	~weak_()
	{
		if(_w){
			if(!_w->weak_release()){
				if(!_w->count()){
	            	alloc_t::confiscate(_w);
				}
			}
			_w=NULL;
			_p=NULL;
		}
	}

	bool operator<(const weak_& w)const
	{
		return _p < w._p;
	}

	bool operator==(const weak_& w)const
	{
		return _p == w._p;
	}

	//[TODO] unordered_map & unordered_set support
};

template<typename refT>
weak_<refT> weak(const refT& t)
{
	return weak_<refT>(t);
}

template<typename refT>
refT lock(const weak_<refT>& w)
{
	return w.lock();
}

} // ns proton


#endif /* PROTON_WEAK_HPP_ */
