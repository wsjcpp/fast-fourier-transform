# fast-fourier-transform

[![Build Status](https://api.travis-ci.com/wsjcpp/fast-fourier-transform.svg?branch=master)](https://travis-ci.com/wsjcpp/fast-fourier-transform) [![Github Stars](https://img.shields.io/github/stars/wsjcpp/fast-fourier-transform.svg?label=github%20%E2%98%85)](https://github.com/wsjcpp/fast-fourier-transform) [![Github Stars](https://img.shields.io/github/contributors/wsjcpp/fast-fourier-transform.svg)](https://github.com/wsjcpp/fast-fourier-transform) [![Github Forks](https://img.shields.io/github/forks/wsjcpp/fast-fourier-transform.svg?label=github%20forks)](https://github.com/wsjcpp/wsjcpp/network/members) [![Total alerts](https://img.shields.io/lgtm/alerts/g/wsjcpp/fast-fourier-transform.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/wsjcpp/fast-fourier-transform/alerts/) [![Language grade: C/C++](https://img.shields.io/lgtm/grade/cpp/g/wsjcpp/fast-fourier-transform.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/wsjcpp/fast-fourier-transform/context:cpp)

C++ fast-fourier-transform (package for wsjcpp)

## Integrate to your project

via wsjcpp:

```
$ wsjcpp install https://github.com/wsjcpp/fast-fourier-transform:master
```

or include this files:

* src.wsjcpp/wsjcpp_core.h
* src.wsjcpp/wsjcpp_core.cpp
* src/fast_fourier_transform_wiki.h
* src/fast_fourier_transform_wiki.cpp

## How to use

``` cpp
int nCount = 64;
double *pSignal = new double[nCount];
double *pFFT = new double[nCount];

// Fill here pSignal and reset values

for (int i = 0; i < nCount; i++) {
    pFFT[i] = 0;
}

FastFourierTransformWiki fft;
long t0 = WsjcppCore::getCurrentTimeInMilliseconds();
fft.analitics(pSignal, pFFT, nCount, nCount);
long t1 = WsjcppCore::getCurrentTimeInMilliseconds();
WsjcppLog::info(TAG, "Calculation time: " + std::to_string(t1-t0) + " ms");

// Now values of fft will be in array: pFFT

// for example get 2 diff arrays 
std::vector<float> vOffsetSin; // first attr of harmonic
std::vector<float> vAmplitudeSin; // second attr of harmonic

for (int i = 0; i < nCount/2; i++) {
    vOffsetSin.push_back(pFFT[i*2]);
    vAmplitudeSin.push_back(pFFT[i*2 + 1]);
}

```