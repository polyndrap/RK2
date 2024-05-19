// ===========================================================================
// PluggableAdapterDesign.cpp // Adapter Pattern 
// Pluggable Adapter Design Pattern using Modern C++
// ===========================================================================

#include <iostream>
#include <string>
#include <functional>
#include <memory>

namespace PluggableAdapterDesignApproach {

    // =======================================================================
    // Legacy code

    class IBeverage
    {
    public:
        virtual void getBeverage() = 0;
    };

    class CoffeeMaker : public IBeverage
    {
    public:
        void brew() { 
            std::cout << "brewing coffee" << std::endl;
        }

        virtual void getBeverage() override {
            brew(); 
        }
    };

    // Interface already shipped & known to client
    static void makeDrink(IBeverage& drink) {
        drink.getBeverage();             
    }

    // =======================================================================
    // New source code (developed later)

    class JuiceMaker 
    {
    public:
        void squeeze() {
            std::cout << "making Juice" << std::endl;
        }
    };

    // making things compatible - using 'class adapter' strategy
    class BeverageAdapter : public IBeverage
    {   
    private:
        std::function<void()> m_request;

    public:
        // c'tors
        BeverageAdapter(CoffeeMaker* cm)
            : m_request{ [&] () -> void { cm->brew(); } }
        {}

        BeverageAdapter(JuiceMaker* jm)
            : m_request{ [&] () -> void { jm->squeeze(); } }
        {}

        virtual void getBeverage() override { 
            m_request();
        }
    };

    // =======================================================================
    // Another new source code, also developed later

    template <typename T>
    class JuiceAdapter : public IBeverage
    {
    private:
        std::function<void()> m_request;
        std::unique_ptr<T> m_juiceMaker;

    public:
        // c'tors
        JuiceAdapter(T* juiceMaker) 
            : m_juiceMaker{ juiceMaker }
        {
            m_request = [this] { m_juiceMaker->squeeze(); };
        }

        virtual void getBeverage() override {
            m_request();
        }
    };
}

// ===========================================================================

static void test_pluggable_adapter_design_01()
{
    using namespace PluggableAdapterDesignApproach;

    CoffeeMaker coffeeMaker;
    
    BeverageAdapter adapter1{ &coffeeMaker };

    makeDrink(adapter1);

    JuiceMaker juiceMaker;

    BeverageAdapter adapter2{ &juiceMaker };

    makeDrink(adapter2);
}

static void test_pluggable_adapter_design_02()
{
    using namespace PluggableAdapterDesignApproach;

    JuiceMaker juiceMaker;

    JuiceAdapter<JuiceMaker> adapter{
        &juiceMaker 
    };

    makeDrink(adapter);
}

void test_pluggable_adapter_design()
{
    test_pluggable_adapter_design_01();
    test_pluggable_adapter_design_02();
}

// ===========================================================================
// End-of-File
// ===========================================================================
