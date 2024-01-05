/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandrad <loandrad@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:59:04 by loandrad          #+#    #+#             */
/*   Updated: 2024/01/05 12:08:04 by loandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void memberFunctionTests(void)
{
    std::cout << std::endl;
    std::cout << "Default constructor test (Bureaucrat b1)" << std::endl;
    Bureaucrat b1;
    std::cout << "b1.getName()  = " << b1.getName() << std::endl;
    std::cout << "b1.getGrade() = " << b1.getGrade() << std::endl;
    std::cout << std::endl;
    
    std::cout << std::endl;
    std::cout << "Parameterized constructor test (Bureaucrat b2(\"Obama\", 5))" << std::endl;
    Bureaucrat b2("Obama", 5);
    std::cout << "b2.getName()  = " << b2.getName() << std::endl;
    std::cout << "b2.getGrade() = " << b2.getGrade() << std::endl;
    std::cout << std::endl;
    
    std::cout << std::endl;
    std::cout << "Copy constructor test (Bureaucrat b3 = b2)" << std::endl;
    Bureaucrat b3 = b2;
    std::cout << "b3.getName()  = " << b3.getName() << std::endl;
    std::cout << "b3.getGrade() = " << b3.getGrade() << std::endl;
    std::cout << std::endl;
    
    std::cout << std::endl;
    std::cout << "Assignment operator overload test (b3 = b1)" << std::endl;
    b3 = b1;
    std::cout << "b3.getName()  = " << b3.getName() << std::endl;
    std::cout << "b3.getGrade() = " << b3.getGrade() << std::endl;
    std::cout << std::endl;
    
    std::cout << std::endl;
    std::cout << "Grade increment test" << std::endl;
    std::cout << "b2.getName()  = " << b2.getName() << std::endl;
    std::cout << "b2.getGrade() before increment " << b2.getGrade() << std::endl;
    b2.increment();
    std::cout << "b2.getGrade() after increment " << b2.getGrade() << std::endl;
    std::cout << std::endl;
    
    std::cout << std::endl;
    std::cout << "Grade decrement test" << std::endl;
    std::cout << "b2.getName()  = " << b2.getName() << std::endl;
    std::cout << "b2.getGrade() before decrement " << b2.getGrade() << std::endl;
    b2.decrement();
    std::cout << "b2.getGrade() after decrement " << b2.getGrade() << std::endl;
    std::cout << std::endl;
    
    std::cout << std::endl;
    std::cout << "Insertion operator overload test(b1 << b2 << b3)" << std::endl;
    std::cout << b1 << b2 << b3;
    std::cout << std::endl;
}

void tryCatchBlockTests(void)
{
    std::cout << std::endl;
    std::cout << "Test to initialize object with grade beyond lower bound" << std::endl;
    try
	{
		Bureaucrat b1("Trump", 166);
        std::cout << "b1.getName()  = " << b1.getName() << std::endl;
        std::cout << "b1.getGrade() = " << b1.getGrade() << std::endl;
	}
	catch(const Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}

    std::cout << std::endl;
    std::cout << "Test to initialize object with grade beyond higher bound" << std::endl;
	try
	{
		Bureaucrat b1("Trump", 0);
        std::cout << "b1.getName()  = " << b1.getName() << std::endl;
        std::cout << "b1.getGrade() = " << b1.getGrade() << std::endl;
	}
	catch(const Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}

    std::cout << std::endl;
    std::cout << "Test to decrease grade beyond lower bound" << std::endl;
	try
	{
		Bureaucrat b1("Trump", 150);
        std::cout << "b1.getName()  = " << b1.getName() << std::endl;
        std::cout << "b1.getGrade() = " << b1.getGrade() << std::endl;
        std::cout << "After running decrement member function on " << b1.getName() << std::endl;
        b1.decrement();
	}
	catch(const Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
    std::cout << "Test to increase grade beyond higher bound" << std::endl;
	try
	{
		Bureaucrat b1("Obama", 1);
        std::cout << "b1.getName()  = " << b1.getName() << std::endl;
        std::cout << "b1.getGrade() = " << b1.getGrade() << std::endl;
        std::cout << "After running increment member function on " << b1.getName() << std::endl;
        b1.increment();
	}
	catch(const Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int main(void)
{
    //memberFunctionTests();
    tryCatchBlockTests();
    return 0;
}