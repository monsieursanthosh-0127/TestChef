#include "ResultFormatter.h"

//////////////////////////////////////////////////////
// Result.cpp										//
// CSE 681: Object Oriented Design					//
// Santhosh Srinivasan, Jiawen Zhen, Alifa Stith	//
//////////////////////////////////////////////////////

/*
* Implementation of the ResultFormatter class
* This class is used to return the results of each test that is run.
* Each test is run at a specific log level and that level determines the level of detail that is passed into the test result
*
*/

/* For a passed test record the elapsed time */
std::string ResultFormatter::testPassedMessage(std::string testName, Timer timer) {
	return testName + "\n        Time elapsed: " + Timer::convertTimeToString(timer.timeTakenNanos()) + " ns.";
}

/* For a failed test record the elapsed time */
std::string ResultFormatter::testFailedMessage(std::string testName, Timer timer) {
	return testName + "\n        Time elapsed: " + Timer::convertTimeToString(timer.timeTakenNanos()) + " ns.";
}

/* Based on the log level determine the amount of detail to pass into the test results */
std::string ResultFormatter::testExceptionMessage(std::string testName, std::exception& e, LOG_LEVEL logLevel) {
	switch (logLevel) {
	case LOG_LEVEL::info:	// level 1 logging
		return testName + "\n        Test failed with exception.";
	case LOG_LEVEL::detail:	// level 2 logging
		return testName + "\n        Test failed with exception: " + exceptionDetails(e) + "";
	case LOG_LEVEL::debug:	// level 3 logging
		return testName + "\n        Test failed with exception: " + exceptionDetails(e)
			+ "\n        Exception occurred on " + Timer::currentTime() + ".";
	}
	return "";
}

/* This method returns the string associated with the exception type */
std::string ResultFormatter::exceptionDetails(std::exception& e) {
	if (typeid(e) == typeid(std::bad_alloc)) {
		return "Failure to allocate storage.";
	}
	else if (typeid(e) == typeid(std::bad_array_new_length)) {
		return "Invalid array lengths.";
	}
	else if (typeid(e) == typeid(std::bad_cast)) {
		return "A dynamic_cast to a reference type fails the\n        run-time check.";
	}
	else if (typeid(e) == typeid(std::bad_exception)) {
		return "Failure exception thrown during runtime.";
	}
	else if (typeid(e) == typeid(std::bad_typeid)) {
		return "A typeid operator is applied to a dereferenced\n        null pointer value of a polymorphic type.";
	}
	else if (typeid(e) == typeid(std::bad_weak_ptr)) {
		return "A std::weak_ptr refers to an already deleted \n        object.";
	}
	else if (typeid(e) == typeid(std::logic_error)) {
		return "Faulty logic within the program.";
	}
	else if (typeid(e) == typeid(std::runtime_error)) {
		return "Error detected during runtime.";
	}
	else if (typeid(e) == typeid(std::invalid_argument)) {
		return "Invalid argument.";
	}
	else if (typeid(e) == typeid(std::domain_error)) {
		return "Domain error, outside of the subset of values\n        domain is defined for.";
	}
	else if (typeid(e) == typeid(std::length_error)) {
		return "Length error.";
	}
	else if (typeid(e) == typeid(std::out_of_range)) {
		return "Out of range.";
	}
	else if (typeid(e) == typeid(std::range_error)) {
		return "Range error, result of computation cannot\n        be represeneted by destination type.";
	}
	else if (typeid(e) == typeid(std::overflow_error)) {
		return "Overflow error, result is either infinite\n        or too large to represent in the numeric type being returned by the function.";
	}
	else if (typeid(e) == typeid(std::underflow_error)) {
		return "Underflow error, result is not zero, but is\n        too small to be represented by any other value in the type being returned by\n        the function.";
	}
	else if (typeid(e) == typeid(std::system_error)) {
		return "System error, exception thrown by various\n        library functions.";
	}
	else if (typeid(e) == typeid(std::ios_base::failure)) {
		return "Exception thrown on failure by the functions\n        in the Input/Output library.";
	}
	else {
		return e.what();
	}
	return "";
}