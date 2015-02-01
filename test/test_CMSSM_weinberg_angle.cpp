#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE test_weinberg_angle

#include <boost/test/unit_test.hpp>

#include "conversion.hpp"
#include "softsusy.h"
#include "CMSSM_two_scale_model.hpp"
#include "test_CMSSM.hpp"

#define private public

#include "weinberg_angle.hpp"

using namespace flexiblesusy;
using namespace weinberg_angle;

BOOST_AUTO_TEST_CASE( test_rho_2 )
{
   Weinberg_angle wein;
   double r;

   r = 0.1;
   BOOST_CHECK_CLOSE_FRACTION(rho2(r), wein.rho_2(r), 1.0e-10);

   r = 1.8;
   BOOST_CHECK_CLOSE_FRACTION(rho2(r), wein.rho_2(r), 1.0e-10);

   r = 1.9;
   BOOST_CHECK_CLOSE_FRACTION(rho2(r), wein.rho_2(r), 1.0e-10);

   r = 2.0;
   BOOST_CHECK_CLOSE_FRACTION(rho2(r), wein.rho_2(r), 1.0e-10);

   r = 2.1;
   BOOST_CHECK_CLOSE_FRACTION(rho2(r), wein.rho_2(r), 1.0e-10);
}

BOOST_AUTO_TEST_CASE( test_delta_vb )
{
   CMSSM<Two_scale> fs;
   MssmSoftsusy ss;
   CMSSM_input_parameters input;
   input.m0 = 125.;
   input.m12 = 500.;
   input.TanBeta = 10.;
   input.SignMu = 1;
   input.Azero = 0.;

   setup_CMSSM_const(fs, ss, input);

   const double scale = ss.displayMu();
   const double mw_pole = ss.displayMw();
   const double mz_pole = ss.displayMz();

   BOOST_REQUIRE(mw_pole > 0.);
   BOOST_REQUIRE(mz_pole > 0.);
   BOOST_CHECK_EQUAL(scale, mz_pole);

   double outrho = 1.0, outsin = 0.48;
   const double alphaMsbar = ss.displayDataSet().displayAlpha(ALPHA);
   const double alphaDrbar = ss.qedSusythresh(alphaMsbar, scale);

   const double ss_delta_vb =
      ss.deltaVb(outrho, outsin, alphaDrbar, 0. /* ignored */);

   Weinberg_angle weinberg;

   const double gY          = ss.displayGaugeCoupling(1) * sqrt(0.6);
   const double g2          = ss.displayGaugeCoupling(2);
   const double hmu         = ss.displayYukawaElement(YE, 2, 2);
   const double mselL       = ss.displayDrBarPars().me(1, 1);
   const double msmuL       = ss.displayDrBarPars().me(1, 2);
   const double msnue       = ss.displayDrBarPars().msnu(1);
   const double msnumu      = ss.displayDrBarPars().msnu(2);
   const Eigen::ArrayXd mneut = ToEigenArray(ss.displayDrBarPars().mnBpmz);
   const Eigen::MatrixXcd n   = ToEigenMatrix(ss.displayDrBarPars().nBpmz);
   const Eigen::ArrayXd mch   = ToEigenArray(ss.displayDrBarPars().mchBpmz);
   const Eigen::MatrixXcd u   = ToEigenMatrix(ss.displayDrBarPars().uBpmz);
   const Eigen::MatrixXcd v   = ToEigenMatrix(ss.displayDrBarPars().vBpmz);

   const auto MSe(fs.get_MSe());
   const auto ZE(fs.get_ZE());
   const auto MSv(fs.get_MSv());
   const auto ZV(fs.get_ZV());

   const double fs_gY          = fs.get_g1() * sqrt(0.6);
   const double fs_g2          = fs.get_g2();
   const double fs_hmu         = fs.get_Ye(1,1);
   double fs_mselL             = 0.;
   double fs_msmuL             = 0.;
   double fs_msnue             = 0.;
   double fs_msnumu            = 0.;
   const Eigen::ArrayXd fs_mneut = fs.get_MChi();
   const Eigen::MatrixXcd fs_n   = fs.get_ZN();
   const Eigen::ArrayXd fs_mch   = fs.get_MCha();
   const Eigen::MatrixXcd fs_u   = fs.get_UM();
   const Eigen::MatrixXcd fs_v   = fs.get_UP();

   for (int i = 0; i < 6; i++) {
      fs_mselL += AbsSqr(ZE(i,0))*MSe(i);
      fs_msmuL += AbsSqr(ZE(i,1))*MSe(i);
   }

   for (int i = 0; i < 3; i++) {
      fs_msnue  += AbsSqr(ZV(i,0))*MSv(i);
      fs_msnumu += AbsSqr(ZV(i,1))*MSv(i);
   }

   BOOST_CHECK_CLOSE_FRACTION(fs_mselL , mselL , 1.0e-10);
   BOOST_CHECK_CLOSE_FRACTION(fs_msmuL , msmuL , 1.0e-10);
   BOOST_CHECK_CLOSE_FRACTION(fs_msnue , msnue , 1.0e-10);
   BOOST_CHECK_CLOSE_FRACTION(fs_msnumu, msnumu, 1.0e-10);

   // test with SoftSusy parameters
   double fs_delta_vb =
      weinberg.calculate_delta_vb(
         scale,
         outrho,
         outsin,
         mw_pole,
         mz_pole,
         alphaDrbar,
         gY,                 // displayGaugeCoupling(1) * sqrt(0.6)
         g2,                 // displayGaugeCoupling(2)
         hmu,                // = displayYukawaElement(YE, 2, 2)
         mselL,              // tree.me(1, 1)
         msmuL,              // tree.me(1, 2)
         msnue,              // tree.msnu(1)
         msnumu,             // tree.msnu(2)
         mneut,              // tree.mnBpmz
         n,                  // tree.nBpmz
         mch,                // tree.mchBpmz
         u,                  // tree.uBpmz
         v                   // tree.vBpmz
      );

   BOOST_CHECK_CLOSE_FRACTION(ss_delta_vb, fs_delta_vb, 1.0e-10);

   // test with FlexibleSUSY CMSSM parameters
   fs_delta_vb =
      weinberg.calculate_delta_vb(
         scale,
         outrho,
         outsin,
         mw_pole,
         mz_pole,
         alphaDrbar,
         fs_gY,                 // displayGaugeCoupling(1) * sqrt(0.6)
         fs_g2,                 // displayGaugeCoupling(2)
         fs_hmu,                // = displayYukawaElement(YE, 2, 2)
         fs_mselL,              // tree.me(1, 1)
         fs_msmuL,              // tree.me(1, 2)
         fs_msnue,              // tree.msnu(1)
         fs_msnumu,             // tree.msnu(2)
         fs_mneut,              // tree.mnBpmz
         fs_n,                  // tree.nBpmz
         fs_mch,                // tree.mchBpmz
         fs_u,                  // tree.uBpmz
         fs_v                   // tree.vBpmz
      );

   BOOST_CHECK_CLOSE_FRACTION(ss_delta_vb, fs_delta_vb, 1.0e-8);
}

