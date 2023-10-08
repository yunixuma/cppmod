/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/07/06 23:05:49 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

// Constructors and destructor
Data::Data(int num, const std::string& str) : num_(num), str_(str) {
	std::clog << "\033[36;2;3m[" << this \
		<< "]<Data> Constructor called\033[m" << std::endl;
}

Data::Data(const Data& src) {
	std::clog << "\033[36;2;3m[" << this << "<-" << &src \
		<< "]<Data> Copy constructor called\033[m" << std::endl;
	this->num_ = src.num_;
	this->str_ = src.str_;
}

//const Data&	Data::operator=(const Data& rhs) const {
Data&	Data::operator=(const Data& rhs) {
	std::clog << "\033[35;2;3m[" << this << "<-" << &rhs \
		<< "]<Data> Copy assignment operator called\033[m" << std::endl;
	if (this != &rhs) {
		this->num_ = rhs.num_;
		this->str_ = rhs.str_;
	}
	return (*this);
}

Data::~Data(void) {
	std::clog << "\033[31;2;3m[" << this \
		<< "]<Data> Destructor called\033[m" << std::endl;
}

// Member functions
int	Data::getNum( void ) const {
	std::clog << "\033[2;3m[" << this \
		<< "]<Data> getNum called\033[m" << std::endl;
	return (this->num_);
}

const std::string&	Data::getStr( void ) const {
	std::clog << "\033[2;3m[" << this \
		<< "]<Data> getStr called\033[m" << std::endl;
	return (this->str_);
}

// Operator overload for stream
std::ostream&	operator<<(std::ostream& stream, const Data& data) {
	stream << "[" << &data << "]<Data>{" << data.getNum() << ", " << data.getStr() << "}";
	return (stream);
}
