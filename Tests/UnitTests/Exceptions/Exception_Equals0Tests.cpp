// Copyright (c) 2022 Sapphire development team. All Rights Reserved.

#include <gtest/gtest.h>

#include <SA/Collections/Debug>

namespace Sa::UT::Exc_Eq
{
	TEST(Exception, Equals0_Success)
	{
		SA_ASSERT(Equals0, UnitTests, 0);
	}

	TEST(Exception, Equals0_Failure)
	{
		try
		{
			SA_ASSERT(Equals0, UnitTests, 1);
		}
		catch (Exception_Equals0& _exc)
		{
		}
	}

	TEST(Exception, Equals0_CatchAny)
	{
		try
		{
			SA_ASSERT(Equals0, UnitTests, 1);
		}
		catch (Exception_Equals& _exc) // try catching any equals exception.
		{
		}
	}

	TEST(Exception, Equals0Float)
	{
		SA_ASSERT(Equals0, UnitTests, std::numeric_limits<float>::epsilon());
	}

	TEST(Exception, Equals0Double)
	{
		SA_ASSERT(Equals0, UnitTests, std::numeric_limits<double>::epsilon());
	}
}
