// Copyright (c) 2022 Sapphire development team. All Rights Reserved.

#include <gtest/gtest.h>

#include <SA/Collections/Debug>

namespace SA::UT::Exc_Eq
{
	TEST(Exception, Equals_Success)
	{
		EXPECT_NO_THROW(SA_ASSERT(Equals, SA/UnitTests/Exception, 4, 4));
	}

	TEST(Exception, Equals_Failure)
	{
		EXPECT_THROW(SA_ASSERT(Equals, SA/UnitTests/Exception, 4, 6, L"Some details!"), Exception_Equals);
	}
}
