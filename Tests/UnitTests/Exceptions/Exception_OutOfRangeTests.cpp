// Copyright (c) 2022 Sapphire development team. All Rights Reserved.

#include <gtest/gtest.h>

#include <SA/Collections/Debug>

namespace Sa::UT::Exc_OOR
{
	TEST(Exception, OutOfRange_Success)
	{
		SA_ASSERT(OutOfRange, UnitTests, 4, 0, 6);
	}

	TEST(Exception, OutOfRange_Failure)
	{
		try
		{
			SA_ASSERT(OutOfRange, UnitTests, 10, 0, 6);
		}
		catch (Exception_OutOfRange& _exc)
		{
			EXPECT_EQ(_exc.currIndex, 10);
			EXPECT_EQ(_exc.minBound, 0);
			EXPECT_EQ(_exc.maxBound, 6);
		}

		try
		{
			SA_ASSERT(OutOfRange, UnitTests, 6, 0, 6);
		}
		catch (Exception_OutOfRange& _exc)
		{
			EXPECT_EQ(_exc.currIndex, 6);
			EXPECT_EQ(_exc.minBound, 0);
			EXPECT_EQ(_exc.maxBound, 6);
		}
	}
}
