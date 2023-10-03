/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/10/03 11:16:01 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <iterator>
# include <algorithm>
# include <exception>

template <class T>
class MutantStack : public std::stack<T>, \
	std::iterator<std::random_access_iterator_tag, T>	
{
private:
	std::stack<T>	stack_;
	// unsigned int	size_;
	unsigned int	index_;
	class OutBoundsException : public std::exception
	{
	public:
		virtual const char*	what() const throw() {
			return ("The index is out of bounds");
		};
	};
public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	MutantStack(void) : index_(0) {
		// if (n)
			// this->stack_ = new T[n];
		std::clog << "\033[36;2;3m[" << this \
			<< "]<MutantStack> Constructor called ( <" \
			<< this->getType() << ">[" \
			<< this->index_ << "] / " << this->stack_.size() \
			<< " )\033[m" << std::endl;
	};
	MutantStack(const MutantStack& src) {
		this->stack_ = NULL;
		*this = src;
		std::clog << "\033[36;2;3m[" << this \
			<< "]<MutantStack> Copy constructor called ( <" \
			<< this->getType() << ">[" \
			<< this->index_ << "] / " << this->stack_.size() \
			<< " )\033[m" << std::endl;
	};
	MutantStack&	operator=(const MutantStack& rhs) {
		if (this != &rhs) {
			if (this->stack_)
				delete[] this->stack_;
			this->stack_ = new T[rhs.index_];
			for (unsigned int i = 0; i < rhs.index_; i++)
				this->stack_[i] = rhs.stack_[i];
			this->index_ = rhs.index_;
		}
		std::clog << "\033[35;2;3m[" << this << "<-" << &rhs \
			<< "]<MutantStack> Copy assignment operator called ( <" \
			<< this->getType() << ">[" \
			<< this->index_ << "] / " << this->stack_.size() \
			<< " )\033[m" << std::endl;
		return (*this);
	};
	~MutantStack(void) {
		std::clog << "\033[31;2;3m[" << this \
			<< "]<MutantStack> Destructor called ( <" \
			<< this->getType() << ">[" \
			<< this->index_ << "] / " << this->stack_.size() \
			<< " )\033[m" << std::endl;
		// if (this->stack_)
			// delete[] this->stack_;
		// this->stack_ = NULL;
	};
	T&	top() {
		return (stack_.top());
	};
	bool	empty() const {
		return (stack_.empty());
	};
	unsigned int	size(void) const {
		return (stack_.size());
	};
	void	push(T value) {
		return (stack_.push(value));
	};
	void	pop(void) {
		return (stack_.pop());
	};
/*
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
*/
	const T&	operator[](unsigned int index) const {
		if (index >= stack_.size()) {
			throw MutantStack::OutBoundsException();
		}
		return (this->stack_[index]);
	};
	T&	operator[](unsigned int index) {
		if (index >= stack_.size()) {
			throw MutantStack::OutBoundsException();
		}
		return (this->stack_[index]);
	};
/*
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
*//*
	MutantStack&	operator=(const T* rhs) {
		for (unsigned int i = 0; i < this->index_; i++)
			this->stack_[i] = rhs[i];
		std::clog << "\033[35;2;3m[" << this \
			<< "]<MutantStack> MutantStack assignment operator called ( <" \
			<< this->getType() << ">[" << this->index_ \
			<< "] <-[" << &rhs << "])\033[m" << std::endl;
		return (*this);
	};
*/
	const std::string	getType(void) const {
			return (typeid(this->stack_).name());
	};
};

template <typename T>
std::ostream&	operator<<(std::ostream& stream, const MutantStack<T>& tc) {
	stream << "[" << &tc << "]<MutantStack> has < " \
		<< tc.getType() << "[" << tc.size() << "] >\033[m";
	return (stream);
};

#endif
