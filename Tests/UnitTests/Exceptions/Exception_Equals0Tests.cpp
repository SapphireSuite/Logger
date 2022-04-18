// Copyright (c) 2022 Sapphire development team. All Rights Reserved.

#include <gtest/gtest.h>

#include <SA/Collections/Debug>

namespace Sa::UT::Exc_Eq
{
	TEST(Exception, Equals0_Success)
	{
		EXPECT_NO_THROW(SA_ASSERT(Equals0, SA/UnitTests/Exception, 0));
	}

	TEST(Exception, Equals0_Failure)
	{
		EXPECT_THROW(SA_ASSERT(Equals0, SA/UnitTests/Exception, 1, L"Some details!"), Exception_Equals0);
	}

	TEST(Exception, Equals0_CatchAny)
	{
		// try catching any equals exception.

		EXPECT_THROW(SA_ASSERT(Equals0, SA/UnitTests/Exception, 1), Exception_Equals);
	}

	TEST(Exception, Equals0Float)
	{
		EXPECT_NO_THROW(SA_ASSERT(Equals0, SA/UnitTests/Exception, std::numeric_limits<float>::epsilon()));
	}

	TEST(Exception, Equals0Double)
	{
		EXPECT_NO_THROW(SA_ASSERT(Equals0, SA/UnitTests/Exception, std::numeric_limits<double>::epsilon()));
	}
}
