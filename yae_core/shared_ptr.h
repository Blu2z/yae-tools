/******************************************************************************
DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE 
                    Version 2, December 2004 

 Copyright (C) 2004 Sam Hocevar <sam@hocevar.net> 

 Everyone is permitted to copy and distribute verbatim or modified 
 copies of this license document, and changing it is allowed as long 
 as the name is changed. 

            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE 
   TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION 

  0. You just DO WHAT THE FUCK YOU WANT TO. 

******************************************************************************/

#ifndef __YAE_SHARED_PTR__
#define __YAE_SHARED_PTR__

namespace yae
{
	template <class T>
	class shared_ptr
	{
	public:
		typedef void (*delete_func)(T *ptr);

		inline shared_ptr();
		inline shared_ptr( const shared_ptr<T> &p );
		template <class A> explicit inline shared_ptr( A *ptr, delete_func deleter = 0 );
		virtual ~shared_ptr();

		inline shared_ptr<T>& operator = ( const shared_ptr<T> &p );

		inline T* operator*() const;
		inline T* operator->() const;
		inline T* ptr() const;

		inline bool is_null() const;
		inline unsigned ref_count() const;

		inline void release();

	private:

		T				*ptr_;
		unsigned		*ref_count_;

		delete_func		m_deleter;
	};

	template <class T> inline shared_ptr<T>::shared_ptr() : ptr_(0), ref_count_(0), m_deleter(0) {}
	template <class T> inline shared_ptr<T>::shared_ptr( const shared_ptr<T> &p ) : ptr_(0), ref_count_(0), m_deleter(0) { operator=(p); }
	template <class T> template <class A> inline shared_ptr<T>::shared_ptr( A *ptr, delete_func deleter) : ptr_(ptr), ref_count_( ptr ? new unsigned : 0 ), m_deleter(deleter) { if(ref_count_ != 0) *ref_count_ = 0; }
	template <class T> shared_ptr<T>::~shared_ptr() { release(); }
	template <class T> inline T* shared_ptr<T>::operator*() const { assert(ptr_); return ptr_; }
	template <class T> inline T* shared_ptr<T>::operator->() const { assert(ptr_); return ptr_; }
	template <class T> inline T* shared_ptr<T>::ptr() const { return ptr_; }
	template <class T> inline bool shared_ptr<T>::is_null() const { return ptr_ == 0; }

	template <class T> inline shared_ptr<T>& shared_ptr<T>::operator = ( const shared_ptr<T> &p )
	{
		if( ptr_ == p.ptr_ )
			return *this;

		release();

		ptr_ = p.ptr_;
		ref_count_ = p.ref_count_;
		m_deleter = p.m_deleter;
		if( ref_count_ ) (*ref_count_)++;

		return *this;
	}

	template <class T>
	inline void shared_ptr<T>::release()
	{
		if( ref_count_ != 0 )
		{
			if( (*ref_count_)-- == 0 ) {
				delete ref_count_;
				if( m_deleter != 0 )
					m_deleter(ptr_);
				else
					delete ptr_;
			}

			ref_count_ = 0;
			ptr_ = 0;
		}
	}

	template <class T>
	inline unsigned shared_ptr<T>::ref_count() const
	{
		if( ref_count_ )
			return *ref_count_;

		return 0;
	}
}

#endif // __YAE_SHARED_PTR__