#define private public

#include "App.hpp"
#include "catch2/catch_test_macros.hpp"

class TestFixture
{
  public:
    TestFixture() : _app(App::getInstance()) {}

  protected:
    App& _app;
};

TEST_CASE_METHOD(TestFixture, "App::init", "[app]")
{
    REQUIRE(_app._engine != nullptr);
    REQUIRE(_app._menu == nullptr);

    REQUIRE(_app.engine() != nullptr);
}

TEST_CASE_METHOD(TestFixture, "App::configInvalid", "[app]")
{
    SECTION("no menu") { REQUIRE_THROWS(_app.initConfig("test.cfg")); }
    SECTION("file name")
    {
        _app.initMenu();
        REQUIRE_THROWS(_app.initConfig("wrong.cfg"));
    }
}

TEST_CASE_METHOD(TestFixture, "App::config", "[app]")
{
    _app.initMenu();
    REQUIRE_NOTHROW(_app.initConfig("test.cfg"));
    REQUIRE(_app._config != nullptr);
}
