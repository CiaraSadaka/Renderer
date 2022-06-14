#pragma once
#include "pch.h"
#include "CppUnitTest.h"
#include "Foo.h"


//
//namespace Microsoft::VisualStudio::CppUnitTestFramework
//{
//	template<>
//	inline std::wstring ToString<Renderer::Foo>(const Renderer::Foo& t)
//	{
//		RETURN_WIDE_STRING(t.Data());
//	}
//}
//
//namespace Microsoft::VisualStudio::CppUnitTestFramework
//{
//	template<>
//	inline std::wstring ToString<Renderer::Foo>(const Renderer::Foo* t)
//	{
//		RETURN_WIDE_STRING(t->Data());
//	}
//}
//
//namespace Microsoft::VisualStudio::CppUnitTestFramework
//{
//	template<>
//	inline std::wstring ToString<Renderer::Foo>(Renderer::Foo* t)
//	{
//		RETURN_WIDE_STRING(t->Data());
//	}
//}