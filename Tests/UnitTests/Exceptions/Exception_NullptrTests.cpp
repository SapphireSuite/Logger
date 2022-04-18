// Copyright (c) 2022 Sapphire development team. All Rights Reserved.

#include <gtest/gtest.h>

#include <SA/Collections/Debug>

namespace Sa::UT::Exc_Nullptr
{
	TEST(Exception, Nullptr_Success)
	{
		int i = 5;
		EXPECT_NO_THROW(SA_ASSERT(Nullptr, SA/UnitTests/Exception, &i));
	}

	TEST(Exception, Nullptr_Failure)
	{
		EXPECT_THROW(SA_ASSERT(Nullptr, SA/UnitTests/Exception, (int*)nullptr), Exception_Nullptr);
	}
}
