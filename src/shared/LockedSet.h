/*
 * Copyright (C) 2009 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
 
#ifndef LOCKEDSET_H
#define LOCKEDSET_H
 
#include <ace/Guard_T.h>
#include <ace/Thread_Mutex.h>
#include <set>
#include <assert.h>
#include "Errors.h"
 
namespace ACE_Based
{
 	template <class T, class LockType> class LockedSet : protected std::set<T>
	{
		mutable LockType _lock;
	public:
		typedef typename std::set<T>::iterator iterator;
		typedef typename std::set<T>::const_iterator const_iterator;
		typedef typename std::set<T>::reverse_iterator reverse_iterator;
		typedef typename std::set<T>::size_type size_type;
		typedef typename std::set<T>::reference reference;
 
		LockedSet() : std::set<T>() {}
		LockedSet(const LockedSet&);
		LockedSet & operator=(const LockedSet&);
 
		virtual ~LockedSet() { }
 
		virtual iterator begin()
		{
			ACE_Guard<LockType> g(this->_lock);
			return std::set<T>::begin();
		}
 
		virtual iterator end()
		{
			ACE_Guard<LockType> g(this->_lock);
			return std::set<T>::end();
		}
 
		virtual void clear()
		{
			ACE_Guard<LockType> g(this->_lock);
			std::set<T>::clear();
		}
 
		virtual size_t count(const T & _Keyval)
		{
			ACE_Guard<LockType> g(this->_lock);
			return std::set<T>::count(_Keyval);
		}
 
		virtual bool empty()
		{
			ACE_Guard<LockType> g(this->_lock);
			return std::set<T>::empty();
		}
 
		virtual void erase(T & t)
		{
			ACE_Guard<LockType> g(this->_lock);
			std::set<T>::erase(t);
		}
 
		virtual void erase(const T & t)
		{
			ACE_Guard<LockType> g(this->_lock);
			std::set<T>::erase(t);
		}
 
		virtual iterator find(T & t)
		{
			ACE_Guard<LockType> g(this->_lock);
			return std::set<T>::find(t);
		}
 
		virtual iterator find(const T & t)
		{
			ACE_Guard<LockType> g(this->_lock);
			return std::set<T>::find(t);
		}
 
		virtual void insert(T & t)
		{
			ACE_Guard<LockType> g(this->_lock);
			std::set<T>::insert(t);
		}
 
		virtual void insert(const T & t)
		{
			ACE_Guard<LockType> g(this->_lock);
			std::set<T>::insert(t);
		}
 
		virtual void insert(const_iterator _first, const_iterator _end)
		{
			ACE_Guard<LockType> g(this->_lock);
			std::set<T>::insert(_first, _end);
		}
	};
}
#endif