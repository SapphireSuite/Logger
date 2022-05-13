// Copyright (c) 2022 Sapphire development team. All Rights Reserved.

#include <gtest/gtest.h>

#include <SA/Collections/Debug>

namespace SA::UT::Exc_NEq
{
	TEST(Exception, NotEquals0_Success)
	{
		EXPECT_NO_THROW(SA_ASSERT(NotEquals0, SA/UnitTests/Exception, 1));
	}

	TEST(Exception, NotEquals0_Failure)
	{
		EXPECT_THROW(SA_ASSERT(NotEquals0, SA/UnitTests/Exception, 0, L"Some details!"), Exception_NotEquals0);
	}

	TEST(Exception, NotEquals0_CatchAny)
	{
		// try catching any not equals exception.

		EXPECT_THROW(SA_ASSERT(NotEquals0, SA/UnitTests/Exception, 0), Exception_NotEquals0);
	}

	TEST(Exception, NotEquals0Float)
	{
		EXPECT_THROW(SA_ASSERT(NotEquals0, SA/UnitTests/Exception,
			std::numeric_limits<float>::epsilon()), Exception_NotEquals0);
	}

	TEST(Exception, NotEquals0Double)
	{
		EXPECT_THROW(SA_ASSERT(NotEquals0, SA/UnitTests/Exception,
			std::numeric_limits<double>::epsilon()), Exception_NotEquals0);
	}
}
