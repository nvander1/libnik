#include "memory.hpp"

#include <gtest/gtest.h>

#include <algorithm>
#include <functional>
#include <iostream>
#include <memory>

struct Object {
  Object() : value{100} {}
  Object(int value) : value{value} {}
  int value;
};

bool operator==(const Object& lhs, const Object& rhs) {
  return lhs.value == rhs.value;
}

struct Child : Object {};

TEST(observer_ptr, constructors) {
  {
    nik::observer_ptr<Object> ptr{};
    ASSERT_EQ(nullptr, ptr.get());
  }

  {
    nik::observer_ptr<Object> ptr{nullptr};
    ASSERT_EQ(nullptr, ptr.get());
  }

  auto obj_ptr = std::make_unique<Object>();

  {
    nik::observer_ptr<Object> watched{obj_ptr.get()};
    ASSERT_EQ(obj_ptr.get(), watched.get());
  }

  auto child_ptr = std::make_unique<Child>();

  {
    nik::observer_ptr<Child> watched_child{child_ptr.get()};
    nik::observer_ptr<Object> watched_upcast{watched_child};
    ASSERT_EQ(watched_upcast.get(), watched_child.get());
  }
}

TEST(observer_ptr, release) {
  auto owner = std::make_unique<Object>();
  auto watched = nik::make_observer<Object>(owner.get());
  auto released = watched.release();

  ASSERT_EQ(released, owner.get());
  ASSERT_EQ(nullptr, watched.get());
}

TEST(observer_ptr, reset) {
  auto owner = std::make_unique<Object>();
  auto watched = nik::make_observer<Object>(nullptr);

  watched.reset(owner.get());
  ASSERT_EQ(watched.get(), owner.get());
}

TEST(observer_ptr, swap) {
  auto owner = std::make_unique<Object>();
  auto watched1 = nik::make_observer<Object>(owner.get());
  auto watched2 = nik::make_observer<Object>(nullptr);

  watched1.swap(watched2);

  ASSERT_EQ(nullptr, watched1.get());
  ASSERT_EQ(owner.get(), watched2.get());
}

TEST(observer_ptr, bool_conversion) {
  auto owner = std::make_unique<Object>();
  auto watched = nik::make_observer<Object>(nullptr);

  ASSERT_FALSE(static_cast<bool>(watched));

  watched.reset(owner.get());
  ASSERT_TRUE(static_cast<bool>(watched));
}

TEST(observer_ptr, dereference) {
  auto owner = std::make_unique<Object>();
  auto watched = nik::make_observer<Object>(owner.get());

  ASSERT_EQ(*watched, *(watched.get()));

  ASSERT_EQ(watched->value, watched.get()->value);
}

TEST(observer_ptr, pointer_conversion) {
  auto owner = std::make_unique<Object>();
  auto watched = nik::make_observer<Object>(owner.get());

  ASSERT_EQ(static_cast<Object*>(watched), watched.get());
}

TEST(observer_ptr, make_observer) {
  {
    auto owner = std::make_unique<Object>();
    auto watched = nik::make_observer<Object>(owner.get());
    ASSERT_EQ(watched.get(), owner.get());
  }

  {
    auto watched = nik::make_observer<Object>(nullptr);
    ASSERT_EQ(nullptr, watched.get());
  }
}

TEST(observer_ptr, relational_operators) {
  Child* array = new Child[5];
  auto front = nik::make_observer<Child>(array);
  auto front2 = nik::make_observer<Child>(array);
  auto mid = nik::make_observer<Child>(&array[2]);

  ASSERT_TRUE(front == front2);
  ASSERT_TRUE(front != mid);
  ASSERT_FALSE(front == nullptr);
  ASSERT_FALSE(nullptr == front);
  ASSERT_TRUE(front != nullptr);
  ASSERT_TRUE(nullptr != front);
  ASSERT_TRUE(front < mid);
  ASSERT_TRUE(mid > front);
  ASSERT_TRUE(front <= mid);
  ASSERT_TRUE(front <= front2);
  ASSERT_TRUE(mid >= front);
  ASSERT_TRUE(front >= front2);

  delete[] array;
}

TEST(observer_ptr, stl_swap) {
  auto owner = std::make_unique<Object>();
  auto watched1 = nik::make_observer<Object>(owner.get());
  auto watched2 = nik::make_observer<Object>(nullptr);

  std::swap(watched1, watched2);

  ASSERT_EQ(nullptr, watched1.get());
  ASSERT_EQ(owner.get(), watched2.get());
}

TEST(observer_ptr, stl_hash) {
  auto owner = std::make_unique<Object>();
  auto watched = nik::make_observer<Object>(owner.get());

  ASSERT_EQ(std::hash<nik::observer_ptr<Object>>()(watched),
            std::hash<Object*>()(watched.get()));
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
