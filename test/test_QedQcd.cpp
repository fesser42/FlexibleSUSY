#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE test_QedQcd

#include <boost/test/unit_test.hpp>

#include "lowe.h"
#include "lowe_legacy.h"

using namespace flexiblesusy;
using namespace softsusy;

BOOST_AUTO_TEST_CASE( test_QedQcd_to )
{
   QedQcd q1;
   QedQcd_legacy q2;

   q1.to(91.);
   q2.to(91.);

   BOOST_CHECK(q1.display() == q2.display());
}

BOOST_AUTO_TEST_CASE( test_QedQcd_toMz )
{
   QedQcd q1;
   QedQcd_legacy q2;

   q1.toMz();
   q2.toMz();

   BOOST_CHECK(q1.display() == q2.display());
}
