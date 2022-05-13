// Copyright (c) 2022 Sapphire development team. All Rights Reserved.

#include <gtest/gtest.h>

#include <SA/Collections/Debug>

namespace SA::UT::Exc_NEq
{
	TEST(Exception, NotEquals1_Success)
	{
		EXPECT_NO_THROW(SA_ASSERT(NotEquals1, SA/UnitTests/Exception, 2));
	}

	TEST(Exception, NotEquals1_Failure)
	{
		EXPECT_THROW(SA_ASSERT(NotEquals1, SA/UnitTests/Exception, 1, L"Some details!"), Exception_NotEquals1);
	}

	TEST(Exception, NotEquals1_CatchAny)
	{
		// try catching any not equals exception.

		EXPECT_THROW(SA_ASSERT(NotEquals1, SA/UnitTests/Exception, 1), Exception_NotEquals);
	}

	TEST(Exception, NotEquals1Float)
	{
		EXPECT_THROW(SA_ASSERT(NotEquals1, SA/UnitTests/Exception,
			1.0f + std::numeric_limits<float>::epsilon()), Exception_NotEquals1);
	}

	TEST(Exception, NotEquals1Double)
	{
		EXPECT_THROW(SA_ASSERT(NotEquals1, SA/UnitTests/Exception,
			1.0 + std::numeric_limits<double>::epsilon()), Exception_NotEquals1);
	}
}
