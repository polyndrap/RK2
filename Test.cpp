#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <gtest/gtest.h>
#include "MediaPlayer01.cpp"
#include "MediaPlayer02.cpp"
#include "ConceptualExample.cpp"
#include "PluggableAdapterDesign.cpp"
//#include <crtdbg.h>

TEST(ConceptualExample, TestConceptualExample01) {
  auto adaptee = std::make_shared<Adaptee>();
  auto adapter = std::make_shared<Adapter>(adaptee);

  ASSERT_EQ(
      adapter->getRequest(),
      "Adapter: (TRANSLATED) .eetpadA eht fo roivaheb laicepS"
  );
}

TEST(ConceptualExample, TestConceptualExample02) {
  auto target = std::make_shared<Target>();
  ASSERT_EQ(target->getRequest(), "Target: The target's default behavior.");

  auto adaptee = std::make_shared<Adaptee>();
  ASSERT_EQ(adaptee->getSpecificRequest(), ".eetpadA eht fo roivaheb laicepS");

  auto adapter = std::make_shared<Adapter>(adaptee);
  ASSERT_EQ(
      adapter->getRequest(),
      "Adapter: (TRANSLATED) .eetpadA eht fo roivaheb laicepS"
  );
}

TEST(ConceptualExample, TestClientCode) {
    auto target = std::make_shared<Target>();
    auto adaptee = std::make_shared<Adaptee>();
    auto adapter = std::make_shared<Adapter>(adaptee);

    testing::internal::CaptureStdout();

    clientCode(target);
    clientCode(adapter);

    std::string output = testing::internal::GetCapturedStdout();

    std::string expectedOutput =
        "Target: The target's default behavior.\n"
        "Client: I can work fine with the Target object\n"
        "Client: The Adaptee class has an incompatible interface:\n"
        "Client: But I can work with the Adaptee via the Adapter:\n"
        "Adapter: (TRANSLATED) .eetpadA eht fo roivaheb laicepS\n";

    ASSERT_EQ(output, expectedOutput);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


// ===========================================================================
// End-of-File
// ===========================================================================
