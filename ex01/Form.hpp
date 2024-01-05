/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandrad <loandrad@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:39:50 by loandrad          #+#    #+#             */
/*   Updated: 2024/01/05 14:41:33 by loandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class	Bureaucrat;

class Form
{
	private:
		Form();
		const std::string	_name;
		bool				_formIsSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public:
		Form (std::string name, int gradeToSign, int gradeToExecute);
		~Form();
		Form(const Form &);
		Form	&operator=(const Form &);

		std::string	getName() const;
		bool		getFormStatus() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;
		
		void		setFormStatus(bool status);

		void		beSigned(Bureaucrat &b);

		class GradeTooHighException : public std::exception
		{
			public:
				const char	*what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char	*what() const throw();
		};
};

std::ostream	&operator<<(std::ofstream &output, const Form &object);

#endif
