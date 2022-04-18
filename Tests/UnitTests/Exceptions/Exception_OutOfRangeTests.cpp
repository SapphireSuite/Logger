// Copyright (c) 2022 Sapphire development team. All Rights Reserved.

#include <gtest/gtest.h>

#include <SA/Collections/Debug>

namespace Sa::UT::Exc_OOR
{
	TEST(Exception, OutOfRange_Success)
	{
		EXPECT_NO_THROW(SA_ASSERT(OutOfRange, SA/UnitTests/Exception, 4, 0, 6));
		EXPECT_NO_THROW(SA_ASSERT(OutOfRange, SA/UnitTests/Exception, 6, 0, 6));
	}

	TEST(Exception, OutOfRange_Failure)
	{
		EXPECT_THROW(SA_ASSERT(OutOfRange, SA/UnitTests/Exception, 2, 4, 6), Exception_OutOfRange);

		try
		{
			SA_ASSERT(OutOfRange, SA/UnitTests/Exception, 2, 4, 6);
		}
		catch (Exception_OutOfRange& _exc)
		{
			EXPECT_EQ(_exc.currIndex, 2u);
			EXPECT_EQ(_exc.minBound, 4u);
			EXPECT_EQ(_exc.maxBound, 6u);
		}


		EXPECT_THROW(SA_ASSERT(OutOfRange, SA/UnitTests/Exception, 10, 0, 6), Exception_OutOfRange);

		try
		{
			SA_ASSERT(OutOfRange, SA/UnitTests/Exception, 10, 0, 6);
		}
		catch (Exception_OutOfRange& _exc)
		{
			EXPECT_EQ(_exc.currIndex, 10u);
			EXPECT_EQ(_exc.minBound, 0u);
			EXPECT_EQ(_exc.maxBound, 6u);
		}
	}
}
