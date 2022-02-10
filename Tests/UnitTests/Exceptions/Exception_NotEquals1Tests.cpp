// Copyright (c) 2022 Sapphire development team. All Rights Reserved.

#include <gtest/gtest.h>

#include <SA/Collections/Debug>

namespace Sa::UT::Exc_NEq
{
	TEST(Exception, NotEquals1_Success)
	{
		SA_ASSERT(NotEquals1, UnitTests, 2);
	}

	TEST(Exception, NotEquals1_Failure)
	{
		try
		{
			SA_ASSERT(NotEquals1, UnitTests, 1, L"Some details!");
		}
		catch (Exception_NotEquals1& _exc)
		{
			(void)_exc;
		}
	}

	TEST(Exception, NotEquals1_CatchAny)
	{
		try
		{
			SA_ASSERT(NotEquals1, UnitTests, 1);
		}
		catch (Exception_NotEquals& _exc) // try catching any not equals exception.
		{
			(void)_exc;
		}
	}

	TEST(Exception, NotEquals1Float)
	{
		try
		{
			SA_ASSERT(NotEquals1, UnitTests, 1.0f + std::numeric_limits<float>::epsilon());
		}
		catch (Exception_NotEquals1& _exc)
		{
			(void)_exc;
		}
	}

	TEST(Exception, NotEquals1Double)
	{
		try
		{
			SA_ASSERT(NotEquals1, UnitTests, 1.0 + std::numeric_limits<double>::epsilon());
		}
		catch (Exception_NotEquals1& _exc)
		{
			(void)_exc;
		}
	}
}
