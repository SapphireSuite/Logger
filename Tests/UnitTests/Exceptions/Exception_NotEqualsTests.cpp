// Copyright (c) 2022 Sapphire development team. All Rights Reserved.

#include <gtest/gtest.h>

#include <SA/Collections/Debug>

namespace SA::UT::Exc_NEq
{
	TEST(Exception, NotEquals_Success)
	{
		EXPECT_NO_THROW(SA_ASSERT(NotEquals, SA/UnitTests/Exception, 4, 6));
	}

	TEST(Exception, NotEquals_Failure)
	{
		EXPECT_THROW(SA_ASSERT(NotEquals, SA/UnitTests/Exception, 4, 4, L"Some details!"), Exception_NotEquals);
	}
}
