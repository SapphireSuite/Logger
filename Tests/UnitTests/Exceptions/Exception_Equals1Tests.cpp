// Copyright (c) 2022 Sapphire development team. All Rights Reserved.

#include <gtest/gtest.h>

#include <SA/Collections/Debug>

namespace Sa::UT::Exc_Eq
{
	TEST(Exception, Equals1_Success)
	{
		EXPECT_NO_THROW(SA_ASSERT(Equals1, SA/UnitTests/Exception, 1));
	}

	TEST(Exception, Equals1_Failure)
	{
		EXPECT_THROW(SA_ASSERT(Equals1, SA/UnitTests/Exception, 2, L"Some details!"), Exception_Equals1);
	}

	TEST(Exception, Equals1_CatchAny)
	{
		// try catching any equals exception.

		EXPECT_THROW(SA_ASSERT(Equals1, SA/UnitTests/Exception, 2), Exception_Equals);
	}

	TEST(Exception, Equals1Float)
	{
		EXPECT_NO_THROW(SA_ASSERT(Equals1, SA/UnitTests/Exception, 1.0f + std::numeric_limits<float>::epsilon()));
	}

	TEST(Exception, Equals1Double)
	{
		EXPECT_NO_THROW(SA_ASSERT(Equals1, SA/UnitTests/Exception, 1.0 + std::numeric_limits<double>::epsilon()));
	}
}
