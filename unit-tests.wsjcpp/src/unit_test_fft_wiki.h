#ifndef UNIT_TEST_FFT_WIKI_H
#define UNIT_TEST_FFT_WIKI_H

#include <wsjcpp_unit_tests.h>

class UnitTestFftWiki : public WsjcppUnitTestBase {
    public:
        UnitTestFftWiki();
        virtual bool doBeforeTest() override;
        virtual void executeTest() override;
        virtual bool doAfterTest() override;
};

#endif // UNIT_TEST_FFT_WIKI_H

