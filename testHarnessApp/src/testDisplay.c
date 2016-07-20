#include <registryFunction.h>
#include <epicsExport.h>
#include <subRecord.h>
#include <genSubRecord.h>

#include "slalib.h"
// #include "tcsConstants.h"

#if 1
#include <math.h>

#include "slalib.h"


#define D90    (M_PI/2.0)                  /* 90 degrees in radians */
#define D2R    (M_PI/180.0)                /* Degrees to radians */
#define R2D    (90.0/M_PI)                 /* Radians to degrees */

#endif

/*+
 *   Function name:
 *   testDisplayAirmass
 *
 *   Purpose:
 *   Produce airmass and zenith distance for potential display
 *
 *   Description:
 *   The routine pulls in the current mount azimuth and elevation. The azimuth
 *   is simply converted to degrees. The elevation is converted to a 
 *   zenith distance and this is used to compute the current relative 
 *   airmass.
 *
 *   Epics inputs:
 *
 *   a => current mount azimuth (degs)
 *   b => current mount elevation (degs)
 *
 *   Epics outputs:
 *
 *   vala => current mount azimuth (degs)
 *   valb => current mount zenith distance (degs)
 *   valc => current airmass
 *
 *   Invocation:
 *   testDisplayAirmass (pgsub)
 *
 *   Parameters: (">" input, "!" modified, "<" output)  
 *      (!)   pgsub    (struct genSubRecord *) Pointer to genSub structure
 *
 *   Function value:
 *   (<)  status  (long)  Return status, 0 = OK
 * 
 *   External functions:
 *   slaAirmas      (slalib)           Computes relative airmass
 *
 *-
 */

long testDisplayAirmass (struct genSubRecord *pgsub)

{
  double elDeg ;                    /* Current elevation (degs) */
  double zdRad ;                    /* current zenith distance (rads) */
  double zdDeg ;                    /* current zenith distance (degs) */
  double airmass ;                  /* current relative airmass */

/* Fetch input elevation */

  elDeg = *(double *) pgsub->b ;

/* convert elevation to zenith distance */

  zdRad = D90 - elDeg * D2R ;

/* Compute airmass at this zenith distance */

  airmass = slaAirmas (zdRad) ;

/* Convert output angles to degrees */

  zdDeg = R2D * zdRad ;

/* Output on EPICS links */

  *(double *)pgsub->vala = *(double *)pgsub->a ;
  *(double *)pgsub->valb = zdDeg ;
  *(double *)pgsub->valc = airmass;

  return 0;
}
epicsRegisterFunction( testDisplayAirmass );

