// Copyright (c) 2022 Sapphire development team. All Rights Reserved.

#include <gtest/gtest.h>

#include <SA/Collections/Debug>

namespace Sa::UT::Exc_Eq
{
	TEST(Exception, Equals_Success)
	{
		SA_ASSERT(Equals, UnitTests, 4, 4);
	}

	TEST(Exception, Equals_Failure)
	{
		try
		{
			SA_ASSERT(Equals, UnitTests, 4, 6);
		}
		catch (Exception_Equals& _exc)
		{
			(void)_exc;
		}
	}
}
