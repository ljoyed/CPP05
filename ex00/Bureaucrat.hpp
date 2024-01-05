/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandrad <loandrad@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:21:55 by loandrad          #+#    #+#             */
/*   Updated: 2024/01/05 16:19:54 by loandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
    private:
        const std::string   _name;
        int                 _grade;

    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat (const Bureaucrat& origObj);
        Bureaucrat& operator =(const Bureaucrat& origObj);
        ~Bureaucrat();
        
        std::string getName(void) const;
        int getGrade(void) const;
        void increment(void);
        void decrement(void);

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

std::ostream& operator <<(std::ostream& COUT, Bureaucrat& obj);

#endif