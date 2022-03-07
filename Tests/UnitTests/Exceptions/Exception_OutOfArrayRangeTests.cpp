// Copyright (c) 2022 Sapphire development team. All Rights Reserved.

#include <gtest/gtest.h>

#include <SA/Collections/Debug>

#include <array>
#include <vector>
#include <list>

namespace Sa::UT::Exc_OOAR
{
	TEST(Exception, OutOfArrayRange_Success)
	{
		const std::array<float, 6> tab{ 1.2f, 3.36f, 45.2f, 78.21f, 6.3f, 11.2f };

		SA_ASSERT(OutOfArrayRange, UnitTests, 0, tab);
		SA_ASSERT(OutOfArrayRange, UnitTests, 1, tab);
		SA_ASSERT(OutOfArrayRange, UnitTests, 5, tab);


		const std::vector<float> v{ 1.2f, 3.36f, 45.2f, 78.21f, 6.3f, 11.2f };

		SA_ASSERT(OutOfArrayRange, UnitTests, 0, v);
		SA_ASSERT(OutOfArrayRange, UnitTests, 3, v);
		SA_ASSERT(OutOfArrayRange, UnitTests, 5, v);


		const std::list<float> l{ 1.2f, 3.36f, 45.2f, 78.21f, 6.3f, 11.2f };

		SA_ASSERT(OutOfArrayRange, UnitTests, 0, l);
		SA_ASSERT(OutOfArrayRange, UnitTests, 2, l);
		SA_ASSERT(OutOfArrayRange, UnitTests, 5, l);
	}

	TEST(Exception, OutOfArrayRange_Failure)
	{
		const std::vector<float> v{ 1.2f, 3.36f, 45.2f, 78.21f, 6.3f, 11.2f };

		try
		{
			SA_ASSERT(OutOfArrayRange, UnitTests, 6, v);
		}
		catch (Exception_OutOfRange& _exc)
		{
			EXPECT_EQ(_exc.currIndex, 6u);
			EXPECT_EQ(_exc.minBound, 0u);
			EXPECT_EQ(_exc.maxBound, 5u);
		}

		try
		{
			SA_ASSERT(OutOfArrayRange, UnitTests, 10, v);
		}
		catch (Exception_OutOfRange& _exc)
		{
			EXPECT_EQ(_exc.currIndex, 10u);
			EXPECT_EQ(_exc.minBound, 0u);
			EXPECT_EQ(_exc.maxBound, 5u);
		}
	}
}
