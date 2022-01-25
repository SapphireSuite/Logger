// Copyright (c) 2022 Sapphire development team. All Rights Reserved.

#include <gtest/gtest.h>

#include <SA/Collections/Debug>

namespace Sa::UT::Exc_Nullptr
{
	TEST(Exception, Nullptr_Success)
	{
		int i = 5;
		SA_ASSERT(Nullptr, UnitTests, &i);
	}

	TEST(Exception, Nullptr_Failure)
	{
		try
		{
			SA_ASSERT(Nullptr, UnitTests, (int*)nullptr);
		}
		catch (Exception_Nullptr& _exc)
		{
		}
	}
}
