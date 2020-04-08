#ifndef FAST_FOURIER_TRANSFORM_WIKI_H
#define FAST_FOURIER_TRANSFORM_WIKI_H

#include <string>

class FastFourierTransformWiki {
    public:
        FastFourierTransformWiki();
        void analitics(double *AVal, double *FTvl, int Nvl, int Nft);

    private:
        std::string TAG;
};

#endif // FAST_FOURIER_TRANSFORM_WIKI_H