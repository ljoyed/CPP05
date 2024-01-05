/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandrad <loandrad@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:42:38 by loandrad          #+#    #+#             */
/*   Updated: 2024/01/05 12:08:41 by loandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Anonymous")
{
    _grade = 145;
}
        
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    else
        _grade = grade;
}
        
Bureaucrat::Bureaucrat(const Bureaucrat& origObj) : _name(origObj._name)
{
    _grade = origObj._grade;
}
        
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& origObj)
{
    if (this != &origObj)
    {
        _grade = origObj._grade;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat()
{}

std::string Bureaucrat::getName(void) const
{
    return _name;
}

int Bureaucrat::getGrade(void) const
{
    return _grade;
}

void Bureaucrat::increment(void)
{
    if (_grade - 1 >= 1)
        _grade--;
    else
        throw GradeTooHighException();
}

void Bureaucrat::decrement(void)
{
    if (_grade + 1 <= 150)
        _grade++;
    else
        throw GradeTooLowException();
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Not possible! Already at the highest possible grade.");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Not possible! Already at the lowest possible grade.");
}

std::ostream& operator <<(std::ostream& COUT, Bureaucrat& obj)
{
    COUT << obj.getName() << ", bureaucrat grade " << obj.getGrade() << std::endl;
    return COUT;
}