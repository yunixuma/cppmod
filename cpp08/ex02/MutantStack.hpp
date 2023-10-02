/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/10/02 19:59:15 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <algorithm>
# include <exception>

template <class T>
class MutantStack : public std::stack
{
private:
	std::stack<T>	stack_;
	unsigned int	size_;
	class OutBoundsException : public std::exception
	{
	public:
		virtual const char*	what() const throw() {
			return ("The index is out of bounds");
		};
	};
public:
	MutantStack(unsigned int n = 0) : arr_(NULL), size_(n) {
		if (n)
			this->arr_ = new T[n];
		std::clog << "\033[36;2;3m[" << this \
			<< "]<MutantStack> Constructor called ( <" \
			<< this->getType() << ">[" \
			<< this->size_ << "] )\033[m" << std::endl;
	};
	MutantStack(const MutantStack& src) {
		this->arr_ = NULL;
		*this = src;
		std::clog << "\033[36;2;3m[" << this \
			<< "]<MutantStack> Copy constructor called ( <" \
			<< this->getType() << ">[" \
			<< this->size_ << "] )\033[m" << std::endl;
	};
	MutantStack&	operator=(const MutantStack& rhs) {
		if (this != &rhs) {
			if (this->stack_)
				delete[] this->stack_;
			this->arr_ = new T[rhs.size_];
			for (unsigned int i = 0; i < rhs.size_; i++)
				this->arr_[i] = rhs.arr_[i];
			this->size_ = rhs.size_;
		}
		std::clog << "\033[35;2;3m[" << this << "<-" << &rhs \
			<< "]<MutantStack> Copy assignment operator called ( <" \
			<< this->getType() << ">[" \
			<< this->size_ << "] )\033[m" << std::endl;
		return (*this);
	};
	~MutantStack(void) {
		std::clog << "\033[31;2;3m[" << this \
			<< "]<MutantStack> Destructor called ( <" \
			<< this->getType() << ">[" \
			<< this->size_ << "] )\033[m" << std::endl;
		if (this->arr_)
			delete[] this->arr_;
		this->arr_ = NULL;
	};
	T&	top() {
		return ();
	};
	bool	empty() const {
		return ();
	};
	unsigned int	size(void) const {
		return (this->size_);
	};
	void	push(T value) {
		return ();
	};
	T&	pop(void) {
		return ();
	};
	const T&	operator*() const {
		return ();
	};
	T&	operator*() {
		return ();
	};
	const T& operator->() const {
		return ();
	};
	T&	operator->() {
		return ();
	};
	const T&	operator[](unsigned int index) const {
		if (index >= this->size_) {
			throw MutantStack::OutBoundsException();
		}
		return (this->arr_[index]);
	};
	T&	operator[](unsigned int index) {
		if (index >= this->size_) {
			throw MutantStack::OutBoundsException();
		}
		return (this->arr_[index]);
	};
	iterator&	operator++() {
		return ();
	};
	iterator	operator++(int) {
		return ();
	};
	iterator&	operator--() {
		return ();
	};
	iterator	operator--(int) {
		return ();
	};
	iterator&	operator+=(size_t n) {
		return ();
	}
	iterator	operator+(size_t n) {
		return ();
	};
	iterator&	operator-=(size_t n) {
		return ();
	};
	iterator	operator-(size_t n) {
		return ();
	};
	bool	operator==(const iterator& it) const {
		return ();
	};
	bool	operator!=(const iterator& it) const {
		return ();
	};
	bool	operator>(const iterator& it) const {
		return ();
	};
	bool	operator<(const iterator& it) const {
		return ();
	}
	bool	operator>=(const iterator& it) const {
		return ();
	};
	bool	operator<=(const iterator& it) const {
		return ();
	};

	const std::string	getType(void) const {
			return (typeid(this->arr_).name());
	};
	MutantStack&	operator=(const T* rhs) {
		for (unsigned int i = 0; i < this->size_; i++)
			this->arr_[i] = rhs[i];
		std::clog << "\033[35;2;3m[" << this \
			<< "]<MutantStack> MutantStack assignment operator called ( <" \
			<< this->getType() << ">[" << this->size_ \
			<< "] <-[" << &rhs << "])\033[m" << std::endl;
		return (*this);
	};
};

template <typename T>
std::ostream&	operator<<(std::ostream& stream, const MutantStack<T>& tc) {
	stream << "[" << &tc << "]<MutantStack> has < " \
		<< tc.getType() << "[" << tc.size() << "] >\033[m";
	return (stream);
};

#endif
