// Copyright (c) 2022 Sapphire development team. All Rights Reserved.

#include <gtest/gtest.h>

#include <SA/Collections/Debug>

#include <array>
#include <vector>
#include <list>

namespace SA::UT::Exc_OOAR
{
	TEST(Exception, OutOfArrayRange_Success)
	{
		const std::array<float, 6> tab{ 1.2f, 3.36f, 45.2f, 78.21f, 6.3f, 11.2f };

		EXPECT_NO_THROW(SA_ASSERT(OutOfArrayRange, SA/UnitTests/Exception, 0, tab));
		EXPECT_NO_THROW(SA_ASSERT(OutOfArrayRange, SA/UnitTests/Exception, 1, tab));
		EXPECT_NO_THROW(SA_ASSERT(OutOfArrayRange, SA/UnitTests/Exception, 5, tab));


		const std::vector<float> v{ 1.2f, 3.36f, 45.2f, 78.21f, 6.3f, 11.2f };

		EXPECT_NO_THROW(SA_ASSERT(OutOfArrayRange, SA/UnitTests/Exception, 0, v));
		EXPECT_NO_THROW(SA_ASSERT(OutOfArrayRange, SA/UnitTests/Exception, 3, v));
		EXPECT_NO_THROW(SA_ASSERT(OutOfArrayRange, SA/UnitTests/Exception, 5, v));


		const std::list<float> l{ 1.2f, 3.36f, 45.2f, 78.21f, 6.3f, 11.2f };

		EXPECT_NO_THROW(SA_ASSERT(OutOfArrayRange, SA/UnitTests/Exception, 0, l));
		EXPECT_NO_THROW(SA_ASSERT(OutOfArrayRange, SA/UnitTests/Exception, 2, l));
		EXPECT_NO_THROW(SA_ASSERT(OutOfArrayRange, SA/UnitTests/Exception, 5, l));
	}

	TEST(Exception, OutOfArrayRange_Failure)
	{
		const std::vector<float> v{ 1.2f, 3.36f, 45.2f, 78.21f, 6.3f, 11.2f };

		EXPECT_THROW(SA_ASSERT(OutOfArrayRange, SA/UnitTests/Exception, 6, v), Exception_OutOfRange);

		try
		{
			SA_ASSERT(OutOfArrayRange, SA/UnitTests/Exception, 6, v);
		}
		catch (Exception_OutOfRange& _exc)
		{
			EXPECT_EQ(_exc.currIndex, 6u);
			EXPECT_EQ(_exc.minBound, 0u);
			EXPECT_EQ(_exc.maxBound, 5u);
		}


		EXPECT_THROW(SA_ASSERT(OutOfArrayRange, SA/UnitTests/Exception, 10, v), Exception_OutOfRange);

		try
		{
			SA_ASSERT(OutOfArrayRange, SA/UnitTests/Exception, 10, v);
		}
		catch (Exception_OutOfRange& _exc)
		{
			EXPECT_EQ(_exc.currIndex, 10u);
			EXPECT_EQ(_exc.minBound, 0u);
			EXPECT_EQ(_exc.maxBound, 5u);
		}
	}
}
