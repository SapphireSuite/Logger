// Copyright (c) 2022 Sapphire development team. All Rights Reserved.

#include <gtest/gtest.h>

#include <SA/Collections/Debug>

namespace Sa::UT::Exc_Eq
{
	TEST(Exception, Equals1_Success)
	{
		SA_ASSERT(Equals1, UnitTests, 1);
	}

	TEST(Exception, Equals1_Failure)
	{
		try
		{
			SA_ASSERT(Equals1, UnitTests, 2, L"Some details!");
		}
		catch (Exception_Equals1& _exc)
		{
			(void)_exc;
		}
	}

	TEST(Exception, Equals1_CatchAny)
	{
		try
		{
			SA_ASSERT(Equals1, UnitTests, 2);
		}
		catch (Exception_Equals& _exc) // try catching any equals exception.
		{
			(void)_exc;
		}
	}

	TEST(Exception, Equals1Float)
	{
		SA_ASSERT(Equals1, UnitTests, 1.0f + std::numeric_limits<float>::epsilon());
	}

	TEST(Exception, Equals1Double)
	{
		SA_ASSERT(Equals1, UnitTests, 1.0 + std::numeric_limits<double>::epsilon());
	}
}