BOOST_AUTO_TEST_CASE( test_delta_r )
{
   CMSSM<Two_scale> fs;
   MssmSoftsusy ss;
   CMSSM_input_parameters input;
   input.m0 = 125.;
   input.m12 = 500.;
   input.TanBeta = 10.;
   input.SignMu = 1;
   input.Azero = 0.;

   setup_CMSSM_const(fs, ss, input);

   const double scale = ss.displayMu();
   const double mw_pole = ss.displayMw();
   const double mz_pole = ss.displayMz();

   BOOST_REQUIRE(mw_pole > 0.);
   BOOST_REQUIRE(mz_pole > 0.);
   BOOST_CHECK_EQUAL(scale, mz_pole);

   double outrho = 1.0, outsin = 0.48;
   const double alphaMsbar = ss.displayDataSet().displayAlpha(ALPHA);
   const double alphaDrbar = ss.qedSusythresh(alphaMsbar, scale);
   const double pizztMZ    = ss.piZZT(mz_pole, scale, true);
   const double piwwt0     = ss.piWWT(0., scale, true);
   const double gfermi     = Electroweak_constants::gfermi;
   softsusy::GMU = gfermi;

   const double ss_delta_r =
      ss.dR(outrho, outsin, alphaDrbar, pizztMZ, piwwt0);

   Weinberg_angle weinberg;

   const double gY          = ss.displayGaugeCoupling(1) * sqrt(0.6);
   const double g2          = ss.displayGaugeCoupling(2);
   const double hmu         = ss.displayYukawaElement(YE, 2, 2);
   const double mselL       = ss.displayDrBarPars().me(1, 1);
   const double msmuL       = ss.displayDrBarPars().me(1, 2);
   const double msnue       = ss.displayDrBarPars().msnu(1);
   const double msnumu      = ss.displayDrBarPars().msnu(2);
   const Eigen::ArrayXd mneut = ToEigenArray(ss.displayDrBarPars().mnBpmz);
   const Eigen::MatrixXcd n   = ToEigenMatrix(ss.displayDrBarPars().nBpmz);
   const Eigen::ArrayXd mch   = ToEigenArray(ss.displayDrBarPars().mchBpmz);
   const Eigen::MatrixXcd u   = ToEigenMatrix(ss.displayDrBarPars().uBpmz);
   const Eigen::MatrixXcd v   = ToEigenMatrix(ss.displayDrBarPars().vBpmz);
   const double mt          = ss.displayDataSet().displayPoleMt();
   const double g3          = ss.displayGaugeCoupling(3);
   const double tanBeta     = ss.displayTanb();
   const double mh          = ss.displayDrBarPars().mh0(1);
   const double alpha       = ss.h1s2Mix();

   const auto MSe(fs.get_MSe());
   const auto ZE(fs.get_ZE());
   const auto MSv(fs.get_MSv());
   const auto ZV(fs.get_ZV());

   const double fs_gY          = fs.get_g1() * sqrt(0.6);
   const double fs_g2          = fs.get_g2();
   const double fs_hmu         = fs.get_Ye(1,1);
   double fs_mselL             = 0.;
   double fs_msmuL             = 0.;
   double fs_msnue             = 0.;
   double fs_msnumu            = 0.;
   const Eigen::ArrayXd fs_mneut = fs.get_MChi();
   const Eigen::MatrixXcd fs_n   = fs.get_ZN();
   const Eigen::ArrayXd fs_mch   = fs.get_MCha();
   const Eigen::MatrixXcd fs_u   = fs.get_UM();
   const Eigen::MatrixXcd fs_v   = fs.get_UP();
   const double fs_mt          = ss.displayDataSet().displayPoleMt();
   const double fs_g3          = fs.get_g3();
   const double fs_tanBeta     = fs.get_vu() / fs.get_vd();
   const double fs_mh          = fs.get_Mhh(0);
   const double fs_alpha       = fs.get_ZH(0,1);

   for (int i = 0; i < 6; i++) {
      fs_mselL += AbsSqr(ZE(i,0))*MSe(i);
      fs_msmuL += AbsSqr(ZE(i,1))*MSe(i);
   }

   for (int i = 0; i < 3; i++) {
      fs_msnue  += AbsSqr(ZV(i,0))*MSv(i);
      fs_msnumu += AbsSqr(ZV(i,1))*MSv(i);
   }

   BOOST_CHECK_CLOSE_FRACTION(fs_mselL , mselL , 1.0e-10);
   BOOST_CHECK_CLOSE_FRACTION(fs_msmuL , msmuL , 1.0e-10);
   BOOST_CHECK_CLOSE_FRACTION(fs_msnue , msnue , 1.0e-10);
   BOOST_CHECK_CLOSE_FRACTION(fs_msnumu, msnumu, 1.0e-10);

   BOOST_CHECK_CLOSE_FRACTION(fs_mt, mt, 1.0e-10);
   BOOST_CHECK_CLOSE_FRACTION(fs_g3, g3, 1.0e-10);
   BOOST_CHECK_CLOSE_FRACTION(fs_tanBeta, tanBeta, 1.0e-10);
   BOOST_CHECK_CLOSE_FRACTION(fs_mh, mh, 1.0e-10);
   BOOST_CHECK_CLOSE_FRACTION(fs_alpha, alpha, 1.0e-10);

   // test with SoftSusy parameters
   double fs_delta_r =
      weinberg.calculate_delta_r(
         scale,
         outrho,
         outsin,
         mw_pole,
         mz_pole,
         alphaDrbar,
         gY,                 // displayGaugeCoupling(1) * sqrt(0.6)
         g2,                 // displayGaugeCoupling(2)
         hmu,                // = displayYukawaElement(YE, 2, 2)
         mselL,              // tree.me(1, 1)
         msmuL,              // tree.me(1, 2)
         msnue,              // tree.msnu(1)
         msnumu,             // tree.msnu(2)
         mneut,              // tree.mnBpmz
         n,                  // tree.nBpmz
         mch,                // tree.mchBpmz
         u,                  // tree.uBpmz
         v,                  // tree.vBpmz
         pizztMZ,
         piwwt0,
         mt,
         gfermi,
         g3,                 // displayGaugeCoupling(3)
         tanBeta,
         mh,
         alpha
      );

   BOOST_CHECK_CLOSE_FRACTION(ss_delta_r, fs_delta_r, 1.0e-10);

   // test with FlexibleSUSY CMSSM parameters
   fs_delta_r =
      weinberg.calculate_delta_r(
         scale,
         outrho,
         outsin,
         mw_pole,
         mz_pole,
         alphaDrbar,
         fs_gY,                 // displayGaugeCoupling(1) * sqrt(0.6)
         fs_g2,                 // displayGaugeCoupling(2)
         fs_hmu,                // = displayYukawaElement(YE, 2, 2)
         fs_mselL,              // tree.me(1, 1)
         fs_msmuL,              // tree.me(1, 2)
         fs_msnue,              // tree.msnu(1)
         fs_msnumu,             // tree.msnu(2)
         fs_mneut,              // tree.mnBpmz
         fs_n,                  // tree.nBpmz
         fs_mch,                // tree.mchBpmz
         fs_u,                  // tree.uBpmz
         fs_v,                  // tree.vBpmz
         pizztMZ,
         piwwt0,
         fs_mt,
         gfermi,
         fs_g3,                 // displayGaugeCoupling(3)
         fs_tanBeta,
         fs_mh,
         fs_alpha
      );

   BOOST_CHECK_CLOSE_FRACTION(ss_delta_r, fs_delta_r, 1.0e-8);
}

