#pragma once

#include"pch.h"

namespace Renderer
{
	class Foo final
	{

	public:

		/// <summary>
		/// The constructor for Foo, an object of type data. 
		/// </summary>
		/// <param name="data">The data type for Foo</param>
		Foo(std::int32_t data);

		/// <summary>
		/// Declaration of copy constructor for Foo. Instantiates an SList from an existing instance. 
		/// </summary>
		/// <param name="other">The source incstance.</param>
		Foo(const Foo& other);

		/// <summary>
		/// Declaration of assignment opperator for Foo.
		/// </summary>
		/// <param name="other">The source incstance.</param>
		/// <returns>The current instance of (i.e. the left hand side of the assignment)</returns>
		Foo& operator = (const Foo& other);

		/// <summary>
		/// Deconstructor for Foo
		/// </summary>
		~Foo();

		/// <summary>
		/// Accesses the Data in a certain Foo
		/// </summary>
		/// <returns>The data contained in that particular foo</returns>
		std::int32_t& Data();

		/// <summary>
		/// Views the constant data in a certain foo
		/// </summary>
		/// <returns>The data contained in that particular foo</returns>
		const std::int32_t& Data() const;

		/// <summary>
		/// Redefines the equals operator for Foo objects.
		/// </summary>
		/// <param name="rhs">the data to be compaired</param>
		/// <returns>returns True if the are equal and false if they are not</returns>
		bool operator==(const Foo& rhs) const;

		/// <summary>
		/// Redefines the not equals operator for Foo objects.
		/// </summary>
		/// <param name="rhs">the data to be compaired</param>
		/// <returns>returns False if the are equal and True if they are not</returns>
		bool operator!=(const Foo& rhs) const;

	private:
		std::int32_t* _data{ nullptr };

	};

}