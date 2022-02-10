// Copyright (c) 2022 Sapphire development team. All Rights Reserved.

#include <gtest/gtest.h>

#include <SA/Collections/Debug>

namespace Sa::UT::Exc_NEq
{
	TEST(Exception, NotEquals0_Success)
	{
		SA_ASSERT(NotEquals0, UnitTests, 1);
	}

	TEST(Exception, NotEquals0_Failure)
	{
		try
		{
			SA_ASSERT(NotEquals0, UnitTests, 0, L"Some details!");
		}
		catch (Exception_NotEquals0& _exc)
		{
			(void)_exc;
		}
	}

	TEST(Exception, NotEquals0_CatchAny)
	{
		try
		{
			SA_ASSERT(NotEquals0, UnitTests, 0);
		}
		catch (Exception_NotEquals& _exc) // try catching any not equals exception.
		{
			(void)_exc;
		}
	}

	TEST(Exception, NotEquals0Float)
	{
		try
		{
			SA_ASSERT(NotEquals0, UnitTests, std::numeric_limits<float>::epsilon());
		}
		catch (Exception_NotEquals0& _exc)
		{
			(void)_exc;
		}
	}

	TEST(Exception, NotEquals0Double)
	{
		try
		{
			SA_ASSERT(NotEquals0, UnitTests, std::numeric_limits<double>::epsilon());
		}
		catch (Exception_NotEquals0& _exc)
		{
			(void)_exc;
		}
	}
}
