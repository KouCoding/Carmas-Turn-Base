#pragma once
#include <iostream>
#include <cstdlib>
#include <string>


namespace GrandHelper {

	static bool IntegerValidation(const char* str) {
		
		if (str == nullptr || str[0] == '\0')
		{
			return false;
		}


		int i = 0;

		// Check for a sign at the beginning
		if (str[i] == '+' || str[i] == '-')
		{
			i++; // Move index to 1 skipping the sign
		}

		// Safety check: Make sure its not just a solitary sign ( e.g "-" with no numbers )

		if (str[i] == '\0')
		{
			return false;
		}

		// Loop through the rest of the string
		while (str[i] != '\0')
		{
			if (str[i] < '0' || str[i] > '9')
			{
 				return false; // found non-digit character
			}

			i++; // Advance to the next character index 
		}

		return true; // Safe and verified
	}


	static void PrintIntegerBinary(const int* num) {
		
		// Safety check: make sure the pointer isn't null
		if (num == nullptr) return;
		
		// Extract the value inside the pointer by dereferencing it
		int value = *num;

		// Loop through all 32 bits from left to right (hightest to lowest)
		for (int i = 31; i >= 0; i--)
		{
			// use a bitwise mask to isolate the bit 'i'
			// if (value AND (1 shifted left i times)) is not zero, that bit is a 1

			if ((value & (1 << i)) != 0) {
				
				std::cout << "1";
			}
			else
			{
				std::cout << "0";
			} 
		}
	}


	static void BubbleSort(int* arr, int size) {
		
		// Safety Check

		if (arr == nullptr || size <= 1) return;
		
		// Outer loop for tracking each pass through arrary

		for (int i = 0; i < size - 1; i++)
		{
			// Inner loop for comparing adjacent elements

			for (int j = 0; j < size - i - 1; j++)
			{
				// if adjacent items are out of order, swap them

				if (arr[j] > arr[j + 1])
				{
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
		
	}


	static void ClearConsoleWindow() {
	
		system("cls");
	}


	static int RandomNumberGenerator(int min = 1, int max = 100) {
		
		if (min > max)
		{
			int temp = min;
			min = max;
			max = temp;
		}

		return (rand() % (max - min + 1)) + min;
	}


	// Console Class Helpers 

	// Reads a full line of text and keeps repeating until a non-empty text is entered.
	static std::string UserInputString(std::string prompt = "") {
		
		std::string input;
		while (true)
		{
			
			if (!prompt.empty())
			{
				std::cout << prompt;
				std::getline(std::cin, input);
				
			}
			if (!input.empty())
			{
				return input;
				std::cout << "Input cannot be empty. Please try again.\n";
			}
		}

	}

	// Reads valid int input from the user, clearing bad inputs and trailing newline characters
	static int UserInputInteger(std::string prompt = "") {
		
		int value;
		while (true)
		{
			if (!prompt.empty())
			{
				std::cout << prompt;
			}
			if (std::cin >> value)
			{
				std::cin.ignore(1000, '\n');
				return value;
			}
			else
			{
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				std::cout << "Invalid number. Please enter a whole number.\n";
			}
		}

	}

	// Personal: Reads valid integer within [min, max], repeating until the input is inside bounds.
	static int UserInputInteger(std::string prompt, int min, int max) {
		while (true)
		{
			int value = UserInputInteger(prompt);
			if (value >= min && value <= max)
			{
				return value;
			
			}
			else
			{
				std::cout << "Out of range. Enter a number between " << min << " and " << max << "\n";
			}
		}
	}

	// Prints any data type without moving to a new line.
	template <typename T>
	static void Write(T item) {
	
		std::cout << item;
	}

	// Prints any data type and moves it to a new line.
	template <typename T>
	static void WriteLine(T item) {
		
		std::cout << item << std::endl;
	}

	// Personal : Prints a blank new line takes no arguments
	static void WriteLine() {
		
		std::cout << std::endl;
	}

	static void ChangeBackgroundColor() {
		// Placeholder for terminal style operations
	}


	static void ChangeForegroundColor() {
		// Placeholder for terminal style operations 
	}

}