BOOST_AUTO_TEST_CASE( test_rho_sinTheta )
{
   CMSSM<Two_scale> fs;
   MssmSoftsusy ss;
   CMSSM_input_parameters input;
   input.m0 = 125.;
   input.m12 = 500.;
   input.TanBeta = 10.;
   input.SignMu = 1;
   input.Azero = 0.;

   setup_CMSSM_const(fs, ss, input);

   const double scale = ss.displayMu();
   const double mw_pole = ss.displayMw();
   const double mz_pole = ss.displayMz();

   BOOST_REQUIRE(mw_pole > 0.);
   BOOST_REQUIRE(mz_pole > 0.);
   BOOST_CHECK_EQUAL(scale, mz_pole);

   double outrho = 1.0, outsin = 0.48;
   const double tol = 1.0e-8;
   const int maxTries = 20;
   const double gfermi = Electroweak_constants::gfermi;
   const double pizztMZ = ss.piZZT(mz_pole, scale, true);
   const double piwwt0  = ss.piWWT(0., scale, true);
   const double piwwtMW = ss.piWWT(mw_pole, scale, true);
   const double alphaMsbar = ss.displayDataSet().displayAlpha(ALPHA);
   const double alphaDrbar = ss.qedSusythresh(alphaMsbar, scale);

   softsusy::GMU = gfermi;

   ss.rhohat(outrho, outsin, alphaDrbar, pizztMZ, piwwt0, piwwtMW,
             tol, maxTries);

   Weinberg_angle weinberg;

   weinberg.set_number_of_iterations(maxTries);
   weinberg.set_precision_goal(tol);
   weinberg.set_alpha_em_drbar(alphaDrbar);
   weinberg.set_fermi_contant(gfermi);
   weinberg.set_self_energy_z_at_mz(pizztMZ);
   weinberg.set_self_energy_z_at_0(piwwt0);
   weinberg.set_self_energy_w_at_mw(piwwtMW);

   const double fs_sintheta = weinberg.calculate();
   const double fs_rhohat   = weinberg.get_rho_hat();

   BOOST_CHECK_CLOSE_FRACTION(outsin, fs_sintheta, 1.0e-10);
   BOOST_CHECK_CLOSE_FRACTION(outrho, fs_rhohat  , 1.0e-10);
}
