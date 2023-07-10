/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/07 15:55:08 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>
# include <typeinfo>

template <class T>
class Array
{
private:
	T*				arr_;
	unsigned int	size_;
	class OutBoundsException : public std::exception
	{
	public:
		virtual const char*	what() const throw() {
			return ("The index is out of bounds");
		};
	};
public:
	Array(unsigned int n = 0) : arr_(NULL), size_(n) {
		this->arr_ = new T[n];
		std::clog << "\033[36;2;3m[" << this \
			<< "]<Array> Constructor called ( <" \
			<< this->getType() << ">[" \
			<< this->size_ << "] )\033[m" << std::endl;
	};
	Array(const Array& src) {
		*this = src;
		std::clog << "\033[36;2;3m[" << this \
			<< "]<Array> Copy constructor called ( <" \
			<< this->getType() << ">[" \
			<< this->size_ << "] )\033[m" << std::endl;
	};
	Array&	operator=(const Array& rhs) {
		if (this != &rhs) {
			delete[] this->arr_;
			this->arr_ = new T[rhs.size_];
			for (unsigned int i = 0; i < rhs.size_; i++)
				this->arr_[i] = rhs.arr_[i];
			size_ = rhs.size_;
		}
		std::clog << "\033[35;2;3m[" << this << "<-" << &rhs \
			<< "]<Array> Copy assignment operator called ( <" \
			<< this->getType() << ">[" \
			<< this->size_ << "] )\033[m" << std::endl;
		return (*this);
	};
	~Array(void) {
		std::clog << "\033[31;2;3m[" << this \
			<< "]<Array> Destructor called ( <" \
			<< this->getType() << ">[" \
			<< this->size_ << "] )\033[m" << std::endl;
		delete[] this->arr_;
		this->arr_ = NULL;
	};
	unsigned int	size(void) const {
		return (this->size_);
	};
	const std::string	getType(void) const {
		return (typeid(this->arr_).name());
	};
	T&	operator[](unsigned int index) {
		if (index >= this->size_) {
			throw Array::OutBoundsException();
		}
		return (this->arr_[index]);
	}
	Array&	operator=(const T* rhs) {
		delete[] this->arr_;
		for (unsigned int i = 0; i < this->size_; i++)
			this->arr_[i] = rhs[i];
		std::clog << "\033[35;2;3m[" << this \
			<< "]<Array> Array assignment operator called ( <" \
			<< this->getType() << ">[" << this->size_ \
			<< "] <-[" << &rhs << "])\033[m" << std::endl;
		return (*this);
	};
};

template <typename T>
std::ostream&	operator<<(std::ostream& stream, const Array<T>& tc) {
	stream << "[" << &tc << "]<Array> has < " \
		<< tc.getType() << "[" << tc.size() << "] >\033[m";
	return (stream);
};

#endif
