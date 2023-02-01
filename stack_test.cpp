#include "stack.hpp"
#include "colors.hpp"
#include <stack>
#include <iostream>

int main (void)
{

	std::cout << BOLDMAGENTA << "\n\n FT::STACK COMPLETE TESTS \n\n";

//--------------- DECLARATION ------------------------------------------------------------------------------
		ft::stack<int> ft_stack_int;
		std::stack<int> std_stack_int;

		ft::stack<std::string> ft_stack_string;
		std::stack<std::string> std_stack_string;

		ft::stack<int>	ft_empty_stack;
		std::stack<int>	std_empty_stack;
//----------------------------------------------------------------------------------------------------------



//--------------- PUSH | TOP -------------------------------------------------------------------------------
	std::cout << BOLDGREEN << "\nSTACK PUSH | TOP TEST\n";

		std::cout << BOLDYELLOW << "std:\n";	
		for (int i = 0; i < 5; i++)
		{
			std_stack_int.push(i);
			std::cout << "top int stack: " << std_stack_int.top() << std::endl;
		}
		std_stack_string.push("yo");
		std::cout << "top string stack: " << std_stack_string.top() << std::endl;
		std_stack_string.push("brrrr");
		std::cout << "top string stack: " << std_stack_string.top() << std::endl;
		std_stack_string.push("vroomvroom");
		std::cout << "top string stack: " << std_stack_string.top() << std::endl;
		std::cout << BOLDCYAN << "ft:\n";
		for (int i = 0; i < 5; i++)
		{
			ft_stack_int.push(i);
			std::cout << "top int stack: " << ft_stack_int.top() << std::endl;
		}
		ft_stack_string.push("yo");
		std::cout << "top string stack: " << ft_stack_string.top() << std::endl;
		ft_stack_string.push("brrrr");
		std::cout << "top string stack: " << ft_stack_string.top() << std::endl;
		ft_stack_string.push("vroomvroom");
		std::cout << "top string stack: " << ft_stack_string.top() << std::endl;
//----------------------------------------------------------------------------------------------------------



//-------------- SIZE TEST ---------------------------------------------------------------------------------
	std::cout << BOLDGREEN << "\nSTACK SIZE TEST\n";

		std::cout << BOLDYELLOW << "std:\n";
		std::cout << "size int stack : " << std_stack_int.size() << std::endl;
		std::cout << "size string stack: " << std_stack_string.size() << std::endl;
		std::cout << BOLDCYAN << "ft:\n";
		std::cout << "size int stack: " << ft_stack_int.size() << std::endl;
		std::cout << "size string stack: " << ft_stack_string.size() << std::endl;
//----------------------------------------------------------------------------------------------------------



//------------- EMPTY TEST ---------------------------------------------------------------------------------
		std::cout << std::boolalpha; // display true | false instead of 0 | 1

		std::cout << BOLDGREEN << "\nSTACK EMPTY TEST\n";

		std::cout << BOLDYELLOW << "std:\n";
		std::cout << "empty int stack: " << std_stack_int.empty() << std::endl;
		std::cout << "empty string stack: " << std_stack_string.empty() << std::endl;
		std::cout << "empty empty stack: " << std_empty_stack.empty() << std::endl;
		std_empty_stack.push(1);
		std::cout << "empty stack after push : " << std_empty_stack.empty() << std::endl;

		std::cout << BOLDCYAN << "ft:\n";
		std::cout << "empty int stack: " << ft_stack_int.empty() << std::endl;
		std::cout << "empty string stack: " << ft_stack_string.empty() << std::endl;
		std::cout << "empty empty stack: " << ft_empty_stack.empty() << std::endl;
		ft_empty_stack.push(1);
		std::cout << "empty stack after push : " << ft_empty_stack.empty() << std::endl;
//----------------------------------------------------------------------------------------------------------



//------------ POP TEST ------------------------------------------------------------------------------------
		std::cout << BOLDGREEN << "\nSTACK POP TEST\n";

		std::cout << BOLDYELLOW << "std:\n";
		std::cout << "string stack BEFORE pop | top : " << std_stack_string.top() << " | size : " << std_stack_string.size() << std::endl;
		std_stack_string.pop();
		std::cout << "string stack AFTER pop | top : " << std_stack_string.top() << " | size : " << std_stack_string.size() << std::endl;
		
		std::cout << BOLDCYAN << "ft:\n";
		std::cout << "string stack BEFORE pop | top : " << ft_stack_string.top() << " | size : " << ft_stack_string.size() << std::endl;
		ft_stack_string.pop();
		std::cout << "string stack AFTER pop | top : " << ft_stack_string.top() << " | size : " << ft_stack_string.size() << std::endl;
//----------------------------------------------------------------------------------------------------------
	
	std::cout << RESET;

	return (0);
}