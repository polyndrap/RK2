#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <gtest/gtest.h>
#include "Program.cpp"
#include "ConceptualExample.cpp"
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

  clientCode(target);
  clientCode(adapter);

  ASSERT_OUTPUT(
      "Target: The target's default behavior.nn"
      "Client: I can work fine with the Target objectn"
      "Adaptee: .eetpadA eht fo roivaheb laicepSnn"
      "Client: The Adaptee class has an incompatible interface:n"
      "Client: But I can work with the Adaptee via the Adapter:n"
      "Adapter: (TRANSLATED) .eetpadA eht fo roivaheb laicepSn"
  );
}


// ===========================================================================
// End-of-File
// ===========================================================================
