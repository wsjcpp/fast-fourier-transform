#include "unit_test_fft_wiki.h"
#include <vector>
#include <wsjcpp_core.h>
#include <fast_fourier_transform_wiki.h>
#include <math.h>

REGISTRY_WSJCPP_UNIT_TEST(UnitTestFftWiki)

UnitTestFftWiki::UnitTestFftWiki()
    : WsjcppUnitTestBase("UnitTestFftWiki") {
}

// ---------------------------------------------------------------------

bool UnitTestFftWiki::doBeforeTest() {
    // nothing
    return true;
}

// ---------------------------------------------------------------------

void UnitTestFftWiki::executeTest() {

    int nCount = 64;
    double *pSignal = new double[nCount];
    double *pFFT = new double[nCount];
    for (int i = 0; i < nCount; i++) {
        if (i < nCount / 4) {
            pSignal[i] = 0.5;
        } else if (i >= nCount / 4 && i < nCount / 2) {
            pSignal[i] = -0.5;
        } else if (i >= nCount / 2 && i < 3 * nCount / 4) {
            pSignal[i] = 0.5;
        } else if (i >= 3 * nCount / 4) {
            pSignal[i] = -0.5;
        }
        // WsjcppLog::info(TAG, "s[" + std::to_string(i) + "]" + std::to_string(pSignal[i]));
        pFFT[i] = 0;
    }
    FastFourierTransformWiki fft;
    long t0 = WsjcppCore::getCurrentTimeInMilliseconds();
    fft.analitics(pSignal, pFFT, nCount, nCount);
    long t1 = WsjcppCore::getCurrentTimeInMilliseconds();
    WsjcppLog::info(TAG, "Calculation time: " + std::to_string(t1-t0) + " ms");
    
    float *pOffsetSin = new float[nCount/2];
    float *pAmplitSin = new float[nCount/2];
    int n_floor = 10000000;
    for (int i = 0; i < nCount/2; i++) {
        int n = pFFT[i*2] * n_floor;
        pOffsetSin[i] = float(n)/n_floor;
    }
    for (int i = 0; i < nCount/2; i++) {
        int n = pFFT[i*2 + 1] * n_floor;
        pAmplitSin[i] = float(n)/n_floor;
    }
    for (int i = 0; i < nCount/2; i++) {
        compare("pOffsetSin[" + std::to_string(i) + "]", pOffsetSin[i], 0.0);
    }

    for (int i = 0; i < nCount/4; i++) {
        compare("pAmplitSin[" + std::to_string(i) + "]", pAmplitSin[i*2 + 1], 0.0);
    }
    std::vector<std::string> vAmpl;
    vAmpl.push_back("0.637644");
    vAmpl.push_back("0.000000");
    vAmpl.push_back("0.215306");
    vAmpl.push_back("0.000000");
    vAmpl.push_back("0.132585");
    vAmpl.push_back("0.000000");
    vAmpl.push_back("0.098519");
    vAmpl.push_back("0.000000");
    vAmpl.push_back("0.080853");
    vAmpl.push_back("0.000000");
    vAmpl.push_back("0.070868");
    vAmpl.push_back("0.000000");
    vAmpl.push_back("0.065312");
    vAmpl.push_back("0.000000");
    vAmpl.push_back("0.062802");
    vAmpl.push_back("0.000000");
    vAmpl.push_back("0.062802");
    vAmpl.push_back("0.000000");
    vAmpl.push_back("0.065312");
    vAmpl.push_back("0.000000");
    vAmpl.push_back("0.070868");
    vAmpl.push_back("0.000000");
    vAmpl.push_back("0.080853");
    vAmpl.push_back("0.000000");
    vAmpl.push_back("0.098519");
    vAmpl.push_back("0.000000");
    vAmpl.push_back("0.132585");
    vAmpl.push_back("0.000000");
    vAmpl.push_back("0.215306");
    vAmpl.push_back("0.000000");
    vAmpl.push_back("0.637644");
    vAmpl.push_back("0.000000");
    
    for (int i = 0; i < nCount/2; i++) {
        compare("pAmplitSin[" + std::to_string(i) + "]", std::to_string(pAmplitSin[i]), vAmpl[i]);
    }

    /*
    std::string sToLog = "\n";
    for (int i = 0; i < nCount/2; i++) {
        sToLog +=
            "Harmonic " + std::to_string(i) + ": "
            + std::to_string(pAmplitSin[i])
            + " *  sin(t + " + std::to_string(pOffsetSin[i]) + ")\n";
    }
    WsjcppLog::info(TAG, sToLog);
    */
}

// ---------------------------------------------------------------------

bool UnitTestFftWiki::doAfterTest() {
    // nothing
    return true;
}
