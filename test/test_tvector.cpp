#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
  ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
  TVector<int> v(10);

  ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
	TVector<int> v(10);
	for (int i = 0; i < 10; i++)
		v[i] = i;

	TVector<int> v1(v);
	EXPECT_EQ(v1, v);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
	TVector<int> v(10);
	TVector<int> v1(v);
	v1[5] = 1;

	EXPECT_NE(v, v1);
}

TEST(TVector, can_get_size)
{
	TVector<int> v(4);

	EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
	TVector<int> v(4, 2);

	EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
	TVector<int> v(4);
	v[0] = 4;

	EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
	TVector<int> v(4);

	ASSERT_ANY_THROW(v[-2] = 4);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector<int> v(4);

	ASSERT_ANY_THROW(v[20] = 4);
}

TEST(TVector, can_assign_vector_to_itself)
{
	TVector<int> v(4);
	ASSERT_NO_THROW(v = v);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	TVector<int> v(4);
	v[0] = 2;
	v[3] = 4;

	TVector<int> v1(4);
	v1[1] = 1;
	v1[2] = 1;

	v1 = v;
	EXPECT_EQ(v, v1);
}

TEST(TVector, assign_operator_change_vector_size)
{
	TVector<int> v(4);

	TVector<int> v1(5);

	v = v1;

	EXPECT_EQ(5, v.GetSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
	TVector<int> v(4);
	v[0] = 2;
	v[3] = 4;

	TVector<int> v1(5);
	v1[1] = 1;
	v1[2] = 1;
	v1[4] = 1;

	v1 = v;
	EXPECT_EQ(v, v1);
}

TEST(TVector, compare_equal_vectors_return_true)
{
	TVector<int> v(4);
	v[0] = 2;
	v[1] = 0;
	v[2] = 0;
	v[3] = 4;

	TVector<int> v1(4);
	v1[0] = 2;
	v1[1] = 0;
	v1[2] = 0;
	v1[3] = 4;

	EXPECT_TRUE(v == v1);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	TVector<int> v(4);
	v[0] = 1;
	v[3] = 4;

	EXPECT_TRUE(v == v);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	TVector<int> v(4);
	TVector<int> v1(5);

	EXPECT_NE(v, v1);
}

TEST(TVector, can_add_scalar_to_vector)
{
	TVector<int> v(4);
	for (int i = 0; i < 4; i++)
		v[i] = i;

	TVector<int> res = v + 4;

	TVector<int> exp(4);
	exp[0] = 4;
	exp[1] = 5;
	exp[2] = 6;
	exp[3] = 7;

	EXPECT_EQ(exp, res);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	TVector<int> v(4);
	for (int i = 0; i < 4; i++)
		v[i] = i + 1;

	TVector<int> res = v - 1;

	TVector<int> exp(4);
	exp[0] = 0;
	exp[1] = 1;
	exp[2] = 2;
	exp[3] = 3;

	EXPECT_EQ(exp, res);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	TVector<int> v(4);
	for (int i = 0; i < 4; i++)
		v[i] = i;

	TVector<int> res = v * 2;

	TVector<int> exp(4);
	exp[0] = 0;
	exp[1] = 2;
	exp[2] = 4;
	exp[3] = 6;

	EXPECT_EQ(exp, res);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	TVector<int> v(4);
	for (int i = 0; i < 4; i++)
		v[i] = i;

	TVector<int> v1(4);
	for (int i = 0; i < 4; i++)
		v1[i] = i;

	TVector<int> res = v + v1;

	TVector<int> exp(4);
	exp[0] = 0;
	exp[1] = 2;
	exp[2] = 4;
	exp[3] = 6;

	EXPECT_EQ(exp, res);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	TVector<int> v(4);
	TVector<int> v1(5);

	EXPECT_ANY_THROW(v + v1);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	TVector<int> v(4);
	for (int i = 0; i < 4; i++)
		v[i] = i;

	TVector<int> v1(4);
	for (int i = 0; i < 4; i++)
		v1[i] = i;

	TVector<int> res = v - v1;

	TVector<int> exp(4);
	exp[0] = 0;
	exp[1] = 0;
	exp[2] = 0;
	exp[3] = 0;

	EXPECT_EQ(exp, res);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	TVector<int> v(4);
	TVector<int> v1(5);

	EXPECT_ANY_THROW(v - v1);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	TVector<int> v(4);
	for (int i = 0; i < 4; i++)
		v[i] = i;

	TVector<int> v1(4);
	for (int i = 0; i < 4; i++)
		v1[i] = i;

	int res = v * v1;

	EXPECT_EQ(14, res);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	TVector<int> v(4);
	TVector<int> v1(5);

	EXPECT_ANY_THROW(v * v1);
}

