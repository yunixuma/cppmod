/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/27 20:15:51 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) \
	: AForm("shrubbery_creation", target, 145, 137) {
	std::clog << "\033[36;2;3m[" << this \
		<< "]<ShrubberyCreationForm> Constructor called (" \
		<< this->getName() << ")\033[m" << std::endl;
	// if (this->getGradeToSign() > 150 || this->getGradeToExec() > 150)
	// 	throw Bureaucrat::GradeTooLowException();
	// else if (this->getGradeToSign() < 1 || this->getGradeToExec() < 1)
	// 	throw Bureaucrat::GradeTooHighException();
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) \
	: AForm(src) {
	std::clog << "\033[36;2;3m[" << this << "<-" << &src \
		<< "]<ShrubberyCreationForm> Copy constructor called (" \
		<< this->getName() << ")\033[m" << std::endl;
	if (this->getGradeToSign() > 150 || this->getGradeToExec() > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (this->getGradeToSign() < 1 || this->getGradeToExec() < 1)
		throw Bureaucrat::GradeTooHighException();
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs) {
	std::clog << "\033[35;2;3m[" << this << "<-" << &rhs \
		<< "]<ShrubberyCreationForm> Copy assignment operator called (" \
		<< this->getName() << ")\033[m" << std::endl;
	if (this != &rhs)
		this->copy(rhs);
	if (this->getGradeToSign() > 150 || this->getGradeToExec() > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (this->getGradeToSign() < 1 || this->getGradeToExec() < 1)
		throw Bureaucrat::GradeTooHighException();
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	std::clog << "\033[31;2;3m[" << this \
		<< "]<ShrubberyCreationForm> Destructor called (" \
		<< this->getName() << ")\033[m" << std::endl;
}

void	ShrubberyCreationForm::beSigned(const Bureaucrat& bc) {
	std::clog << "\033[32;2;3m[" << this \
		<< "]<ShrubberyCreationForm> beSigned() called (" \
		<< this->getName() << ")\033[m" << std::endl;
	if (this->getGradeToSign() < bc.getGrade())
		throw ShrubberyCreationForm::GradeTooLowException();
	else if (this->getSigned() == true)
		throw ShrubberyCreationForm::AlreadySignedException();
	this->setSigned(true);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	std::clog << "\033[32;2;3m[" << this \
		<< "]<ShrubberyCreationForm> execute() called (" \
		<< this->getName() << ")\033[m" << std::endl;
	if (this->getSigned() == false)
		throw ShrubberyCreationForm::NotSignedException();
	else if (this->getGradeToExec() < executor.getGrade())
		throw ShrubberyCreationForm::GradeTooLowException();

	std::ofstream	ofs;
	std::string		filepath_out = this->getTarget() + "_shrubbery";
	try {
		ofs.open(filepath_out.c_str(), std::ios::out | std::ios::binary);
		if (ofs.fail())
			throw (std::exception());
	}
	catch (const std::exception& e) {
		std::cerr << "\033[31m!!! Error opening thetarg dest. file. !!!\033[m" << std::endl;
		return ;
	}

	std::string	content = "\
               ,@@@@@@@,\n\
       ,,,.   ,@@@@@@/@@,  .oo8888o.\n\
    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n\
   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n\
   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n\
   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n\
   `&%\\ ` /%&'    |.|        \\ '|8'\n\
       |o|        | |         | |\n\
       |.|        | |         | |\n\
jgs \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_\n\
\n\
------------------------------------------------\n\
Thank you for visiting https://asciiart.website/\n\
This ASCII pic can be found at\n\
https://asciiart.website/index.php?art=plants/trees";

	ofs << content;
	ofs.close();
}

// When an exception thrown
const char*	ShrubberyCreationForm::GradeTooHighException::what(void) const throw() {
	std::clog << "\033[35;3m[" << this \
		<< "]<ShrubberyCreationForm::GradeTooHighException> what() called\033[m" << std::endl;
	return ("the grade is too high");
	// return (1);
}

const char*	ShrubberyCreationForm::GradeTooLowException::what(void) const throw() {
	std::clog << "\033[35;3m[" << this \
		<< "]<ShrubberyCreationForm::GradeTooLowException> what() called\033[m" << std::endl;
	return ("the grade is too low");
	// return (2);
}

const char*	ShrubberyCreationForm::AlreadySignedException::what(void) const throw() {
	std::clog << "\033[35;3m[" << this \
		<< "]<ShrubberyCreationForm::AlreadySignedException> what() called\033[m" << std::endl;
	return ("already signed");
	// return (3);
}

const char*	ShrubberyCreationForm::NotSignedException::what(void) const throw() {
	std::clog << "\033[35;3m[" << this \
		<< "]<ShrubberyCreationForm::NotSignedException> what() called\033[m" << std::endl;
	return ("not signed yet");
	// return (4);
}

// Insertion operator overload to print
std::ostream&	operator<<(std::ostream& stream, const ShrubberyCreationForm& ShrubberyCreationForm) {
	stream << "ShrubberyCreationForm \"" << ShrubberyCreationForm.getName() << "\", signed " \
		<< (ShrubberyCreationForm.getSigned() ? "true" : "false") << ", grade " \
		<< ShrubberyCreationForm.getGradeToSign() << " to sign, grade " \
		<< ShrubberyCreationForm.getGradeToExec() << " to execute.";
	return (stream);
}
