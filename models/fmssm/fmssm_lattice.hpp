#ifndef fmssm_lattice_hpp
#define fmssm_lattice_hpp


#include "fmssm.hpp"
#include "lattice_solver.hpp"

class Lattice;

template<>
class Fmssm<Lattice>: public Lattice_model {
public:
    Fmssm();
    virtual ~Fmssm() {}
    virtual void calculate_spectrum();
    virtual std::string name() const { return "FMSSM"; }
    virtual void print(std::ostream& s) const;

    Real dx(const Real a, const Real *x, size_t i) const;
    void ddx(const Real a, const Real *x, size_t i, Real *ddx) const;

    struct Translator : public RGFlow<Lattice>::Translator {
	Translator(RGFlow<Lattice> *f, size_t T, size_t m) :
	    RGFlow<Lattice>::Translator::Translator(f, T, m) {}
	#include "fmssm_lattice_translator.inc"
    };

    Translator operator()(size_t m) const { return Translator(f, T, m); }
};


#endif // fmssm_lattice_hpp
