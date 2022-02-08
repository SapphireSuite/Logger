// Copyright (c) 2022 Sapphire development team. All Rights Reserved.

#include <gtest/gtest.h>

#include <SA/Collections/Debug>

namespace Sa::UT::Exc_NEq
{
	TEST(Exception, NotEquals_Success)
	{
		SA_ASSERT(NotEquals, UnitTests, 4, 6);
	}

	TEST(Exception, NotEquals_Failure)
	{
		try
		{
			SA_ASSERT(NotEquals, UnitTests, 4, 4);
		}
		catch (Exception_NotEquals& _exc)
		{
			(void)_exc;
		}
	}
}
